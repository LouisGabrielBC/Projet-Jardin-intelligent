#ifndef m_management_h
#define m_management_h 

#include "sensors.h"
#include "Plantes.h"
#include <Arduino.h>

#define PompePin         D8

    class m_management {
    private :
      moisture_sensor *M;
      plante *P;
    public :
    m_management(moisture_sensor *MS, plante *PL);
    void PompeInit();
    void ComPompe();
    void setplante(plante* p);
  };

#endif