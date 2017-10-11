#include <msp430.h> 
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       // Disable the GPIO power-on default high-impedance mode
                                // to activate previously configured port settings

    P1DIR |= BIT0; // Tells the processor to write
    P1OUT |= BIT0;


    while (1) // INFINITE LOOP
            {
               P1OUT ^= BIT0;  // Exclusive OR so that every time it loops it alternates between being on and off.
               __delay_cycles(80000);  // Delays the clock so that the blinking is actually visible
            }
    return 0;
}
