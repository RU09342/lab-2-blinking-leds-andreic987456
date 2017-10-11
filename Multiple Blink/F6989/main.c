#include <msp430.h>

void main(void)
{
    PM5CTL0 &= ~LOCKLPM5;
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P9DIR |= BIT7;                  // configure P1.6 as output
    P1DIR |= BIT0;                  // configure P1.0 as output

   int i = 0;   // volatile to prevent optimization
   int j = 0;


    while(1)
    {
        i ++;
        j++;
        if(i>10000)
        {i=0;P9OUT^=BIT7;}
        if(j>10000)
        {j=0;P1OUT^=BIT0;}
        }
}
