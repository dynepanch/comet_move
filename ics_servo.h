#ifndef __ICS_SERVO__
#define	__ICS_SERVO__

#include "iodefine.h"

const unsigned int put_position = 0x80;
const unsigned int put_stretch = 0xC0;
const unsigned int put_speed = 0xC0;

int servo_angle_buff[20];
int servo_strech_buff[20];
int servo_speed_buff[20];
int cnt_time,cnt_str,ltica_timer;

int set_position(int sci_no,unsigned int id,int set_position);
int set_angle(int id,int angle);
int servo_free(int id);

#endif