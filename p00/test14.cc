#include <avr/io.h>

#include <type_traits>

namespace AVR {
    struct A;
    struct B;
    struct C;
    struct D;
    struct E;
    struct F;
    
    struct Output;
    struct Input;
    
    template<typename C, typename N> struct Address;
    template<>
    struct Address<RTC_t, std::integral_constant<uint8_t, 0>> {
        static inline constexpr uintptr_t value = 0x0140;
    };
    template<>
    struct Address<VPORT_t, A> {
        static inline constexpr uintptr_t value = 0x0000;
    };
    template<>
    struct Address<VPORT_t, E> {
        static inline constexpr uintptr_t value = 0x0010;
    };
    template<>
    struct Address<PORT_t, A> {
        static inline constexpr uintptr_t value = 0x0400;
    };
    template<>
    struct Address<PORT_t, E> {
        static inline constexpr uintptr_t value = 0x0480;
    };

    template<typename C, uint8_t N>
    C* getAddress() {
        return reinterpret_cast<C*>(Address<C, std::integral_constant<uint8_t, N>>::value);
    }
    template<typename C, typename L>
    C* getAddress() {
        return reinterpret_cast<C*>(Address<C, L>::value);
    }
}
namespace AVR {
    struct Avr128Da64 {

        template<typename L>
        struct Port {
            static inline constexpr auto mcu_vport = AVR::getAddress<VPORT_t, L>;
            static inline constexpr auto mcu_port  = AVR::getAddress<PORT_t, L>;
            
            
            
            
        };
        
        template<typename P, uint8_t N>
        requires (N < 8)
        struct Pin {
            template<typename D>
            static void dir() {
                
            }
        };
        
        template<typename P, uint8_t... N>
        requires ((N < 8) && ...)
        struct PinSet {
            template<typename D>
            static void dir() {
                
            }
            template<uint8_t... II>
            static void on() {
                
            }
            template<uint8_t... II>
            static void toggle() {
                
            }
            
        };
        
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

using porte = AVR::Avr128Da64::Port<AVR::E>;
using ledpin1 = AVR::Avr128Da64::Pin<porte, 2>;
using ledpin2 = AVR::Avr128Da64::Pin<porte, 3>;

using leds = AVR::Avr128Da64::PinSet<porte, 2, 3>;

int main() {
    leds::dir<AVR::Output>();
//    PORTE.DIR = led1 | led2;
    
    rtc::init();
    
    leds::on<0>();
    
//    ledpin1::on();
    
//    PORTE.OUT = led1;
    while(true) {
        rtc::periodic([]{
            leds::toggle<0, 1>();
//            PORTE.OUTTGL = led1 | led2;
        });
    }
}
