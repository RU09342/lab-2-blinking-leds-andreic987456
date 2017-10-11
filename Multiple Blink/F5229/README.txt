Andrei MSP430F5529 Multiple Blink

Code works with case statements that light LEDS 1 and 2 (P1.0 and P4.7 (set = on and
clear =0) based on each other. For instance case 0 (first case) set then clears LED P1.0 
then clears P1.0. Then P4.7 is set and cleared twice. Finally P1.0 is set and cleared a third time.
this will continue as the clock incrimints to 750 where it will then reset the counter 
and repeat the lights order.