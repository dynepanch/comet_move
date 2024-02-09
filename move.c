#include"move.h"
#include"VS_C3.h"

extern int servo_angle_buff[20];
extern int cnt_time;

void leftarm(int kubi,int ude,int kata){
	//kubi+=;
	//ude+=;
	
	if(kata<360){
		kata+=2;
		set_angle(2,kata);
	}else{
		servo_free(2);
		//servo_free_2(12,2);
	}
	if(ude<360){
		ude*=-1;
		set_angle(1,ude);
	}else{
		servo_free(1);
		//servo_free_2(12,1);
	}
	if(kubi<360){
		kubi*=-1;
		
		set_angle(0,kubi);
	}else{
		servo_free(0);
		//servo_free_2(12,0);
	}
}

void leftarm_strech(int kubi,int ude,int kata){
	set_strech_num(2,kata);
	set_strech_num(1,ude);
	set_strech_num(0,kubi);
}

void leftarm_speed(int kubi,int ude,int kata){
	set_speed_num(2,kata);
	set_speed_num(1,ude);
	set_speed_num(0,kubi);
}

void rightarm(int kubi,int ude,int kata){
	//kubi=7500+kubi/270;
	//ude=7500+ude/270;
	if(kata<360){
		kata*=-1;
		kata-=4;
		set_angle(5,kata);
	}else{
		servo_free(5);
		//servo_free_2(9,5);
	}
	if(ude<360){
		//ude*=-1;
		set_angle(4,ude);
	}else{
		servo_free(4);
		//servo_free_2(9,4);
	}
	if(kubi<360){
		set_angle(3,kubi);
	}else{
		servo_free(3);
		//servo_free_2(9,3);
	}
}


void rightarm_strech(int kubi,int ude,int kata){
	set_strech_num(5,kata);
	set_strech_num(4,ude);
	set_strech_num(3,kubi);
}

void rightarm_speed(int kubi,int ude,int kata){
	set_speed_num(5,kata);
	set_speed_num(4,ude);
	set_speed_num(3,kubi);
}

void rightleg(int mata,int momo,int hiza,int kubi){
	
	if(mata<360){
		mata-=3;
		set_angle(13,mata);
	}else{
		servo_free(13);
		//servo_free_2(5,13);
	}
	if(momo<360){
		momo-=2;
		set_angle(12,momo);
	}else{
		servo_free(12);
		//servo_free_2(5,12);
	}
	if(hiza<360){
		hiza+=8;
		set_angle(11,hiza);
	}else{
		servo_free(11);
		//servo_free_2(5,11);
	}
	if(kubi<360){
		kubi*=-1;
		kubi+=2;
		set_angle(10,kubi);
	}else{
		servo_free(10);
		//servo_free_2(5,10);
	}
	
}


void rightleg_strech(static int mata,static int momo,static int hiza,static int kubi){
	set_strech_num(13,mata);
	set_strech_num(12,momo);
	set_strech_num(11,hiza);
	set_strech_num(10,kubi);
	
}

void rightleg_speed(static int mata,static int momo,static int hiza,static int kubi){
	set_speed_num(13,mata);
	set_speed_num(12,momo);
	set_speed_num(11,hiza);
	set_speed_num(10,kubi);
	
}

void leftleg(static int mata,static int momo,static int hiza,static int kubi){
	//momo=7500+momo/270;
	//hiza=7500+hiza/270;
	if(mata<360){
		mata*=-1;
		mata+=3;
		set_angle(9,mata);
	}else{
		servo_free(9);
		//servo_free_2(6,9);
	}
	if(momo<360){
		momo*=-1;
		momo+=3;	
		set_angle(8,momo);
	}else{
		servo_free(8);
		//servo_free_2(6,8);
	}
	if(hiza<360){
		hiza*=-1;	
		set_angle(7,hiza);
	}else{
		servo_free(7);
		//servo_free_2(6,7);
	}
	if(kubi<360){
		kubi-=2;
		set_angle(6,kubi);	
	}else{
		servo_free(6);
		//servo_free_2(6,6);
	}
}
void leftleg_strech(static int mata,static int momo,static int hiza,static int kubi){
	set_strech_num(9,mata);
	set_strech_num(8,momo);
	set_strech_num(7,hiza);
	set_strech_num(6,kubi);	
}

void leftleg_speed(static int mata,static int momo,static int hiza,static int kubi){
	set_speed_num(9,mata);
	set_speed_num(8,momo);
	set_speed_num(7,hiza);
	set_speed_num(6,kubi);	
}

void kosi(static int kosi){
	if(kosi<360){
		kosi-=4;
		set_angle(14,kosi);
	}else{
		servo_free(14);
		//servo_free_2(6,14);
	}
}


void kosi_strech(int kosi){
	set_strech_num(14,kosi);
}


void kosi_speed(int kosi){
	set_speed_num(14,kosi);
}

void datu(void){
	leftarm(360,360,360);
	rightarm(360,360,360);
	leftleg(360,360,360,360);
	rightleg(360,360,360,360);
	kosi(360);
}

void zero_all(void){
	leftarm(0,0,0);
	rightarm(0,0,0);
	leftleg(0,0,0,0);
	rightleg(0,0,0,0);
	kosi(0);
}

void bace(void){
	leftarm(0,360,0);
	rightarm(0,360,0);
	leftleg(15,35,-50,-30);
	rightleg(15,35,-50,-30);
	kosi(0);

	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(80,60,60,60);
	rightleg_strech(80,60,60,60);
	kosi_strech(60);
	
	rightarm_speed(0,127,127);
	leftarm_speed(0,127,127);
	leftleg_speed(127,127,127,127);
	rightleg_speed(127,127,127,127);
	kosi_speed(127);
	
}


void side_L(void){
	rightarm_speed(0,127,127);
	leftarm_speed(0,127,127);
	leftleg_speed(127,127,127,127);
	rightleg_speed(127,127,127,127);
	kosi_speed(127);
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(80,60,60,60);
	rightleg_strech(80,60,60,60);
	kosi_strech(60);	
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		rightleg(20,10,-10,10);
		leftleg(20,45,-45,-20);
	}else{
		rightleg(5,45,-45,-20);
		leftleg(5,10,-10,0);
		rightarm(-40,60,0);
		leftarm(-40,60,0);
		kosi(0);
	}
}

