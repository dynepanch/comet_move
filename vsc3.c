#include"VS_C3.h"
#include"stdio.h"
#include"move.h"
#include"define.h"
#include"math.h"

extern int cnt_time;
extern int dualshock;

void CNTR_PUTS(void){
	static int joint_L_X,joint_L_Y,joint_R_X,joint_R_Y,i=0,pn=0,mode=0,led_mode=1,da=0,demo_mode=0;
	static float theata_L,theata_R,level_R,level_L;
	static int first=0,syaga=0,syagaowari=0,analog=0,fuck=0,back_mode=0,punch_mode=0;
	static char *send_data[100];
	static int wolk_mode=0,datu_mode=0,bace_mode=0,ent_mode=0,mina_R=0,mina_L=0,wk=0,AL_mode=0,wolk=0,gd=0;
	PA_DATA();
	joint_L_X=(joint_L() & 0xff00)/0x100;
	joint_L_Y=(joint_L() & 0x00ff);
	joint_R_X=(joint_R() & 0xff00)/0x100;
	joint_R_Y=(joint_R() & 0x00ff);
		switch(CONTLLOR()*mode){
			
			case 0:
				datu();
				if(CONTLLOR()==C_P_LEF){
					led_mode=2;
				}
				if(CONTLLOR()==C_P_RIG){
					led_mode=1;
				}
				
				if(CONTLLOR()==C_L2){
					while(CONTLLOR()!=C_START){
						zero_all();
					}
				}
				if(CONTLLOR()==C_START){
					mode=1;
					bace();
					break;
				}
				if(CONTLLOR()==C_R2){	
					//wk=1;
				}
				if(wk==1 && CONTLLOR()!=C_R2){
					if(wolk_mode==1){
						wolk_mode=0;
					}else{
						wolk_mode=1;
					}
					wk=0;
				}
				LEDOUT(led_mode);
				
			break;
			
			//��
			case C_LEFT:
				
				if(wolk_mode==1){
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					if(AL_mode==0){
					
						while(CONTLLOR()==C_LEFT){
							side_wolk_L();
						}
					}else{
						while(CONTLLOR()==C_LEFT){
							AL_side_L();
						}
					}
				}else if(wolk_mode==2){
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					yosen50msouside_L();
				}else{
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					while(CONTLLOR()==C_LEFT){
						side_L();
					}
				}
			break;
			
			//��
			case C_RIGHT:
				if(wolk_mode==1){
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					while(CONTLLOR()==C_RIGHT){
						side_wolk_R();
					}

				}else if(wolk_mode==2){
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					yosen50msouside_R();					
				}else{
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					while(CONTLLOR()==C_RIGHT){
						side_R();
					}
				}
			break;

			//��
			case C_UP:
				if(wolk_mode==1){
					if(first==0){	
						cnt_time=0;
						first=1;
						//�������낦��
						leftleg(0,40,40,-5);
						rightleg(0,40,-40,-5);
					}
					while(CONTLLOR()==C_UP){
						front_work();
					}
				}if(wolk_mode==2){
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					yosen50msoufront(cnt_time);
				}else{
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					while(CONTLLOR()==C_UP){
						suri_front();
						if(wolk==0){
							wolk=1;
						}
					}
				} 

			break;
			
			//��
			case C_DOWN:
				if(wolk_mode==1){
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					while(CONTLLOR()==C_DOWN){
						back_wolk();
					}
				}else{
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					while(CONTLLOR()==C_DOWN){
						suri_back();
						back_mode=1;
					}
				}
			break;
			
			case C_DOWN & C_CR:
				if(first==0){	
					cnt_time=0;
					first=1;
				}	
				up_up_R();
			break;
			case C_DOWN & C_SQ:
				if(first==0){	
					cnt_time=0;
					first=1;
				}	
				up_up_L();
			break;
			
			//��
			case C_SQ:
				if(first==0){
					cnt_time=0;
					first=1;
				}
				if(first!=2){
					up_L();
				}
			break;
			
			case C_SQ & C_RIGHT:
				if(first==0){
					cnt_time=0;
					first=1;
				}
				if(first!=2){
					side_up_R();
				}
			break;
			
			case C_SQ & C_LEFT:
				if(first==0){
					cnt_time=0;
					first=1;
				}
				if(first!=2){
					side_up_L();
				}
			break;
			
			//�~
			case C_PEC:
				syaga=0;
				if(first==0){
					cnt_time=0;
					first=1;
				}
				while(CONTLLOR()==C_PEC && demo_mode==0){
					syagami();
				}
				if(demo_mode==1){
					leftarm(-90,60,0);
					rightarm(-90,60,0);
				}
				if(cnt_time>300){
					syagaowari=1;
				}
					
			break;
			//�~
			case C_PEC & C_R1:
				syaga=0;
				if(first==0){
					cnt_time=0;
					first=1;
				}
				while(CONTLLOR()==(C_PEC& C_R1) && demo_mode==0){
					syagami_roll_R();
				}
			break;
			
			//�~
			case C_PEC & C_L1:
				syaga=0;
				if(first==0){
					cnt_time=0;
					first=1;
				}
				while(CONTLLOR()==(C_PEC & C_L1) && demo_mode==0){
					syagami_roll_L();
				}
			break;
			
			case C_PEC & C_UP:
				LEDOUT(0x03);
				if(first==0||syaga==0){
					cnt_time=0;
					first=1;
					syaga=1;
					wolk=0;
				}
				stand_flont();
			break;
			case C_PEC & C_DOWN:
				LEDOUT(0x03);
				if(first==0||syaga==0){
					cnt_time=0;
					first=1;
					syaga=1;
				}
				stand_back();
				mode=1;
			break;
			
			case C_PEC & C_LEFT:
				if(first==0||syaga==0){
					cnt_time=0;
					first=1;
					syaga=1;
				}
				//throw();
				stand_side_L();
				mode=1;
			break;
			
			case C_PEC & C_RIGHT:
				if(first==0||syaga==0){
					cnt_time=0;
					first=1;
					syaga=1;
				}
				//throw();
				stand_side_R();
				
				mode=1;
			break;
			
			//�Z
			case C_CR:
				if(first==0){
					cnt_time=0;
					first=1;
				}
				if(first!=2){
					up_R();
				}
				
			break;
			
			case C_SQ & C_UP:
				if(first==0){
					cnt_time=0;
					first=2;
					wolk=0;
				}
				punch_L();
				first=2;
			break;
			
			case C_CR & C_UP:
				if(first==0){
					cnt_time=0;
					first=2;
					wolk=0;
				}
				punch_R();
				first=2;
			break;
			

			
			//��
			case C_TR:
				if(first==0){
					cnt_time=0;
					first=1;
				}
				if(demo_mode==0){
					if(wolk_mode==2){
						yosen50msoufront();
					}else{
						gurd_jaku();
						gd=1;
					}
				}
			break;
			//��
			case C_TR & C_R1:
				if(first==0){
					cnt_time=0;
					first=1;
				}
				if(demo_mode==0){
					gurd_roll_R();
					gd=1;
				}
			break;
			
			//��
			case C_TR & C_L1:
				if(first==0){
					cnt_time=0;
					first=1;
				}
				if(demo_mode==0){
					gurd_roll_L();
					gd=1;
				}
			break;
			
			case C_TR & C_UP:
				if(first!=2){
					cnt_time=0;
					first=2;
				}
				if(demo_mode==0){
					gurd();
					gd=1;
				}
			break;
			
			
			//R1
			case C_R1:
				if(first==0){	
					cnt_time=0;
					first=1;
				}
				while(CONTLLOR()==C_R1){
					roll_R();
				}
			break;
			
			//L1
			case C_L1:
				if(first==0){	
					cnt_time=0;
					first=1;
				}
				while(CONTLLOR()==C_L1){
					roll_L();
				}
			break;
			
			case C_L1 & C_R1:
				if(first==0){	
					cnt_time=0;
					first=1;
				}
				if(demo_mode==0){
					zenten();
				}
				break;
			
			case C_R1 & C_RIGHT:
				if(first==0){	
					cnt_time=0;
					first=1;
				}
				roll_side_R();
			break;
			case C_L1 & C_RIGHT:
				if(first==0){	
					cnt_time=0;
					first=1;
				}
				roll_side_R_L();
			break;
			
			case C_RIGHT & C_CR:
				if(first==0){	
					cnt_time=0;
					first=1;
				}
				if(demo_mode==0){
					side_up_R();
				}
			//side_track_R();
			break;
			
			case C_LEFT & C_CR:
				if(first==0){	
					cnt_time=0;
					first=1;
				}
				if(demo_mode==0){
					side_up_L();
				}
				
			break;
			
			case C_R1 & C_LEFT:
				if(first==0){	
					cnt_time=0;
					first=1;
				}
				roll_side_L_R();
			break;
			
			case C_L1 & C_LEFT:
				if(first==0){	
					cnt_time=0;
					first=1;
				}
				roll_side_L();
			break;
			//R2
			case C_R2:
				if(first==0){
					cnt_time=0;
					first=1;
					fuck=1;
				}
				if(demo_mode==0){
					fuck_low_R();
				}
			break;
			
			case C_R2 & C_DOWN:
				if(first==0){
					cnt_time=0;
					first=1;
					fuck=1;
				}
				if(demo_mode==0){
					fuck_R();
				}
			break;
			
			//L2
			case C_L2:
				if(first==0){
					cnt_time=0;
					first=1;
					fuck=2;
				}
				if(demo_mode==0){
					fuck_low_L();
				}
			break;
			case C_L2 & C_DOWN:
				if(first==0){
					cnt_time=0;
					first=1;
					fuck=2;
				}
				if(demo_mode==0){
					fuck_L();
				}
			break;
			//L2+up
			case C_L2 & C_UP:
				if(first==0){
					cnt_time=0;
					first=1;
				}
				if(demo_mode==0){
					humi_L();
					wolk=2;
				}
			break;
			
			//L2+�Z
			case C_L1 & C_UP:
				if(first==0){
					cnt_time=0;
					first=1;
				}
				if(demo_mode==0){
					humi_low_L();
					wolk=2;
				}
			break;
			
			//R2+up
			case C_R2 & C_UP:
				if(first==0){
					cnt_time=0;
					first=1;
				}
				if(demo_mode==0){
					humi_R();
					wolk=2;
				}
			break;
			
			case C_R1 & C_UP:
				if(first==0){
					cnt_time=0;
					first=1;
				}
				if(demo_mode==0){
					humi_low_R();
					wolk=2;
				}
			break;
				
			
			
			
			case C_L2 & C_R2:
				if(first==0){
					cnt_time=0;
					first=1;
				}
				
					up_flont();
			break;
			
			case C_L2 & C_R2 & C_LEFT:
				if(demo_mode==0){
					if(cnt_time>3000){	
						mina_L=1;
					}else{
						mina_L=0;
					}
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					minakawa_L();
				}
			break;
			
			case C_L2 & C_R2 & C_RIGHT:
				if(demo_mode==0){
					if(cnt_time>3000){	
						mina_R=1;
					}else{
						mina_R=0;
					}
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					minakawa_R();
				}
			break;
			
			//START
			case C_START:
				leftarm_strech(30,60,60);
				rightarm_strech(30,60,60);
				leftarm(0,40,0);
				rightarm(0,40,0);
				leftleg(15,35,-50,-25);
				rightleg(15,35,-50,-25);
				kosi(0);
			break;
			
			case C_START & C_RIGHT:
				if(demo_mode==0){
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					if(cnt_time>3000){	
						mina_R=1;
					}else{
						mina_R=0;
					}
					minakawa_R();
				}
			break;
			
			case C_START & C_LEFT:
				if(demo_mode==0){
					if(cnt_time>3000){	
						mina_L=1;
					}else{
						mina_L=0;
					}
					if(first==0){	
						cnt_time=0;
						first=1;
					}
					minakawa_L();
				}
			break;
			
			case C_START & C_UP:
				if(first==0){	
					cnt_time=0;
					first=1;
				}
				if(demo_mode==0){
					zenten();
				}
				break;
			break;
			
			case C_START & C_P_LEF:
			if(first==0){
				if(AL_mode==0){
					first=1;
					AL_mode=1;
				}else{
					first=1;
					AL_mode=0;
				}
			}
			break;
			
			//�E�W���C���g��������
			case C_P_RIG:
				if(wolk_mode==0 && first==0){
					wolk_mode=1;
					first=1;
					LEDOUT(0x03);
				}else if(wolk_mode==1 && first==0){
					wolk_mode=2;
					first=1;
					LEDOUT(0x03);
				}else if(wolk_mode==2 && first==0){
					wolk_mode=0;
					first=1;
					LEDOUT(0x00);
				}
			break;
			
			//���W���C���g��������
			case C_P_LEF:
				if(first==0){
					if(analog==0){
						analog=1;
					}else{
						analog=0;
					}
					/*if(demo_mode==1){
						demo_mode=0;
					}else{
						demo_mode=1;
					}*/
					first=1;
				}
				LEDOUT(0x03);
				//hand_huri();
			break;
			
			case C_L1 & C_R1 & C_R1 & C_UP:
				if(first==0){
					first=1;
					cnt_time=0;
				}
				touritu();
			break;
			
			case C_START & C_DOWN:
				if(first==0){
					first=1;
					cnt_time=0;
				}
				if(demo_mode==0){
					backdorop();
				}
			break;
			
			//�Z���N�g
			case C_SEL:
				datu();
				mode=0;
			break;
			
			//�f�t�H���g
			case C_DEF:
				if(first==0 && (mina_R==2||mina_L==2)){
					mina_R=0;
					mina_L=0;
				}
				mode=1;
				//cnt_time=0;
				if(first>=1){	
					cnt_time=0;
					first=0;
				}
				if((mina_R==1 || mina_L==1)){
					if(mina_L==1){
						while(cnt_time<2500){	
							if(cnt_time>2000){
								leftarm(0,60,0);
								rightarm(0,60,0);
								rightleg(15,90,-90,-20);
								leftleg(15,90,-90,-20);
							}else if(cnt_time>1000){
								leftarm(0,90,0);
								rightarm(0,90,0);
							}else{
								kosi(90);
								leftarm(0,90,0);
								rightarm(0,90,0);
								rightleg(90,90,-90,0);
								leftleg(90,90,-90,0);
							}
							LEDOUT(0x03);
						}
					}else if(cnt_time>500 && mina_R==1){
						while(cnt_time<2500){
							if(cnt_time>2000){
								leftarm(0,60,0);
								rightarm(0,60,0);
								rightleg(15,90,-90,-20);
								leftleg(15,90,-90,-20);
							}else if(cnt_time>1000){
								leftarm(0,90,0);
								rightarm(0,90,0);
							}else{
								kosi(-90);
								leftarm(0,90,0);
								rightarm(0,90,0);
								rightleg(90,90,-90,0);
								leftleg(90,90,-90,0);
							}
							LEDOUT(0x03);
						}
					}
					while((CONTLLOR()==C_L2 & C_R2 & C_LEFT) || (CONTLLOR()==C_L2 & C_R2 & C_RIGHT)){}
					if(cnt_time>2500){
						
						leftarm(0,40,0);
						rightarm(0,40,0);
						if(cnt_time>2700 ||(CONTLLOR()!=C_L2 & C_R2 & C_LEFT) || (CONTLLOR()!=C_L2 & C_R2 & C_RIGHT)){
							mina_R=2;
							mina_L=2;
						}
					}
				}else if(wolk==1){
					leftleg(15,50,-35,-20);
					rightleg(15,50,-35,-20);
					if(cnt_time>500){
						wolk=0;
					}
				}else if(wolk==2){
					leftleg(15,50,-35,-20);
					rightleg(15,50,-35,-20);
					if(cnt_time>1000){
						wolk=0;
					}
				}else if(gd==1){
					leftleg(15,35,-50,-35);
					rightleg(15,35,-50,-35);
					if(cnt_time>1500){
						gd=0;
					}
				}else if(analog==1){
					if(joint_L_X!=0x80 || joint_L_Y!=0x7f){	
						analog_wolk();
					}else{
						LEDOUT(led_mode);
						bace();
						cnt_time=0;
						first=0;
					}
				}else if(fuck==1){
					rightarm(0,0,0);
					if(cnt_time>500){
						fuck=0;
					}
				}else if(fuck==2){
					leftarm(0,0,0);
					if(cnt_time>500){
						fuck=0;	
					}
				}else if(back_mode==1){
					leftleg(15,35,-50,-20);
					rightleg(15,35,-50,-20);
					if(cnt_time>1300){
						back_mode=0;	
					}
				}else if(punch_mode>0){
					leftarm(0,50,-20);
					rightarm(0,50,-20);
					kosi(0);
					if(cnt_time>1300){
						punch_mode=0;	
					}
				}else if(joint_R_Y<=0x00 &&AL_mode==1){
					flont_osidasi();
				}else if(joint_R_Y>=0xff && AL_mode==1){
					back_osidasi();
				}else if(syagaowari==1){
					if(cnt_time>1000){
						syagaowari=0;
					}else{
						leftleg_strech(60,60,60,60);
						rightleg_strech(60,60,60,60);
						leftleg(20,90,-90,-65);
						rightleg(20,90,-90,-65);
						leftarm(-60,40,0);
						rightarm(-60,40,0);
					}
				}else{
					LEDOUT(led_mode);
					bace();
					cnt_time=0;
					first=0;
					wolk=0;
				}
				//
				
				//zero_all();
			break;
			
			
		}
		if(CONTLLOR()!=C_PEC && CONTLLOR()!=C_DEF){
			syagaowari=0;
		}
	
}