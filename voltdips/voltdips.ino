#include <cstdlib>
#include <math.h>
#include <LiquidCrystal.h>
#define _RESOLUTION 1000
/*----------------------------------------------------------------\
// Display code works as follows:                                 |
//                                                                |
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
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
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
  lcd.begin(16, 2);
  pinMode (9,OUTPUT); //puntino
  for(int i = 0; i <= 7; i++)
  {
    pinMode (SEG[i], OUTPUT);                //abilito pin segmenti
    digitalWrite (SEG[i],HIGH);              //livello iniziale segmenti 1
  }
  for(int i = 0; i <= 4; i++)
  {
    pinMode (Vp[i], OUTPUT);                 //abilito pin alimentazioni
    digitalWrite (Vp[i], LOW);               //livello iniziale 0
  }
}

void loop() 
{
  for(int i = 0; i < _RESOLUTION; i++)                 //ciclo da 20
  {      
    campioni += (float)(analogRead(A5) * (float)(5.0 / 1.023));  
  }                                      
  tensione = (float)(campioni / _RESOLUTION);               
  campioni = 0;                         
  update();                              
}

void update()
{
  delay(10);
  lcd.clear();
  lcd.print(tensione / _RESOLUTION);  
  lcd.write('.');
  lcd.print(tensione % _RESOLUTION);
}

/*void update()  
{  
  byte voltageFigures[3] = {tensione / 100, };   
  for(int i = 0; i < 4; i++)
  {
    digitalWrite (Vp[i], HIGH);     
    for(int j = 0; j < 8; j++)
    {
      if(NMatrix[voltageFigures[i]][j])      
        digitalWrite(SEG[j], LOW);           
      else
        digitalWrite(SEG[j], HIGH);
        delay(1);
        digitalWrite (Vp[i], LOW);
    }     
  }
}

*/
