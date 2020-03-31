// Sistema de telemetria integrado - Respirador mecânico
// Autor: Fellipy Kühne 
// Data de modificação 30/03/2020
// Em desenvolvimento

#include "U8glib.h"
#include "HX711.h"                     
#define DOUT  A0                      
#define CLKP  A1 

HX711 balanca;
float calibration_factor = 42130;

U8GLIB_ST7920_128X64_1X u8g(6, 5, 4 ,7); //Enable, RW, RS, RESET  
int display = 1; 

/////////////////////////////////////////////Variáveis de setup/////////////////////////////////
const int pinoCLK = 9;                                                  //PINO DIGITAL (CLK)
const int pinoDT = 8;                                                  //PINO DIGITAL (DT)
const int pinoSW = 10;                                                //PINO DIGITAL (SW)
int ultPosicao;                                                      //REGISTRA A ÚLTIMA POSIÇÃO DO ENCODER
int leituraCLK;                                                       //VARIÁVEL PARA ARMAZENAR LEITURA DO PINO CLK
int buzzer = 11;                                                     //Saída buzzer
int offsetVol=5.55;                                                  // Offset de tolerancia de ar
float tIns=0.00;
float rInv=0.00;
float blend=0.00;
int fr=0;
int vol=0;
int count = 0;
float contadorPosD=0.00;
int pressao;


int displayOld=0;
////////////////////////////////////////////////Variáveis de sensoriamento////////////////////



////////////////////////////////////////////////Funções de calculo////////////////////////


float leitura_encoder(float minimo, float maximo, float incr){
  //contadorPosD=var;
  leituraCLK = digitalRead(pinoCLK); //VARIÁVEL RECEBE A LEITURA DO PINO CLK
  if (leituraCLK != ultPosicao){ //SE VALOR DA VARIÁVEL FOR DIFERENTE DO VALOR DE "ultPosicao", FAZ
     if (digitalRead(pinoDT) != leituraCLK) { //SE LEITURA DO PINO FOR DIFERENTE DA LEITURA DE "leituraCLK",
      //SIGNIFICA QUE O EIXO ESTÁ SENDO GIRADO NO SENTIDO HORÁRIO E FAZ
       if( contadorPosD<maximo-incr){
       contadorPosD=contadorPosD+incr; //INCREMENTA CONTAGEM DA VARIÁVEL EM +1
       //bCW = true; //VARIÁVEL BOOLEANA RECEBE VERDADEIRO (SENTIDO HORÁRIO)
       }
     } else if (digitalRead(pinoDT) == leituraCLK) {
        if(contadorPosD>minimo+incr){//SENÃO, SIGNIFICA QUE O EIXO ESTÁ SENDO GIRADO NO SENTIDO ANTI-HORÁRIO E FA
       contadorPosD=contadorPosD-incr; //DECREMENTA CONTAGEM DA VARIÁVEL EM -1
        }
     }
  }
  return(contadorPosD);
}

//////////////////////////////////////////////// Impressão em tela///////////////////////   

void u8g_prepare() 
{  
  u8g.setFont(u8g_font_6x10);  
  u8g.setFontRefHeightExtendedText();  
  u8g.setDefaultForegroundColor();  
  u8g.setFontPosTop();  
}  
   
void u8g_Tela1()  
{
  u8g.setFont(u8g_font_unifont);  
  u8g.drawStr( 11, 35, "CITI-OpenLung");  
  u8g.drawStr( 12, 35, "CITI-OpenLung");  
  u8g.drawFrame(0,0,128,64);  
  u8g.drawFrame(2,2,124,60);   
  
}  
   
void u8g_Tela2() 
{
  u8g.setFont(u8g_font_unifont);  
  u8g.drawStr( 11, 20, "Blender (O2):");  
  u8g.drawStr( 12, 20, "Blender (O2):");  
  u8g.drawFrame(0,0,128,64);  
  u8g.drawFrame(2,2,124,60);   
  blend=leitura_encoder(0.00,1.00,0.01);
  u8g.setPrintPos(11, 40);
  u8g.print(blend);
  
}  
   
void u8g_Tela3()   
{
  u8g.setFont(u8g_font_unifont);  
  u8g.drawStr( 11, 20, "Volume (ml):");  
  u8g.drawStr( 12, 20, "Volume (ml):");  
  u8g.drawFrame(0,0,128,64);  
  u8g.drawFrame(2,2,124,60);
  vol=leitura_encoder(0,1000,1);
  u8g.setPrintPos(11, 40);
  u8g.print(vol);
  
}  
   
void u8g_Tela4()  
{
  u8g.setFont(u8g_font_unifont);  
  u8g.drawStr( 11, 20, "T. Insp (s):");  
  u8g.drawStr( 12, 20, "T. Insp (s):");  
  u8g.drawFrame(0,0,128,64);  
  u8g.drawFrame(2,2,124,60);
  tIns = leitura_encoder(0.00,5.00,0.10);
  u8g.setPrintPos(11, 40);
  u8g.print(tIns);
}  
   
