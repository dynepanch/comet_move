#include"move.h"
#include"VS_C3.h"

extern int servo_angle_buff[20];
extern int cnt_time;

void punch_bace(void){
	leftarm(-150,60,20);
	rightarm(-150,60,20);
	leftleg(15,35,-50,-25);
	rightleg(15,35,-50,-25);
	kosi(0);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
}

void punch_side_L(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);	
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		rightleg(30,10,-10,10);
		leftleg(10,40,-50,-45);
	}else{
		rightleg(10,50,-50,-20);
		leftleg(15,30,-30,-45);
		leftarm(-150,60,0);
		rightarm(-150,60,0);
		kosi(0);
	}
}

void punch_side_R(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		leftleg(30,10,-10,10);
		rightleg(15,40,-50,-35);
	}else{
		leftleg(10,50,-50,-20);
		rightleg(10,30,-30,-35);
		leftarm(-150,60,0);
		rightarm(-150,60,0);
		kosi(0);
	}
}

void punch_up_L(void){
	if(cnt_time>500){
		leftarm(0,0,0);
		rightarm(0,0,0);
		leftleg(15,35,-50,-25);
		rightleg(15,35,-50,-25);
		kosi(90);
	}else{
		leftarm(-150,60,0);
		rightarm(-150,60,0);
		leftleg(15,35,-50,-25);
		rightleg(15,35,-50,-25);
		kosi(90);
	}
}