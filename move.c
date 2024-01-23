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
		ude*=-1;
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
		servo_free(5);
		//servo_free_2(5,10);
	}
	
}


void rightleg_strech(int mata,int momo,int hiza,int kubi){
	set_strech_num(13,mata);
	set_strech_num(12,momo);
	set_strech_num(11,hiza);
	set_strech_num(10,kubi);
	
}

void leftleg(int mata,int momo,int hiza,int kubi){
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
void leftleg_strech(int mata,int momo,int hiza,int kubi){
	set_strech_num(9,mata);
	set_strech_num(8,momo);
	set_strech_num(7,hiza);
	set_strech_num(6,kubi);	
}

void kosi(int kosi){
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
	leftarm(360,360,0);
	rightarm(360,360,0);
	leftleg(15,35,-50,-25);
	rightleg(15,35,-50,-25);
	kosi(0);
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
}

void side_L(void){
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
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
	}
}

void side_R(void){
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
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
	}
}
void side_wolk_R(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>5500){
		cnt_time=0;
	}else if(cnt_time>4500){
		//左を挙げる
		rightarm(10,40,0);
		leftarm(10,60,0);
		kosi(0);
		rightleg(15,35,-50,-15);
		leftleg(5,35,-50,-5);
	}else if(cnt_time>3500){
		//左を挙げる
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		rightleg(10,80,-80,0);
		leftleg(-15,10,-40,10);
	}else if(cnt_time>2500){
		//右足に重心を
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		rightleg(10,30,-40,-10);
		leftleg(-10,35,-50,10);
	}else if(cnt_time>1500){
		//足をそろえる
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		rightleg(0,35,-50,0);
		leftleg(0,35,-50,0);
	}else if(cnt_time>500){
		//左足に重心を
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		rightleg(-10,10,-45,10);
		leftleg(10,80,-80,0);
	}else{
		//左足に重心を
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		rightleg(0,35,-50,-15);
		leftleg(15,10,-10,-15);
	}
}
void side_wolk_L(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>5500){
		cnt_time=0;
	}else if(cnt_time>4500){
		//左を挙げる
		leftarm(10,40,0);
		rightarm(10,60,0);
		kosi(0);
		leftleg(15,35,-50,-15);
		rightleg(5,35,-50,-5);
	}else if(cnt_time>3500){
		//左を挙げる
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		leftleg(10,80,-80,0);
		rightleg(-15,10,-40,10);
	}else if(cnt_time>2500){
		//右足に重心を
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		leftleg(10,30,-40,-10);
		rightleg(-10,35,-50,10);
	}else if(cnt_time>1500){
		//足をそろえる
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		leftleg(0,35,-50,0);
		rightleg(0,35,-50,0);
	}else if(cnt_time>500){
		//左足に重心を
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		leftleg(-10,10,-45,10);
		rightleg(10,80,-80,0);
	}else{
		//左足に重心を
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
		leftleg(0,35,-50,-15);
		rightleg(15,10,-10,-15);
	}
}

void AL_side_L(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
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
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		leftleg(15,0,-20,-20);
		rightleg(5,0,-20,-10);
		kosi(-20);
	}else{
		leftleg(15,60,-40,-20);
		rightleg(13,40,-60,-10);
		leftarm(10,60,30);
		rightarm(10,60,30);
		kosi(0);
	}
}

void roll_L(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		rightleg(15,0,-20,-20);
		leftleg(5,0,-20,-10);
		kosi(20);
	}else{
		rightleg(15,60,-40,-20);
		leftleg(13,40,-60,-10);
		leftarm(10,60,30);
		rightarm(10,60,30);
		kosi(0);
	}
/*leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		//leftarm(10,60,40);
		//rightarm(10,60,0);
		rightleg(15,0,-20,-20);
		leftleg(5,0,-20,-10);
		kosi(20);
	}else{
		leftarm(0,60,20);
		rightarm(0,60,20);
		rightleg(15,60,-40,-20);
		leftleg(13,40,-60,-10);
		kosi(0);
	}*/
}

void suri_front(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftarm(0,60,40);
	rightarm(0,60,40);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		rightleg(5,40,-40,-7);
		leftleg(5,-10,-40,-15);
		kosi(5);
	}else{
		rightleg(5,-10,-40,-15);
		leftleg(5,42,-42,-7);
		kosi(-5);
	}
}

