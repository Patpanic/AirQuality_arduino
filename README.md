# AirQuality_arduino
Exemple d'utilisation du capteur iAQ core de AMS pour mesurer la qualité de l'air avec un arduino mega2560

Le capteur iAQ-core de AMS permet de mesurer simplement le taux de CO2  et le taux des composés organiques volatils totaux dans l'air intérieur.
Les mesures du capteur sont communiquées sur un bus i2c.
Le capteur nécessite un temps de démarrage de 5 minutes.
Il ne nécessite pas d'étalonnage.
CO2 en PPM (parties par million)
TVOC (Total Volatils Organics Compounds) en PPB (parties par milliard)

iAQ-core_exemple.ino    
    fichier source, lit le capteur toutes les 15 secondes. Envoie le résultat de la lecture sur le port série via USB de l'arduino.
    Si les mesures sont valides, elles sont envoyées sur le port série sinon c'est l'état du capteur qui est envoyé.
    


