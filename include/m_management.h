#ifndef m_management_h
#define m_management_h 

#include "sensors.h"
#include "Plantes.h"
#include <Arduino.h>

#define PompePin         D8

//la classe m_management gère la pompe, elle arrose la plante quand son taux d'humidité est infèrieur à son taux minimum

    class m_management {
    private :
      moisture_sensor *M;
      plante *P;
    public :
    m_management(moisture_sensor *MS, plante *PL);
    void PompeInit(); //on donne le pin de la pompe au programme
    void ComPompe(); //on met en marche la pompe si le taux d'humidité est infèrieur au taux minimum sinon on arrête la pompe
    void setplante(plante* p); //on peut changer la plante à arroser n'importe quand
  };

#endif
