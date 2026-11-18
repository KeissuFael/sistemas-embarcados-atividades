#include <Servo.h>

Servo meuServo;

bool fechada = true;
bool fechando = false;
bool aberta = false;
bool abrindo = false;
int botao = 2;
int pinoServo = 3;
  
void setup()
{
  Serial.begin(9600);
  pinMode(botao, INPUT_PULLUP);
  meuServo.attach(pinoServo);
}

void loop()
{
  if(digitalRead(botao) == HIGH && fechada == true) {
  	fechada = false;
    abrindo = true;
    Serial.println("Abrindo, um momento");
    meuServo.write(180);
    delay(500);
    abrindo = false;
    aberta = true;
  }
  if(meuServo.read() == 180 && aberta == true) {
  	delay(2000);
    aberta = false;
    fechando = true;
    meuServo.write(90);
    delay(500);
    fechando = false;
    fechada = true;
  }
}