void side_R(void){
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(80,60,60,60);
	rightleg_strech(80,60,60,60);
	kosi_strech(60);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		leftleg(20,10,-10,10);
		rightleg(20,45,-45,-20);
	}else{
		leftleg(5,45,-45,-20);
		rightleg(5,10,-10,0);
		leftarm(-40,60,0);
		rightarm(-40,60,0);
		kosi(0);
	}
}
void side_wolk_R(void){
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	leftarm(-30,60,0);
	rightarm(-30,60,0);
	kosi_strech(60);
	if(cnt_time>2650){
		cnt_time=0;
	}else if(cnt_time>2200){
		//�E��������
		rightleg(5,90,-90,-5);
		leftleg(15,40,-40,-5);
	}else if(cnt_time>1750){
		//���d�S
		rightleg(5,35,-35,-5);
		leftleg(0,45,-45,0);
	}else if(cnt_time>1350){
		//������
		leftleg(5,35,-50,5);
		rightleg(5,40,-40,-10);
	}else if(cnt_time>900){
		//����������
		leftleg(15,90,-90,-10);
		rightleg(0,40,-40,0);
	}else if(cnt_time>450){
		//�E�d�S
		leftleg(5,35,-35,-10);
		rightleg(0,45,-45,0);
	}else{
		//������
		leftleg(5,40,-40,0);
		rightleg(0,40,-40,5);
	}
}
void side_wolk_L(void){
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>5500){
		cnt_time=0;
	}else if(cnt_time>4500){
		//����������
		leftarm(10,40,0);
		rightarm(10,60,0);
		kosi(0);
		leftleg(15,35,-50,-15);
		rightleg(5,35,-50,-5);
	}else if(cnt_time>3500){
		//����������
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		leftleg(10,80,-80,0);
		rightleg(-15,10,-40,10);
	}else if(cnt_time>2500){
		//�E���ɏd�S��
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		leftleg(10,30,-40,-10);
		rightleg(-10,35,-50,10);
	}else if(cnt_time>1500){
		//�������낦��
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		leftleg(0,35,-50,0);
		rightleg(0,35,-50,0);
	}else if(cnt_time>500){
		//�����ɏd�S��
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		leftleg(-10,10,-45,10);
		rightleg(10,80,-80,0);
	}else{
		//�����ɏd�S��
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		leftleg(0,35,-50,-15);
		rightleg(15,10,-10,-15);
	}
}

void AL_side_L(void){
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>1000){
		cnt_time=0;
	}else if(cnt_time>500){
		rightleg(20,30,-30,0);
		leftleg(10,40,-50,-25);
	}else{
		rightleg(10,70,-70,-15);
		leftleg(15,50,-50,-25);
		leftarm(10,60,0);
		rightarm(10,30,0);
		kosi(0);
	}
}

void roll_R(void){
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(100);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		leftleg(0,0,-20,-20);
		rightleg(0,0,-20,-20);
		kosi(-30);
	}else{
		leftleg(15,40,-40,-20);
		rightleg(15,40,-40,-20);
		leftarm(0,60,0);
		rightarm(0,60,0);
		kosi(0);
	}
}

void syagami_roll_R(void){
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		leftleg(5,90,-90,-40);
		rightleg(5,90,-90,-40);
		kosi(-30);
	}else{
		leftleg(40,90,-90,-40);
		rightleg(40,90,-90,-40);
		leftarm(-70,30,0);
		rightarm(-70,30,0);
		kosi(0);
	}
}

void roll_L(void){
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(100);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		rightleg(5,0,-20,-20);
		leftleg(5,0,-20,-20);
		kosi(30);
	}else{
		rightleg(15,40,-40,-20);
		leftleg(15,40,-40,-20);
		leftarm(0,60,0);
		rightarm(0,60,0);
		kosi(0);
	}
}

void syagami_roll_L(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		leftleg(5,90,-90,-40);
		rightleg(5,90,-90,-40);
		kosi(30);
	}else{
		leftleg(40,90,-90,-40);
		rightleg(40,90,-90,-40);
		leftarm(-70,30,0);
		rightarm(-70,30,0);
		kosi(0);
	}
}
void suri_front(void){
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftarm(-40,60,10);
	rightarm(-40,60,10);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		rightleg(5,40,-40,-7);
		leftleg(5,0,-40,-15);
		kosi(5);
	}else{
		rightleg(5,0,-40,-15);
		leftleg(5,42,-42,-7);
		kosi(-5);
	}
}

void suri_back(void){
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftarm(0,50,0);
	rightarm(0,50,0);
	if(cnt_time>800){
		cnt_time=0;
	}else if(cnt_time>400){
		rightleg(10,40,-40,-20);
		leftleg(10,50,10,-10);
		kosi(5);
	}else{
		rightleg(10,50,10,-10);
		leftleg(10,40,-40,-20);
		kosi(-5);
	}
}

void syagami(void){
	static int i=0;
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(10,20,20);
	rightarm_strech(10,20,20);
	leftleg_strech(100,20,20,60);
	rightleg_strech(100,20,20,60);
	kosi_strech(20);
	kosi(0);
	if(cnt_time>2000){
		i=1;
	}else if(cnt_time>300){
		leftleg(40,80,-90,-50);
		rightleg(40,80,-90,-50);
		leftarm(-60,30,20);
		rightarm(-60,30,20);
	}else{
		leftleg(40,35,-90,-40);
		rightleg(40,35,-90,-40);
		leftarm(-60,30,20);
		rightarm(-60,30,20);
	}
	if(i==1){
		leftleg(40,90,-90,-50);
		rightleg(40,90,-90,-50);
		leftarm(-60,360,20);
		rightarm(-60,360,20);
	}
	if(CONTLLOR()!=C_PEC){
			i=0;
	}
}

