#include "define.h"
#include "stdio.h"

extern int servo_angle_buff[20];
extern int cnt_time;

void start_up(void){

	PORTB.PDR.BIT.B1 = 1;
	PORTB.PDR.BIT.B0 = 1;
	
}

void control1(void)
{
	static unsigned int time_b;
	static unsigned int time_c; 
	
	if(time_b++ >= 10)
	{
		time_b = 0;
		spi_start();
	}
}


void LEDOUT(int i){
	int in;
	
	start_up();
	in=~i;
	
	PORTB.PODR.BIT.B1 = (in&0x01)/0x01;
	
	PORTB.PODR.BIT.B0 = (in&0x02)/0x02;
}

void LTICA(void){
	
	LEDOUT(0x01);
	wait(1000);
	LEDOUT(0x02);
	wait(1000);
}



void CNT_TIME(void){
	static unsigned int time_a;
	unsigned char send_data[100];
	
	cnt++;
	cnt1++;
	/*if(time_a++ >= 300)
	{
		time_a = 0;
		sprintf((char*)send_data,"%bd \r\n",CONTLLOR());
		sci1_puts(send_data);
	}*/
}



void wait_time(int time){
	int waiti;
	
	for(waiti=0;waiti<time*5000;waiti++);
}

void wait(int i){
	for(cnt_time=0;cnt_time<i;);
}
