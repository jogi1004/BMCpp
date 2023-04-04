#include <avr/io.h>

namespace AVR {
}
namespace Internal {
    struct Rtc {
        static inline constexpr uintptr_t address = 0x0140;
        static inline RTC_t& mcu_rtc = *reinterpret_cast<RTC_t*>(address);
        
        static inline void init() {
            mcu_rtc.CLKSEL = 0x00;
            while (mcu_rtc.STATUS & RTC_PERBUSY_bm) ;
            mcu_rtc.PER = 32768 / 3;
            while (mcu_rtc.STATUS & RTC_CTRLABUSY_bm) ;
            mcu_rtc.CTRLA = RTC_RTCEN_bm;
        }
        static inline void atOverflow(auto f) {
            if (mcu_rtc.INTFLAGS & RTC_OVF_bm) {
                mcu_rtc.INTFLAGS = RTC_OVF_bm;
                f();
            }
        }        
    };
}

namespace {
    constexpr uint8_t led1 = (0x01 << 2);
    constexpr uint8_t led2 = (0x01 << 3);
}
 
using rtc = Internal::Rtc;

int main() {
    PORTE.DIR = led1 | led2;
    
    rtc::init();
    
    PORTE.OUT = led1;
    while(true) {
        rtc::atOverflow([]{
            PORTE.OUTTGL = led1 | led2;
        });
    }
}