void stand_flont(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	kosi(0);
	if(cnt_time>1500){
		leftleg(40,80,-80,-45);
		rightleg(40,80,-80,-45);
		leftarm(0,40,80);
		rightarm(0,40,80);
	}else if(cnt_time>500){
		leftleg(40,80,-80,-45);
		rightleg(40,80,-80,-45);
		leftarm(-90,40,80);
		rightarm(-90,40,80);
	}else{
		leftleg(40,80,-80,-45);
		rightleg(40,80,-80,-45);
		leftarm(-90,40,0);
		rightarm(-90,40,0);
	}
}

void stand_side_L(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	kosi(0);
	if(cnt_time>2800){
		leftleg(15,80,-80,-40);
		rightleg(15,80,-80,-40);
	}else if(cnt_time>1500){
		leftleg(60,80,-80,-60);
		rightleg(60,80,-80,-60);
		leftarm(0,60,-80);
		rightarm(0,60,80);
	}else if(cnt_time>1000){
		leftleg(60,80,-80,-60);
		rightleg(60,80,-80,-60);
		leftarm(0,-50,-80);
		rightarm(0,-50,80);
	}else{
		leftleg(60,80,-80,-60);
		rightleg(60,80,-80,-60);
		leftarm(0,-50,0);
		rightarm(0,-50,0);
	}
}

void stand_side_R(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	kosi(0);
	if(cnt_time>2800){
		leftleg(15,80,-80,-40);
		rightleg(15,80,-80,-40);
	}else if(cnt_time>1500){
		leftleg(60,80,-80,-60);
		rightleg(60,80,-80,-60);
		leftarm(0,60,80);
		rightarm(0,60,-80);
	}else if(cnt_time>1000){
		leftleg(60,80,-80,-60);
		rightleg(60,80,-80,-60);
		leftarm(0,-50,80);
		rightarm(0,-50,-80);
	}else{
		leftleg(60,80,-80,-60);
		rightleg(60,80,-80,-60);
		leftarm(0,-50,0);
		rightarm(0,-50,0);
	}
}
void stand_back(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	kosi(0);
	if(cnt_time>1500){
		leftleg(40,70,-90,-45);
		rightleg(40,70,-90,-45);
		leftarm(-30,50,-80);
		rightarm(-30,50,-80);	
	}else if(cnt_time>500){
		leftleg(40,80,-80,-45);
		rightleg(40,80,-80,-45);
		leftarm(-100,40,-80);
		rightarm(-100,40,-80);
	}else{
		leftleg(40,80,-80,-45);
		rightleg(40,80,-80,-45);
		leftarm(-100,40,0);
		rightarm(-100,40,0);
	}
}

void gurd_roll_R(void){
	leftarm(10,40,0);
	rightarm(10,40,0);
	if(cnt_time>1200){
		cnt_time=0;
	}else if(cnt_time>600){
		leftleg(15,10,-70,-45);
		rightleg(15,10,-70,-45);
		kosi(-20);
	}else{	
		leftleg(30,10,-70,-45);
		rightleg(30,10,-70,-45);
		kosi(0);
	}

}

void gurd_roll_L(void){
	leftarm(10,40,0);
	rightarm(10,40,0);
	if(cnt_time>1200){
		cnt_time=0;
	}else if(cnt_time>600){
		leftleg(15,10,-70,-45);
		rightleg(15,10,-70,-45);
		kosi(20);
	}else{	
		leftleg(30,10,-70,-45);
		rightleg(30,10,-70,-45);
		kosi(0);
	}

}

void roll_side_L(void){
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftarm(-40,60,10);
	rightarm(-40,60,10);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		rightleg(5,40,-40,-7);
		leftleg(5,0,-40,-15);
		kosi(10);
	}else{
		rightleg(15,0,-40,-15);
		leftleg(15,42,-42,-7);
		kosi(0);
	}
}
void roll_side_L_R(void){
	side_L();
	if(cnt_time>600){
		//cnt_time=0;
	}else if(cnt_time>300){
		kosi(-10);
	}else{
		kosi(0);
	}
}

void roll_side_R_L(void){
	/*side_R();
	if(cnt_time>600){
		//cnt_time=0;
	}else if(cnt_time>300){
		kosi(10);
	}else{
		kosi(0);
	}*/
}

void roll_side_R(void){
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftarm(-40,60,10);
	rightarm(-40,60,10);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		leftleg(5,40,-40,-7);
		rightleg(5,0,-40,-15);
		kosi(-10);
	}else{
		leftleg(15,0,-40,-15);
		rightleg(15,42,-42,-7);
		kosi(0);
	}
}
void front_work(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftarm(-30,60,10);
	rightarm(-30,60,10);
	kosi(0);
	
	if(cnt_time>2650){
		cnt_time=0;
	}else if(cnt_time>2200){
		//�E��������
		rightleg(5,90,-90,-5);
		leftleg(5,30,-50,5);
	}else if(cnt_time>1750){
		//���d�S
		rightleg(5,35,-35,-5);
		leftleg(0,45,-45,0);
	}else if(cnt_time>1350){
		//������
		leftleg(0,50,-35,5);
		rightleg(5,35,-50,-10);
	}else if(cnt_time>900){
		//����������
		leftleg(5,90,-90,-10);
		rightleg(5,30,-50,5);
	}else if(cnt_time>450){
		//�E�d�S
		leftleg(5,35,-35,-10);
		rightleg(0,45,-45,0);
	}else{
		//������
		leftleg(5,30,-50,0);
		rightleg(0,50,-30,5);
	}
}

void back_wolk(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi(0);
	leftarm(-30,60,0);
	rightarm(-30,60,0);
		if(cnt_time>2650){
		cnt_time=0;
	}else if(cnt_time>2200){
		//�E��������
		rightleg(5,90,-90,-5);
		leftleg(5,50,-30,5);
	}else if(cnt_time>1750){
		//���d�S
		rightleg(5,35,-35,-5);
		leftleg(0,45,-45,0);
	}else if(cnt_time>1350){
		//������
		leftleg(0,35,-50,5);
		rightleg(5,50,-35,-10);
	}else if(cnt_time>900){
		//����������
		leftleg(5,90,-90,-10);
		rightleg(5,50,-30,5);
	}else if(cnt_time>450){
		//�E�d�S
		leftleg(5,35,-35,-10);
		rightleg(0,45,-45,0);
	}else{
		//������
		leftleg(5,50,-30,0);
		rightleg(0,30,-50,5);
	}
}

