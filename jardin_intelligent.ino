

#include "LED.h"
#include "Plantes.h"
#include "sensors.h"
#include"s_management.h"
#include "m_management.h"
#include <Arduino.h>

//Bouton poussoir pour choisir le type de plante 
#define  BoutonPin      D6


barette_LED BL;
temperature_sensor TS;
ecran_LED E;
moisture_sensor MS;


P_Tropical TROPICAL ;
P_Moderee MODEREE ;
P_Aride DESERT ;
//définition d'un tableau contenant les trois types de plantes possibles et d'un pointeur pour sélectionner 
int itplante = 0;
plante* tabplante[3]={&MODEREE,&DESERT,&TROPICAL};
//création des objets de management initiaux
s_management SM(&TS,&BL,&E,&TROPICAL);
m_management MM(&MS,&TROPICAL);

int buttonState ;

void setup(){
  pinMode(BoutonPin,INPUT); //définition du mode de pin pour le bouton poussoir
  //Initialisation de tous les capteurs et actionneurs
  MM.PompeInit();
  SM.LEDinit();
  SM.ECRANinit();
  SM.LEDmanagement();
  SM.ECRANmanagement();
}



void loop(){
// A chaque appui, on change de plante 
  buttonState = digitalRead(BoutonPin);

  if (buttonState==1){


    if (itplante != 2){itplante++;}
    else {itplante=0;}

    SM.setplante(tabplante[itplante]);
    MM.setplante(tabplante[itplante]);

    }
 //A chaque boucle on actualise les capteurs et les actionneurs
    SM.LEDmanagement();
    SM.ECRANmanagement();
    MM.ComPompe();
  
  }
  