void suri_back(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftarm(10,60,20);
	rightarm(10,60,20);
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

	/*leftarm(10,60,0);
	rightarm(10,60,0);
	if(cnt_time>1000){
		cnt_time=0;
	}else if(cnt_time>500){
		rightleg(15,0,-40,-25);
		leftleg(15,40,0,-15);
		kosi(-5);
	}else{
		rightleg(15,40,0,-15);
		leftleg(15,0,-40,-25);
		kosi(5);
	}*/
}

void syagami(void){
	static int i=0;
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	kosi(0);
	if(cnt_time>2000){
		i=1;
	}else if(cnt_time>800){
		leftleg(40,90,-90,-40);
		rightleg(40,90,-90,-40);
		leftarm(-90,30,0);
		rightarm(-90,30,0);
	}else{
		leftleg(40,40,-90,-40);
		rightleg(40,40,-90,-40);
		leftarm(-90,30,0);
		rightarm(-90,30,0);
	}
	if(i==1){
		leftleg(40,360,360,-45);
		rightleg(40,360,360,-45);
		leftarm(-90,360,0);
		rightarm(-90,360,0);
	}
	if(CONTLLOR()!=C_PEC){
			i=0;
	}
}

void stand_flont(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	kosi(0);
	if(cnt_time>1600){
		leftleg(15,80,-80,-15);
		rightleg(15,80,-80,-15);
		rightarm(-30,70,-80);
		leftarm(-20,60,80);
		while(CONTLLOR()==C_PEC||CONTLLOR()==C_PEC&C_UP){
			rightarm(0,70,-80);
			leftarm(-40,60,80);
		}
	}else if(cnt_time>1000){
		leftleg(15,80,-80,-15);
		rightleg(15,80,-80,-15);
		leftarm(-30,60,80);
		rightarm(-30,60,80);	
	}else if(cnt_time>500){
		leftleg(15,80,-80,-15);
		rightleg(15,80,-80,-15);
		leftarm(-160,60,80);
		rightarm(-160,60,80);
	}else{
		leftleg(15,80,-80,-15);
		rightleg(15,80,-80,-15);
		leftarm(-160,60,0);
		rightarm(-160,60,0);
	}
}

void stand_side_L(void){
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
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	kosi(0);
	if(cnt_time>1800){
		leftleg(15,80,-80,-15);
		rightleg(15,80,-80,-15);
		leftarm(-30,70,-80);
		rightarm(-30,60,80);
		while(CONTLLOR()==C_PEC||CONTLLOR()==C_PEC&C_DOWN){
			leftarm(0,70,-80);
			rightarm(-30,60,80);
		}
	}else if(cnt_time>800){
		leftleg(15,80,-80,-15);
		rightleg(15,80,-80,-15);
		leftarm(-30,60,-80);
		rightarm(-30,60,-80);	
	}else if(cnt_time>500){
		leftleg(15,80,-80,-15);
		rightleg(15,80,-80,-15);
		leftarm(-30,60,-80);
		rightarm(-30,60,-80);
	}else{
		leftleg(15,80,-80,-15);
		rightleg(15,80,-80,-15);
		leftarm(-160,60,0);
		rightarm(-160,60,0);
	}
}

void fuck_R(void){
	leftarm_strech(127,127,127);
	rightarm_strech(127,127,127);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftleg(15,40,-45,-10);
	rightleg(15,40,-45,-10);
	if(cnt_time>2500){
		rightarm(360,360,90);
	}else if(cnt_time>1500){
		kosi(-90);
		rightarm(30,-10,90);
	}else if(cnt_time>1000){
		leftarm(10,60,0);
		rightarm(10,-10,0);
	}else if(cnt_time>500){
		leftarm(10,60,0);
		rightarm(-90,60,0);
	}else{
		leftarm(10,60,0);
		rightarm(10,60,0);
		kosi(0);
	}
}

void fuck_L(void){
	leftarm_strech(127,127,127);
	rightarm_strech(127,127,127);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftleg(15,40,-45,-10);
	rightleg(15,40,-45,-10);
	if(cnt_time>2500){
		leftarm(360,360,90);
	}else if(cnt_time>1500){
		kosi(90);
		leftarm(30,-10,90);
	}else if(cnt_time>1000){
		rightarm(10,60,0);
		leftarm(10,-10,0);
	}else if(cnt_time>500){
		rightarm(10,60,0);
		leftarm(-90,60,0);
	}else{
		rightarm(10,60,0);
		leftarm(10,60,0);
		kosi(0);
	}	
}

