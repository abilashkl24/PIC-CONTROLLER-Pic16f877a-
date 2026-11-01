#include <pic.h>

#define _XTAL_FREQ 20000000

volatile unsigned char emergency = 0;
volatile unsigned int timer_count = 0;
volatile unsigned char one_second = 0;

unsigned char road = 1;
unsigned char phase = 0;
unsigned char seconds = 0;

unsigned char emergency_active = 0;
unsigned char emergency_seconds = 0;

unsigned char saved_road;
unsigned char saved_phase;
unsigned char saved_seconds;

void interrupt isr()
{
    unsigned char value;

    if (TMR0IF)
    {
        TMR0IF = 0;
        TMR0 = 236;

        timer_count++;

        if (timer_count >= 977)
        {
            timer_count = 0;
            one_second = 1;
        }
    }

    if (INTF)
    {
        INTF = 0;
        emergency = 1;
    }

    if (RBIF)
    {
        value = PORTB;

        if ((value & 0x10) == 0)
        {
            emergency = 2;
        }
        else if ((value & 0x20) == 0)
        {
            emergency = 3;
        }
        else if ((value & 0x40) == 0)
        {
            emergency = 4;
        }

        RBIF = 0;
    }
}

void road1_green()
{
    RD0 = 0;
    RD1 = 0;
    RD2 = 1;

    RD3 = 1;
    RD4 = 0;
    RD5 = 0;

    RD6 = 1;
    RD7 = 0;
    RC0 = 0;

    RC1 = 1;
    RC2 = 0;
    RC3 = 0;
}

void road1_yellow()
{
    RD0 = 0;
    RD1 = 1;
    RD2 = 0;

    RD3 = 1;
    RD4 = 0;
    RD5 = 0;

    RD6 = 1;
    RD7 = 0;
    RC0 = 0;

    RC1 = 1;
    RC2 = 0;
    RC3 = 0;
}

void road2_green()
{
    RD0 = 1;
    RD1 = 0;
    RD2 = 0;

    RD3 = 0;
    RD4 = 0;
    RD5 = 1;

    RD6 = 1;
    RD7 = 0;
    RC0 = 0;

    RC1 = 1;
    RC2 = 0;
    RC3 = 0;
}

void road2_yellow()
{
    RD0 = 1;
    RD1 = 0;
    RD2 = 0;

    RD3 = 0;
    RD4 = 1;
    RD5 = 0;

    RD6 = 1;
    RD7 = 0;
    RC0 = 0;

    RC1 = 1;
    RC2 = 0;
    RC3 = 0;
}

void road3_green()
{
    RD0 = 1;
    RD1 = 0;
    RD2 = 0;

    RD3 = 1;
    RD4 = 0;
    RD5 = 0;

    RD6 = 0;
    RD7 = 0;
    RC0 = 1;

    RC1 = 1;
    RC2 = 0;
    RC3 = 0;
}

void road3_yellow()
{
    RD0 = 1;
    RD1 = 0;
    RD2 = 0;

    RD3 = 1;
    RD4 = 0;
    RD5 = 0;

    RD6 = 0;
    RD7 = 1;
    RC0 = 0;

    RC1 = 1;
    RC2 = 0;
    RC3 = 0;
}

void road4_green()
{
    RD0 = 1;
    RD1 = 0;
    RD2 = 0;

    RD3 = 1;
    RD4 = 0;
    RD5 = 0;

    RD6 = 1;
    RD7 = 0;
    RC0 = 0;

    RC1 = 0;
    RC2 = 0;
    RC3 = 1;
}

void road4_yellow()
{
    RD0 = 1;
    RD1 = 0;
    RD2 = 0;

    RD3 = 1;
    RD4 = 0;
    RD5 = 0;

    RD6 = 1;
    RD7 = 0;
    RC0 = 0;

    RC1 = 0;
    RC2 = 1;
    RC3 = 0;
}

void main()
{
    TRISB = 0x71;
    TRISC = 0x00;
    TRISD = 0x00;

    PORTB = 0x70;
    PORTC = 0x00;
    PORTD = 0x00;

    OPTION = 0x07;

    TMR0 = 236;
    TMR0IF = 0;
    TMR0IE = 1;

    INTF = 0;
    INTE = 1;

    PORTB;
    RBIF = 0;
    RBIE = 1;

    GIE = 1;

    road1_green();

    while (1)
    {
        if (emergency != 0 && emergency_active == 0)
        {
            saved_road = road;
            saved_phase = phase;
            saved_seconds = seconds;

            emergency_active = emergency;
            emergency = 0;
            emergency_seconds = 0;

            timer_count = 0;
            one_second = 0;

            if (emergency_active == 1)
                road1_green();

            else if (emergency_active == 2)
                road2_green();

            else if (emergency_active == 3)
                road3_green();

            else if (emergency_active == 4)
                road4_green();
        }

        if (emergency_active != 0)
        {
            if (one_second)
            {
                one_second = 0;

                emergency_seconds++;

                if (emergency_seconds >= 10)
                {
                    emergency_active = 0;

                    road = saved_road;
                    phase = saved_phase;
                    seconds = saved_seconds;

                    timer_count = 0;
                    one_second = 0;

                    if (road == 1)
                    {
                        if (phase == 0)
                            road1_green();
                        else
                            road1_yellow();
                    }

                    else if (road == 2)
                    {
                        if (phase == 0)
                            road2_green();
                        else
                            road2_yellow();
                    }

                    else if (road == 3)
                    {
                        if (phase == 0)
                            road3_green();
                        else
                            road3_yellow();
                    }

                    else
                    {
                        if (phase == 0)
                            road4_green();
                        else
                            road4_yellow();
                    }
                }
            }
        }

        else
        {
            if (one_second)
            {
                one_second = 0;

                seconds++;

                if (phase == 0)
                {
                    if (seconds >= 5)
                    {
                        seconds = 0;
                        phase = 1;

                        if (road == 1)
                            road1_yellow();

                        else if (road == 2)
                            road2_yellow();

                        else if (road == 3)
                            road3_yellow();

                        else
                            road4_yellow();
                    }
                }

                else
                {
                    if (seconds >= 2)
                    {
                        seconds = 0;
                        phase = 0;

                        if (road == 1)
                        {
                            road = 2;
                            road2_green();
                        }

                        else if (road == 2)
                        {
                            road = 3;
                            road3_green();
                        }

                        else if (road == 3)
                        {
                            road = 4;
                            road4_green();
                        }

                        else
                        {
                            road = 1;
                            road1_green();
                        }
                    }
                }
            }
        }
    }
}