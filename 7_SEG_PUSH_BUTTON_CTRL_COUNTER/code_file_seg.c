#include <pic.h>
#define _XTAL_FREQ 20000000

#define SEG PORTB
#define BUTTON RD7

int main()
{
    int C[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

    int count = 0;

    TRISB = 0x00;
    TRISD7 = 1;

    while (1)
    {
        SEG = C[count];

        if (BUTTON == 0)
        {
            __delay_ms(20);

            if (BUTTON == 0)
            {
                count++;

                if (count > 9)
                {
                    count = 0;
                }

                while (BUTTON == 0);

                __delay_ms(20);
            }
        }
    }
}