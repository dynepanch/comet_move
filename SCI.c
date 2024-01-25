#include "SCI.h"
#include "stdio.h"
extern int dualshock;
/*
void INIT_SCI1(void){
	int k;
	SYSTEM.PRCR.WORD = 0xA502;
	MSTP(SCI1)=0;
	SYSTEM.PRCR.WORD = 0xA500;
	SCI1.SCR.BIT.TE =0;
	SCI1.SCR.BIT.RE =0;
	SCI1.SMR.BIT.CKS=0;
	SCI1.SMR.BIT.STOP =0;
	SCI1.SCR.BIT.TEIE =0;
	SCI1.SCR.BIT.TIE =1;
	SCI1.SCR.BIT.RIE =1;
	ICU.IER[27].BIT.IEN3	=1;
	ICU.IER[27].BIT.IEN4	=1;
	ICU.IER[27].BIT.IEN5	=1;
	ICU.IPR[218].BIT.IPR	=15;
	SCI1.SEMR.BIT.ABCS = 1;
	SCI1.SEMR.BIT.NFEN = 1;
	
	SCI1.BRR = 10;			//	ボートレートが115200になるように設定
	for(k=0;k<100;k++);		//	少し待つ
	SCI1.SSR.BYTE &= 0xC7;
	MPC.PWPR.BIT.B0WI=0;
	BPS(115200);
	MPC.PWPR.BIT.B0WI=0;
	MPC.PWPR.BIT.PFSWE = 1;
	PORT2.PMR.BIT.B6 = 1;
	PORT3.PMR.BIT.B0= 1;
	MPC.P26PFS.BIT.PSEL = 10;
	MPC.P30PFS.BIT.PSEL = 10;
	MPC.PWPR.BIT.PFSWE = 0;
	MPC.PWPR.BIT.B0WI=1;
	SCI1.SCR.BIT.TE =0;
	SCI1.SCR.BIT.RE =1;
	SCI1.TDR = 0xff;
}
*/
void INIT_SCI1(void){
	SYSTEM.PRCR.WORD = 0xA502;
	MSTP(SCI1)=0;
	SYSTEM.PRCR.WORD = 0xA500;
	SCI1.SCR.BIT.TE =0;
	SCI1.SCR.BIT.RE =0;
	SCI1.SMR.BIT.CKS=0;
	SCI1.SMR.BIT.STOP =0;
	SCI1.SMR.BIT.PE = 1;
	SCI1.SMR.BIT.PM = 0;
	SCI1.SCR.BIT.TEIE =0;
	SCI1.SCR.BIT.TIE =1;
	SCI1.SCR.BIT.RIE =1;
	ICU.IER[27].BIT.IEN3	=1;
	ICU.IER[27].BIT.IEN4	=1;
	ICU.IER[27].BIT.IEN5	=1;
	ICU.IPR[218].BIT.IPR	=15;
	SCI1.SEMR.BIT.ABCS = 1;
	SCI1.SEMR.BIT.NFEN = 1;
	BPS(115200);
	MPC.PWPR.BIT.B0WI=0;
	MPC.PWPR.BIT.PFSWE = 1;
	PORT2.PMR.BIT.B6 = 1;
	PORT3.PMR.BIT.B0= 1;
	MPC.P30PFS.BIT.PSEL = 10;
	MPC.P26PFS.BIT.PSEL = 10;
	MPC.PWPR.BIT.PFSWE = 0;
	MPC.PWPR.BIT.B0WI=1;
	SCI1.SCR.BIT.TE =0;
	SCI1.SCR.BIT.RE =1;
	SCI1.TDR = 0xff;
}


void int_scr1_txi1(void) {
	static int i=0;
	setpsw_i();
	if(trans_b_1[i]=='\0'){
		SCI1.SCR.BIT.TIE=0;
		SCI1.SCR.BIT.TEIE=1;
		SCI1.TDR='\0';
		i=0;
	}else{
		SCI1.TDR=trans_b_1[i++];
	}
	trans_b_1[(i-1)]=0x00;

}

