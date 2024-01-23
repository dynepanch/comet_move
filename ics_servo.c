#include "ics_servo.h"

int set_position(int sci_no,unsigned int id,unsigned int set_position){
	int error = 0;
	unsigned char trance_data[3];
	switch (sci_no){
		case 5:	//右脚
			trance_data[0] = (unsigned char)(put_position | (id));
			trance_data[1] = (unsigned char)((set_position >> 7) & 0x7f);
			trance_data[2] = (unsigned char)(set_position & 0x7f);
			sci5_put(&trance_data[0],3);
		break;
		
		case 6:	//左脚+腰
			trance_data[0] = (unsigned char)(put_position | (id));
			trance_data[1] = (unsigned char)((set_position >> 7) & 0x7f);
			trance_data[2] = (unsigned char)(set_position & 0x7f);
			sci6_put(&trance_data[0],3);
		break;
		
		case 9:	//右腕
			trance_data[0] = (unsigned char)(put_position | (id));
			trance_data[1] = (unsigned char)((set_position >> 7) & 0x7f);
			trance_data[2] = (unsigned char)(set_position & 0x7f);
			sci9_put(&trance_data[0],3);
		break;
		
		case 12://左脚
			trance_data[0] = (unsigned char)(put_position | (id));
			trance_data[1] = (unsigned char)((set_position >> 7) & 0x7f);
			trance_data[2] = (unsigned char)(set_position & 0x7f);
			sci12_put(&trance_data[0],3);
		break;
		
		default:
			error = 1;
		break;
	}
	if(error == 0){ }
	return error;
}

int set_strech(int sci_no,unsigned int id,unsigned int set_position){
	int error = 0;
	unsigned char trance_data[3];
	switch (sci_no){
		case 5:	//右腕
			trance_data[0] = (unsigned char)(0xC0 | (id));
			trance_data[1] = (unsigned char)(0x01);
			trance_data[2] = (unsigned char)(set_position);
			sci5_put(&trance_data[0],3);
		break;
		
		case 6:	//左腕
			trance_data[0] = (unsigned char)(put_stretch | (id));
			trance_data[1] = (unsigned char)(0x01);
			trance_data[2] = (unsigned char)(set_position);
			sci6_put(&trance_data[0],3);
		break;
		
		case 9:	//右足
			trance_data[0] = (unsigned char)(put_stretch | (id));
			trance_data[1] = (unsigned char)(0x01);
			trance_data[2] = (unsigned char)(set_position);
			sci9_put(&trance_data[0],3);
		break;
		
		case 12://左足
			trance_data[0] = (unsigned char)(put_stretch | (id));
			trance_data[1] = (unsigned char)(0x01);
			trance_data[2] = (unsigned char)(set_position);
			sci12_put(&trance_data[0],3);
		break;
		
		default:
			error = 1;
		break;
	}
	if(error == 0){ }
	return error;
}

int set_speed(int sci_no,unsigned int id,unsigned int set_position){
	int error = 0;
	unsigned char trance_data[3];
	switch (sci_no){
		case 5:	//右腕
			trance_data[0] = (unsigned char)(put_stretch | (id));
			trance_data[1] = (unsigned char)(0x02);
			trance_data[2] = (unsigned char)(set_position);
			//sci5_put(&trance_data[0],3);
		break;
		
		case 6:	//左腕
			trance_data[0] = (unsigned char)(put_stretch | (id));
			trance_data[1] = (unsigned char)(0x02);
			trance_data[2] = (unsigned char)(set_position);
			//sci6_put(&trance_data[0],3);
		break;
		
		case 9:	//右足
			trance_data[0] = (unsigned char)(put_stretch | (id));
			trance_data[1] = (unsigned char)(0x02);
			trance_data[2] = (unsigned char)(set_position);
			//sci9_put(&trance_data[0],3);
		break;
		
		case 12://左足
			trance_data[0] = (unsigned char)(put_stretch | (id));
			trance_data[1] = (unsigned char)(0x02);
			trance_data[2] = (unsigned char)(set_position);
			//sci12_put(&trance_data[0],3);
		break;
		
		default:
			error = 1;
		break;
	}
	if(error == 0){ }
	return error;
}

int set_angle(int id,int angle){
	servo_angle_buff[id] = (int)(11500-3500)/270*angle+7500;
	return 0;
}

int set_strech_num(int id,int angle){
	servo_strech_buff[id] = angle;
	return 0;
}

int servo_free(int id){
	servo_angle_buff[id] = 0;
	return 0;
}

