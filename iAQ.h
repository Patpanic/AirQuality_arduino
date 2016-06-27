 /*****************************************************************************************************/
/*   Bibliothèque pour lire le capteur
/*   iAQ-CORE de AMS http://ams.com/eng/Products/Environmental-Sensors/Air-Quality-Sensors/iAQ-core-C
/*   utilise le bus i2C
/*   26/06/2016
/*   Ver 1.1
/*   Patpanic                   
/******************************************************************************************************/

#ifndef iAQ
#define iAQ

#include <Wire.h>
#include "Arduino.h"
#include "sIAQDATA.h"

#define  IAQ_ADDR       0x5A  // Addresse du capteur (non modifiable)

#define  IAQ_I2C_ERROR  0X20  // erreur de communication sur le bus i2c
#define  IAQ_ERROR      0x80  // erreur capteur défectueux
#define  IAQ_BUSY       0x01  // erreur mesure en cours d'actualisation
#define  IAQ_RUNIN      0x10  // erreur le capteur s'initialise 5 minutes nécessaires
#define  IAQ_OK         0x00  // les données sont valides

byte iaqRead(struct IAQDATA*);

#endif /* iAQ */
