
// Pinos de controle do motor na Ponte H
#define IN1       13      
#define IN2       12
#define IN3       11
#define IN4       10

// Pinos de controle da velocidade do motor na Ponte H
#define ENA_PIN   5
#define ENB_PIN   6

// Velocidade de cada motor
#define M1_VEL    50  // Motor direita
#define M2_VEL    50  // Motor esquerda

// Pinos dos sensores segue faixa
#define SENSOR_D  9   // Sensor da direita
#define SENSOR_E  8   // Sensor da esquerda

void frente(void)
{
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);

  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
;
}

void tras(void)
{
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);

  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}

void direita(void)
{
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);

  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void esquerda(void)
{
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);

  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);
}

void parar(void)
{ 
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);

  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);
    
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(ENA_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);

  pinMode(SENSOR_D, INPUT);
  pinMode(SENSOR_E, INPUT);

  analogWrite(ENA_PIN, 127);
  analogWrite(ENB_PIN, 127);

  parar();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int vel_motor_d, vel_motor_e;

  if(digitalRead(SENSOR_D) && digitalRead(SENSOR_E)) parar();else

    if(SENSOR_D)
    {
      direita();
    }else
      if(SENSOR_E)
      {
        esquerda();
      }    
  frente();

  analogWrite(ENA_PIN, map(M1_VEL, 0, 100, 0, 255));
  analogWrite(ENB_PIN, map(M1_VEL, 0, 100, 0, 255));

  delay(100);
}
