#include <Servo.h>

#define BASEMAX 180
#define BASEMIN 0
#define GARRAMAX 170
#define GARRAMIN 115

//A base ficou sem limitacoes, aceita valores de 0 a 100
Servo servoBase;
int pinServoBase = 8;

//A garra detem de uma folga consideravel no link do braco com o atuador
//B80 para garra aberta e B100 para fechada dao uma abertura consideravel e um grip forte
Servo servoGarra;
int pinServoGarra = 9;

//Para a altura do braco, o maximo de altura ficou em A86
//O minimo em A40
Servo servoBraco;
int pinServoBraco = 10;

//Aparentemente esse servo controla o "tilt" da garra, mas nao e constante.
//Dependendo da altura do braco, suas articulaces variam.
//Parece responder bem com comandos entre 20% e 70%.
Servo servoAux;
int pinServoAux = 11;


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  //setTimeout e importante para o programa nao ficar lerdo na leitura da serial.
  //Inicializo e posiciono os servos de forma conveniente.
  servoBase.attach(pinServoBase);
  //servoBase.write(BASEMAX);

  servoGarra.attach(pinServoGarra);
  //servoGarra.write(BASEMIN);
  aplicaServo(servoGarra, 80);

  servoBraco.attach(pinServoBraco);
 // servoBraco.write(30);
  //aplicaServo(servoBraco, 50);

  servoAux.attach(pinServoAux);
}

void loop() {
	//Uma string sera recebida com os valores da BASE, ALTURA e GARRA.
	//Em vez do angulo puro, sera porcentagem, porque cada motor e estrutura tem tolerancias
	//a serem consideradas. Como a entrada sera validada por um software cliente, assumo que
	//a string SEMPRE sera verdadeira.

	//A conexao serial recebera UMA das tres informacoes abaixo:
	//Bxxx
	//Gxxx
	//Axxx
	//Sendo 0 <= xxx <= 100
	//B para BASE, G para GARRA e A para ALTURA.

	if (Serial.available() > 0)
	{
		if (Serial.peek() == 'B')
		{
			Serial.read();
			float val = 0;
			val = Serial.parseInt();
			aplicaServo(servoBase, val);
			//Serial.flush();
		}

		if (Serial.peek() == 'G')
		{
			Serial.read();
			float val;
			val = Serial.parseInt();
			aplicaServo(servoGarra, val);
			//Serial.flush();
		}

		if (Serial.peek() == 'A')
		{
			Serial.read();
			float val;
			val = Serial.parseInt();
			aplicaServo(servoBraco, val);
			//Serial.flush();
		}
		if (Serial.peek() == 'X')
		{
			Serial.read();
			float val;
			val = Serial.parseInt();
			aplicaServo(servoAux, val);
			//Serial.flush();
		}

		//Serial.flush();
	}
}

void aplicaServo(Servo servoTarget, float porcent)
{
	if (porcent < 0 || porcent > 100)
		return;

	float servoStart;
	servoStart = servoTarget.read();
	porcent = porcent / 100;

	for (; servoStart < (porcent * 180); servoStart++) {
		servoTarget.write(servoStart);
		delay(30);
	}
	for (; servoStart > (porcent * 180); servoStart--) {
		servoTarget.write(servoStart);
		delay(30);
	}
}










