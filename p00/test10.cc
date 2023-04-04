#include <avr/io.h>
#include <util/delay.h>

namespace {
    constexpr uint8_t led1 = (0x01 << 2);
    constexpr uint8_t led2 = (0x01 << 3);
}
  
int main() {
    PORTE.DIR = led1 | led2;
    PORTE.OUTSET = led1;

    while(true) {
        _delay_ms(100); 
        PORTE.OUTTGL = led1 | led2;
//        PORTE.OUT ^= led1 | led2;
    }
}
