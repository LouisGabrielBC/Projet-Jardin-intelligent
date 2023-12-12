

#ifndef sensors_h
#define sensors_h

#include "DHT.h"
#include <Arduino.h>

//moisture sensor
  #define MoisturesensorPin      A0

//temperature sensor&humidity sensor
#if defined(ARDUINO_ARCH_AVR)
    #define debug  Serial

#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
    #define debug  SerialUSB
#else
    #define debug  Serial
#endif
#define  TempHumsensorPin      D5
#define  DHT_TYPE              DHT11


class sensor {
    public:
    virtual void actualise_sensor();
};

class moisture_sensor : public sensor{
  protected :
      int moisture_rate;
  public:
      virtual void actualise_sensor();
      int getvalue_sensor();

};

class temperature_sensor : public sensor{
  protected :
      DHT dht;
      float temperature_C;
      float humidity_rate;
  public:
      temperature_sensor();
      void init();
      virtual void actualise_sensor();
      float getvalue_sensorT();
      float getvalue_sensorH();
};

#endif