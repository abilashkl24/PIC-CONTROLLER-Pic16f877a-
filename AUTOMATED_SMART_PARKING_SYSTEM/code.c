
#include <pic.h>

#define _XTAL_FREQ 20000000

#define ENTRY_SERVO RE0
#define EXIT_SERVO  RE1

unsigned char slot1;
unsigned char slot2;
unsigned char slot3;
unsigned char slot4;

unsigned char occupied;
unsigned char available;

unsigned char entryOpen = 0;
unsigned char exitOpen = 0;

unsigned char displayCounter = 0;

const unsigned char segment_code[5] =
{
    0x3F,
    0x06,
    0x5B,
    0x4F,
    0x66
};

void LCD_Nibble(unsigned char data)
{
    PORTB = (PORTB & 0x0F) | (data & 0xF0);

    RB1 = 1;
    __delay_us(10);
    RB1 = 0;

    __delay_us(100);
}

void LCD_Cmd(unsigned char cmd)
{
    RB0 = 0;

    LCD_Nibble(cmd);
    LCD_Nibble(cmd << 4);

    __delay_ms(2);
}

void LCD_Data(unsigned char data)
{
    RB0 = 1;

    LCD_Nibble(data);
    LCD_Nibble(data << 4);

    __delay_ms(2);
}

void LCD_String(const char *text)
{
    while(*text)
    {
        LCD_Data(*text);
        text++;
    }
}

void LCD_Init(void)
{
    TRISB = 0x00;
    PORTB = 0x00;

    __delay_ms(20);

    RB0 = 0;
    RB1 = 0;

    LCD_Nibble(0x30);
    __delay_ms(5);

    LCD_Nibble(0x30);
    __delay_ms(1);

    LCD_Nibble(0x30);
    __delay_ms(1);

    LCD_Nibble(0x20);

    LCD_Cmd(0x28);
    LCD_Cmd(0x0C);
    LCD_Cmd(0x06);
    LCD_Cmd(0x01);

    __delay_ms(2);
}

void Update_Parking(void)
{
    slot1 = (RA2 == 0);
    slot2 = (RA3 == 0);
    slot3 = (RA4 == 0);
    slot4 = (RA5 == 0);

    occupied = slot1 + slot2 + slot3 + slot4;

    available = 4 - occupied;

    RC0 = !slot1;
    RC1 = !slot2;
    RC2 = !slot3;
    RC3 = !slot4;

    RC4 = slot1;
    RC5 = slot2;
    RC6 = slot3;
    RC7 = slot4;

    PORTD = segment_code[available];
}

void Update_LCD(void)
{
    LCD_Cmd(0x80);
    LCD_String("Free Slots: ");
    LCD_Data(available + '0');
    LCD_String("   ");

    LCD_Cmd(0xC0);
    LCD_String("Occupied: ");
    LCD_Data(occupied + '0');
    LCD_String("   ");
}

void Servo_Frame(void)
{
    ENTRY_SERVO = 1;
    EXIT_SERVO = 1;

    RB2 = entryOpen;
    RB3 = exitOpen;

    __delay_us(1000);

    if(entryOpen == 0)
        ENTRY_SERVO = 0;

    if(exitOpen == 0)
        EXIT_SERVO = 0;

    __delay_us(1000);

    if(entryOpen == 1)
        ENTRY_SERVO = 0;

    if(exitOpen == 1)
        EXIT_SERVO = 0;

    __delay_ms(18);
}

void main(void)
{
    ADCON1 = 0x06;

    TRISA = 0x3F;
    TRISB = 0x00;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;

    PORTA = 0xFF;
    PORTB = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;
    PORTE = 0x00;

    LCD_Init();

    Update_Parking();
    Update_LCD();

    while(1)
    {
        Update_Parking();

        if(RA0 == 0 && available > 0)
            entryOpen = 1;
        else
            entryOpen = 0;

        if(RA1 == 0)
            exitOpen = 1;
        else
            exitOpen = 0;
       
        RB2 = entryOpen;
        RB3 = exitOpen;
   
        Servo_Frame();

        displayCounter++;

        if(displayCounter >= 10)
        {
            displayCounter = 0;
            Update_Parking();
            Update_LCD();
        }
    }
}
