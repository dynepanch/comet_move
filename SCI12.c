#include "SCI12.h"

void INIT_SCI12(void){
	int k;
	SYSTEM.PRCR.WORD = 0xA502;
	MSTP(SCI12)=0;
	SYSTEM.PRCR.WORD = 0xA500;
	SCI12.SCR.BIT.TE =0;
	SCI12.SCR.BIT.RE =0;
	SCI12.SMR.BIT.CKS=0;
	SCI12.SMR.BIT.STOP =0;
	SCI12.SMR.BIT.PE = 1;
	SCI12.SMR.BIT.PM = 0;
	SCI12.SCR.BIT.TEIE =0;
	SCI12.SCR.BIT.TIE =1;
	SCI12.SCR.BIT.RIE =1;
	ICU.IER[27].BIT.IEN3	=1;
	ICU.IER[27].BIT.IEN4	=1;
	ICU.IER[27].BIT.IEN5	=1;
	ICU.IPR[222].BIT.IPR	=15;
	SCI12.SEMR.BIT.ABCS = 1;
	SCI12.SEMR.BIT.NFEN = 1;
	
	SCI12.BRR = 17;			//	?{?[?g???[?g??115200?????????
	for(k=0;k<1000;k++);		//	???????
	MPC.PWPR.BIT.B0WI=0;
	MPC.PWPR.BIT.PFSWE = 1;
	PORTE.PMR.BIT.B1 = 1;
	MPC.PE1PFS.BIT.PSEL = 12;
	MPC.PWPR.BIT.PFSWE = 0;
	MPC.PWPR.BIT.B0WI=1;
	SCI12.SCR.BIT.TE =0;
	SCI12.SCR.BIT.RE =1;
	SCI12.TDR = 0xff;
	
}

void start_sci12(void){
	//?S??????????????,???W?X?^???????
	IPR(SCI12,RXI12)=0x7;		//	?D??x???V
	IEN(SCI12,RXI12)=0x1;		//	???????L????
	IR(SCI12,RXI12)=0x0;
	
	IPR(SCI12,TXI12)=0x7;		//	?D??x???V
	IEN(SCI12,TXI12)=0x1;		//	???????L????
	IR(SCI12,TXI12)=0x0;
	
	IPR(SCI12,TEI12)=0x7;		//	?D??x???V
	IEN(SCI12,TEI12)=0x1;		//	???????L????
	IR(SCI12,TEI12)=0x0;
	
	IPR(SCI12,ERI12)=0x7;		//	?D??x???V
	IEN(SCI12,ERI12)=0x1;		//	???????L????
	IR(SCI12,ERI12)=0x0;
	
	SCI12.SCR.BIT.RE = 1;
	SCI12.SCR.BIT.RIE = 1;
	SCI12.SCR.BIT.TIE = 1;
	SCI12.SCR.BIT.TE = 1;
	
	SCI12.SSR.BIT.ORER;
	SCI12.SSR.BIT.FER;
	SCI12.SSR.BIT.PER;
}


void int_scr12_txi12(void) {
	static int i=0;
	setpsw_i();
	if(i>=3){
		SCI12.SCR.BIT.TIE=0;
		SCI12.SCR.BIT.TEIE=1;
		SCI12.TDR='\0';
		i=0;
	}else{
		SCI12.TDR=trans_b_12[i++];
	}
	trans_b_12[(i-1)]=0x00;

}
void int_scr12_tei12(void) {
	static int i=0;
	setpsw_i();
	if(i>= sci12_trance_bit_num ){
		SCI12.SCR.BIT.TIE=0;
		SCI12.SCR.BIT.TEIE=0;
		i=0;
	}else{
		SCI12.TDR = trans_b_12[i];
		trans_b_12[i++] = '\0';
	}
	
	
	SCI12.SCR.BIT.TE=0;
	PORTE.PMR.BIT.B1=0;
	PORTE.PDR.BIT.B1=1;
	PORTE.PODR.BIT.B1=1;
}
/*
//intprg.cで呼び出す
void int_scr12_tei12(void) {
	SCI12.SCR.BIT.TIE=0;
	SCI12.SCR.BIT.TE=0;
	SCI12.SCR.BIT.TEIE=0;
	PORTE.PMR.BIT.B1=0;
	PORTE.PDR.BIT.B1=1;
	PORTE.PODR.BIT.B1=1;
}*/
//intprg.cで呼び出す
void int_scr12_rxi12(void) {
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
				get_buff_12[n]='\0';
			}
			PORT4.PODR.BIT.B0^=1;
		break;

		case ENTER_KEY:
			string_num = receve_data_num;
			receve_data_num=0;
			for ( n=0; n<=sizeof (get_buff_12);n++){
				get_buff_12[n]='\0';
			}
			for( n=0;n<string_num-1; n++){
				get_buff_12[n]=get_buff_m[n];
			}
			get_buff_12[string_num]='\0';
			for (n=0 ;n<sizeof(get_buff_m);n++){
				get_buff_m[n]='\0';
			}
			PORT4.PODR.BIT.B4^=1;
			break;
	}
}//intprg.cで呼び出す
void int_scr12_eri12(void) {
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
	sci12_error=er;
}
//intprg.cで呼び出す
void sci12_put_start(void){
	PORTE.PMR.BIT.B1=1;
	SCI12.SCR.BIT.TIE=1;
	SCI12.SCR.BIT.TE=1;
}


void sci12_puts(unsigned char* c){
	int i;
	if(TEND!=1){
		return;
	}
	for(i=0; (*(c+i)!='\0')&&(sizeof(trans_b_12)>=i);i++){
		trans_b_12[i]=(*(c+i));
	}
	sci12_put_start();
}

void sci12_put(unsigned char* c,int n){
	int i;
	if(TEND!=1){
		return;
	}
	R_STOP;
	for(i=0;i<=n-1;i++){
		trans_b_12[i]=(*(c+i));
	}
	sci12_trance_bit_num = n;
	
	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	PORTE.PMR.BIT.B1 = 1;
	MPC.PE1PFS.BIT.PSEL = 12;
	MPC.PWPR.BIT.PFSWE = 0;
	MPC.PWPR.BIT.B0WI = 1;
	sci12_put_start();
}

void sci12_put_data(unsigned char* c,int n){
	int i;
	if(TEND!=1){
		return;
	}
	for(i=0;i<=n-1;i++){
		trans_b_12[i]=(*(c+i));
	}
	sci12_put_start();
}

int sci12_gets( volatile unsigned char* p){
	int n;
	for(n=0;(get_buff_12[n]!='\0')&&(n<=sizeof(get_buff_12));n++){
		*(p+n)=get_buff_12[n];
	}
	return 0;
}
