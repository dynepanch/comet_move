#include "SPI.h"
#include "stdio.h"
#include "iodefine.h"

//初期化
void RSPI(){
	
	SYSTEM.PRCR.WORD = 0x0A50b;   //保護の解除
	MSTP(RSPI0) = 0;
	SYSTEM.PRCR.WORD = 0x0A502;   //保護
	
	RSPI0.SPCR.BIT.MSTR = 1;      //マスタモードに設定  
	RSPI0.SPCR.BIT.SPEIE = 0;     //RSPIエラー割り込み要求の発生を禁止
	RSPI0.SPCR.BIT.SPTIE = 0;     //送信割り込み要求の発生を禁止 
	RSPI0.SPCR.BIT.SPE = 0;       //RSPIの機能の無効
	RSPI0.SPCR.BIT.SPRIE = 0;     //受信割り込み要求の発生を禁止
	RSPI0.SSLP.BIT.SSL0P = 0;     //active Low
	
	//モード選択
	RSPI0.SPPCR.BIT.SPLP = 0;     //通常モード
	RSPI0.SPPCR.BIT.SPLP2 = 0;    //通常モード
	RSPI0.SPPCR.BIT.MOIFV = 1;    //アイドル時　出力HIGI
	RSPI0.SPPCR.BIT.MOIFE = 1;    //最終データ送信
	
	//ビットレートの選択
	RSPI0.SPBR = 12;		//大体250kHz
	
	//フレーム数、アクセス方法設定
	RSPI0.SPDCR.BIT.SPFC = 0;     //フレーム数の選択１～４
	RSPI0.SPDCR.BIT.SPRDTD = 0;   //SPDRは受信バッファを読み出す
	RSPI0.SPDCR.BIT.SPLW = 0;     //SPRDへはワードアクセス
	RSPI0.SPCKD.BIT.SCKDL = 1;    //ｸﾛｯｸ遅延
	
	//step5
	RSPI0.SSLND.BIT.SLNDL = 0;    //ネゲートの遅延設定
	
	//step6
	RSPI0.SPND.BIT.SPNDL = 0;     //次アクセス遅延
	
	//step7
	RSPI0.SPCR2.BIT.SPPE = 0;     //パリティなし
	RSPI0.SPCR2.BIT.SPOE = 0;     //パリティなし
	RSPI0.SPCR2.BIT.SPIIE = 0;    //アイドル割り込み要求禁止
	RSPI0.SPCR2.BIT.PTE = 0;      //自己診断しない
	
	//step8
	RSPI0.SPCMD0.BIT.CPHA = 0;    //ｸﾛｯｸ立ち上がりで送信
	RSPI0.SPCMD0.BIT.CPOL = 1;    //RSPCKアイドルじHIGI
	RSPI0.SPCMD0.BIT.BRDV = 2;    //
	RSPI0.SPCMD0.BIT.SSLA = 0;    //
	RSPI0.SPCMD0.BIT.SSLKP = 1;   //転送終了時にネゲート
	RSPI0.SPCMD0.BIT.SPB = 4;     //8bit
	RSPI0.SPCMD0.BIT.LSBF = 1;    //LSBファースト
	RSPI0.SPCMD0.BIT.SPNDEN = 1;  //
	RSPI0.SPCMD0.BIT.SLNDEN = 1;  //
	RSPI0.SPCMD0.BIT.SCKDEN = 1;  //
	
	//step11
	MPC.PWPR.BIT.B0WI = 0;        //PFSレジスタの保護解除
	MPC.PWPR.BIT.PFSWE = 1;       //
	
	
	PORTC.PMR.BIT.B4 = 1;         //周辺ポートにする
	PORTC.PMR.BIT.B5 = 1;
	PORTC.PMR.BIT.B6 = 1;
	PORTC.PMR.BIT.B7 = 1;
	
	MPC.PC4PFS.BYTE = 0xD;        //SSLA0
	MPC.PC5PFS.BYTE = 0xD;        //RSPCK
	MPC.PC6PFS.BYTE = 0xD;        //MOSIA
	MPC.PC7PFS.BYTE = 0xD;        //MISOA

	
	MPC.PWPR.BIT.PFSWE = 0;       //PFSレジスタの保護
	MPC.PWPR.BIT.B0WI = 1;
	
	//step12
	RSPI0.SPCR.BIT.SPMS = 0;      //SPIで送信
  	RSPI0.SPCR.BIT.TXMD = 0;          //全二重送信
	RSPI0.SPCR.BIT.MODFEN = 0;    //エラー検出禁止
	RSPI0.SPCR.BIT.MSTR = 1;      //マスターモード
	RSPI0.SPCR.BIT.SPTIE = 0;     //sousin割り込み禁止
	RSPI0.SPCR.BIT.SPRIE = 0;     //zyusin割り込み禁止
	RSPI0.SPCR.BIT.SPE = 0;       //RSPI機能を許可しない
	
	//step13
	RSPI0.SPCR.BYTE;              //レジスタをリード
//*/
/*
	RSPI0.SPCR.BIT.SPE = 0;			//	RSPIを無効にする
	SYSTEM.PRCR.WORD = 0xA50b;		//	書き込み許可【消費電力低減モード・クロック発生関連
	MSTP(RSPI0) = 0;			//	RSPI0のモジュールストップ解除
	SYSTEM.PRCR.WORD = 0xA502;
	
	RSPI0.SPCR.BYTE = 0x08;			//	初期化
	//RSPI0.SSLP.BIT.SSL0P = 0;		//	アクティブをLOWにする
	RSPI0.SPCR2.BYTE=0x00;
	RSPI0.SPDCR.BYTE=0x00;
	RSPI0.SPPCR.BYTE = 0x30;		//	データを送信していないときHIGH
	RSPI0.SPSR.BYTE = 0x00;			//	ステータスをリセット
	//RSPI0.SPSR.BYTE = 0x00;
	RSPI0.SSLP.BIT.SSL0P = 0;
	RSPI0.SPSCR.BIT.SPSLN = 0;
	RSPI0.SPCKD.BIT.SCKDL = 0;
	RSPI0.SSLND.BIT.SLNDL = 0;
	RSPI0.SPND.BIT.SPNDL = 0;
	
	RSPI0.SPBR = 9;				//	250kHzで送信する
	RSPI0.SPCMD0.BIT.BRDV = 2;		//
	/*
	RSPI0.SPDCR.BYTE = 0x00;		//	初期化6
	RSPI0.SPCR2.BYTE = 0x00;		//	アイドル割り込みを禁止
	*/
/*	RSPI0.SPCMD0.BIT.LSBF = 1;
	RSPI0.SPCMD0.BIT.SPB = 7;
	RSPI0.SPCMD0.BIT.CPHA = 0;		//	分周を選択
	RSPI0.SPCMD0.BIT.CPOL = 1;
	RSPI0.SPCMD0.BIT.BRDV = 1;
	//RSPI0.SPCMD0.BIT.SSLA = 0;
	RSPI0.SPCMD0.BIT.SSLA = 1;
	/*RSPI0.SPCMD0.BIT.SSLKP = 1;
	RSPI0.SPCMD0.BIT.LSBF = 1;
	RSPI0.SPCMD0.BIT.SPNDEN = 0;
	RSPI0.SPCMD0.BIT.SLNDEN = 0;
	RSPI0.SPCMD0.BIT.SCKDEN = 0;*/
/*	ICU.IER[5].BIT.IEN4 = 0;
	ICU.IER[5].BIT.IEN5 = 0;
	ICU.IER[5].BIT.IEN6 = 0;
	ICU.IER[5].BIT.IEN7 = 0;
	ICU.IPR[44].BIT.IPR = 14;
	
	MPC.PWPR.BIT.B0WI =0;
	MPC.PWPR.BIT.PFSWE =1;
	MPC.PC7PFS.BIT.PSEL =0x0d;
	MPC.PC6PFS.BIT.PSEL =0x0d;
	MPC.PC5PFS.BIT.PSEL =0x0d;
	MPC.PC4PFS.BIT.PSEL =0x0d;
	PORTC.PMR.BIT.B7=1;
	PORTC.PMR.BIT.B6=1;
	PORTC.PMR.BIT.B5=1;
	PORTC.PMR.BIT.B4=1;
	MPC.PWPR.BIT.PFSWE = 0;
	MPC.PWPR.BIT.B0WI =1;
	RSPI0.SPSR.BYTE=0x00;
	RSPI0.SPCR.BIT.SPE=0;
	RSPI0.SPCR2.BIT.SPIIE=0;
	RSPI0.SPCR.BIT.SPEIE=0;
	RSPI0.SPCR.BIT.SPRIE=0;
	RSPI0.SPCR.BIT.SPTIE=0;
	RSPI0.SPDR;
	/*MSTP_RSPI0 = 0;
	IEN(RSPI0,SPEI0) = 0;			//	割り込み不許可
	IPR(RSPI0,SPEI0) = 10;			//	割り込みレベル10
*/		
}
void spi_start()
{
	//step1
	RSPI0.SPSR.BIT.MODF = 0;    //モードデフォルトエラーなし
	RSPI0.SPSR.BIT.OVRF = 0;    //オーバーランフラグなし
	RSPI0.SPSR.BIT.PERF = 0;	//パリティエラーなし
	
	//step2
	RSPI0.SPCR2.BIT.SPIIE = 0;  //アイドル割り込み要求の発生を禁止
	
	//step3
	IPR(RSPI0,SPTI0) = 0x01;    //割り込み優先度
	IEN(RSPI0,SPTI0) = 0x1;
	IR(RSPI0,SPTI0)  = 0x0;
    
	IPR(RSPI0,SPRI0) = 0x01;
	IEN(RSPI0,SPRI0) = 0x1;
	IR(RSPI0,SPRI0)  = 0x1;
	
	IPR(RSPI0,SPII0) = 0x08;
	IEN(RSPI0,SPII0) = 0x1;
	IR(RSPI0,SPII0)  = 0x1; 
	
	RSPI0.SPCR.BIT.SPTIE = 1;
	RSPI0.SPCR.BIT.SPRIE = 1;
	RSPI0.SPCR.BIT.SPEIE = 1;
//	RSPI0.SPCR.BIT.TXMD = 0;
	RSPI0.SPCR.BIT.SPE = 1;
	
}


