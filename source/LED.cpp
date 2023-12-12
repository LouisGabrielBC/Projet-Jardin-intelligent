#include "LED.h"

//barette led
#include "Adafruit_NeoPixel.h"
#ifdef __AVR__
    #include <avr/power.h>
#endif

  #define NUMPIXELS      10
  #define BARETTEPIN     D3
  #define orange         'o'
  #define red            'r'
  #define green          'g'
  #define blue           'b'

//ecran LCD
#include <Wire.h>
#include "rgb_lcd.h"

// class LED
  char LED::getcolor(){return this->color;}
  void LED::setcolor(char c){color=c;}


// class barette_LED {

  barette_LED::barette_LED (){
    NbLED_ON=NUMPIXELS;
    color=orange;
    brightness=200;
  } //pour savoir si la barette a reçu une nouvelle valeur depuis son initialisation, on l'initialise orange avec toutes les led allumées, set qu'elle ne peut pas avoir dans le fonctionement normal du jardin

  int barette_LED::getNbLED_ON (){return this->NbLED_ON;}

  int barette_LED::getbrightness (){return this->brightness;}

  void barette_LED::setbrightness(int b){brightness=b;}

  void barette_LED::setNbLED_ON(int nb){NbLED_ON=nb;}
  void barette_LED::setbarette(int nb,char c){
    NbLED_ON=nb;
    color=c;
  }
  
  void barette_LED::refresh() {
    Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, BARETTEPIN, NEO_GRB + NEO_KHZ800);
    int a =0;//rouge
    int b=0;//vert
    int c=0;//bleue
    if (color==orange){a=150;b=150;}
    else if (color==red){a=150;}
    else if (color==green){b=150;}
    else if (color==blue){c=150;}
    pixels.setBrightness(this->brightness); 
    pixels.begin();
    for (int i = 0; i < NUMPIXELS; i++) { //on actualise 1 à 1 tous les pixels
      if (i<NbLED_ON) {
        pixels.setPixelColor(i, pixels.Color(a, b, c));
      }
      else{
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
      pixels.show();
    }
  }


//ecran_LED 
  ecran_LED::ecran_LED() : lcd()  //on inialise de tel façon qu'on puisse reconaître si l'écran est dans ces paramètres initiaux
    this->message = "init";
    this->color = orange;
    this->columns = 3;
    this->rows = 2;


  }

  String ecran_LED::getmessage() {return this->message;}
  void ecran_LED::setmessage (String m) {this->message=m;}
  void ecran_LED::setecran (String m,char c){this->message=m;this->color=c;}
  void ecran_LED::setdim (int L,int l){this->columns=L;this->rows=l;}

  void ecran_LED::refresh(){
  int a =0;//rouge
  int b=0;//vert
  int c=0;//bleue
  if (color==orange){a=150;b=150;}
  else if (color==red){a=150;}
  else if (color==green){b=150;}
  else if (color==blue){c=150;}

  // set up the LCD's number of columns and rows:
  lcd.begin(this->columns,this->rows);
  //set up color
  lcd.setRGB(a, b, c);
  //print message
  lcd.print(this->message);
  }





