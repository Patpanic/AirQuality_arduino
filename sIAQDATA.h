 /*****************************************************************************************************/
/*   Déclaration de la structure de données
/*   iAQ-CORE de AMS http://ams.com/eng/Products/Environmental-Sensors/Air-Quality-Sensors/iAQ-core-C
/*   utilise le bus i2C
/*   26/06/2016
/*   Ver 1.1
/*   Patpanic                   
/******************************************************************************************************/

#ifndef sIAQDATA_H
#define sIAQDATA_H




struct IAQDATA {
    unsigned int co2;
    unsigned int tvoc;
    unsigned long resistance;
    };

typedef struct IAQDATA IAQDATA;


#endif  /* sIAQDATA */
