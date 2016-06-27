/*****************************************/
/*   Bibliothèque pour lire le capteur
/*   iAQ-CORE de AMS http://ams.com/eng/Products/Environmental-Sensors/Air-Quality-Sensors/iAQ-core-C
/*   utilise le bus i2C
/*   26/06/2016
/*   Ver 1.1
/*   Patpanic                   
/*****************************************/

#include "iAQ.h"
#include <Arduino.h>
#include "sIAQDATA.h"


/****************************************************************************/
/*  Lire le capteur iAQ-core branché sur le bus i2C
/*  Les mesures sont transmises par référence dans une structure
/*  Retourne l'octet d'état du capteur (0 si la lecture a réussi) voir iAQ.h
/****************************************************************************/
byte iaqRead(IAQDATA* iaqData) {
  
  byte buff[9];  //buffer pour stocker la trame i2c
  int i = 0;
  
  int nbytes;   //nombre d'octets de la trame reçue 
  
  byte stat = 0;  //état de la communication et du capteur
  
  
  /* récupération de la trame du capteur */
  Wire.begin();
  Wire.requestFrom(IAQ_ADDR, 9);  //Interroger le capteur, 9 octets attendus
  nbytes = Wire.available();  //Nombre d'octets retouné par le capteur 
  
  if (nbytes != 9) 
    return IAQ_I2C_ERROR;  // Impossible de communiquer avec le capteur
  else {
    while(Wire.available()) {  //Mettre les données fournies dans un tampon
      buff[i] = Wire.read();
      i++;
      }
    }
     
  stat = buff[2];
  // Si les données sont valides, calculer le taux de CO2, le taux des composés organiques volatils totaux et la résistance mesurée
  if (stat==0) {
    iaqData -> co2 = buff[0] * 256 + buff[1];
    iaqData -> tvoc = buff[7] * 256 + buff[8];
    iaqData -> resistance = buff[4] * 65536 + buff[5] * 256 + buff[6];
    }
  return stat;  //Renvoyer l'état de la communication avec le capteur
  }
