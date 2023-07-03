#include <avr/io.h>
#include <avr/interrupt.h>

//#define F_CPU 20000000UL
#define F_CPU 1000000UL
#define TRIGGER_PIN PIN1_bm
#define ECHO_PIN PIN0_bm
#define SUMMER_PIN PIN7_bm

template <typename T>
struct Timer
{
    static void delay(T milliseconds)
    {
        TCB0.CNT = 0;
        TCB0.INTFLAGS = TCB_CAPT_bm;
        TCB0.CCMP = milliseconds * (F_CPU / 1000 / 64); // Set compare value for the desired delay
        TCB0.CTRLA = TCB_CLKSEL_DIV2_gc | TCB_ENABLE_bm; // Start the timer with CLK_PER/2 prescaler

        while (!(TCB0.INTFLAGS & TCB_CAPT_bm))
            ; // Wait for the timer to reach the compare value

        TCB0.CTRLA = 0; // Stop the timer
    }
};

void init_timer()
{
    TCB1.CTRLA = TCB_CLKSEL_DIV1_gc;  // Set timer/counter B1 to run at system clock
    TCB1.CTRLB = TCB_CNTMODE_PWM8_gc; // Set timer/counter B1 to PWM mode

    TCB1.CCMPH = 0;
    TCB1.CCMPL = 100;             // Set PWM frequency to about 4 kHz
    TCB1.CTRLB = TCB_CCMPEN_bm; // Enable PWM output on PC7
}

void send_pulse()
{
    // Send trigger pulse
    PORTD.OUTSET = TRIGGER_PIN;
    Timer<uint16_t>::delay(10);
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

    uint16_t pulse_duration = pulse_end - pulse_start; // Calculate pulse duration
    return pulse_duration;                             // Return pulse duration in timer ticks
}

void update_summer(uint16_t distance)
{
    if (distance < 200 && distance >= 100)
    {
        TCB1.CCMPH = 50; // Set PWM duty cycle to 0% for a very low-pitched tone
        TCB1.CCMPL = 10;
        Timer<uint16_t>::delay(500);
        PORTD.OUTSET = SUMMER_PIN; // Turn on the summer
        Timer<uint16_t>::delay(500);
        PORTD.OUTCLR = SUMMER_PIN; // Turn off the summer
    }
    else if (distance < 100 && distance >= 75)
    {
        TCB1.CCMPH = 0; // Set PWM duty cycle to 0% for a low-pitched tone
        TCB1.CCMPL = 25;
        Timer<uint16_t>::delay(300);
        PORTD.OUTSET = SUMMER_PIN; // Turn on the summer
        Timer<uint16_t>::delay(300);
        PORTD.OUTCLR = SUMMER_PIN; // Turn off the summer
    }
    else if (distance < 50 && distance >= 25)
    {
        TCB1.CCMPH = 0; // Set PWM duty cycle to 0% for a mid-pitched tone
        TCB1.CCMPL = 50;
        Timer<uint16_t>::delay(100);
        PORTD.OUTSET = SUMMER_PIN; // Turn on the summer
        Timer<uint16_t>::delay(100);
        PORTD.OUTCLR = SUMMER_PIN; // Turn off the summer
    }
    else if (distance < 25 && distance > 0)
    {
        TCB1.CCMPH = 0; // Set PWM duty cycle to 0% for a high-pitched tone
        TCB1.CCMPL = 75;
        Timer<uint16_t>::delay(50);
        PORTD.OUTSET = SUMMER_PIN; // Turn on the summer
        Timer<uint16_t>::delay(50);
        PORTD.OUTCLR = SUMMER_PIN; // Turn off the summer
    }
    else
    {
        TCB1.CCMPH = 0; // Set PWM duty cycle to 0% for a very high-pitched tone
        TCB1.CCMPL = 100;
        Timer<uint16_t>::delay(25);
        PORTD.OUTSET = SUMMER_PIN; // Turn on the summer
        Timer<uint16_t>::delay(25);
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
