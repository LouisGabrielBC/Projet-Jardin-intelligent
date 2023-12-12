

#include "LED.h"
#include "Plantes.h"
#include "sensors.h"
#include"s_management.h"
#include "m_management.h"
#include <Arduino.h>

#define  BoutonPin      D6

barette_LED BL;
temperature_sensor TS;
ecran_LED E;
moisture_sensor MS;


P_Tropical TROPICAL ;
P_Moderee MODEREE ;
P_Aride DESERT ;

int itplante = 0;
plante* tabplante[3]={&MODEREE,&DESERT,&TROPICAL};
s_management SM(&TS,&BL,&E,&TROPICAL);
m_management MM(&MS,&TROPICAL);

int buttonState ;

void setup(){
  pinMode(BoutonPin,INPUT);
  Serial.begin(9600);
  MM.PompeInit();
  SM.LEDinit();
  SM.ECRANinit();
  SM.LEDmanagement();
  SM.ECRANmanagement();
}



void loop(){

  buttonState = digitalRead(BoutonPin);

  if (buttonState==1){


    if (itplante != 2){itplante++;}
    else {itplante=0;}

    SM.setplante(tabplante[itplante]);
    MM.setplante(tabplante[itplante]);

    }

    SM.LEDmanagement();
    SM.ECRANmanagement();
    MM.ComPompe();
  
  }
  

