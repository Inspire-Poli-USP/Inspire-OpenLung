// Sistema de telemetria integrado - Respirador mecânico
// Autor: Fellipy Kühne
// Data de modificação 04/04/2020
//
// Implementações desde a versão anterior:
// - Corrigido a falta de sensibilidade no modulo encoder;
// - Implementado sensores de pressão mais precisos;
// - Saída analogica para controle de avanço do motor para o clp;
// - Contador-temporizador correto;
// - Acionamento das valvuas de inspiração, expiração e backup;
// 
// Itens a fazer:
// - Armazenar os valores nas variaveis quando retornar as configurações;
// - Corrigir bug, que faz imprimir a tela 4 antes da tela 5 quando entra em alarme de pressao pulmonar;
// - Imprimir o valor máximo quando rotaciona o encoder no sentido anti-horario na posicao minima;
// - Implementar saída analogica para controle de velocidade de avanço;
// - Implementar saída analogica para controle de velocidade de recuo;
// - Desligar as valvulas de inspiração/expiracao e ligar a valvula de backup quando estiver em pressao pulmonar alta;
// 
// Em desenvolvimento....  


#include "U8glib.h"



unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 1000; // 1000 ms = 1s


U8GLIB_ST7920_128X64_1X u8g(6, 5, 4 , 7); //Enable, RW, RS, RESET
int display = 1;

/////////////////////////////////////////////Variáveis de setup/////////////////////////////////

volatile unsigned int encoderPos = 0;  // a counter for the dial
unsigned int lastReportedPos = 1;   // change management
static boolean rotating = false;    // debounce management
int c = 0;
boolean A_set = false;
boolean B_set = false;

//____________________________________________________//

const int pinoCLK = 2;                                                  //PINO DIGITAL (CLK) - ENCODER
const int pinoDT = 1;                                                  //PINO DIGITAL (DT)  - ENCODER
const int pinoSW = 10;                                                 // PINO DIGITAL (SW) - ENCODER
int buzzer = 8;                                                       //Saída buzzer
const int analogPressure = A1;                                        // SENSOR PRESSAO ANALOGICO - NXP MPX 5700DP
int pressureRead = 0 ;                                                //Variavel que armazena leitura analogica do sensor (0~1023)
int pressureValue = 0 ;                                               //Variável que converte a leitura do sensor para (0~7bar)
float unidade = 0.00;
const int avanco = 9;
int insValve = 11;
int exValve = 12;
int bckpValve = 13;
int countDisp = 0;
int countDisp2 = 0;
int countResp = 0;
int countExp = 0;
int set = 0;                                                          //PINO DIGITAL (SW)
int ultPosicao;                                                      //REGISTRA A ÚLTIMA POSIÇÃO DO ENCODER
int leituraCLK;                                                       //VARIÁVEL PARA ARMAZENAR LEITURA DO PINO CLK

////////////////////////////////////////////////Variáveis de sensoriamento////////////////////

float tIns = 0.00;
int cIns = 0;
int rInv = 0;
int blend = 0;
int fr = 0;
int vol = 0;
int count = 0;
float contadorPosD = 0.00;
int pressao;

////////////////////////////////////////////////Funções de calculo////////////////////////
//void calculaAvanco( int volumeSetado){
 // int conversao = 0.255*volumeSetado;
  //analogWrite(avanco, conversao);
  //Serial.println(conversao);
//}

int encoderRot(int minimo, int maximo) {
  rotating = true;  // reset the debouncer
  if (minimo > encoderPos) encoderPos = minimo;
  //if (lastReportedPos == encoderPos && lastReportedPos == 0) encoderPos=maximo;
  if (lastReportedPos != encoderPos) {
    if (encoderPos > maximo) encoderPos = minimo;
    lastReportedPos = encoderPos;

  }
  return encoderPos;
}

