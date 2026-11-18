const int desativadoInicial = true;
bool desativado = desativadoInicial;
bool ativado = false;
bool alerta = false;

const int botaoAtivar = 3;
const int botaoAlerta = 4;
const int piezo = 5;

#define NOTE_D4  294
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_C4  262
#define NOTE_B3  247
#define NOTE_AS3 233

int melody[] = {
  NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4, NOTE_GS4,
  NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,

  NOTE_C4, NOTE_C4, NOTE_D5, NOTE_A4, NOTE_GS4,
  NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,

  NOTE_B3, NOTE_B3, NOTE_D5, NOTE_A4, NOTE_GS4,
  NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,

  NOTE_AS3, NOTE_AS3, NOTE_D5, NOTE_A4, NOTE_GS4,
  NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4
};

int durations[] = {
  125, 125, 250, 250, 250,
  250, 250, 125, 125, 125,

  125, 125, 250, 250, 250,
  250, 250, 125, 125, 125,

  125, 125, 250, 250, 250,
  250, 250, 125, 125, 125,

  125, 125, 250, 250, 250,
  250, 250, 125, 125, 125
};

int tamanho = sizeof(melody) / sizeof(melody[0]);

void setup()
{
  Serial.begin(9600);
  pinMode(botaoAtivar, INPUT);
  pinMode(botaoAlerta, INPUT);
  pinMode(piezo, OUTPUT);
  Serial.println("Desativado");
}

void tocarMegalovania()
{
  for (int i = 0; i < tamanho; i++)
  {
    tone(piezo, melody[i], durations[i]);

    delay(durations[i] * 1.5);

    noTone(piezo);
  }
}

void loop()
{
  if (digitalRead(botaoAtivar) == HIGH && desativado == true)
  {
    desativado = false;
    ativado = true;
    Serial.println("Ativado");
  }

  if (digitalRead(botaoAlerta) == HIGH && ativado == true && alerta == false)
  {
    alerta = true;
    Serial.println("Em Alerta");
    tocarMegalovania();
  }

  // Permite tocar novamente após soltar o botão
  if (digitalRead(botaoAlerta) == HIGH)
  {
    alerta = false;
  }
}
