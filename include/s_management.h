#ifndef s_management_h
#define s_management_h

#include "sensors.h"
#include <Arduino.h>
#include "LED.h"
#include "Plantes.h"


class s_management{
  private:
    temperature_sensor* sensorTH;
    barette_LED* barette;
    ecran_LED* ecran;
    plante*  pl;

  public:
    s_management(temperature_sensor* s,  barette_LED* b, ecran_LED* e, plante* p);

    void LEDinit();
    void LEDmanagement();

    void ECRANinit();
    void ECRANmanagement();

    void setplante (plante* p);
};

#endif