void throw(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>2000){
		rightarm(-10,0,90);
		leftarm(-10,0,90);
		leftleg(15,40,-35,-10);
		rightleg(15,40,-35,-10);
	}else{	
		rightarm(30,50,90);
		leftarm(30,50,90);
		kosi(0);
		leftleg(15,70,-70,-10);
		rightleg(15,70,-70,-10);
	}
}


void hand_huri(void){
	static int i=0,j=0,cnti,cntj;
	static int kuri=1,swi=0,swj=0;
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
		cnti++;
		cntj++;
		if(i>30){
			swi=1;
		}else if(i<-30){
			swi=0;
		}
		if(j>20){
			swj=1;
		}else if(j<-20){
			swj=0;
		}
		if(cnti>1000&&swi==0){
			i++;
			cnti=0;	
		}else if(cnti>1000){
			i--;
			cnti=0;
		}
		if(cntj>2000&&swj==0){
			j++;
			cntj=0;	
		}else if(cntj>2000){
			j--;
			cntj=0;
		}
		leftarm(0,60,0);
		rightarm(0,j-60,j);
		leftleg(15,35,-50,-20);
		rightleg(15,35,-50,-20);
		kosi(i);
}

void touritu(void){
	kosi(0);
	if(cnt_time>7500){
		cnt_time=6400;
	}else if(cnt_time>7000){
		leftarm(-10,-10,80);
		rightarm(-10,-10,-80);
		leftleg(0,80,-80,0);
		rightleg(0,80,-80,0);
	}else if(cnt_time>6500){
		leftarm(0,0,30);
		rightarm(0,0,-30);
		leftleg(0,80,-80,0);
		rightleg(0,80,-80,0);
	}else if(cnt_time>5500){
		leftarm(-10,-10,-80);
		rightarm(-10,-10,80);
	}else if(cnt_time>3500){
		leftarm(0,0,80);
		rightarm(0,0,-80);
	}else if(cnt_time>3000){
		leftarm(0,0,90);
		rightarm(0,0,90);
		leftleg(15,80,-80,-20);
		rightleg(15,80,-80,-20);
	}else{
		leftarm(60,60,90);
		rightarm(60,60,90);
		leftleg(15,0,-80,-20);
		rightleg(15,0,-80,-20);
		kosi(0);
	}
}

void analog_wolk(void){
	float joint_L_X,joint_L_Y;
	joint_L_X=-1*(((joint_L() & 0xff00)/0x100)-0x80)/18;
	joint_L_Y=((joint_L() & 0x00ff)-0x7f)/4;
	if(-1*joint_L_Y/3>0){	
		leftarm(-30,60,-1*joint_L_Y/4);
		rightarm(-30,60,-1*joint_L_Y/4);
	}else{
		leftarm(-30,60,joint_L_Y/3);
		rightarm(-30,60,joint_L_Y/3);
	}
	kosi(0);
	if(cnt_time>2650){
		cnt_time=0;
	}else if(cnt_time>2200){
		//�E��������
		rightleg(5,90,-90,-5);
		leftleg(5-joint_L_X,30+joint_L_Y,-30+joint_L_Y,10);
	}else if(cnt_time>1750){
		//���d�S
		rightleg(5,35,-35,-5);
		leftleg(5,45,-45,5);
	}else if(cnt_time>1350){
		//������
		leftleg(5+joint_L_X,35,-35,0);
		rightleg(5,35,-35,-10);
	}else if(cnt_time>900){
		//����������
		leftleg(5,90,-90,-10);
		rightleg(5+joint_L_X,30+joint_L_Y,-30+joint_L_Y,10);
	}else if(cnt_time>450){
		//�E�d�S
		leftleg(5,35,-35,-10);
		rightleg(5,45,-45,5);
	}else{
		//������
		leftleg(5,35,-35,-10);
		rightleg(5,35,-35,0);
	}
}

void back_osidasi(void){
	if(cnt_time>1000){
		cnt_time=0;
	}else if(cnt_time>500){
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,50,0,-10);
		rightleg(15,-30,-50,-25);
		kosi(10);
	}else{
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,-30,-50,-25);
		rightleg(15,50,-0,-10);
		kosi(-10);
	}
}
void flont_osidasi(void){
	if(cnt_time>1000){
		cnt_time=0;
	}else if(cnt_time>500){
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,50,0,-25);
		rightleg(15,-30,-50,-10);
		kosi(-10);
	}else{
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,-30,-50,-10);
		rightleg(15,50,-0,-25);
		kosi(10);
	}
}

void fuck_R(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftarm(0,50,0);
	if(cnt_time>3000){
		rightarm(360,0,0);
		rightleg(20,40,-45,-25);
		leftleg(20,40,-45,-25);
		kosi(0);
	}else if(cnt_time>1500){
		rightarm(-10,0,60);
		rightleg(20,40,-45,-25);
		leftleg(20,40,-45,-25);
	}else if(cnt_time>800){
		kosi(-90);
		rightarm(0,0,60);
		rightleg(30,40,-45,-20);
		leftleg(30,40,-45,-20);
	}else if(cnt_time>300){
		kosi(0);
		rightarm(0,0,0);
		rightleg(30,40,-45,-20);
		leftleg(30,40,-45,-20);
	}else{
		rightarm(10,60,0);
		kosi(0);
		rightleg(30,40,-45,-30);
		leftleg(30,40,-45,-30);
	}
}