void up_R(void){
	leftarm_strech(127,127,60);
	rightarm_strech(127,127,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftleg(20,30,-55,-35);
	rightleg(20,30,-55,-35);
	if(cnt_time>2800){
		rightarm(-80,360,0);
		kosi(0);
	}else if(cnt_time>2000){
		rightarm(-30,-60,90);
		kosi(-20);
	}else if(cnt_time>1500){
		rightarm(0,-60,90);
	}else if(cnt_time>1300){
		rightarm(100,-10,90);
	}else if(cnt_time >800){
		leftarm(10,60,0);
		rightarm(80,-10,90);
	}else if(cnt_time>500){
		rightarm(10,60,90);
		kosi(-20);
		leftarm(80,30,0);
	}else{
		rightarm(80,30,0);
		leftarm(10,60,0);
		kosi(0);
	}
}

void humi_R(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>1400){
		leftarm(-30,60,-70);
		rightarm(-80,-80,70);
		leftleg(5,-20,-90,-3);
		rightleg(5,90,0,-10);
		kosi(-20);
	}else if(cnt_time>900){
		leftarm(-30,30,0);
		rightarm(100,-60,70);
		leftleg(5,0,-60,-3);
		rightleg(5,70,-40,-30);
		kosi(-20);
	}else{
		leftarm(-30,30,0);
		rightarm(70,00,70);
		leftleg(5,40,-60,0);
		rightleg(5,0,0,0);
		kosi(-20);
	}
}
void humi_L(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>1500){
		rightarm(-30,60,-70);
		leftarm(-80,-80,70);
		rightleg(5,-20,-90,-3);
		leftleg(5,90,0,-10);
		kosi(20);
	}else if(cnt_time>1000){
		rightarm(-30,30,0);
		leftarm(100,-60,70);
		rightleg(5,0,-60,-3);
		leftleg(5,70,-40,-30);
		kosi(20);
	}else{
		rightarm(-30,40,0);
		leftarm(100,00,70);
		rightleg(5,40,-50,11);
		leftleg(5,0,0,-5);
		kosi(20);
	}
}

