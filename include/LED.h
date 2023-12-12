
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


class LED {
    protected :
    char color;
    public:
    virtual void refresh();
    void setcolor(char c);
    char getcolor();
};

//BARETTE LED

  class barette_LED : public LED {
  
  private :

  int NbLED_ON;
  int brightness;

  public :
  barette_LED ();

  int getNbLED_ON ();
  int getbrightness ();

  void setbrightness(int b);
  void setNbLED_ON(int nb);
  void setbarette(int nb,char c);

  virtual void refresh();
};

//ECRAN LCD

class ecran_LED : public LED {
  private :
  int columns;
  int rows;
  String message;
  rgb_lcd lcd;
  public :

  ecran_LED() ;

  String getmessage() ;
  void setmessage (String m) ;
  void setecran (String m,char c);
  void setdim (int L,int l);

  virtual void refresh();
  };

#endif