float lePressao() {
  // read the analog in value:
  pressureRead = analogRead(analogPressure);
  // map it to the range of the analog out:
  pressureValue = map(pressureRead, 0, 1023, 0, 1020);


  // print the results to the Serial Monitor:
  //Serial.print("sensor = ");
  //Serial.print(pressureRead);
  //Serial.print("\t output = ");
  //Serial.println(pressureValue);
  return (pressureValue);
}

int fluxoResp(float ins, int rmin) {
  if (set == 0) {
    digitalWrite(insValve, LOW);
    digitalWrite(exValve, LOW);
    digitalWrite(bckpValve, HIGH);
  }
  else if ((ins != 0) && (rmin != 0) && (set != 0) && (countResp <= (11 * ins))) {
    digitalWrite(bckpValve, LOW);///condicao de inspiracao
    digitalWrite(insValve, HIGH);
    digitalWrite(exValve, LOW);
    countResp++;
  }
  else if ((ins != 0) && (rmin != 0) && (set != 0) && (countResp > (11 * ins))) {
    digitalWrite(bckpValve, LOW);///condicao de expiracao
    digitalWrite(insValve, LOW);
    digitalWrite(exValve, HIGH);
    countExp++;
    if (countExp > (((60 - (rmin * ins)) / rmin)*11)) {
      countResp = 0;
      countExp = 0;
    }
  }
  return 0;
}

//////////////////////////////////////////////// Impressão em tela///////////////////////


void doPinoCLK() {
  // debounce
  if ( rotating );// delay (1);  // wait a little until the bouncing is done
  // Test transition, did things really change?
  if ( digitalRead(pinoCLK) != A_set ) { // debounce once more
    A_set = !A_set;

    // adjust counter + if A leads B
    if ( A_set && !B_set )
      encoderPos += 1;

    rotating = false;  // no more debouncing until loop() hits again
  }

}

void doPinoDT() {

  if ( rotating );// delay (1);
  if ( digitalRead(pinoDT) != B_set ) {
    B_set = !B_set;
    //  adjust counter - 1 if B leads A
    if ( B_set && !A_set )
      encoderPos -= 1;

    rotating = false;
  }

}

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
  u8g.drawFrame(0, 0, 128, 64);
  u8g.drawFrame(2, 2, 124, 60);
}

void u8g_Tela2()
{
  set = 0;
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 11, 20, "Blender (O2):");
  u8g.drawStr( 12, 20, "Blender (O2):");
  u8g.drawFrame(0, 0, 128, 64);
  u8g.drawFrame(2, 2, 124, 60);
  blend = encoderRot(21, 100);
  u8g.setPrintPos(11, 40);
  u8g.print(blend);


}

void u8g_Tela3()
{
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 11, 20, "Volume (ml):");
  u8g.drawStr( 12, 20, "Volume (ml):");
  u8g.drawFrame(0, 0, 128, 64);
  u8g.drawFrame(2, 2, 124, 60);
  u8g.setPrintPos(11, 40);
  u8g.print(vol);
  vol = encoderRot(0, 100);
  vol = vol * 10;

}

void u8g_Tela4()
{

  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 11, 20, "T. Insp (s):");
  u8g.drawStr( 12, 20, "T. Insp (s):");
  u8g.drawFrame(0, 0, 128, 64);
  u8g.drawFrame(2, 2, 124, 60);
  u8g.setPrintPos(11, 40);
  u8g.print(tIns);
  cIns = encoderRot(0, 500);
  tIns = cIns / 100.00;

  //u8g.print(tIns);

}

void u8g_Tela5()
{
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 5, 20, "F. Resp (R/min):");
  u8g.drawStr( 6, 20, "F. Resp (R/min):");
  u8g.drawFrame(0, 0, 128, 64);
  u8g.drawFrame(2, 2, 124, 60);

  u8g.setPrintPos(11, 40);
  u8g.print(fr);
  fr = encoderRot(0, 30);
}



void u8g_Tela6()
{

  u8g.drawFrame(0, 0, 128, 64);
  u8g.drawFrame(2, 2, 124, 60);
  u8g.drawHLine(2, 30, 124);
  u8g.drawVLine(62, 2, 60);
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

}