void fuck_low_R(void){
rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftarm(0,50,0);
	if(cnt_time>3000){
		rightarm(360,40,0);
		rightleg(20,40,-45,-25);
		leftleg(20,40,-45,-25);
		kosi(0);
	}else if(cnt_time>1500){
		rightarm(-10,40,60);
		rightleg(20,40,-45,-25);
		leftleg(20,40,-45,-25);
	}else if(cnt_time>800){
		kosi(-90);
		rightarm(0,40,60);
		rightleg(30,40,-45,-20);
		leftleg(30,40,-45,-20);
	}else if(cnt_time>300){
		kosi(0);
		rightarm(0,40,0);
		rightleg(30,40,-45,-20);
		leftleg(30,40,-45,-20);
	}else{
		rightarm(10,60,0);
		kosi(0);
		rightleg(30,40,-45,-30);
		leftleg(30,40,-45,-30);
	}
}

void fuck_L(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,60);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	rightarm(0,50,0);
	if(cnt_time>3000){
		leftarm(360,0,0);
		rightleg(20,40,-45,-25);
		leftleg(20,40,-45,-25);
		kosi(0);
	}else if(cnt_time>1500){
		leftarm(-10,0,60);
		rightleg(20,40,-45,-25);
		leftleg(20,40,-45,-25);
		rightleg(30,40,-45,-20);
		leftleg(30,40,-45,-20);
	}else if(cnt_time>800){
		kosi(90);
		leftarm(0,0,60);
		rightleg(30,40,-45,-20);
		leftleg(30,40,-45,-20);
	}else if(cnt_time>300){
		leftarm(0,0,0);
		rightleg(30,40,-45,-20);
		leftleg(30,40,-45,-20);	
	}else{
		leftarm(10,60,0);
		kosi(0);
		rightleg(30,40,-45,-30);
		leftleg(30,40,-45,-30);
	}	
}

void fuck_low_L(void){
		rightarm_speed(127,127,127);
	leftarm_speed(127,127,60);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	rightarm(0,50,0);
	if(cnt_time>3000){
		leftarm(360,0,0);
		rightleg(20,40,-45,-25);
		leftleg(20,40,-45,-25);
		kosi(0);
	}else if(cnt_time>1500){
		leftarm(-10,40,60);
		rightleg(20,40,-45,-25);
		leftleg(20,40,-45,-25);
		rightleg(30,40,-45,-20);
		leftleg(30,40,-45,-20);
	}else if(cnt_time>800){
		kosi(90);
		leftarm(0,40,60);
		rightleg(30,40,-45,-20);
		leftleg(30,40,-45,-20);
	}else if(cnt_time>300){
		leftarm(0,40,0);
		rightleg(30,40,-45,-20);
		leftleg(30,40,-45,-20);	
	}else{
		leftarm(10,60,0);
		kosi(0);
		rightleg(30,40,-45,-30);
		leftleg(30,40,-45,-30);
	}
}

void up_R(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	rightleg(20,30,-55,-25);
	leftleg(20,30,-55,-25);
	if(cnt_time >2300){
		rightarm(-80,360,0);
		leftarm(0,60,0);
		kosi(0);
	}else if(cnt_time >1500){
		rightarm(-80,-70,20);
	}else if(cnt_time >1000){
		rightarm(30,-60,20);
		kosi(-70);
	}else if(cnt_time>500){
		rightarm(110,-30,50);
		kosi(-40);
		leftarm(0,60,0);
	}else{
		rightarm(30,30,0);
		leftarm(0,60,0);
		kosi(0);
	}
}


void up_up_R(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time >2300){
		rightarm(-80,360,0);
		leftarm(0,60,0);
		kosi(0);
		rightleg(15,40,-45,-25);
		leftleg(15,40,-45,-25);
	}else if(cnt_time >1300){
		rightarm(-80,-50,0);
		kosi(-90);
	}else if(cnt_time >1000){
		rightarm(100,-30,10);
		kosi(-80);
		rightleg(10,15,-15,-20);
		leftleg(10,15,-15,-20);
	}else if(cnt_time>500){
		rightarm(90,-30,50);
		kosi(-40);
		leftarm(0,60,0);
		rightleg(10,15,-15,-20);
		leftleg(10,15,-15,-20);
	}else{
		rightarm(30,0,0);
		leftarm(0,60,0);
		kosi(0);
		rightleg(10,20,-20,-20);
		leftleg(10,20,-20,-20);
	}
}


void up_up_L(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time >2300){
		leftarm(-80,360,0);
		rightarm(0,60,0);
		kosi(0);
		rightleg(15,40,-45,-25);
		leftleg(15,40,-45,-25);
	}else if(cnt_time >1300){
		leftarm(-80,-50,0);
		kosi(90);
	}else if(cnt_time >1000){
		leftarm(100,-30,20);
		kosi(80);
		rightleg(10,15,-15,-20);
		leftleg(10,15,-15,-20);
	}else if(cnt_time>500){
		leftarm(100,-30,50);
		kosi(40);
		rightarm(0,60,0);
		rightleg(10,15,-15,-20);
		leftleg(10,15,-15,-20);
	}else{
		leftarm(30,0,0);
		rightarm(0,60,0);
		kosi(0);
		rightleg(10,20,-20,-20);
		leftleg(10,20,-20,-20);
	}
}



void up_L(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	rightleg(20,30,-55,-25);
	leftleg(20,30,-55,-25);
	if(cnt_time >2300){
		leftarm(-80,360,0);
		rightarm(0,60,0);
		kosi(0);
	}else if(cnt_time >1500){
		leftarm(-80,-80,20);
	}else if(cnt_time >1000){
		leftarm(30,-70,20);
		kosi(70);
	}else if(cnt_time>500){
		leftarm(110,-30,50);
		kosi(40);
		rightarm(0,60,0);	
	}else{
		leftarm(30,30,0);
		rightarm(0,60,0);
		kosi(0);
	}
}

void punch_L(void){
	rightarm_speed(127,60,60);
	leftarm_speed(127,60,60);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	
	if(cnt_time >2800){
		leftarm(-80,360,0);
		rightarm(0,60,0);
		kosi(0);
		rightleg(15,40,-45,-25);
		leftleg(15,40,-45,-25);
	}else if(cnt_time >1500){
		leftarm(-80,-50,50);
	}else if(cnt_time >1000){
		leftarm(0,-10,40);
		kosi(50);
		rightleg(20,40,-45,-20);
		leftleg(20,40,-45,-20);
	}else if(cnt_time>500){
		leftarm(90,40,50);
		kosi(40);
		rightarm(0,60,0);
		rightleg(20,40,-45,-20);
		leftleg(20,40,-45,-20);
	}else{
		leftarm(30,30,0);
		rightarm(0,60,0);
		kosi(0);
		rightleg(15,40,-45,-20);
		leftleg(15,40,-45,-20);
	}
}

