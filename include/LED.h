
#ifndef LED_h
#define LED_h

#include <Arduino.h>
#include "Adafruit_NeoPixel.h"
#include "rgb_lcd.h"

#define NUMPIXELS      10
#define BARETTEPIN     D3
#define orange         'o'
#define red            'r'
#define green          'g'
#define blue           'b'

//la classe LED sert de driver à l'écran et à la barette, ce qui y est affiché est controller par la classe s_management

class LED {
    protected :
    char color;
    public:
    virtual void refresh(); //refresh() permet à la barette ou à l'écran d'actualiser son affichage en fonction des paramètres qui ont changé
    void setcolor(char c);
    char getcolor();
};

//BARETTE LED

  class barette_LED : public LED {
  
  private :

  int NbLED_ON; //nombre de led allumées sur la barette
  int brightness;

  public :
  barette_LED ();

  int getNbLED_ON ();
  int getbrightness ();

  void setbrightness(int b); //une foi initialisé, on ne touche plus à l'intensité lumineuse
  void setNbLED_ON(int nb);
  void setbarette(int nb,char c);

  virtual void refresh(); //définition de refresh() propre à la barette
};

//ECRAN LCD

class ecran_LED : public LED {
  private :
  int columns;
  int rows;
  String message;//message à afficher
  rgb_lcd lcd;
  public :

  ecran_LED() ;

  String getmessage() ;
  void setmessage (String m) ;
  void setecran (String m,char c);
  void setdim (int L,int l);

  virtual void refresh();//définition de refresh() propre à l'écran
  };

#endif
