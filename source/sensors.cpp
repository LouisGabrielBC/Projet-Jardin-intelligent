%#include "sensors.h"

#include "DHT.h"


// class moisture_sensor 

     void moisture_sensor::actualise_sensor(){
        moisture_rate = analogRead(MoisturesensorPin);}
     int moisture_sensor::getvalue_sensor(){
      return this->moisture_rate;
    }


//class temperature_sensor 
    temperature_sensor::temperature_sensor() : dht(TempHumsensorPin, DHT_TYPE){}
    void temperature_sensor::init(){ Wire.begin();dht.begin();}
    void temperature_sensor::actualise_sensor(){
      float temp_hum_val[2] = {0};
      if (!dht.readTempAndHumidity(temp_hum_val)) { //re
      temperature_C = temp_hum_val[1];
      humidity_rate = temp_hum_val[0];}
      else{
        humidity_rate = 99;// on a pas réussit à mettre une exeption avec arduino, pour signalé un problème on met le taux d'humidité à 99%
      }
    }
    float temperature_sensor::getvalue_sensorT(){
       return this->temperature_C;
    }
    float temperature_sensor::getvalue_sensorH(){
       return this->humidity_rate;
    }






