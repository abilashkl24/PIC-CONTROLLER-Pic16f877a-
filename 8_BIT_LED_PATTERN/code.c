#include<pic.h>
#define _XTAL_FREQ 20000000
#define LED PORTB
void main()
{
      TRISB = 0X00;
      while(1)
      {
          LED = 0X18;
          __delay_ms(100);
          LED = 0X24;
          __delay_ms(100);
          LED = 0X42;
          __delay_ms(100);
          LED = 0X81;
         __delay_ms(100);
      }
}