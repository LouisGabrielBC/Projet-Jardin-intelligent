    #include "m_management.h"
    #include "sensors.h"
    #include "Plantes.h"

//class m_management 
      m_management::m_management(moisture_sensor *MS, plante *PL){
        this->M=MS;
        this->P=PL;
      }

      void m_management::PompeInit(){pinMode(PompePin,OUTPUT);}
      void m_management::ComPompe(){
        M->actualise_sensor();
        if (M->getvalue_sensor()<P->getMinHum()) {
          
          digitalWrite(PompePin,HIGH);
        }
        else {digitalWrite(PompePin,LOW);}
      }
      void m_management::setplante( plante* p){this->P =p;}