void u8g_Tela8()
{
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 11, 35, "Pressao Pulm.");
  u8g.drawFrame(0, 0, 128, 64);
  u8g.drawFrame(2, 2, 124, 60);
}
void draw() //Rotina Desenho
{
  u8g_prepare();
  switch (display) //Carrega a tela correspondente
  {
    case 1:
      set = 0;
      u8g_Tela1();
      break;
    case 2:
      set = 0;
      u8g_Tela2();

      break;
    case 3:
      set = 0;
      u8g_Tela3();
      break;
    case 4:
      set = 0;
      u8g_Tela4();
      break;
    case 5:
      set = 0;
      u8g_Tela5();
      break;
    case 6:
      set = 1;
      u8g_Tela6();
      break;
    case 8:
      set = 0;
      u8g_Tela8();
      break;
  }
}




////////////Sensor de pressao/////////////////////////

void setup()
{

  startMillis = millis();  //initial start time
  pinMode (analogPressure, INPUT);
  pinMode (insValve, OUTPUT);
  pinMode (exValve, OUTPUT);
  pinMode (bckpValve, OUTPUT);
  pinMode (pinoCLK, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode (pinoDT, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode (pinoSW, INPUT_PULLUP); //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
  pinMode(buzzer, OUTPUT);
  pinMode (avanco, OUTPUT);
  digitalWrite(pinoCLK, HIGH);
  digitalWrite(pinoDT, HIGH);
  digitalWrite(pinoSW, HIGH);




  // encoder pin on interrupt 0 (pin 2)
  attachInterrupt(0, doPinoCLK, CHANGE);
  // encoder pin on interrupt 1 (pin 3)
  attachInterrupt(1, doPinoDT, CHANGE);

  //ultPosicao = digitalRead(pinoCLK); //VARIÁVEL RECEBE A LEITURA DO PINO CLK

  Serial.begin (9600); //INICIALIZA A SERIAL
  if ( u8g.getMode() == U8G_MODE_R3G3B2 )
    u8g.setColorIndex(255);   // white
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT )
    u8g.setColorIndex(1);     // max intensity
  else if ( u8g.getMode() == U8G_MODE_BW )
    u8g.setColorIndex(1);     // pixel on
}





void loop()
{
  int conversao = 0.255*vol;
  analogWrite(avanco, conversao);
  //Serial.println(currentMillis);
  //Serial.print( " ");
  //Serial.print(conversao);
  //calculaAvanco(vol);
  currentMillis = millis();
  if (currentMillis - startMillis >= period)
  {
    /* Do stuff */
    startMillis = currentMillis;
  }

  int respira = fluxoResp(tIns, fr);
  if (digitalRead(pinoSW) == LOW ) {
    if (countDisp2 > 11 - 1) { //temporizador entre telas
      countDisp2 = 0;
      c = 0;
      if  (digitalRead(buzzer) == LOW) {
        u8g.firstPage();
        do
        {
          draw();
        }
        while ( u8g.nextPage() );

        display++;

      }
    }
  }
  else {
    u8g.firstPage();
    do
    {
      draw();
    }
    while ( u8g.nextPage() );
    countDisp2++;
    if (c == 0) {
      encoderPos = 0;
      c++;
    }

  }

  if (display == 7) display = 2;
  unidade = lePressao();
  if (unidade > 350) {                               //cond alarme
    digitalWrite(buzzer, HIGH);
    Serial.println("PRESSAO PULMONAR ALTA!!");
    while (digitalRead(pinoSW) == HIGH) {
      display = 8;
      u8g.firstPage();
      do
      {
        draw();
      }
      while ( u8g.nextPage() );
      countDisp2++;
      if (digitalRead(pinoSW) == LOW) {
        set = 0;
        display = 5;
      }
    }
    digitalWrite(buzzer, LOW);
  }
  Serial.println(unidade);

}
