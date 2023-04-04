#include <avr/io.h>

namespace AVR {
    template<typename C, uint8_t N> struct Address;
    template<>
    struct Address<RTC_t, 0> {
        static inline constexpr uintptr_t value = 0x0140;
    };
    template<typename C, uint8_t N>
    C* getAddress() {
        return reinterpret_cast<C*>(Address<C, N>::value);
    }
}
namespace AVR {
    struct Avr128Da64 {
        template<uint8_t N>
        struct Rtc {
            static inline constexpr auto mcu_rtc = AVR::getAddress<RTC_t, N>;
            static void init() {
                mcu_rtc()->CLKSEL = 0x00;
                while (mcu_rtc()->STATUS & RTC_PERBUSY_bm) ;
                mcu_rtc()->PER = 32768 / 3;
                while (mcu_rtc()->STATUS & RTC_CTRLABUSY_bm) ;
                mcu_rtc()->CTRLA = RTC_RTCEN_bm;
            }
            static void periodic(auto f) {
                if (mcu_rtc()->INTFLAGS & RTC_OVF_bm) {
                    mcu_rtc()->INTFLAGS = RTC_OVF_bm;
                    f();
                }
            }        
        };
    };
}

namespace {
    constexpr uint8_t led1 = (0x01 << 2);
    constexpr uint8_t led2 = (0x01 << 3);
}
 
using rtc = AVR::Avr128Da64::Rtc<0>;

int main() {
    PORTE.DIR = led1 | led2;
    
    rtc::init();
    
    PORTE.OUT = led1;
    while(true) {
        rtc::periodic([]{
            PORTE.OUTTGL = led1 | led2;
        });
    }
}
