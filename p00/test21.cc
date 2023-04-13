#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Konfiguriere PD2 als Ausgangspin
    PORTD.DIRSET = PIN7_bm;
    
    while(1)
    {
        // Summer einschalten, indem du PD2 auf HIGH setzt
        PORTD.OUTSET = PIN7_bm;
        
        // Warte für 500ms
        _delay_ms(500);
        
        // Summer ausschalten, indem du PD2 auf LOW setzt
        PORTD.OUTCLR = PIN7_bm;
        
        // Warte für 500ms
        _delay_ms(500);
    }
}