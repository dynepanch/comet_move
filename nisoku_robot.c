#include"VS_C3.h"
#include"define.h"
extern int cnt_time;
extern int servo_angle_buff[20];
extern int servo_strech_buff[20];
extern int servo_speed_buff[20];
void start(void){
	ontip_timer();
	INIT_SCI5();
	INIT_SCI6();
	INIT_SCI1();
	INIT_SCI9();
	INIT_SCI12();
	RSPI();
	init_cmt0();
	init_cmt1();
	start_sci5();
	start_sci6();
	start_sci9();
	start_sci12();
	
	start_up();
	LEDOUT(0x03);
	spi_start();
}

void main(void)
{ 	
	static char mode=0;
	start();
	while(1){
		
		if(CONTLLOR()==C_START && mode==0){
			while(cnt_time<500){	
				mode=1;
				rightarm_speed(0,1,1);
				leftarm_speed(0,1,1);
				leftleg_speed(1,1,1,1);
				rightleg_speed(1,1,1,1);
				kosi_speed(1);
				leftarm_strech(0,0,0);
				rightarm_strech(0,0,0);
				leftleg_strech(0,0,0,0);
				rightleg_strech(0,0,0,0);
				kosi_strech(0);
				LEDOUT(0x00);
				rightarm(0,0,0);
				leftarm(0,0,0);
				rightleg(0,0,0,0);
				leftleg(0,0,0,0);
				kosi(0);
			}
		}else if(mode==0){
			cnt_time=0;
		}else if(mode==1){
			/*rightarm(360,360,360);
			leftarm(360,360,360);
			rightleg(360,360,360,360);
			leftleg(360,360,360,360);*/
			if(CONTLLOR()==C_P_LEF){
				LEDOUT(0x02);
				mode=2;
			}
			if(CONTLLOR()==C_P_RIG){
				LEDOUT(0x01);
				mode=2;
			}
		}else if(mode==2){
			CNTR_PUTS();
			mode=2;
		}
		
		
		PA_DATA();
		
	}
}