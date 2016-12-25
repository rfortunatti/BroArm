# BroArm

Two programs to control one of these generic laser-cutted MDF robotic arms with servo-motors. There are two folder: SoftwarePot and Software Serial.

SoftwareSerial receive commands via the Arduino USB Serial port, interpretates them as percentages of a specific servo and do it. 

SoftwarePot is more a practical approach, using 5k linear potentiometers connected at the analog inputs acting the same as SoftwareSerial.