void u8g_Tela5()  
{
  u8g.setFont(u8g_font_unifont);  
  u8g.drawStr( 5, 20, "F. Resp (R/min):");  
  u8g.drawStr( 6, 20, "F. Resp (R/min):");   
  u8g.drawFrame(0,0,128,64);  
  u8g.drawFrame(2,2,124,60); 
  fr=leitura_encoder(0,150,1);
  u8g.setPrintPos(11, 40);
  u8g.print(fr); 
}   



void u8g_Tela6()   
{
  u8g.drawFrame(0,0,128,64);  
  u8g.drawFrame(2,2,124,60);
  u8g.drawHLine(2,30, 124);
  u8g.drawVLine(62,2, 60);
  u8g.setPrintPos(5, 4);
  u8g.print("Blend O :"); 
  u8g.setPrintPos(46, 7);
  u8g.print("2"); 
  u8g.setPrintPos(37, 20);
  u8g.print(blend); 
  u8g.setPrintPos(5, 20);
  u8g.print(blend); 


  u8g.setPrintPos(5, 32);
  u8g.print("Volume:");
  u8g.setPrintPos(5, 50);
  u8g.print(vol); 
  u8g.setPrintPos(37, 50);
  u8g.print(vol); 
  
  u8g.setPrintPos(65, 4);
  u8g.print("T insp.:");
  u8g.setPrintPos(65, 20);
  u8g.print(tIns); 
  u8g.setPrintPos(97, 20);
  u8g.print(tIns);

  u8g.setPrintPos(65, 32);
  u8g.print("F resp.:");
  u8g.setPrintPos(65, 50);
  u8g.print(fr);
  u8g.setPrintPos(97, 50);
  u8g.print(fr);
  //pressao=pressureRead();
}   

   void u8g_Tela8()  
{
  u8g.setFont(u8g_font_unifont);  
  u8g.drawStr( 11, 35, "Pressao Pulm.");  
  //u8g.drawStr( 12, 35, "Pressão Pulm.");  
  u8g.drawFrame(0,0,128,64);  
  u8g.drawFrame(2,2,124,60);
  //digitalWrite(buzzer,HIGH);   
  
} 
void draw() //Rotina Desenho  
{
  u8g_prepare();  
  switch(display) //Carrega a tela correspondente  
  {
   case 1:  
    u8g_Tela1();  
    break;  
   case 2:  
    u8g_Tela2();
    break;  
   case 3:  
    u8g_Tela3();  
    break;  
   case 4:  
    u8g_Tela4();  
    break;  
   case 5:  
    u8g_Tela5();  
    break;  
   case 6:  
    u8g_Tela6();  
    break; 
   case 8:  
    u8g_Tela8();  
    break;
  }  
}  


////////////Sensor de pressao/////////////////////////

void setup() 
{  
   Serial.begin (9600); //INICIALIZA A SERIAL
  
   pinMode (pinoCLK,INPUT); //DEFINE O PINO COMO ENTRADA
   pinMode (pinoDT,INPUT); //DEFINE O PINO COMO ENTRADA
   pinMode (pinoSW,INPUT_PULLUP); //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
   pinMode(buzzer,OUTPUT);
   ultPosicao = digitalRead(pinoCLK); //VARIÁVEL RECEBE A LEITURA DO PINO CLK 
  // assign default color value  
  if ( u8g.getMode() == U8G_MODE_R3G3B2 )   
   u8g.setColorIndex(255);   // white  
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT )  
   u8g.setColorIndex(1);     // max intensity  
  else if ( u8g.getMode() == U8G_MODE_BW )  
   u8g.setColorIndex(1);     // pixel on    

   //u8g.begin();
   balanca.begin(DOUT, CLKP);                          // inicializa a balança
   Serial.println("Balança com HX711 - celula de carga 50 Kg");            
   Serial.println("Pressione t para Tara");           // imprime no monitor serial
   balanca.set_scale(calibration_factor);             // ajusta fator de calibração
   balanca.tare();  // zera a Balança
    
  
}  
   
void loop() 
{    
  
  if(digitalRead(pinoSW) == LOW ){
    if  (digitalRead(buzzer) == LOW){
    u8g.firstPage();   
    do 
    {  
    draw();
    } 
    while( u8g.nextPage() );
    display++;
    delay(100);
    contadorPosD=0.00;
  }
  }
  else{
     u8g.firstPage();   
    do 
    {  
    draw();
    } 
    while( u8g.nextPage() );
    delay(50);
  }
  
  if(display==7) display=2;

  
  Serial.print("Peso: ");                            // imprime no monitor serial
  Serial.print(balanca.get_units(), 3);              // imprime peso na balança com 3 casas decimais 
  float unidade=balanca.get_units();
  Serial.println(" kg");                             // imprime no monitor serial 
  //delay(500) ;                                       // atraso de 0,5 segundos 

   if (unidade>7.0){                                  //cond alarme
    digitalWrite(buzzer,HIGH);
    Serial.println("PRESSAO PULMONAR ALTA!!");
    while(digitalRead(pinoSW) == HIGH) {
      display=8;
      u8g.firstPage();   
        do 
      {  
      draw();
      } 
      while( u8g.nextPage() );
      delay(50);
      if(digitalRead(pinoSW) == LOW) {
        digitalWrite(buzzer,LOW);
        display=5;
      }
    }
  }
 digitalWrite(buzzer,LOW);
 }

  
