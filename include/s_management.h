#ifndef s_management_h
#define s_management_h

#include "sensors.h"
#include <Arduino.h>
#include "LED.h"
#include "Plantes.h"

//la classe s_management indique à la barette et à l'écran ce qu'ils doivent afficher en fonction de la température et de l'humidité captées par le capteursT&H ainsi que par la plante qui lui est attribuée

class s_management{
  private:
    temperature_sensor* sensorTH;
    barette_LED* barette;
    ecran_LED* ecran;
    plante*  pl;

  public:
    s_management(temperature_sensor* s,  barette_LED* b, ecran_LED* e, plante* p);

    void LEDinit();
    void LEDmanagement();//on indique le nombre de led à allumées, la couleur puis on refresh

    void ECRANinit();
    void ECRANmanagement();//on construit et on indique le message à afficher, on donne la couleur puis on refresh

    void setplante (plante* p);//on peut changer la plante n'importe quand
};

#endif
