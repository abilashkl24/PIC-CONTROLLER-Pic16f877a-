#include <pic.h>

#define led1 RB0
#define led2 RB1
#define led3 RB2
#define led4 RB3
#define led5 RB4
#define led6 RB5
#define led7 RB6
#define led8 RB7

#define sw RD0

void delay();

void main()
{
    unsigned int led;

    TRISB = 0x00;      // PORTB as output
    PORTB = 0x00;      // All LEDs OFF

    TRISD0 = 1;        // RD0 as input
    
    while(1)
    {
        if(sw == 0)
        {
            delay();         

            if(sw == 0)
            {
                for(led = 0; led < 8; led++)
                {
                    if(sw != 0)       // switch released
                    {
                        PORTB = 0x00;  // LEDs OFF
                        break;  //sequence off
                    }

                    PORTB = (1 << led);
                    delay();
                }
                for(led = 6; led > 0; led--)
                {
                    if(sw != 0)
                    {
                        PORTB = 0x00;   //LEDs OFF
                        break;          // Sequence  off
                    }
                    PORTB = (1 << led);
                    delay();
                }

                PORTB = 0x00;
            }
        }
    }
}

void delay()
{
    unsigned int i;

    for(i = 0; i < 1000; i++);
}