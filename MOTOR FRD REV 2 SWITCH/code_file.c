#include <pic.h>

#define SW1 RD0
#define SW2 RD1

#define IN1 RB0
#define IN2 RB1
#define EN1  RB2

void main()
{
    TRISD0 = 1;     // SWITCH 1 input
    TRISD1 = 1;     // SWITCH 2 input

    TRISB0 = 0;     // L293D IN1 output
    TRISB1 = 0;     // L293D IN2 output
    TRISB2 = 0;     // L293D ENABLE output

    EN1 = 1;          // Enable L293D

    IN1 = 0;
    IN2 = 0;

    while(1)
    {
        if(SW1 == 0 && SW2 == 1)  //SW1 ON BOTH TRUE SW2 OFF 
        {
            IN1 = 1;
            IN2 = 0;     // Forward
        }

        else if(SW1 == 1 && SW2 == 0)  //SW1 OFF BOTH TRUE SW2 ON 
        {
            IN1 = 0;
            IN2 = 1;     // Reverse
        }

        else
        {
            IN1 = 0;
            IN2 = 0;     // Stop
        }
    }
}