#ifndef __DEFINE
#define __DEFINE

#include "iodefine.h"

#define LED1	(PORTB.PODR.BIT.B1)
#define LED2	(PORTB.PODR.BIT.B0)

#define ON 0
#define OFF 1


void LEDOUT(int i);
void start_up(void);
void CNT_TIME(void);
void wait_time(int time);
void wait(int time);

int CONTLLOR(void);

static int cnt,DATA,cnt1;
static unsigned char READ_DATA[]={0x01,0x42,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static char RETURN_DATA[13];


#endif