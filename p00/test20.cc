#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main(void)
{
    PORTD.DIRSET = PIN1_bm; // Set PD1 as output
    PORTD.DIRCLR = PIN0_bm; // Set PD0 as input
    PORTD.DIRSET = PIN7_bm; // Set PD7 als output

    TCB1.CTRLA = TCB_CLKSEL_DIV1_gc; // Set timer/counter B1 to run at system clock
    TCB1.CTRLB = TCB_WGMODE_NORMAL_gc; // Set timer/counter B1 to normal mode

    while(1)
    {
        PORTD.OUTSET = PIN1_bm; // Send a 10us pulse to trigger the sensor
        _delay_us(10);
        PORTD.OUTCLR = PIN1_bm;

        while(!(PORTD.IN & PIN0_bm)); // Wait for the echo pulse to start

        uint16_t pulse_start = TCB1.CNT; // Record the timer value

        while((PORTD.IN & PIN0_bm)); // Wait for the echo pulse to end

        uint16_t pulse_end = TCB1.CNT; // Record the timer value 
        uint16_t pulse_duration = pulse_end - pulse_start; // Calculate pulse duration
        uint16_t distance = pulse_duration / 58; // Calculate distance in cm

        if (distance < 200 && distance >= 100) {
            PORTD.OUTSET = PIN7_bm; // Set PD2 to high to turn on the LED
            _delay_ms(500);
            PORTD.OUTCLR = PIN7_bm; // Set PD2 to low to turn off the LED
        }
        if (distance < 100 && distance >= 75) {
            PORTD.OUTSET = PIN7_bm; // Set PD2 to high to turn on the LED
            _delay_ms(300);
            PORTD.OUTCLR = PIN7_bm; // Set PD2 to low to turn off the LED
        }
        if (distance < 75 && distance >= 50) {
            PORTD.OUTSET = PIN7_bm; // Set PD2 to high to turn on the LED
            _delay_ms(200);
            PORTD.OUTCLR = PIN7_bm; // Set PD2 to low to turn off the LED
        }
        if (distance < 50 && distance >= 25) {
            PORTD.OUTSET = PIN7_bm; // Set PD2 to high to turn on the LED
            _delay_ms(100);
            PORTD.OUTCLR = PIN7_bm; // Set PD2 to low to turn off the LED
        }
        if (distance < 25) {
            PORTD.OUTSET = PIN7_bm; // Set PD2 to high to turn on the LED
            _delay_ms(10);
            PORTD.OUTCLR = PIN7_bm; // Set PD2 to low to turn off the LED
        }

        //_delay_ms(500); // Wait for 500ms before taking another reading
    }
}