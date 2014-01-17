#include <cstdlib>
#include <math.h>
int SEG[8]={2,3,4,5,6,7,8,9}; //array colonne
int Vp[4]={A3,A2,A1,A0}; //Tensione per ogni quadrante
int campioni=0; //campioni di tensione
int i;
int x;
int tensione; //valore dela tensione
void setup() {
  pinMode (9,OUTPUT); //puntino
  for (x=0;x<=7;x++)
{
  pinMode (SEG[x], OUTPUT);  //abilito pin segmenti
  digitalWrite (SEG[x],HIGH); //livello iniziale segmenti 1
}
for (x=0;x<=4;x++)
{
  pinMode (Vp[x], OUTPUT); //abilito pin alimentazioni
  digitalWrite (Vp[x], LOW); //livello iniziale 0
}
}

void loop() {
  for (i=0;i<10;i++) //ciclo da 20
  {
  int sensorValue = analogRead(A5); //prendo il valore da A5
  float volt = sensorValue * (5.0 / 1023.0); //metto in scala 0-5V
  campioni=campioni+(volt*100); //converto da float x.xx in xxx e raccolgo 20 campioni
  }//Serve ad evitare eccessive oscillazioni di tensione
  tensione=campioni/10; //media dei valori
  campioni=0; //rimetto i campioni a 0 per ripetere il tutto
  USCITA (); //funzione per portare in uscita il valore di temp.
}

void USCITA ()
{
  VOLT1 (); //primo quadrante (0.0x)
  VOLT2 (); //secondo quadrante (0.x0)
  VOLT3 (); //terzo quadrante (x.00)
}
void VOLT1 () //primo quadrante (0.0x)
{
  digitalWrite (Vp[0],HIGH); //abilito primo quadrante
  if (tensione%10==0) //Ex. 123%10=3 (valore per primo quadrante)
  {
    ZERO();
  }
  if (tensione%10==1)
  {
    UNO();
  }
  if (tensione%10==2)
  {
    DUE();
  }
  if (tensione%10==3)
  {
    TRE();
  }
  if (tensione%10==4)
  {
    QUATTRO();
  }
  if (tensione%10==5)
  {
    CINQUE();
  }
  if (tensione%10==6)
  {
    SEI();
  }
  if (tensione%10==7)
  {
    SETTE();
  }
  if (tensione%10==8)
  {
    OTTO();
  }
  if (tensione%10==9)
  {
    NOVE();
  }
   digitalWrite(Vp[0],LOW);
}

void VOLT2 () //secondo quadrante (x.1x)
{
  digitalWrite (Vp[1],HIGH);
  if ((tensione%100)/10==0) //Ex. 123%100=23, 23/10=2 secondo quadrante)
  {
    ZERO();
  }
  if ((tensione%100)/10==1)
  {
    UNO();
  }
  if ((tensione%100)/10==2)
  {
    DUE();
  }
  if ((tensione%100)/10==3)
  {
    TRE();
  }
  if ((tensione%100)/10==4)
  {
    QUATTRO();
  }
  if ((tensione%100)/10==5)
  {
    CINQUE();
  }
  if ((tensione%100)/10==6)
  {
    SEI();
  }
  if ((tensione%100)/10==7)
  {
    SETTE();
  }
  if ((tensione%100)/10==8)
  {
    OTTO();
  }
  if ((tensione%100)/10==9)
  {
    NOVE();
  }
  digitalWrite (Vp[1],LOW);
}

void VOLT3 () //terzo quadrante (x.00)
{
  digitalWrite (Vp[2],HIGH);
  digitalWrite (9,LOW); //puntino
  if (tensione/100==0) //Ex. 123/100=1 terzo quadrante
  {
    ZERO();
  }
  if (tensione/100==1)
  {
    UNO();
  }
  if (tensione/100==2)
  {
    DUE();
  }
  if (tensione/100==3)
  {
    TRE();
  }
  if (tensione/100==4)
  {
    QUATTRO();
  }
  if (tensione/100==5)
  {
    CINQUE();
  }
  if (tensione/100==6)
  {
    SEI();
  }
  if (tensione/100==7)
  {
    SETTE();
  }
  if (tensione/100==8)
  {
    OTTO();
  }
  if (tensione/100==9)
  {
    NOVE();
  }
  digitalWrite (Vp[2],LOW);
  digitalWrite (9,HIGH);
}  

//FUNZIONI PER I NUMERI
void ZERO ()
{
  ON(0);
  ON(1);
  ON(2);
  ON(3);
  ON(4);
  ON(5);
}

void UNO ()
{
  ON(1);
  ON(2);
}

void DUE ()
{
  ON(0);
  ON(1);
  ON(3);
  ON(4);
  ON(6);
}

void TRE ()
{
  ON(0);
  ON(1);
  ON(2);
  ON(3);
  ON(6);
}

void QUATTRO ()
{
  ON(1);
  ON(2);
  ON(5);
  ON(6);
}

void CINQUE ()
{
  ON(0);
  ON(2);
  ON(3);
  ON(5);
  ON(6);
}

void SEI ()
{
  ON(0);
  ON(2);
  ON(3);
  ON(4);
  ON(5);
  ON(6);
}

void SETTE ()
{
  ON(0);
  ON(1);
  ON(2);
}

void OTTO ()
{
  ON(0);
  ON(1);
  ON(2);
  ON(3);
  ON(4);
  ON(5);
  ON(6);
}
void NOVE ()
{
  ON(0);
  ON(1);
  ON(2);
  ON(3);
  ON(5);
  ON(6);
}
  
void ON (int s) //funzione per i segmenti
{
  digitalWrite (SEG[s],LOW);
  delay(1);
  digitalWrite (SEG[s],HIGH);
}
