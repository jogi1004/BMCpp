#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define F_CPU 20000000UL
#define TRIGGER_PIN PIN1_bm
#define ECHO_PIN PIN0_bm
#define SUMMER_PIN PIN7_bm

#define MESSUNG_TRIGGER_US 10 // Trigger-Impulsdauer in Mikrosekunden
#define MESSUNG_PAUSE_MS 200 // Pause zwischen den Messungen in Millisekunden
#define ABSTAND_MAX_MM 4000 // Maximale Messreichweite in Millimetern
#define MESSUNG_FAKTOR_CMUS 58 // Faktor für die Entfernungsberechnung in cm/us

volatile uint16_t pulse_start = 0;
volatile uint16_t pulse_end = 0;
volatile uint16_t distance = 0;
volatile uint8_t measurement_complete = 0;

void send_pulse(){
    PORTD.OUTSET = TRIGGER_PIN;
    _delay_us(MESSUNG_TRIGGER_US);
    PORTD.OUTCLR = TRIGGER_PIN;
}

ISR(TCB1_INT_vect) {
    if (measurement_complete == 0) {
        if ((PORTD.IN & ECHO_PIN) == ECHO_PIN) {
            pulse_start = TCB1.CNT;
        } else {
            pulse_end = TCB1.CNT;
            uint16_t pulse_duration = pulse_end - pulse_start;
            distance = pulse_duration * MESSUNG_FAKTOR_CMUS;
            measurement_complete = 1;
        }
    }
}

void init_timer() {
    TCB1.CTRLA = TCB_CLKSEL_DIV1_gc | TCB_ENABLE_bm;
    TCB1.CTRLB = TCB_CCMPEN_bm;
    TCB1.INTCTRL = TCB_CAPT_bm;
    TCB1.CCMP = 0xFFFF;
}

int main(void) {
    PORTD.DIRSET = TRIGGER_PIN | SUMMER_PIN;
    PORTD.OUTCLR = SUMMER_PIN;
    init_timer();
    sei();

    while (1) {
        measurement_complete = 0;
        send_pulse();
        _delay_ms(MESSUNG_PAUSE_MS);
        if (distance <= ABSTAND_MAX_MM) {
            PORTD.OUTSET = SUMMER_PIN;
            _delay_ms(distance/10); // Zeit zum Summer aktivieren abhängig von Entfernung
            PORTD.OUTCLR = SUMMER_PIN;
        }
    }
}