void punch_R(void){
	rightarm_speed(127,60,60);
	leftarm_speed(127,60,60);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time >2800){
		rightarm(-80,360,0);
		leftarm(0,60,0);
		kosi(0);
		rightleg(15,40,-45,-25);
		leftleg(15,40,-45,-25);
	}else if(cnt_time >1500){
		rightarm(-80,-30,50);
	}else if(cnt_time >1000){
		rightarm(0,-10,40);
		kosi(-50);
	}else if(cnt_time>500){
		rightarm(90,30,50);
		kosi(-40);
		leftarm(0,60,0);
		rightleg(20,40,-45,-20);
		leftleg(20,40,-45,-20);
	}else{
		rightarm(30,30,0);
		leftarm(0,60,0);
		kosi(0);
		rightleg(15,40,-45,-20);
		leftleg(15,40,-45,-20);
	}	
}

void up_flont(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>3300){
		rightarm(0,50,0);
		leftarm(0,50,0);
		kosi(0);
		leftleg(5,90,0,-5);
		rightleg(5,0,-90,-3);
	}else if(cnt_time>2300){
		rightarm(-30,-70,95);
		leftarm(-30,-70,95);
		kosi(0);
		leftleg(5,90,0,-5);
		rightleg(5,0,-90,-3);
	}else if(cnt_time>1800){
		rightarm(90,-60,95);
		leftarm(85,-60,95);
		kosi(0);
		leftleg(5,90,0,-5);
		rightleg(5,0,-90,-3);
	}else if(cnt_time>800){
		rightarm(60,50,95);
		leftarm(60,50,95);
		kosi(0);
		leftleg(5,90,0,-10);
		rightleg(5,30,-50,-5);
		
	}else{
		rightarm(0,50,95);
		leftarm(0,50,95);
		kosi(0);
		leftleg(5,40,-35,-10);
		rightleg(5,40,-35,-5);
	}
}
//�K�[�h
void gurd_jaku(void){
	leftarm(10,40,-10);
	rightarm(10,40,-10);
	leftleg(30,10,-70,-45);
	rightleg(30,10,-70,-45);
	kosi(0);

}

void gurd(void){
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>3000){
		leftarm(10,40,-15);
		rightarm(10,40,-15);
		leftleg(35,-5,-77,-55);
		rightleg(35,-5,-77,-55);
		kosi(0);
	}else if(cnt_time>1800){
		leftarm(10,40,-15);
		rightarm(10,40,-15);
		leftleg(35,0,-77,-55);
		rightleg(35,0,-77,-55);
		kosi(0);
	}else if(cnt_time>1000){
		leftarm(10,40,-15);
		rightarm(10,40,-15);
		leftleg(35,10,-77,-50);
		rightleg(35,10,-77,-50);
		kosi(0);
	}else{
		leftarm(10,40,-50);
		rightarm(10,40,-50);
		leftleg(35,10,-70,-50);
		rightleg(35,10,-70,-50);
		kosi(0);
	}
}
//���ݍ���
void side_up_R(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,80,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	kosi(-40);
	if(cnt_time>2700){
		leftarm(-30,50,-10);
		rightarm(0,-80,10);
		leftleg(40,-50,-90,-45);
		rightleg(40,90,50,-45);	
	}else if(cnt_time>1700){
		leftarm(-20,50,-10);
		rightarm(0,40,10);
		leftleg(40,-50,-90,-45);
		rightleg(40,90,50,-45);
	}else if(cnt_time>1000){
		leftarm(-20,50,-10);
		rightarm(10,50,10);
		leftleg(10,-30,-50,3);
		rightleg(40,90,-0,-15);
	}else if(cnt_time>600){
		leftarm(-20,50,-10);
		rightarm(10,50,10);
		leftleg(10,-30,-50,3);
		rightleg(8,90,-0,-15);
	}else if(cnt_time>200){
		leftarm(30,0,0);
		rightarm(60,60,10);
		leftleg(10,40,-50,-5);
		rightleg(8,0,-0,-15);
	}else{
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,35,-50,-25);
		rightleg(15,35,-50,-25);
	}
}

void side_up_L(void){	
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,80,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>2700){
		rightarm(-30,50,-10);
		leftarm(0,-80,10);
		rightleg(40,-50,-90,-45);
		leftleg(40,90,50,-45);
		kosi(40);
	}else if(cnt_time>1700){
		rightarm(-30,50,-10);
		leftarm(0,40,10);
		rightleg(40,-50,-90,-45);
		leftleg(40,90,50,-45);
		kosi(40);
	}else if(cnt_time>1000){
		rightarm(-30,50,-10);
		leftarm(0,50,10);
		rightleg(10,-30,-50,5);
		leftleg(40,90,-0,-15);
		kosi(40);
	}else if(cnt_time>600){
		rightarm(-30,50,-10);
		leftarm(0,50,10);
		rightleg(10,-30,-50,5);
		leftleg(8,90,-0,-15);
		kosi(40);
	}else if(cnt_time>200){
		rightarm(30,0,0);
		leftarm(60,50,10);
		rightleg(10,40,-50,0);
		leftleg(8,0,-0,-15);
		kosi(40);
	}else{
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,35,-50,-25);
		rightleg(15,35,-50,-25);
		kosi(0);
	}
}


