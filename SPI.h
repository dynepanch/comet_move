#ifndef __SPI
#define __SPI


#include "iodefine.h"

#include "define.h"

void wari_2(void);
void RSPI(void);
//void RSPI_PUTS(unsigned char *data,int data_num,unsigned char *return_p);
void int_rspi0_spti0(void);
void int_rspi0_spri0(void);
void int_rspi0_spii0(void);
void zyusin(void);
void PA_DATA(void);
void spi_start(void);
void wari_2(void);



int flag=0,trans_byte_num=0,frame_num=1;
int get_data_num;
char data1[100];
unsigned char trans_byte[20];
unsigned char *gp;
unsigned char get_data[20];
unsigned char return_data[20];


char receve_data_buff[10];
#endif