/*
//送受信関数
void RSPI_PUTS(unsigned char *data,int data_num,unsigned char *return_p){
	int i=0;
	if(data_num == 0)return;	//データがなかったら抜ける
	if(RSPI0.SPSR.BIT.IDLNF == 1)return;
	RSPI0.SPDR.WORD.H = *data;
	for(i=0;data_num>i;i++){
		trans_byte[i]=*(data+i);
	}
	trans_byte_num=data_num=9;
	gp=return_p;
	RSPI0.SPSR.BYTE=0x00;
	RSPI0.SPCR2.BIT.SPIIE=0;	//1:アイドル割り込み要求を許可
	RSPI0.SPCR.BIT.SPEIE=1;		//1:RSPIエラー割り込み要求の発生を許可
	RSPI0.SPCR.BIT.SPRIE=1;		//1:RSPI受信割り込み要求の発生を許可
	RSPI0.SPCR.BIT.SPTIE=1;		//1:RSPI送信割り込み要求の発生を許可
	ICU.IER[5].BIT.IEN6=1;
	ICU.IER[5].BIT.IEN5=1;
	ICU.IER[5].BIT.IEN4=1;
	RSPI0.SPSR;
	RSPI0.SPSR.BYTE=0x00;
	while(1!=RSPI0.SPCR.BIT.SPTIE){		}
	RSPI0.SPCR.BIT.SPE=1;
	RSPI0.SPCR.BIT.SPRIE=1;
	ICU.IER[5].BIT.IEN5=1;
	
}*/
//受信割り込み
void zyusin()
{
	static unsigned int wp;
	RETURN_DATA[wp] = RSPI0.SPDR.WORD.H;
	wp++;
	if(wp>9)
	{
		wp=0;
		RSPI0.SPCR.BIT.SPRIE = 0;
	}
	
}
//送信割り込み関数