int servo_free_2(int sci_no,int id){
	unsigned char trance_data[3];
	switch (sci_no){
		case 5:	//右腕
			trance_data[0] = (unsigned char)(put_position | (id));
			trance_data[1] = (unsigned char)((0x00 >> 7) & 0x7f);
			trance_data[2] = (unsigned char)(0x00 & 0x7f);
			sci5_put(&trance_data[0],3);
			wait_time(100);
			SCI5.TDR='\0';
			wait_time(100);
			SCI5.TDR='\0';
		break;
		
		case 6:	//左腕
			trance_data[0] = (unsigned char)(put_position | (id));
			trance_data[1] = (unsigned char)((0x00 >> 7) & 0x7f);
			trance_data[2] = (unsigned char)(0x00 & 0x7f);
			sci6_put(&trance_data[0],3);
			wait_time(100);
			SCI6.TDR='\0';
			wait_time(100);
			SCI6.TDR='\0';
		break;
		
		case 9:	//右足
			trance_data[0] = (unsigned char)(put_position | (id));
			trance_data[1] = (unsigned char)((0x00 >> 7) & 0x7f);
			trance_data[2] = (unsigned char)(0x00 & 0x7f);
			sci9_put(&trance_data[0],3);
			wait_time(100);
			SCI9.TDR='\0';
			wait_time(100);
			SCI9.TDR='\0';
		break;
		
		case 12://左足
			trance_data[0] = (unsigned char)(put_position | (id));
			trance_data[1] = (unsigned char)((0x00 >> 7) & 0x7f);
			trance_data[2] = (unsigned char)(0x00 & 0x7f);
			sci12_put(&trance_data[0],3);
			wait_time(100);
			SCI12.TDR='\0';
			wait_time(100);
			SCI12.TDR='\0';
		break;
		
		default:
		
		break;
	}
	return 0;
}


void wari_1(void){
	 static int i=0,cont_cnt=0,cont_buff,sw=0,j=0;
	 static char buff[15];
	control1();
	
	if(sw>2){
		if(i>300){
			sw=-10;
			i=0;
		}else if(i>250){
			set_strech(6,14,servo_strech_buff[14]);//腰
		}else if(i>200){
			set_strech(12,1,servo_strech_buff[1]);//左腕
			set_strech(9,4,servo_strech_buff[4]);//右腕
			set_strech(5,11,servo_strech_buff[11]);//右ひざ
			set_strech(6,7,servo_strech_buff[7]);//左ひざ
		}else if(i>150){
			set_strech(12,2,servo_strech_buff[2]);//左肩
			set_strech(9,5,servo_strech_buff[5]);//右肩
			set_strech(5,12,servo_strech_buff[12]);//右腿
			set_strech(6,8,servo_strech_buff[8]);//左腿
		}else if(i>100){
			set_strech(5,13,servo_strech_buff[13]);//右また
			set_strech(6,9,servo_strech_buff[9]);//左また
		}else if(i>50){
			set_strech(12,0,servo_strech_buff[0]);//左手首
			set_strech(9,3,servo_strech_buff[3]);//手首
			set_strech(5,10,servo_strech_buff[10]);//右足首
			set_strech(6,6,servo_strech_buff[6]);//左足首
		}
		j++;
	}else{
		if(i>25){
			sw=0;
			i=0;
		}else if(i>20){
			set_position(6,14,servo_angle_buff[14]);//腰
			set_position(9,4,servo_angle_buff[4]);//右腕
			set_position(12,1,servo_angle_buff[1]);//左腕
		}else if(i>15){
			set_position(12,0,servo_angle_buff[0]);//左手首
			set_position(9,3,servo_angle_buff[3]);//手首
			set_position(5,11,servo_angle_buff[11]);//右ひざ
			set_position(6,7,servo_angle_buff[7]);//左ひざ
		}else if(i>10){
			set_position(12,2,servo_angle_buff[2]);//左肩
			set_position(9,5,servo_angle_buff[5]);//右肩
			set_position(5,12,servo_angle_buff[12]);//右腿
			set_position(6,8,servo_angle_buff[8]);//左腿
		}else if(i>5){
			set_position(5,13,servo_angle_buff[13]);//右また
			set_position(6,9,servo_angle_buff[9]);//左また
		}else{
			set_position(5,10,servo_angle_buff[10]);//右足首
			set_position(6,6,servo_angle_buff[6]);//左足首
		}
		i++;
	}
	
	
	cnt_time++;
	
}
