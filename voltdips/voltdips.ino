#include <cstdlib>
#include <math.h>

int campioni=0; //campioni di tensione
int i;
int x;
int tensione; //valore dela tensione

int SEG[8]={2,3,4,5,6,7,8,9}; //array colonne
int Vp[4]={A3,A2,A1,A0}; //Tensione per ogni quadrante

boolean NMatrix[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0},  //0
  {0, 1, 1, 0, 0, 0, 0, 0},  //1
  {1, 1, 0, 1, 1, 0, 1, 0},  //2
  {1, 1, 1, 1, 0, 0, 1, 0},  //3
  {0, 1, 1, 0, 0, 1, 1, 0},  //4 
  {1, 0, 1, 1, 0, 1, 1, 0},  //5
  {0, 0, 1, 1, 1, 1, 1, 0},  //6
  {1, 1, 1, 0, 0, 0, 0, 0},  //7
  {1, 1, 1, 1, 1, 1, 1, 0},  //8
  {1, 1, 1, 1, 0, 1, 1, 0}}; //9
  
void setup() 
{
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

void loop() 
{
  for (i=0;i<10;i++) //ciclo da 20
  {
  int sensorValue = analogRead(A5); //prendo il valore da A5
  float volt = sensorValue * (5.0 / 1023.0); //metto in scala 0-5V
  campioni = campioni + (volt * 100); //converto da float x.xx in xxx e raccolgo 20 campioni
  }//Serve ad evitare eccessive oscillazioni di tensione
  tensione = campioni / 10; //media dei valori
  campioni = 0; //rimetto i campioni a 0 per ripetere il tutto
  update(); //funzione per portare in uscita il valore di temp.
}

void update()  
{  
  byte voltageFigures[3] = {};   
  for(int i = 0; i < 6; i++)
  {
    digitalWrite (Vp[i], HIGH);     
    for(int j = 0; j < 8; j++)
    {
      if(NMatrix[timeFigures[i]][j])      
        digitalWrite(SEG[j], LOW);           
      else
        digitalWrite(SEG[j], HIGH);
        delay(1);
        digitalWrite (Vp[i], LOW);
    }     
  }
}