void humi_R(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>2000){
		leftarm(-30,60,-30);
		rightarm(-80,-60,30);
		leftleg(15,-40,-50,-15);
		rightleg(3,50,-40,0);
		kosi(-60);
	}else if(cnt_time>1400){
		leftarm(-80,60,-30);
		rightarm(120,-60,30);
		leftleg(15,-40,-40,-15);
		rightleg(3,50,-30,0);
		kosi(-60);
	}else if(cnt_time>1000){
		leftarm(-30,60,-50);
		rightarm(100,-30,50);
		leftleg(15,-30,-50,3);
		rightleg(3,90,-0,-15);
		kosi(-40);
	}else if(cnt_time>600){
		leftarm(-30,60,-50);
		rightarm(100,-30,50);
		leftleg(10,-30,-50,3);
		rightleg(8,90,-0,-15);
		kosi(-40);
	}else if(cnt_time>200){
		leftarm(-30,30,0);
		rightarm(100,-30,50);
		leftleg(10,40,-50,-5);
		rightleg(8,0,-0,-15);
		kosi(-40);
	}else{
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,35,-50,-25);
		rightleg(15,35,-50,-25);
		kosi(0);
	}
	
}
void humi_L(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>2000){
		rightarm(-30,60,-30);
		leftarm(-80,-60,30);
		rightleg(15,-40,-50,-15);
		leftleg(3,50,-40,0);
		kosi(60);
	}else if(cnt_time>1400){
		rightarm(-30,60,-30);
		leftarm(120,-60,30);
		rightleg(15,-40,-40,-15);
		leftleg(3,50,-40,0);
		kosi(60);
	}else if(cnt_time>1000){
		rightarm(-30,30,-50);
		leftarm(100,-30,50);
		rightleg(15,-30,-50,3);
		leftleg(3,90,-0,-15);
		kosi(40);
	}else if(cnt_time>600){
		rightarm(-30,30,-50);
		leftarm(100,-30,50);
		rightleg(10,-30,-50,5);
		leftleg(8,90,-0,-15);
		kosi(40);
	}else if(cnt_time>200){
		rightarm(-30,40,0);
		leftarm(100,00,50);
		rightleg(10,40,-50,0);
		leftleg(8,0,-0,-15);
		kosi(40);
	}else{
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,35,-50,-25);
		rightleg(15,35,-50,-25);
		kosi(0);
	}
}
void humi_low_R(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>2000){
		leftarm(-30,60,-30);
		rightarm(-80,0,30);
		leftleg(15,-40,-50,-15);
		rightleg(3,50,-40,-3);
		kosi(-60);
	}else if(cnt_time>1400){
		leftarm(-80,60,-30);
		rightarm(100,0,30);
		leftleg(15,-40,-40,-15);
		rightleg(3,50,-30,0);
		kosi(-60);
	}else if(cnt_time>1000){
		leftarm(-30,60,-50);
		rightarm(100,30,50);
		leftleg(15,-30,-50,3);
		rightleg(3,90,-0,-15);
		kosi(-40);
	}else if(cnt_time>600){
		leftarm(-30,60,-50);
		rightarm(100,30,50);
		leftleg(10,-30,-50,3);
		rightleg(8,90,-0,-15);
		kosi(-40);
	}else if(cnt_time>200){
		leftarm(-30,30,0);
		rightarm(100,30,50);
		leftleg(10,40,-50,-5);
		rightleg(8,0,-0,-15);
		kosi(-40);
	}else{
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,35,-50,-25);
		rightleg(15,35,-50,-25);
		kosi(0);
	}
}


void humi_low_L(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>2000){
		rightarm(-30,60,-30);
		leftarm(-80,0,30);
		rightleg(15,-40,-50,-15);
		leftleg(3,50,-40,0);
		kosi(60);
	}else if(cnt_time>1400){
		rightarm(-30,60,-30);
		leftarm(120,0,30);
		rightleg(15,-40,-40,-15);
		leftleg(3,50,-40,0);
		kosi(60);
	}else if(cnt_time>1000){
		rightarm(-30,30,-50);
		leftarm(100,30,50);
		rightleg(15,-30,-50,3);
		leftleg(3,90,-0,-15);
		kosi(40);
	}else if(cnt_time>600){
		rightarm(-30,30,-50);
		leftarm(100,30,50);
		rightleg(10,-30,-50,5);
		leftleg(8,90,-0,-15);
		kosi(40);
	}else if(cnt_time>200){
		rightarm(-30,40,0);
		leftarm(100,00,50);
		rightleg(10,40,-50,0);
		leftleg(8,0,-0,-15);
		kosi(40);
	}else{
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,35,-50,-25);
		rightleg(15,35,-50,-25);
		kosi(0);
	}
}

void zenten(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	kosi(0);
	if(cnt_time>5000){
		leftarm(360,360,360);
		rightarm(360,360,360);
		leftleg(10,0,0,0);
		rightleg(10,0,0,0);
	}else if(cnt_time>2300){
		leftleg(0,0,0,0);
		rightleg(0,0,0,0);
		leftarm(-30,-70,80);
		rightarm(-30,-70,80);
	}else if(cnt_time>1700){
		leftarm(0,-60,80);
		rightarm(0,-60,80);
		leftleg(0,90,-90,0);
		rightleg(0,90,-90,0);
	}else if(cnt_time>1300){
		leftarm(70,60,80);
		rightarm(70,60,80);
		leftleg(0,90,-90,0);
		rightleg(0,90,-90,0);
	}else{
		leftarm(70,60,80);
		rightarm(70,60,80);
		leftleg(0,-35,-90,-15);  
		rightleg(0,-35,-90,-15);
		kosi(0);
	}
}

