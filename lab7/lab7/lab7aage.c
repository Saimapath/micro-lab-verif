#include <at89c5131.h>
#include <stdio.h>
#include "lcd.h"

int a;
int key;
sbit NOTE=P0^7;

//void Check_release(void);

void check_rnc(void);
void timer0_isr () interrupt 1
{
	if(key!=9 )//&& key!=0)
	{NOTE=~NOTE;
	}
	else{}

	
	if (key==1)
	{TH0=0XEF;
  TL0=0XB9;
	
	}
	
	else if (key==2)
	{TH0=0XF1;
  TL0=0X88;
	}
	
	else if (key==3)
	{TH0=0XF2;
  TL0=0XFB;
	}
	
	else if (key==4)
	{TH0=0XF3;
  TL0=0XCB;
}
	
	else if (key==5)
	{TH0=0XF5;
  TL0=0X26;
	}
	
else if (key==6)
	{TH0=0XF6;
  TL0=0X3C;
		}
	
	else if (key==7)
	{TH0=0XF7;
  TL0=0X52;
		}
	
	else if (key==8)
	{TH0=0XF7;
  TL0=0XD0;
		}
	 
	
	else
{
}
}





void check_rnc(void)
{
	P3=0X7F;
	if(P3==0X7F)
	{
		P3=0XbF;
			if(P3==0XbF)
		{
			P3=0XdF;
				if(P3==0XdF)
	       {
		        P3=0XeF;
					  if(P3==0XeF)
						{
			       
						}
		        else
						{
							if(P3==0Xee)
							{key=0x0d;}
							else if(P3==0Xed)
							{key=0x0f;}
							else if(P3==0Xeb)
							{key=0x10;}
							else if(P3==0Xe7)
							{key=0x0e;}	
						}
		
	       }
			  else
				{
					
							if(P3==0Xde)
							{key=0x0c;}
							else if(P3==0Xdd)
							{key=0x09;}
							else if(P3==0Xdb)
							{key=0x08;}
							else if(P3==0Xd7)
							{key=0x07;}	
				} 
			
			
		}
	else
	{
		
							if(P3==0Xbe)
							{key=0x0b;}
							else if(P3==0Xbd)
							{key=0x06;}
							else if(P3==0Xbb)
							{key=0x05;}
							else if(P3==0Xb7)
							{key=0x04;}	
	}
	}
	else
	{
		
							if(P3==0X7e)
							{key=0x0a;}
							else if(P3==0X7d)
							{key=0x03;}
							else if(P3==0X7b)
							{key=0x02;}
							else if(P3==0X77)
							{key=0x01;}	
	}
//	return key;
}




void main()

{
	TMOD = 0X11; //mode 1 timer 0 and timer 1
	 //Values for Timer 1 TL1
	//TH1=0X00;
 // TL1=0X00;
  TH0=0X00;
  TL0=0X00;
	ET0 = 1; //activate interrupts for both timers
	///ET1 = 1;
	EA = 1;  //activate global interrupts
	TR0 = 1; //start timer 0
	lcd_init();
	lcd_cmd(0x80);
	NOTE=0;
	//TR1 = 1;

	 while(1)
{
    int b=0;
    int a=0;
   
    P3=0x0F;
	  

    while(b == 0)
    {
        while(a == 0)
        {
            if(P3 != 0x0F)
                a=1;
        }
        a=0;
        while(a == 0)
        {
            if(P3 != 0x0F)
                a=1;
        }
        a=0;
				msdelay(20);
        check_rnc();
				b=1;
		}
		if (key==1)
	{
	lcd_init();
	lcd_cmd(0x80);													//Move cursor to first line
	msdelay(4);
	lcd_write_string("Sa");
	}
	
	else if (key==2)
	{
	lcd_init();
	lcd_cmd(0x80);
		lcd_write_string("Re");}
	
	else if (key==3)
	{
	lcd_init();
lcd_cmd(0x80);
	lcd_write_string("Ga");}
	
	else if (key==4)
	{
lcd_init();
lcd_cmd(0x80);
	lcd_write_string("Ma");}
	
	else if (key==5)
	{
	lcd_init();
lcd_cmd(0x80);
	lcd_write_string("Pa");}
	
else if (key==6)
	{
		lcd_init();
	lcd_cmd(0x80);
	lcd_write_string("Dha");}
	
	else if (key==7)
	{
		lcd_init();
	lcd_cmd(0x80);
	lcd_write_string("Nee");}
	
	else if (key==8)
	{
		lcd_init();
	lcd_cmd(0x80);
	lcd_write_string("Saa");}
	 
	
	else
{
}
	 }}