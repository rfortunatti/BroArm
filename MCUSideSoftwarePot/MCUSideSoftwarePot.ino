#include <Servo.h>

#define BASEMAX 180
#define BASEMIN 0
#define GARRAMAX 180
#define GARRAMIN 126
#define BRACOMAX 154
#define BRACOMIN 0
#define AUXMAX 145
#define AUXMIN 45

Servo servoBase;
int pinServoBase = 8;
int pinPotBase = A0;
int potBase;

Servo servoGarra;
int pinServoGarra = 9;
int pinPotGarra = A1;
int potGarra;

Servo servoBraco;
int pinServoBraco = 10;
int pinPotBraco = A2;
int potBraco;

Servo servoAux;
int pinServoAux = 11;
int pinPotAux = A3;
int potAux;



void setup()
{
	servoBase.attach(pinServoBase);
	servoGarra.attach(pinServoGarra);
	servoBraco.attach(pinServoBraco);
	servoAux.attach(pinServoAux);
}

void loop()
{
	int valMap = 0;

	//Adquirindo o valor dos pots
	potBase = analogRead(pinPotBase);
	potGarra = analogRead(pinPotGarra);
	potBraco = analogRead(pinPotBraco);
	potAux = analogRead(pinPotAux);

	valMap = map(potBase, 0, 1023, BASEMIN, BASEMAX);
	aplicaServo(servoBase, valMap);

	valMap = map(potGarra, 0, 1023, GARRAMIN, GARRAMAX);
	aplicaServo(servoGarra, valMap);

	valMap = map(potBraco, 0, 1023, BRACOMIN, BRACOMAX);
	aplicaServo(servoBraco, valMap);

	valMap = map(potAux, 0, 1023, AUXMIN, AUXMAX);
	aplicaServo(servoAux, valMap);
}

void aplicaServo(Servo servoDestino, int valueMapped)
{
	servoDestino.write(valueMapped);
}









