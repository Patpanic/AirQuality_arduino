/* 
   Exemple
   Lecture du capteur iAQ-core P de AMS
   Période de la mesure 15s
   Capteur connecté sur le port i2C
   Les mesures sont envoyées sur le port série via USB
   MEGA2560
   26/06/2016
   ver 1.1
   Patpanic
   
*/

#include "iAQ.h"   //Utiliser la bibliothèque de communication avec l'iAQ
#include "sIAQDATA.h"  //Utiliser une structure de données
#include <Wire.h>


  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("CO2(PPM) \t");
  Serial.print("tvoc(PPB) \t");
  Serial.print("Resistance(Ohm) \n");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  
  IAQDATA iaqData;  //structure de données qui accueille les mesures
  
  
  
  byte ret = iaqRead(&iaqData);  //Lire le capteur
  
  // traitement des erreurs et affichage de la mesure
  switch (ret) {
    
    case IAQ_I2C_ERROR :
      Serial.println(F("Erreur de communication avec le capteur"));  //la fonction F() indique que la chaine de caractères est stockée dans la mémoire flash et pas en RAM
      break;
    
    case IAQ_ERROR :
      Serial.println(F("Le capteur iAQ-core est en erreur"));
      break;
    
    case IAQ_BUSY :
      Serial.println(F("Une mesure est en cours"));
      break;
    
    case IAQ_RUNIN :
      Serial.println(F("Capteur iAQ-core en initialisation, attendre 5 minutes"));
      break;
    
    case IAQ_OK :
      Serial.print(iaqData.co2);
      Serial.print("\t\t");
      Serial.print(iaqData.tvoc);
      Serial.print("\t\t");
      Serial.print(iaqData.resistance);
      Serial.print("\n");
      break;
      }  
  
  delay(15000); // Faire une mesure toutes les 15 secondes (Minimum 11s pour un iAQ-core de type P)
}
