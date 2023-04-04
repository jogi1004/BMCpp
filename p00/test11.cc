#include <avr/io.h>

namespace {
    constexpr uint8_t led1 = (0x01 << 2);
    constexpr uint8_t led2 = (0x01 << 3);
}

int main() {
    PORTE.DIR = led1 | led2;
    
    RTC.CLKSEL = 0x00;
    
    while (RTC.STATUS & RTC_PERBUSY_bm) ;
    RTC.PER = 1024 * 64u - 1;
   
    while (RTC.STATUS & RTC_CTRLABUSY_bm) ;

    RTC.CTRLA = (0x05 << 3) | RTC_RTCEN_bm;
    
    PORTE.OUTSET = led1;
    while(true) {
        if (RTC.INTFLAGS & RTC_OVF_bm) {
            RTC.INTFLAGS = RTC_OVF_bm;
            PORTE.OUTTGL = led1 | led2;
        }
    }
}
