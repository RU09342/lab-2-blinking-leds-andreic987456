#include <msp430FR5994.h>

#define BUTTON BIT6
#define LED1 BIT0

void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

P1OUT &= ~LED1;                         // Clear P1.0 output latch for a defined power-on state
P1DIR = LED1;                          // Set P1.0 to output direction

P5DIR &= ~BUTTON;
P5REN ^= BUTTON; //Enables a puller-Resistor on the button-pin
P5OUT ^= BUTTON; //Writes a "1" to the portpin, telling the resistor to pullup
PM5CTL0 &= ~LOCKLPM5;

while(1)
{
    if (!(BUTTON & P5IN))
       P1OUT |= LED1;  // Blink Led
    else
       P1OUT &= ~LED1;
}
}
