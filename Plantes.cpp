#include "Plantes.h"

#include <string>

//class plante 
      plante::plante(float min,float max,String s){
        this->Tmin=min;
        this->Tmax=max;
        this->type=s;
        }

       int plante::getMinHum () {
        return this->HumMin;
      };
       int plante::getMaxHum () {
        return this->HumMax;
      };
      float plante::getTmin(){return this->Tmin;}
      float plante::getTmax(){return this->Tmax;}
      String plante::gettype(){return this->type;}

//  class P_Tropical 
      P_Tropical::P_Tropical(): plante(15,35,"TROPICAL"){
        this->nom = "Plante tropicale classique";
        this->HumMin = 350;
        this->HumMax = 525;
      }

      P_Tropical::P_Tropical (String Nom, int HMin, int HMax) : plante(15,35,"TROPICAL"){
        this->nom = Nom;
        this->HumMin = HMin;
        this->HumMax = HMax;
      }

//class P_Moderee
      P_Moderee::P_Moderee() : plante(0,30,"MODEREE") {
        this->nom = "Plante moderee classique";
        this->HumMin = 210;
        this->HumMax = 350;
      }

      P_Moderee::P_Moderee(String Nom, int HMin, int HMax): plante(0,30,"MODEREE") {
        this->nom = Nom;
        this->HumMin = HMin;
        this->HumMax = HMax;
      }

//class P_Aride 
      P_Aride::P_Aride() : plante(15,40,"ARIDE") {
        this->nom = "Plante aride classique";
        this->HumMin = 140;
        this->HumMax = 210;
      }

      P_Aride::P_Aride(String Nom, int HMin, int HMax): plante(15,40,"ARIDE") {
        this->nom = Nom;
        this->HumMin = HMin;
        this->HumMax = HMax;
      }



