
/*************************************************************/
/*  Colégio Univap CTI - 2019
 *   Código para testes do Robô segue linha
 */

// Pinos de controle do motor na Ponte H
#define IN1       13      
#define IN2       12
#define IN3       11
#define IN4       10

// Pinos de controle da velocidade do motor na Ponte H
#define ENA_PIN   6
#define ENB_PIN   9

// Velocidade de cada motor
#define M1_VEL    30  // Motor direita
#define M2_VEL    30  // Motor esquerda

// Pinos dos sensores segue faixa
#define SENSOR_D  4   // Sensor da direita
#define SENSOR_E  5   // Sensor da esquerda

int vel_motor_d, vel_motor_e;


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

  analogWrite(ENA_PIN, map(M1_VEL, 0, 100, 0, 255));
  analogWrite(ENB_PIN, map(M1_VEL, 0, 100, 0, 255));

  //frente();
  //direita();
  //while(1);
  parar();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(digitalRead(SENSOR_D) && digitalRead(SENSOR_E)) parar();else

    if(digitalRead(SENSOR_E))
    {
      direita();
      //Serial.println("Sensor D");
    }else
      if(digitalRead(SENSOR_D))
      {
        esquerda();
        //Serial.println("Sensor E");
      }else
       //Serial.println("");
  frente();

}
