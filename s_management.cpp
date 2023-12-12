#include"s_management.h"
#include "LED.h"
#include "Plantes.h"
#include "sensors.h"

//class s_management
  s_management::s_management(temperature_sensor* s,  barette_LED* b, ecran_LED* e, plante* p){
    this->sensorTH=s;
    this->barette=b;
    this->ecran=e;
    this->pl=p;
  }
  void s_management::LEDinit(){
    this->sensorTH->init();
    this->barette->refresh();

  }
  void s_management::LEDmanagement(){
    sensorTH->actualise_sensor();
    if (sensorTH->getvalue_sensorT()<10.0){barette->setNbLED_ON(1);}
    else if (sensorTH->getvalue_sensorT()>30.0){barette->setNbLED_ON(NUMPIXELS);}
    else{
      int a = (int)((sensorTH->getvalue_sensorT()-10)/2.5);
      barette->setNbLED_ON(a+1);
    }
    if ((sensorTH->getvalue_sensorT())<(pl->getTmin())){barette->setcolor(blue);}
    else if ((sensorTH->getvalue_sensorT())>(pl->getTmax())){barette->setcolor(red);}
    else {barette->setcolor(green);}
    barette->refresh();
  }
 void  s_management::ECRANinit(){
    this->ecran->setdim (20,1);

  }

  void  s_management::ECRANmanagement() {
    char color;
    if (pl->gettype()=="TROPICAL"){color=red;}
    else if (pl->gettype()=="MODEREE"){color=green;}
    else if (pl->gettype()=="ARIDE"){color=orange;}
    sensorTH->actualise_sensor();
    String hum = (String) sensorTH->getvalue_sensorH();
    String m = pl->gettype()+" hum:"+hum;
    ecran->setecran(m,color);
    ecran->refresh();
  }

  void  s_management::setplante (plante* p){
    this->pl=p;
  }


