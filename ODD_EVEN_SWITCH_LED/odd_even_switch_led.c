#include<pic.h>

#define SW1 RD0
#define SW2 RD1
void delay();
void main()
{
    TRISB = 0x00;   // PORT B AS OUTPUT FOR THE 8 LED
    TRISD0 = 1;     // PORT D0 AS INPUT SWITCH1
    TRISD1 = 1;     // PORT D1 AS INPUT SWITCH2
  PORTB = 0x00;  // PORT B AS OFF
   while(1)
    {
      if(SW1 == 0)
        {
         PORTB = 0x55;    //EVEN LED BLINK 
         delay();
        }
      else if(SW2 == 0)
        {
          PORTB = 0xAA;    //ODD LED BLINK
          delay();
        }
      else 
       {
          PORTB = 0x00;   //PORT GETS LOW LED NOT BLINK
       }
     }
 }
void delay()
     {
      unsigned int i;
      for(i=0; i<30000; i++);
     }