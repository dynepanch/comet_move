#include "SCI9.h"

void INIT_SCI9(void){
	int k;
	SYSTEM.PRCR.WORD = 0xA502;
	MSTP(SCI9)=0;
	SYSTEM.PRCR.WORD = 0xA500;
	SCI9.SCR.BIT.TE =0;
	SCI9.SCR.BIT.RE =0;
	SCI9.SMR.BIT.CKS=0;
	SCI9.SMR.BIT.STOP =0;
	SCI9.SMR.BIT.PE = 1;
	SCI9.SMR.BIT.PM = 0;
	SCI9.SCR.BIT.TEIE =0;
	SCI9.SCR.BIT.TIE =1;
	SCI9.SCR.BIT.RIE =1;
	ICU.IER[27].BIT.IEN3	=1;
	ICU.IER[27].BIT.IEN4	=1;
	ICU.IER[27].BIT.IEN5	=1;
	ICU.IPR[222].BIT.IPR	=15;
	SCI9.SEMR.BIT.ABCS = 1;
	SCI9.SEMR.BIT.NFEN = 1;
	
	SCI9.BRR = 17;			//	?{?[?g???[?g??115200?????????
	for(k=0;k<1000;k++);		//	???????
	//SCI5.SSR.BYTE &= 0xC7;
	//MPC.PWPR.BIT.B0WI=0;
	//BPS(115200);
	MPC.PWPR.BIT.B0WI=0;
	MPC.PWPR.BIT.PFSWE = 1;
	PORTB.PMR.BIT.B7 = 1;
	MPC.PB7PFS.BIT.PSEL = 10;
	MPC.PWPR.BIT.PFSWE = 0;
	MPC.PWPR.BIT.B0WI=1;
	SCI9.SCR.BIT.TE =0;
	SCI9.SCR.BIT.RE =1;
	SCI9.TDR = 0xff;
	
}

void start_sci9(void){
	//?S??????????????,???W?X?^???????
	IPR(SCI9,RXI9)=0x7;		//	?D??x???V
	IEN(SCI9,RXI9)=0x1;		//	???????L????
	IR(SCI9,RXI9)=0x0;
	
	IPR(SCI9,TXI9)=0x7;		//	?D??x???V
	IEN(SCI9,TXI9)=0x1;		//	???????L????
	IR(SCI9,TXI9)=0x0;
	
	IPR(SCI9,TEI9)=0x7;		//	?D??x???V
	IEN(SCI9,TEI9)=0x1;		//	???????L????
	IR(SCI9,TEI9)=0x0;
	
	IPR(SCI9,ERI9)=0x7;		//	?D??x???V
	IEN(SCI9,ERI9)=0x1;		//	???????L????
	IR(SCI9,ERI9)=0x0;
	
	SCI9.SCR.BIT.RE = 1;
	SCI9.SCR.BIT.RIE = 1;
	SCI9.SCR.BIT.TIE = 1;
	SCI9.SCR.BIT.TE = 1;
	
	SCI9.SSR.BIT.ORER;
	SCI9.SSR.BIT.FER;
	SCI9.SSR.BIT.PER;
}


void int_scr9_txi9(void) {
	static int i=0;
	setpsw_i();
	if(i>=3){
		SCI9.SCR.BIT.TIE=0;
		SCI9.SCR.BIT.TEIE=1;
		SCI9.TDR='\0';
		i=0;
	}else{
		SCI9.TDR=trans_b_9[i++];
	}
	trans_b_9[(i-1)]=0x00;

}
//intprg.cで呼び出す
/*void int_scr9_tei9(void) {
	SCI9.SCR.BIT.TIE=0;
	SCI9.SCR.BIT.TE=0;
	SCI9.SCR.BIT.TEIE=0;
	PORTB.PMR.BIT.B7=0;
	PORTB.PDR.BIT.B7=1;
	PORTB.PODR.BIT.B7=1;
}*/
void int_scr9_tei9(void) {
	static int i=0;
	setpsw_i();
	if(i>= sci9_trance_bit_num ){
		SCI9.SCR.BIT.TIE=0;
		SCI9.SCR.BIT.TEIE=0;
		i=0;
	}else{
		SCI9.TDR = trans_b_9[i];
		trans_b_9[i++] = '\0';
	}
	
	
	SCI9.SCR.BIT.TE=0;
	PORTB.PMR.BIT.B7=0;
	PORTB.PDR.BIT.B7=1;
	PORTB.PODR.BIT.B7=1;
}
//intprg.cで呼び出す
void int_scr9_rxi9(void) {
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
}//intprg.cで呼び出す
void int_scr9_eri9(void) {
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
	sci9_error=er;
}
//intprg.cで呼び出す
void sci9_put_start(void){
	PORTB.PMR.BIT.B7=1;
	SCI9.SCR.BIT.TIE=1;
	SCI9.SCR.BIT.TE=1;
}


void sci9_puts(unsigned char* c){
	int i;
	if(TEND!=1){
		return;
	}
	for(i=0; (*(c+i)!='\0')&&(sizeof(trans_b_9)>=i);i++){
		trans_b_9[i]=(*(c+i));
	}
	sci9_put_start();
}

void sci9_put(unsigned char* c,int n){
	int i;
	if(TEND!=1){
		return;
	}
	R_STOP;
	for(i=0;i<=n-1;i++){
		trans_b_9[i]=(*(c+i));
	}
	sci9_trance_bit_num = n;
	
	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	PORTB.PMR.BIT.B7 = 1;
	MPC.PB7PFS.BIT.PSEL = 10;
	MPC.PWPR.BIT.PFSWE = 0;
	MPC.PWPR.BIT.B0WI = 1;
	sci9_put_start();
}

void sci9_put_data(unsigned char* c,int n){
	int i;
	if(TEND!=1){
		return;
	}
	for(i=0;i<=n-1;i++){
		trans_b_9[i]=(*(c+i));
	}
	sci9_put_start();
}

int sci9_gets( volatile unsigned char* p){
	int n;
	for(n=0;(get_buff_2[n]!='\0')&&(n<=sizeof(get_buff_2));n++){
		*(p+n)=get_buff_2[n];
	}
	return 0;
}
