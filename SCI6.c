#include "SCI6.h"

void INIT_SCI6(void){
	int k;
	SYSTEM.PRCR.WORD = 0xA502;
	MSTP(SCI6)=0;
	SYSTEM.PRCR.WORD = 0xA500;
	SCI6.SCR.BIT.TE =0;
	SCI6.SCR.BIT.RE =0;
	SCI6.SMR.BIT.CKS=0;
	SCI6.SMR.BIT.STOP =0;
	SCI6.SMR.BIT.PE = 1;
	SCI6.SMR.BIT.PM = 0;
	SCI6.SCR.BIT.TEIE =0;
	SCI6.SCR.BIT.TIE =1;
	SCI6.SCR.BIT.RIE =1;

	ICU.IER[28].BIT.IEN3	=1;
	ICU.IER[28].BIT.IEN4	=1;
	ICU.IER[28].BIT.IEN5	=1;
	ICU.IPR[226].BIT.IPR	=15;
	SCI6.SEMR.BIT.ABCS = 1;
	SCI6.SEMR.BIT.NFEN = 1;
	
	SCI6.BRR = 17;			
	for(k=0;k<1000;k++);		
	//SCI5.SSR.BYTE &= 0xC7;
	//MPC.PWPR.BIT.B0WI=0;
	//BPS(115200);
	MPC.PWPR.BIT.B0WI=0;
	MPC.PWPR.BIT.PFSWE = 1;
	PORT3.PMR.BIT.B2 = 1;
	MPC.P32PFS.BIT.PSEL = 11;
	MPC.PWPR.BIT.PFSWE = 0;
	MPC.PWPR.BIT.B0WI=1;
	SCI6.SCR.BIT.TE =0;
	SCI6.SCR.BIT.RE =1;
	SCI6.TDR = 0xff;
	
}

void start_sci6(void){
	IPR(SCI6,RXI6)=0x7;		
	IEN(SCI6,RXI6)=0x1;		//	???????L????
	IR(SCI6,RXI6)=0x0;
	
	IPR(SCI6,TXI6)=0x7;		//	?D??x???V
	IEN(SCI6,TXI6)=0x1;		//	???????L????
	IR(SCI6,TXI6)=0x0;
	
	IPR(SCI6,TEI6)=0x7;		//	?D??x???V
	IEN(SCI6,TEI6)=0x1;		//	???????L????
	IR(SCI6,TEI6)=0x0;
	
	IPR(SCI6,ERI6)=0x7;		//	?D??x???V
	IEN(SCI6,ERI6)=0x1;		//	???????L????
	IR(SCI6,ERI6)=0x0;
	
	SCI6.SCR.BIT.RE = 1;
	SCI6.SCR.BIT.RIE = 1;
	SCI6.SCR.BIT.TIE = 1;
	SCI6.SCR.BIT.TE = 1;
	
	SCI6.SSR.BIT.ORER;
	SCI6.SSR.BIT.FER;
	SCI6.SSR.BIT.PER;
}


void int_scr6_tei6(void) {
	static int i=0;
	setpsw_i();
	if(i>= sci6_trance_bit_num ){
		SCI6.SCR.BIT.TIE=0;
		SCI6.SCR.BIT.TEIE=0;
		i=0;
	}else{
		SCI6.TDR = trans_b_6[i];
		trans_b_6[i++] = '\0';
	}
	
	
	SCI6.SCR.BIT.TE=0;
	PORT3.PMR.BIT.B2=0;
	PORT3.PDR.BIT.B2=1;
	PORT3.PODR.BIT.B2=1;
}

void int_scr6_txi6(void) {
	static int i=0;
	setpsw_i();
	if(i>=3){
		SCI6.SCR.BIT.TIE=0;
		SCI6.SCR.BIT.TEIE=1;
		SCI6.TDR='\0';		
		i=0;
	}else{
		SCI6.TDR=trans_b_6[i++];
	}
	trans_b_6[(i-1)]=0x00;

}


//intprg.cで呼び出す
/*void int_scr6_tei6(void) {
	SCI6.SCR.BIT.TIE=0;
	SCI6.SCR.BIT.TE=0;
	SCI6.SCR.BIT.TEIE=0;
	PORT3.PMR.BIT.B2=0;
	PORT3.PDR.BIT.B2=1;
	PORT3.PODR.BIT.B2=1;
}
*/
//intprg.cで呼び出す
void int_scr6_rxi6(void) {
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
void int_scr6_eri6(void) {
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
	sci6_error=er;
}
//intprg.cで呼び出す
void sci6_put_start(void){
	PORT3.PMR.BIT.B2=1;
	SCI6.SCR.BIT.TIE=1;
	SCI6.SCR.BIT.TE=1;
}


void sci6_puts(unsigned char* c){
	int i;
	if(TEND!=1){
		return;
	}
	for(i=0; (*(c+i)!='\0')&&(sizeof(trans_b_6)>=i);i++){
		trans_b_6[i]=(*(c+i));
	}
	sci6_put_start();
}

void sci6_put(unsigned char* c,int n){
	int i;
	if(TEND!=1){
		return;
	}
	R_STOP;
	for(i=0;i<=n-1;i++){
		trans_b_6[i]=(*(c+i));
	}
	sci6_trance_bit_num = n;
	
	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	PORT3.PMR.BIT.B2 = 1;
	MPC.P32PFS.BIT.PSEL = 11;
	MPC.PWPR.BIT.PFSWE = 0;
	MPC.PWPR.BIT.B0WI = 1;
	sci6_put_start();
}

void sci6_put_data(unsigned char* c,int n){
	int i;
	if(TEND!=1){
		return;
	}
	for(i=0;i<=n-1;i++){
		trans_b_6[i]=(*(c+i));
	}
	sci6_put_start();
}

int sci6_gets( volatile unsigned char* p){
	int n;
	for(n=0;(get_buff_2[n]!='\0')&&(n<=sizeof(get_buff_2));n++){
		*(p+n)=get_buff_2[n];
	}
	return 0;
}

