#include <cstdlib>
#include <math.h>
#define _RESOLUTION 1000
/*----------------------------------------------------------------\
// Display code works as follows:                                 |
//A3 Volt units -> A0 mills                                       |
//                                                                |
//              2                                                 |
//           #######                                              |
//        7  #     #  3                                           |  
//           #  8  #                                              |
//           #######                                              |
//           #     #                                              |
//        6  #     #  4                                           | 
//           ####### # <- 9                                       |
//              5                                                 |   
\----------------------------------------------------------------*/
float campioni = 0; //campioni di tensione
int tensione; //valore dela tensione

int SEG[8]={2, 3, 4, 5, 6, 7, 8, 9}; //array colonne
int Vp[4]={A3, A2, A1, A0}; //Tensione per ogni quadrante
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
  for(int i = 0; i <= 7; i++)
  {
    pinMode (SEG[i], OUTPUT);                
    digitalWrite (SEG[i],HIGH);             
  }
  for(int i = 0; i <= 4; i++)
  {
    pinMode (Vp[i], OUTPUT);               
    digitalWrite (Vp[i], LOW);             
  }
}

void loop() 
{
  for(int i = 0; i < _RESOLUTION; i++)                 
  {      
    campioni += (float)(analogRead(A5) * (float)(5.0 / 1.023));  
  }                                      
  tensione = (float)(campioni / _RESOLUTION);               
  campioni = 0;                         
  update();                              
}

void update()  
{  
  byte voltageFigures[4] = {tensione / 1000, (tensione % 1000) / 100, (tensione % 100) / 10, tensione % 10};
  for(int i = 0; i < 4; i++)
  {         
    for(int j = 0; j < 8; j++)
    {
      if(NMatrix[voltageFigures[i]][j])      
        digitalWrite(SEG[j], LOW);           
      else
        digitalWrite(SEG[j], HIGH);
      if(i == 1)
      {
        digitalWrite(SEG[7], LOW);
      }  
      digitalWrite (Vp[i], HIGH);      
      delay(2);
      digitalWrite (Vp[i], LOW);
    }     
  }
}

