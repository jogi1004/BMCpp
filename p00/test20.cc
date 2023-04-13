#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define F_CPU 20000000UL
#define TRIGGER_PIN PIN1_bm
#define ECHO_PIN PIN0_bm
#define SUMMER_PIN PIN7_bm

void init_timer()
{
    TCB1.CTRLA = TCB_CLKSEL_DIV1_gc;  // Set timer/counter B1 to run at system clock
    TCB1.CTRLB = TCB_CNTMODE_PWM8_gc; // Set timer/counter B1 to PWM mode

    TCB1.CCMP = 100;             // Set PWM frequency to about 4 kHz
    TCB1.CTRLB |= TCB_CCMPEN_bm; // Enable PWM output on PB7

    // Configure PD2 as output pin
    PORTD.DIRSET = SUMMER_PIN;

        TCB1.CCMP = 10;            // Set PWM duty cycle to 10% for a very low-pitched tone
        PORTD.OUTSET = SUMMER_PIN; // Turn on the summer
        _delay_ms(100);
        PORTD.OUTCLR = SUMMER_PIN; // Turn off the summer
        _delay_ms(100);
        PORTD.OUTSET = SUMMER_PIN; // Turn on the summer
        _delay_ms(100);
        PORTD.OUTCLR = SUMMER_PIN; // Turn off the summer
        _delay_ms(2000);
}

void send_pulse()
{
    // Send trigger pulse
    PORTD.OUTSET = TRIGGER_PIN;
    _delay_us(20);
    PORTD.OUTCLR = TRIGGER_PIN;


}

uint16_t measure_pulse()
{
    uint16_t pulse_start = 0;
    uint16_t pulse_end = 0;

    // Send trigger pulse
    send_pulse();

    // Wait for the echo pulse to start
    while (!(PORTD.IN & ECHO_PIN))
        ;

    pulse_start = TCB1.CNT; // Record the timer value

    // Wait for the echo pulse to end
    while ((PORTD.IN & ECHO_PIN))
        ;

    pulse_end = TCB1.CNT; // Record the timer value
    PORTD.OUTSET = SUMMER_PIN; // Turn on the summer
    _delay_ms(100);
    PORTD.OUTCLR = SUMMER_PIN; // Turn off the summer

    uint16_t pulse_duration = pulse_end - pulse_start; // Calculate pulse duration
    return pulse_duration;                             // Return pulse duration in timer ticks
}

void update_summer(uint16_t distance)
{
    if (distance < 200 && distance >= 100)
    {
        TCB1.CCMP = 50;            // Set PWM duty cycle to 50% for a mid-pitched tone
        _delay_ms(500);
        PORTD.OUTSET = SUMMER_PIN; // Turn on the summer
        _delay_ms(500);
        PORTD.OUTCLR = SUMMER_PIN; // Turn off the summer


    }
    else if (distance < 100 && distance >= 75)
    {
        TCB1.CCMP = 25;            // Set PWM duty cycle to 25% for a low-pitched tone 
        _delay_ms(300);
        PORTD.OUTSET = SUMMER_PIN; // Turn on the summer
        _delay_ms(300);
        PORTD.OUTCLR = SUMMER_PIN; // Turn off the summer
    }
    else if (distance < 50 && distance >= 25)
    {
        TCB1.CCMP = 10;            // Set PWM duty cycle to 10% for a very low-pitched tone
        _delay_ms(100);
        PORTD.OUTSET = SUMMER_PIN; // Turn on the summer
        _delay_ms(100);
        PORTD.OUTCLR = SUMMER_PIN; // Turn off the summer
    }
    else if (distance < 25)
    {
        TCB1.CCMP = 90;            // Set PWM duty cycle to 90% for a very high-pitched tone
        _delay_ms(50);
        PORTD.OUTSET = SUMMER_PIN; // Turn on the summer
        _delay_ms(50);
        PORTD.OUTCLR = SUMMER_PIN; // Turn off the summer
    }
    else
    {
        TCB1.CCMP = 0;             // Turn off the PWM output
        PORTD.OUTCLR = SUMMER_PIN; // Turn off the summer
    }
}

int main(void)
{
    PORTD.DIRSET = TRIGGER_PIN | SUMMER_PIN; // Set trigger and summer pins as outputs
    PORTD.DIRCLR = ECHO_PIN; // Set echo pin as input

init_timer(); // Initialize timer/counter B1 for PWM

while (1)
{
    uint16_t pulse_duration = measure_pulse(); // Measure pulse duration
    uint16_t distance = pulse_duration / 58;   // Convert pulse duration to distance in centimeters

    update_summer(distance); // Update the summer based on the measured distance
}
return 0;

}