void sousin()
{
	static unsigned int rp;
	static char send[]={0x01,0x42,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	RSPI0.SPDR.WORD.H = send[rp];
	rp++;
	if(rp>=9){
		rp=0;
		RSPI0.SPCR.BIT.SPTIE = 0;
		RSPI0.SPCR2.BIT.SPIIE = 1;
	}
}

/*void int_rspi0_spti0(void){
	static int rp;
	RSPI0.SPDR.WORD.H = READ_DATA[rp];
	rp++;
	if(rp>=9){
		rp=0;
		RSPI0.SPCR.BIT.SPTIE = 0;
		RSPI0.SPCR2.BIT.SPIIE = 1;
		//sci1_puts("sousin\r\n");
	}
	/*static int num=0;
	unsigned char dummy;
	
	dummy=RSPI0.SPSR.BIT.IDLNF;
	RSPI0.SPDR.WORD.H=(unsigned short)trans_byte[num++];
	num++;
	if(num>=trans_byte_num){
		num=0;
		ICU.IER[5].BIT.IEN6 =0;
		ICU.IER[5].BIT.IEN7 =0;
		RSPI0.SPCR.BIT.SPTIE=0;
		RSPI0.SPCR2.BIT.SPIIE=0;
		while(0!=RSPI0.SPCR.BIT.SPTIE){}
		IR(RSPI0,SPTI0)=0;
		RSPI0.SPCR2.BIT.SPIIE=1;
		IEN(RSPI0,SPTI0)=0;
		while(RSPI0.SPSR.BIT.IDLNF==0);
		RSPI0.SPSR;
		RSPI0.SPSR.BYTE=0x00;

	}
}*/


/*
void int_rspi0_spri0(void){
	static int wp;
	RETURN_DATA[wp] = RSPI0.SPDR.WORD.H;
	wp++;
	if(wp>=9)
	{
		wp=0;
		RSPI0.SPCR.BIT.SPRIE = 0;
		//sci1_puts("zyusin\r\n");
	}
	/*static int i;
	unsigned char buf;
	
	RSPI0.SPDCR.BIT.SPRDTD=0;
	buf=(unsigned char)RSPI0.SPDR.WORD.H;
	get_data[i]=buf;
	RSPI0.SPCR.BIT.SPRIE=1;
	ICU.IER[5].BIT.IEN5=1;
	i++;
	if(i>=trans_byte_num){
		i=0;
		RSPI0.SPCR.BIT.SPRIE=0;
		ICU.IER[5].BIT.IEN5 =0;
		IEN(RSPI0,SPRI0)=0;
		while(0!=RSPI0.SPCR.BIT.SPRIE){	}
		IEN(RSPI0,SPEI0)=0;
		RSPI0.SPCR.BIT.SPEIE=0;
		while(0!=RSPI0.SPCR.BIT.SPRIE){	}
		IR(RSPI0,SPRI0)=0;	
	}
}*/
//アイドル割り込み

void idol_warikomi()
{
	RSPI0.SPCR2.BIT.SPIIE = 0;
	
	RSPI0.SPCR.BYTE = 0x08;
	
	IPR(RSPI0,SPTI0) = 0x0;
	IEN(RSPI0,SPTI0) = 0x0;
	IR(RSPI0,SPTI0)  = 0x0;
	
	IPR(RSPI0,SPRI0) = 0x0;
	IEN(RSPI0,SPRI0) = 0x0;
	IR(RSPI0,SPRI0) = 0x0;
	
	IPR(RSPI0,SPII0) = 0x0;
	IEN(RSPI0,SPII0) = 0x0;
	IR(RSPI0,SPII0) = 0x0;
	
	//sci1_puts("idol\r\n");
	//return 0;
}

/*void int_rspi0_spii0(void){
	RSPI0.SPCR2.BIT.SPIIE = 0;
	
	RSPI0.SPCR.BYTE = 0x08;
	
	IPR(RSPI0,SPTI0) = 0x0;
	IEN(RSPI0,SPTI0) = 0x0;
	IR(RSPI0,SPTI0)  = 0x0;
	
	IPR(RSPI0,SPRI0) = 0x0;
	IEN(RSPI0,SPRI0) = 0x0;
	IR(RSPI0,SPRI0) = 0x0;
	
	IPR(RSPI0,SPII0) = 0x0;
	IEN(RSPI0,SPII0) = 0x0;
	IR(RSPI0,SPII0) = 0x0;
	
	/*int i;
	
	RSPI0.SPCR.BIT.SPE =0;
	
	IEN(RSPI0,SPII0)=0;
	
	RSPI0.SPCR2.BIT.SPIIE=0;
	while(0!=RSPI0.SPCR2.BIT.SPIIE){}
	flag=1;
	for(i=0;i<=trans_byte_num;i++){
		*(gp+i)=get_data[i];
	}
	
}*/
//エラー割り込み関数
void int_rspi0_spei0(void){
	RSPI0.SPSR;
	RSPI0.SPSR.BYTE=0x00;
}

void PA_DATA()
{
	//setpsw_i();
	DATA = (RETURN_DATA[3] << 8) + RETURN_DATA[4];	
}


int joint_R(void){
	return	(RETURN_DATA[6])*0x100+RETURN_DATA[7];
}


int joint_L(void){
	return	RETURN_DATA[8]*0x100+RETURN_DATA[0];
}

int CONTLLOR(void){
	return (RETURN_DATA[4]*0x100+RETURN_DATA[5]);
}