void minakawa_L(void){	
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(30,60,60);
	rightarm_strech(30,60,60);
	leftleg_strech(30,60,60,60);
	rightleg_strech(30,60,60,60);
	kosi_strech(60);
	if(cnt_time>3000){
		leftarm(20,40,0);
		rightarm(20,40,0);
		leftleg(100,0,0,0);
		rightleg(90,0,0,-5);
		kosi(90);
	}else if(cnt_time>2200){
		leftarm(0,40,0);
		rightarm(0,40,0);
		leftleg(30,90,-90,0);
		rightleg(90,0,0,5);
		kosi(90);
	}else if(cnt_time>1700){
		leftarm(0,40,90);
		rightarm(0,40,90);
		leftleg(30,90,-90,0);
		rightleg(5,10,-10,5);
		kosi(90);
	}else if(cnt_time>1200){
		leftarm(0,40,90);
		rightarm(0,40,90);
		leftleg(5,90,-90,-30);
		rightleg(5,10,-10,10);
		kosi(90);
	}else if(cnt_time>200){
		leftarm(0,60,90);
		rightarm(0,60,90);
		leftleg(15,0,-0,-30);
		rightleg(0,40,-40,10);
		kosi(90);
	}else{
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,35,-50,-15);
		rightleg(15,35,-50,-15);
		kosi(0);

	}
}
void minakawa_R(void){
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftarm_strech(30,60,60);
	rightarm_strech(30,60,60);
	leftleg_strech(30,60,60,60);
	rightleg_strech(30,60,60,60);
	kosi_strech(60);;	
	if(cnt_time>2900){
		leftarm(25,40,0);
		rightarm(25,40,0);
		rightleg(100,0,0,0);
		leftleg(90,0,0,10);
		kosi(-90);
	}else if(cnt_time>2000){
		leftarm(0,40,0);
		rightarm(0,40,0);
		rightleg(50,90,-90,0);
		leftleg(70,0,0,0);
		kosi(-90);
	}else if(cnt_time>1700){
		leftarm(0,40,90);
		rightarm(0,40,90);
		rightleg(30,90,-90,0);
		leftleg(5,10,-10,5);
		kosi(-90);
	}else if(cnt_time>1200){
		leftarm(0,40,90);
		rightarm(0,40,90);
		rightleg(5,90,-90,-30);
		leftleg(5,10,-10,5);
		kosi(-90);
	}else if(cnt_time>700){
		leftarm(0,60,90);
		rightarm(0,60,90);
		rightleg(15,0,-0,-30);
		leftleg(0,40,-40,5);
		kosi(-90);
	}else if(cnt_time>200){
		leftarm(0,60,90);
		rightarm(0,60,90);
		kosi(-90);
	}else{
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,35,-50,-15);
		rightleg(15,35,-50,-15);
		kosi(0);

	}
}
void yosen50msoufront(void){
	leftarm_strech(0,60,60);
	rightarm_strech(0,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftarm(-40,60,10);
	rightarm(-40,60,10);
	if(cnt_time>800){
		cnt_time=0;
	}else if(cnt_time>400){
		rightleg(5,50,-30,-15);
		leftleg(5,0,-50,-7);
		kosi(-10);
	}else{
		rightleg(15,0,-50,-7);
		leftleg(15,52,-32,-15);
		kosi(0);
	}
}

void backdorop(void){
	rightarm_strech(60,80, 60);
	leftarm_strech(60,80, 60);
	rightleg_strech(60,60,60,60);
	leftleg_strech(60,60,60,60);
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftleg_speed(127,127,127,127);
	rightleg_speed(127,127,127,127);
	kosi_speed(127);
	kosi(0);
	
	if(cnt_time>6200){
		leftarm(-60,-90,0);
		rightarm(-60,-90,0);
		leftleg(5,0,-90,-5);
		rightleg(5,0,-90,-5);
	}else if(cnt_time>5800){
		leftarm(-60,-70,-70);
		rightarm(-60,-70,-70);
		leftleg(5,90,40,-5);
		rightleg(5,90,40,-5);
	}else if(cnt_time>5600){
		leftarm(-60,-70,70);
		rightarm(-60,-70,70);
		leftleg(15,90,40,-15);
		rightleg(15,90,40,-15);
	}else if(cnt_time>5000){
		leftarm(-90,60,90);
		rightarm(-90,60,90);
		leftleg(15,90,40,-15);
		rightleg(15,90,40,-15);
	}else if(cnt_time>3000){
		leftarm(-90,60,90);
		rightarm(-90,60,90);
		leftleg(5,40,40,-5);
		rightleg(5,40,40,-5);
	}else if(cnt_time>2000){
		leftarm(-90,30,90);
		rightarm(-90,30,90);
		leftleg(5,90,-40,-5);
		rightleg(5,90,-40,-5);
	}else if(cnt_time>1000){
		leftarm(0,0,90);
		rightarm(0,0,90);
		leftleg(5,80,-80,-25);
		rightleg(5,80,-80,-25);
	}else if(cnt_time>500){
		leftarm(0,0,0);
		rightarm(0,0,0);
		leftleg(15,80,-80,-25);
		rightleg(15,80,-80,-25);		
	}else{
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,40,-40,-25);
		rightleg(15,40,-40,-25);
			
	}
}

void sidedorop_R(void){
	rightarm_strech(60,80, 30);
	leftarm_strech(60,80, 30);
	rightleg_strech(60,60,60,60);
	leftleg_strech(60,60,60,60);
	rightarm_speed(127,127,127);
	leftarm_speed(127,127,127);
	leftleg_speed(127,127,127,127);
	rightleg_speed(127,127,127,127);
	kosi_speed(127);
	if(cnt_time>10000){
		leftarm(0,0,0);
		rightarm(0,0,0);
		leftleg(5,40,-40,-5);
		rightleg(5,40,-40,-5);
		kosi(90);
	}else if(cnt_time>6000){
		leftarm(0,0,90);
		rightarm(0,0,0);
		leftleg(5,40,-40,-5);
		rightleg(5,40,-40,-5);
		kosi(90);
	}else if(cnt_time>3000){
		leftarm(-90,60,90);
		rightarm(-90,60,90);
		leftleg(5,40,40,-5);
		rightleg(5,40,40,-5);
		kosi(0);
	}else if(cnt_time>2000){
		leftarm(-90,30,90);
		rightarm(-90,30,90);
		leftleg(5,90,-40,-5);
		rightleg(5,90,-40,-5);
		kosi(0);
	}else if(cnt_time>1000){
		leftarm(0,0,90);
		rightarm(0,0,90);
		leftleg(5,80,-80,-25);
		rightleg(5,80,-80,-25);
		kosi(0);
	}else{
		leftarm(0,0,0);
		rightarm(0,0,0);
		leftleg(15,80,-80,-25);
		rightleg(15,80,-80,-25);
		kosi(0);	
	}
}