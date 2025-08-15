#include <at89c5131.h>
sbit R0=P3^4;
sbit R1=P3^5;
sbit R2=P3^6;
sbit R3=P3^7;
sbit C0=P3^3;
sbit C1=P3^2;
sbit C2=P3^1;
sbit C3=P3^0;
sbit RS=P0^0;	//Register select
sbit RW=P0^1;	//Read from or write to register
sbit EN=P0^2;
int a;
void lcd_init(void);																				//Initialize LCD
void lcd_cmd(unsigned int i);			
void Check_release(void);
void msdelay(unsigned int time);
int check_rnc(void);
void lcd_write_char(unsigned char ch);
int key;
void main()


{while(1)
{
	P3=0X0F;
	Check_release();
	if(P3!=0X0F)
	{
		msdelay(20);
		if(P3==0X0F)
		{
			Check_release();
		}
		else
		{
			key=check_rnc();
		}
		
	}
	else
	{Check_release();}
	lcd_init();
	lcd_cmd(0x80);													//Move cursor to first line
	msdelay(4);
	lcd_write_char(48+key);
	
	
}	
	}

void Check_release(void)
{
		while(P3!=0X0F)
			{a=2;
}
}

void msdelay(unsigned int time)
{
	int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<382;j++);
	}
}

int check_rnc(void)
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
			       Check_release();
						}
		        else
						{
							if(P3==0Xee)
							{key=0x01;}
							else if(P3==0Xed)
							{key=0x02;}
							else if(P3==0Xeb)
							{key=0x03;}
							else if(P3==0Xe7)
							{key=0x04;}	
						}
		
	       }
			  else
				{
					
							if(P3==0Xde)
							{key=0x05;}
							else if(P3==0Xdd)
							{key=0x06;}
							else if(P3==0Xdb)
							{key=0x07;}
							else if(P3==0Xd7)
							{key=0x08;}	
				} 
			
			
		}
	else
	{
		
							if(P3==0Xbe)
							{key=0x09;}
							else if(P3==0Xbd)
							{key=0x0a;}
							else if(P3==0Xbb)
							{key=0x0b;}
							else if(P3==0Xb7)
							{key=0x0c;}	
	}
	}
	else
	{
		
							if(P3==0X7e)
							{key=0x0d;}
							else if(P3==0X7d)
							{key=0x0e;}
							else if(P3==0X7b)
							{key=0x0f;}
							else if(P3==0X77)
							{key=0x10;}	
	}
	return key;
}


void lcd_write_char(unsigned char ch)
{
	RS=1;
	RW=0;
	EN=1;
	P2=ch;
	msdelay(10);
	EN=0;
}
void lcd_init(void)
{
	P2=0x00;
	EN=0;
	RS=0;
	RW=0;
	
	lcd_cmd(0x38);	// Function set: 2 Line, 8-bit, 5x7 dots
	msdelay(4);
	lcd_cmd(0x06);	// Entry mode, auto increment with no shift
	msdelay(4);
	lcd_cmd(0x0C);	// Display on, Curson off
	msdelay(4);
	lcd_cmd(0x01);	// LCD clear
	msdelay(4);
	lcd_cmd(0x80);	//Move cursor to Row 1 column 0
}

void lcd_cmd(unsigned int i)
{
	RS=0;
	RW=0;
	EN=1;
	P2=i;
	msdelay(10);
	EN=0;
}