void up_L(void){
		leftarm_strech(127,127,60);
	rightarm_strech(127,127,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftleg(20,30,-55,-35);
	rightleg(20,30,-55,-35);
	if(cnt_time>2800){
		leftarm(-80,360,0);
		kosi(0);
	}else if(cnt_time>2000){
		leftarm(-30,-60,90);
		kosi(20);
	}else if(cnt_time>1500){
		leftarm(0,-60,90);
	}else if(cnt_time>1300){
		leftarm(100,-10,90);
	}else if(cnt_time >800){
		rightarm(10,60,0);
		leftarm(80,-10,90);
	}else if(cnt_time>500){
		leftarm(10,60,90);
		kosi(20);
		rightarm(80,30,0);
	}else{
		leftarm(80,30,0);
		rightarm(10,60,0);
		kosi(0);
	}
	/*
	leftarm_strech(127,127,60);
	rightarm_strech(127,127,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftleg(20,20,-65,-35);
	rightleg(20,20,-65,-35);
	
	if(cnt_time>2500){
		kosi(0);
		leftarm(-80,360,0);
	}else if(cnt_time>1500){
		leftarm(-30,-60,90);
		kosi(20);
	}else if(cnt_time>1200){
		leftarm(360,0,90);
	}else if(cnt_time >700){
		rightarm(10,60,0);
		leftarm(70,-10,90);
	}else if(cnt_time>500){
		leftarm(10,60,90);
		kosi(0);
		rightarm(10,60,0);
	}else{
		rightarm(10,60,0);
		leftarm(10,60,0);
		kosi(0);
	}*/
}

void up_flont(void){
	leftarm_strech(127,127,60);
	rightarm_strech(127,127,60);
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
		leftarm(70,50,95);
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

void gurd_jaku(void){
	leftarm(10,40,0);
	rightarm(10,40,0);
	leftleg(30,30,-50,-45);
	rightleg(30,30,-50,-45);
	kosi(0);

}
void gurd(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
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

void zenten(void){
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
	}else if(cnt_time>3200){
		leftleg(0,0,0,0);
		rightleg(0,0,0,0);
	}else if(cnt_time>1800){
		leftarm(-15,-30,80);
		rightarm(-15,-30,80);
		leftleg(0,90,-90,0);
		rightleg(0,90,-90,0);
	}else{
		leftarm(70,60,90);
		rightarm(70,60,90);
		leftleg(0,-35,-90,-15);
		rightleg(0,-35,-90,-15);
		kosi(0);
	}
}

void minakawa_L(void){
	if(cnt_time>3000){
		leftarm(0,20,-90);
		rightarm(0,20,90);
		leftleg(100,0,0,0);
		rightleg(100,0,0,0);
		kosi(0);
	}else if(cnt_time>2500){
		leftarm(0,-20,-90);
		rightarm(0,-20,90);
		leftleg(100,0,0,0);
		rightleg(100,0,0,0);
		kosi(0);
	}else if(cnt_time>2000){
		leftarm(0,-10,0);
		rightarm(0,-10,0);
		leftleg(100,0,0,0);
		rightleg(80,0,0,0);
		kosi(0);
	}else if(cnt_time>1500){
		leftarm(-50,0,0);
		rightarm(0,0,0);
		leftleg(50,30,-80,0);
		rightleg(30,0,0,0);
		kosi(0);
	}else if(cnt_time>1000){
		leftarm(-50,0,0);
		rightarm(0,60,0);
		leftleg(50,80,-80,0);
		rightleg(-15,0,0,15);
		kosi(0);
	}else if(cnt_time>500){
		leftarm(-50,60,0);
		rightarm(0,60,0);
		leftleg(15,80,-80,-70);
		rightleg(-15,0,0,15);
		kosi(0);
	}else{		
		leftarm(-50,60,0);
		rightarm(0,60,90);
		leftleg(15,35,-35,-10);
		rightleg(0,80,-70,-30);
		kosi(0);
	}
	/*leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	kosi(0);
	if(cnt_time>2500){
		leftarm(0,40,-90);
		rightarm(0,40,90);
		leftleg(100,0,0,0);
		rightleg(100,0,0,-10);
	}else if(cnt_time>2000){
		leftarm(0,0,-90);
		rightarm(0,0,90);
		leftleg(50,80,-80,0);
		rightleg(20,40,-40,0);
	}else if(cnt_time>1000){
		leftarm(0,0,-90);
		rightarm(0,0,0);
		leftleg(10,30,-30,-80);
		rightleg(5,40,-40,0);
	}else if(cnt_time>500){
		leftarm(10,60,0);
		rightarm(0,0,0);
		leftleg(15,35,-35,-70);
		rightleg(5,80,-80,5);
	}else{
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(15,35,-35,-10);
		rightleg(5,70,-70,-30);
		kosi(0);
	}*/
}
void minakawa_R(void){
	if(cnt_time>3000){
		rightarm(0,20,-90);
		leftarm(0,20,90);
		rightleg(100,0,0,0);
		leftleg(100,0,0,0);
		kosi(0);
	}else if(cnt_time>2500){
		rightarm(0,-20,-90);
		leftarm(0,-20,90);
		rightleg(100,0,0,0);
		leftleg(100,0,0,0);
		kosi(0);
	}else if(cnt_time>2000){
		rightarm(0,-10,0);
		leftarm(0,-10,0);
		rightleg(80,0,0,0);
		leftleg(30,0,0,0);
		kosi(0);
	}else if(cnt_time>1500){
		rightarm(-50,0,0);
		leftarm(0,0,0);
		rightleg(50,30,-80,0);
		leftleg(10,0,0,0);
		kosi(0);
	}else if(cnt_time>1000){
		rightarm(-50,0,0);
		leftarm(0,60,0);
		rightleg(50,80,-80,0);
		leftleg(-15,0,0,15);
		kosi(0);
	}else if(cnt_time>500){
		rightarm(-50,60,0);
		leftarm(0,60,0);
		rightleg(15,80,-80,-70);
		leftleg(-15,0,0,15);
		kosi(0);
	}else{		
		rightarm(-50,60,0);
		leftarm(0,60,90);
		rightleg(15,35,-35,-10);
		leftleg(0,80,-70,-30);
		kosi(0);
	}
	/*
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	kosi(0);
	if(cnt_time>3000){
		leftarm(0,40,-90);
		rightarm(0,40,90);
		rightleg(100,0,0,0);
		leftleg(100,0,0,20);
	}else if(cnt_time>2000){
		leftarm(0,0,-90);
		rightarm(0,0,90);
		rightleg(100,80,-80,0);
		leftleg(20,40,-40,0);
	}else if(cnt_time>1000){
		rightarm(0,0,90);
		leftarm(0,0,0);
		rightleg(10,30,-30,-70);
		leftleg(5,40,-40,-10);
	}else if(cnt_time>500){
		rightarm(10,60,0);
		leftarm(0,0,0);
		rightleg(15,35,-35,-10);
		leftleg(5,70,-70,-10);
	}else{
		rightarm(10,60,0);
		leftarm(0,0,0);
		rightleg(15,35,-35,-10);
		leftleg(5,70,-70,-30);
		kosi(0);
	}*/
}

void roll_side_L(void){
	leftarm(0,60,30);
	rightarm(0,60,30);
	if(cnt_time>600){
		cnt_time=0;	
	}else if(cnt_time>300){
		kosi(20);
		rightleg(5,10,-10,-5);
		leftleg(5,10,-10,-10);
	}else{
		kosi(0);
		rightleg(15,35,-50,0);
		leftleg(15,50,-35,-25);
	}
	/*if(cnt_time>700){
		cnt_time=0;
	}else if(cnt_time>600){
		kosi(0);
		leftleg(20,10,-10,-10);
		rightleg(15,10,-10,-25);
	}else if(cnt_time>500){
		kosi(20);
		leftleg(5,10,-10,-10);
		rightleg(25,10,-10,-25);
	}else{	
		kosi(0);
		leftleg(5,50,-35,-25);
		rightleg(5,35,-50,-10);
	}*/
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
	leftarm(0,60,30);
	rightarm(0,60,30);
	if(cnt_time>600){
		cnt_time=0;	
	}else if(cnt_time>300){
		kosi(-10);
		leftleg(15,10,-10,0);
		rightleg(5,20,-20,-10);
	}else{
		kosi(0);
		leftleg(5,35,-50,-20);
		rightleg(15,35,-40,-15);
	}

/*side_R();
	if(cnt_time>600){
		//cnt_time=0;
	}else if(cnt_time>300){
		kosi(-20);
	}else{
		kosi(0);
	}*/
}

void front_work(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	leftarm(0,60,30);
	rightarm(0,60,30);
	if(cnt_time>8000){
		cnt_time=2500;
	}else if(cnt_time>7000){
		//左を前に	
		leftleg(5,70,-10,-5);
		rightleg(5,-10,-70,0);
	}else if(cnt_time>6000){
		//左を挙げる
		leftleg(10,80,-80,-10);
		rightleg(-10,00,-30,10);
	}else if(cnt_time>6000){
		//右に重心を
		leftleg(5,-10,-70,-5);
		rightleg(-5,40,-40,5);
	}else if(cnt_time>5000){
		//右を前に
		leftleg(5,-10,-70,0);
		rightleg(5,80,0,-5);
	}else if(cnt_time>4500){
		//右を挙げる
		leftleg(-10,00,-20,10);
		rightleg(10,80,-80,0);
	}else if(cnt_time>3500){
		//左に重心を
		leftleg(-10,30,-50,10);
		rightleg(10,0,-80,-10);
	}else if(cnt_time>3000){
		//左に重心を
		leftleg(-5,80,0,5);
		rightleg(5,0,-80,-5);
	}else if(cnt_time>2500){
		//左を前に
		leftleg(5,80,0,0);
		rightleg(5,0,-80,-5);
	}else if(cnt_time>2000){
		//左を挙げる
		leftleg(5,70,-70,-20);
		rightleg(-5,40,-40,5);
	}else if(cnt_time>1000){
		//右に重心を載せる
		leftleg(10,40,-40,-10);
		rightleg(-10,40,-40,10);
	}else{
		//足をそろえる
		leftleg(0,40,-40,-5);
		rightleg(0,40,-40,-5);
	}

}

void back_wolk(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi(0);
	leftarm(0,60,0);
	rightarm(0,60,0);
	if(cnt_time>10000){
		cnt_time=3000;
	}else if(cnt_time>9000){
		//左を後ろに	
		leftleg(5,-10,-70,-5);
		rightleg(5,80,0,0);
	}else if(cnt_time>8000){
		//左をあげて
		leftleg(15,80,-80,-15);
		rightleg(-15,20,-20,15);
	}else if(cnt_time>7000){
		//右に重心を
		leftleg(15,40,-40,-15);
		rightleg(-15,45,-45,15);
	}else if(cnt_time>6000){
		//右を後ろに
		leftleg(5,70,-10,0);
		rightleg(5,-10,-70,-5);
	}else if(cnt_time>5000){
		//右を持ち上げ
		leftleg(-5,20,-20,5);
		rightleg(5,80,-80,-5);
	}else if(cnt_time>4000){
		//左に重心を
		leftleg(-15,45,-45,15);
		rightleg(15,80,0,-15);
	}else if(cnt_time>3000){
		//左を後ろに
		leftleg(5,-10,-70,-5);
		rightleg(5,80,0,0);
	}else if(cnt_time>2000){
		//左を挙げる
		leftleg(10,70,-70,-20);
		rightleg(-15,20,-20,15);
	}else if(cnt_time>1000){
		//右に重心を載せる
		leftleg(5,40,-40,-5);
		rightleg(-5,45,-45,5);
	}else{
		//足をそろえる
		leftleg(0,40,-40,-5);
		rightleg(0,40,-40,-5);
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

void side_up_R(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>3100){
		leftleg(30,-10,-10,-20);
		rightleg(0,60,-30,0);
		leftarm(-30,-60,95);
		rightarm(-30,-60,95);
		kosi(30);
	}else if(cnt_time>2300){
		leftleg(30,-10,-10,-20);
		rightleg(0,60,-30,0);
		leftarm(60,-60,95);
		rightarm(60,-60,95);
		kosi(30);
	}else if(cnt_time>1800){
		leftleg(30,-10,-10,-20);
		rightleg(0,60,-30,5);
		leftarm(0,60,95);
		rightarm(0,60,95);
		kosi(30);
	}else if(cnt_time>1000){
		leftarm(0,60,95);
		rightarm(0,60,95);
		leftleg(-15,10,-10,15);
		rightleg(0,80,-80,-30);
		kosi(30);
	}else if(cnt_time>500){
		leftarm(0,60,95);
		rightarm(0,60,95);
		leftleg(-15,50,-50,-20);
		rightleg(15,35,-50,-20);
		kosi(30);
	}else{
		leftarm(0,60,0);
		rightarm(0,60,0);
		leftleg(-15,35,-50,-20);
		rightleg(15,35,-50,-20);
		kosi(30);
	}
}

void side_up_L(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>2800){
		rightleg(30,-10,-10,-20);
		leftleg(10,60,-30,0);
		leftarm(-30,-60,95);
		rightarm(-30,-60,95);
		kosi(-30);
	}else if(cnt_time>2000){
		rightleg(30,-10,-10,-20);
		leftleg(10,60,-30,360);
		leftarm(60,-60,95);
		rightarm(60,-60,95);
		kosi(-30);
	}else if(cnt_time>1500){
		rightleg(30,-10,-10,-20);
		leftleg(10,60,-30,360);
		leftarm(0,60,95);
		rightarm(0,60,95);
		kosi(-30);
	}else if(cnt_time>1000){
		leftarm(0,60,95);
		rightarm(0,60,95);
		rightleg(-15,30,-30,20);
		leftleg(0,80,-80,-40);
		kosi(-30);
	}else{
		leftarm(0,55,95);
		rightarm(0,65,95);
		rightleg(-15,50,-50,-20);
		leftleg(15,35,-50,-20);
		kosi(-30);
	}
}

void side_track_R(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		leftleg(20,10,-10,0);
		rightleg(10,40,-50,-25);
		leftarm(10,60,0);
		rightarm(0,0,0);
	}else{
		leftleg(10,50,-50,-15);
		rightleg(15,30,-30,-25);
		
		kosi(0);
	}
}
void side_track_L(void){
	leftarm_strech(60,60,60);
	rightarm_strech(60,60,60);
	leftleg_strech(60,60,60,60);
	rightleg_strech(60,60,60,60);
	kosi_strech(60);
	if(cnt_time>600){
		cnt_time=0;
	}else if(cnt_time>300){
		rightleg(20,10,-10,0);
		leftleg(10,40,-50,-25);
		leftarm(10,0,0);
		rightarm(10,60,0);
	}else{
		rightleg(10,50,-50,-15);
		leftleg(15,30,-30,-25);
		
		kosi(0);
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

void punch_L(void){
	if(cnt_time>2800){	
		leftarm(360,360,0);
		rightarm(0,60,0);
		leftleg(15,35,-50,-20);
		rightleg(15,35,-50,-20);
		kosi(0);
	}else if(cnt_time>1500){	
		leftarm(-80,-80,0);
		rightarm(0,60,0);
		leftleg(5,90,20,-5);
		rightleg(5,-20,-90,-5);
		kosi(90);
	}else if(cnt_time>1000){
		leftarm(0,0,0);
		rightarm(0,60,0);
		leftleg(5,90,20,-5);
		rightleg(5,-20,-90,-5);
		kosi(90);
	}else if(cnt_time>500){
		leftarm(70,60,0);
		rightarm(0,60,0);
		leftleg(5,85,0,-10);
		rightleg(5,35,-50,-5);
		kosi(90);
	}else{
		leftarm(60,60,0);
		rightarm(0,60,0);
		leftleg(5,35,-50,-10);
		rightleg(5,35,-50,-10);
		kosi(90);
	}	
}

void punch_R(void){
	if(cnt_time>2800){
		rightarm(360,360,0);
		leftarm(0,60,0);
		leftleg(15,35,-50,-20);
		rightleg(15,35,-50,-20);
		kosi(0);
	}else  if(cnt_time>1500){
		rightarm(-80,-80,0);
		leftarm(0,60,0);
		leftleg(15,35,-50,-20);
		rightleg(15,35,-50,-20);
		kosi(-90);
	}else if(cnt_time>1000){
		rightarm(0,0,0);
		leftarm(0,60,0);
		leftleg(5,0,-85,-5);
		rightleg(5,85,0,-5);
		kosi(-90);
	}else if(cnt_time>500){
		rightarm(70,50,0);
		leftarm(0,60,0);
		leftleg(5,0,-85,-5);
		rightleg(5,85,0,-10);
		kosi(-90);
	}else{
		leftarm(60,0,0);
		rightarm(70,60,0);
		leftleg(5,35,-50,-10);
		rightleg(5,35,-50,-10);
		kosi(-90);
	}	
}

void osikomi_L(void){
	if(cnt_time>1500){
		leftarm(0,20,0);
		rightarm(0,60,0);
		leftleg(15,35,-50,-20);
		rightleg(15,35,-50,-20);
		kosi(90);
	}else{
		leftarm(110,-60,0);
		rightarm(0,60,0);
		leftleg(15,35,-50,-20);
		rightleg(15,35,-50,-20);
		kosi(90);
	}
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
	joint_L_Y=((joint_L() & 0x00ff)-0x7f)/5;
	leftarm(-30,60,-1*joint_L_Y/5);
	rightarm(-30,60,-1*joint_L_Y/5);
	kosi(0);
	if(cnt_time>2650){
		cnt_time=0;
	}else if(cnt_time>2200){
		//右を挙げる
		rightleg(5,90,-90,-5);
		leftleg(5-joint_L_X,30+joint_L_Y,-30+joint_L_Y,-joint_L_X);
	}else if(cnt_time>1750){
		//左重心
		rightleg(5,35,-35,-5);
		leftleg(5,45,-45,-5);
	}else if(cnt_time>1350){
		//揃える
		leftleg(5+joint_L_X,35,-35,joint_L_X);
		rightleg(5,35,-35,-10);
	}else if(cnt_time>900){
		//左を挙げる
		leftleg(5,90,-90,-5);
		rightleg(5+joint_L_X,30+joint_L_Y,-30+joint_L_Y,-joint_L_X);
	}else if(cnt_time>450){
		//右重心
		leftleg(5,35,-35,-5);
		rightleg(5,45,-45,0);
	}else{
		//揃える
		leftleg(5,35,-35,-10);
		rightleg(5,35,-35,0);
	}
}