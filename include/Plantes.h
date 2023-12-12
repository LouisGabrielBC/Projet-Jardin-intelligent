#ifndef Plantes_h
#define Plantes_h
#include <Arduino.h>

//la classe plante représente la plante à arroser, on lui met en atribue un nom,un type,des températures et des humidités significatives pour elle ( min et max )

class plante {
    protected :
      String nom;
      String type;
      float Tmin;
      float Tmax;
      int HumMin;
      int HumMax;
    public :
      plante(float min,float max,String s);

      virtual int getMinHum () ;
      virtual int getMaxHum () ;
      float getTmin();
      float getTmax();
      String gettype();

  };
//On distingue 3 types de plantes : Tropicales,Arides et modérées avec chacune des paramètre par défaults mais personalisables

  class P_Tropical : public plante {
    public :
      P_Tropical();
      P_Tropical (String Nom, int HMin, int HMax) ;
  };

  class P_Moderee : public plante {
    public :
      P_Moderee();
      P_Moderee(String Nom, int HMin, int HMax);
  };

  class P_Aride : public plante {
    public :
      P_Aride();
      P_Aride(String Nom, int HMin, int HMax);
  };

#endif