//intprg.cで呼び出す
void int_scr1_tei1(void) {
	SCI1.SCR.BIT.TIE=0;
	SCI1.SCR.BIT.TE=0;
	SCI1.SCR.BIT.TEIE=0;
	PORT2.PMR.BIT.B6=0;
	PORT2.PDR.BIT.B6=1;
	PORT2.PODR.BIT.B6=1;
}
//intprg.cで呼び出す
void int_scr1_rxi1(void){
	int n;
	while((SCI1.SSR.BYTE&0x40)==0){} //受信フラグがが1にセットされるのを待つ
	setpsw_i();
	LEDOUT(0x00);
	get_buff_m[receve_data_num++]=RDR;
	if(receve_data_num>3){
		receve_data_num=0;
		for(n=0;n<sizeof(get_buff_2);n++){
			get_buff_2[n]=get_buff_m[n];
		}
	}
} 
/*void int_scr1_rxi1(void) {
	int n;
	setpsw_i();
	get_buff_m[receve_data_num++]=RDR;
	if(receve_data_num >= sizeof(get_buff_m)-1 ){
		receve_data_num=0;
	}
	switch(RDR){
		case ESC_KEY:
			receve_data_num=0;
			for (n=0;n<=sizeof(get_buff_m);n++){
				get_buff_m[n]='\0';
			}
			for( n=0; n<=sizeof(get_buff_m);n++){
				get_buff_2[n]='\0';
			}
			PORT4.PODR.BIT.B0^=1;
		break;

		case ENTER_KEY:
			string_num = receve_data_num;
			receve_data_num=0;
			for ( n=0; n<=sizeof (get_buff_2);n++){
				get_buff_2[n]='\0';
			}
			for( n=0;n<string_num-1; n++){
				get_buff_2[n]=get_buff_m[n];
			}
			get_buff_2[string_num]='\0';
			for (n=0 ;n<sizeof(get_buff_m);n++){
				get_buff_m[n]='\0';
			}
			PORT4.PODR.BIT.B4^=1;
			break;
	}
}*/
//intprg.cで呼び出す
void int_scr1_eri1(void) {
	int er=1;
	if(SCI.SSR.BIT.PER == 1){
		SCI.SSR.BIT.PER=0;///バリティエラーフラグ
		er=2;
	}
	if(SCI.SSR.BIT.FER==1){
		SCI.SSR.BIT.FER=0;///フレームエラーフラグ
		er=3;
	}
	if(SCI.SSR.BIT.ORER== 1){
		SCI.SSR.BIT.ORER=0;//オーバランエラーフラグ
		er = 4;
	}
	sci1_error=er;
}
//intprg.cで呼び出す
void sci1_put_start(void){
	PORT2.PMR.BIT.B6=1;
	SCI1.SCR.BIT.TIE=1;
	SCI1.SCR.BIT.TE=1;
}


void sci1_puts(unsigned char* c){
	int i;
	if(TEND!=1){
		return;
	}
	for(i=0; (*(c+i)!='\0')&&(sizeof(trans_b_1)>=i);i++){
		trans_b_1[i]=(*(c+i));
	}
	sci1_put_start();
}

void sci1_put_data(unsigned char* c,int n){
	int i;
	if(TEND!=1){
		return;
	}
	for(i=0;i<=n-1;i++){
		trans_b_1[i]=(*(c+i));
	}
	sci1_put_start();
}

int sci1_gets( volatile unsigned char* p){
	int n;
	for(n=0;(get_buff_2[n]!='\0')&&(n<=sizeof(get_buff_2));n++){
		*(p+n)=get_buff_m[n];
	}
	return 0;
}

void sci1_put(unsigned char* c,int n){
	int i;
	if(TEND!=1){
		return;
	}
	SCI1.SCR.BIT.RE = 0;
	for(i=0;i<=n-1;i++){
		trans_b_1[i]=(*(c+i));
	}
	sci1_trance_bit_num = n;
	
	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	PORT2.PMR.BIT.B6 = 1;
	MPC.P26PFS.BIT.PSEL = 12;
	MPC.PWPR.BIT.PFSWE = 0;
	MPC.PWPR.BIT.B0WI = 1;
	sci1_put_start();
}

void wari_2(void){
	
	static unsigned int time_a,error,k;
	unsigned char send_data[100];
	
	if(time_a++ >= 1000)
	{
		time_a = 0;
		sprintf((char*)send_data,"Hello,%x\r\n",joint_L());
		sci1_puts(send_data);
		
	}
	
}
