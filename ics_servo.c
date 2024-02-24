#include "ics_servo.h"

int set_position(static unsigned int sci_no,static unsigned int id,static unsigned int set_position){
	int error = 0;
	static unsigned char trance_data[3];
	switch (sci_no){
		case 5:	//�E�r
			trance_data[0] = (unsigned char)(put_position | (id));
			trance_data[1] = (unsigned char)((set_position >> 7) & 0x7f);
			trance_data[2] = (unsigned char)(set_position & 0x7f);
			sci5_put(&trance_data[0],3);
		break;
		
		case 6:	//���r+��
			trance_data[0] = (unsigned char)(put_position | (id));
			trance_data[1] = (unsigned char)((set_position >> 7) & 0x7f);
			trance_data[2] = (unsigned char)(set_position & 0x7f);
			sci6_put(&trance_data[0],3);
		break;
		
		case 9:	//�E�r
			trance_data[0] = (unsigned char)(put_position | (id));
			trance_data[1] = (unsigned char)((set_position >> 7) & 0x7f);
			trance_data[2] = (unsigned char)(set_position & 0x7f);
			sci9_put(&trance_data[0],3);
		break;
		
		case 12://���r
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
	static unsigned char trance_data[3];
	switch (sci_no){
		case 5:	//�E�r
			trance_data[0] = (unsigned char)(0xC0 | (id));
			trance_data[1] = (unsigned char)(0x01);
			trance_data[2] = (unsigned char)(set_position);
			sci5_put(&trance_data[0],3);
		break;
		
		case 6:	//���r
			trance_data[0] = (unsigned char)(0xC0 | (id));
			trance_data[1] = (unsigned char)(0x01);
			trance_data[2] = (unsigned char)(set_position);
			sci6_put(&trance_data[0],3);
		break;
		
		case 9:	//�E��
			trance_data[0] = (unsigned char)(put_stretch | (id));
			trance_data[1] = (unsigned char)(0x01);
			trance_data[2] = (unsigned char)(set_position);
			sci9_put(&trance_data[0],3);
		break;
		
		case 12://����
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
	static unsigned char trance_data[3];
	switch (sci_no){
		case 5:	//�E�r
			trance_data[0] = (unsigned char)(0xC0 | (id));
			trance_data[1] = (unsigned char)(0x02);
			trance_data[2] = (unsigned char)(set_position);
			//sci5_put(&trance_data[0],3);
		break;
		
		case 6:	//���r
			trance_data[0] = (unsigned char)(0xC0 | (id));
			trance_data[1] = (unsigned char)(0x02);
			trance_data[2] = (unsigned char)(set_position);
			//sci6_put(&trance_data[0],3);
		break;
		
		case 9:	//�E��
			trance_data[0] = (unsigned char)(0xC0 | (id));
			trance_data[1] = (unsigned char)(0x02);
			trance_data[2] = (unsigned char)(set_position);
			//sci9_put(&trance_data[0],3);
		break;
		
		case 12://����
			trance_data[0] = (unsigned char)(0xC0 | (id));
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
	if(angle<=0){
		angle=1;
	}
	servo_strech_buff[id] = angle;
	return 0;
}
int set_speed_num(int id,int angle){
	if(angle<=0){
		angle=1;
	}
	servo_speed_buff[id] = angle;
	return 0;
}

int servo_free(int id){
	servo_angle_buff[id] = 0;
	return 0;
}


void wari_1(void){
	 static int i=0,cont_cnt=0,cont_buff,sw=0,j=0;
	 static char buff[15];
	control1();
	
	if(sw==2){
		if(i>30){
			sw=0;
			i=0;
		}else if(i>25){
			set_speed(6,14,servo_speed_buff[14]);//��
			set_speed(9,4,servo_speed_buff[4]);//�E�r
			set_speed(12,1,servo_speed_buff[1]);//���r
		}else if(i>20){
			set_speed(12,0,servo_speed_buff[0]);//�����
			set_speed(9,3,servo_speed_buff[3]);//���
			set_speed(5,11,servo_speed_buff[11]);//�E�Ђ�
			set_speed(6,7,servo_speed_buff[7]);//���Ђ�
		}else if(i>15){
			set_speed(12,2,servo_speed_buff[2]);//����
			set_speed(9,5,servo_speed_buff[5]);//�E��
			set_speed(5,12,servo_speed_buff[12]);//�E��
			set_speed(6,8,servo_speed_buff[8]);//����
		}else if(i>10){
			set_speed(5,13,servo_speed_buff[13]);//�E�܂�
			set_speed(6,9,servo_speed_buff[9]);//���܂�
		}else if(i>5){
			set_speed(5,10,servo_speed_buff[10]);//�E����
			set_speed(6,6,servo_strech_buff[6]);//������
		}
		
	}else if(sw==1){
		if(i>30){
			sw=2;
			i=0;
		}else if(i>25){
			set_strech(6,14,servo_strech_buff[14]);//��
			set_strech(9,4,servo_strech_buff[4]);//�E�r
			set_strech(12,1,servo_strech_buff[1]);//���r
		}else if(i>20){
			set_strech(12,0,servo_strech_buff[0]);//�����
			set_strech(9,3,servo_strech_buff[3]);//���
			set_strech(5,11,servo_strech_buff[11]);//�E�Ђ�
			set_strech(6,7,servo_strech_buff[7]);//���Ђ�
		}else if(i>15){
			set_strech(12,2,servo_strech_buff[2]);//����
			set_strech(9,5,servo_strech_buff[5]);//�E��
			set_strech(5,12,servo_strech_buff[12]);//�E��
			set_strech(6,8,servo_strech_buff[8]);//����
		}else if(i>10){
			set_strech(5,13,servo_strech_buff[13]);//�E�܂�
			set_strech(6,9,servo_strech_buff[9]);//���܂�
		}else if(i>5){
			set_strech(5,10,servo_strech_buff[10]);//�E����
			set_strech(6,6,servo_strech_buff[6]);//������
		}
		
	}else{
		if(i>30){
			sw=1;
			i=0;
		}else if(i>25){
			set_position(6,14,servo_angle_buff[14]);//��
			set_position(9,4,servo_angle_buff[4]);//�E�r
			set_position(12,1,servo_angle_buff[1]);//���r
		}else if(i>20){
			set_position(12,0,servo_angle_buff[0]);//�����
			set_position(9,3,servo_angle_buff[3]);//���
			set_position(5,11,servo_angle_buff[11]);//�E�Ђ�
			set_position(6,7,servo_angle_buff[7]);//���Ђ�
		}else if(i>15){
			set_position(12,2,servo_angle_buff[2]);//����
			set_position(9,5,servo_angle_buff[5]);//�E��
			set_position(5,12,servo_angle_buff[12]);//�E��
			set_position(6,8,servo_angle_buff[8]);//����
		}else if(i>10){
			set_position(5,13,servo_angle_buff[13]);//�E�܂�
			set_position(6,9,servo_angle_buff[9]);//���܂�
		}else if(i>5){
			set_position(5,10,servo_angle_buff[10]);//�E����
			set_position(6,6,servo_angle_buff[6]);//������
		}
		
	}
	i++;
	
	cnt_time++;
	
}
