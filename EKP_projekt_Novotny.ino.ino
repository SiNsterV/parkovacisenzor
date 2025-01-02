

#define PIN_TRIG 33
#define PIN_ECHO 34
#define LEDC 16
#define LEDZ2 17
#define LEDZ1 12
#define LEDG1 27
#define LEDG2 32
#define buzzer 4


void setup() {
  Serial.begin(115200);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(LEDC, OUTPUT);
  pinMode(LEDZ2, OUTPUT);
  pinMode(LEDZ1, OUTPUT);
  pinMode(LEDG2, OUTPUT);
  pinMode(LEDG1, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  float fastener;
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  int duration = pulseIn(PIN_ECHO, HIGH);
  int distance = duration/58;
  Serial.println(distance);

  if(distance > 18 && distance < 20){
    fastener = 1;
    tone(buzzer, 2000, 1000*fastener);
    digitalWrite(LEDG1, HIGH);
    delay(1000*fastener);
  }
  else if(distance > 16 && distance <= 18){
    fastener = 1;
    tone(buzzer, 2000, 1000*fastener);
    digitalWrite(LEDG1, HIGH);
    digitalWrite(LEDG2, HIGH);
    delay(1000*fastener);
  }
  else if(distance > 12 && distance <= 16){
    fastener = 0.6;
    tone(buzzer, 2000, 1000*fastener);
    digitalWrite(LEDG1, HIGH);
    digitalWrite(LEDG2, HIGH);
    digitalWrite(LEDZ1, HIGH);
    delay(1000*fastener);
  }
  else if(distance > 8 && distance <= 12){
    fastener = 0.4;
    tone(buzzer, 2000, 1000*fastener);
    digitalWrite(LEDG1, HIGH);
    digitalWrite(LEDG2, HIGH);
    digitalWrite(LEDZ1, HIGH);
    digitalWrite(LEDZ2, HIGH);
    delay(1000*fastener);
  }
  else if(distance > 4 && distance <= 8){
    fastener = 0.2;
    tone(buzzer, 2000, 1000*fastener);
    digitalWrite(LEDG1, HIGH);
    digitalWrite(LEDG2, HIGH);
    digitalWrite(LEDZ1, HIGH);
    digitalWrite(LEDZ2, HIGH);
    digitalWrite(LEDC, HIGH);
    delay(1000*fastener);
  }
  else if(distance < 4){
    fastener = 0.2;
    tone(buzzer, 2000, 0);
    digitalWrite(LEDG1, HIGH);
    digitalWrite(LEDG2, HIGH);
    digitalWrite(LEDZ1, HIGH);
    digitalWrite(LEDZ2, HIGH);
    digitalWrite(LEDC, HIGH);
    delay(1000*fastener);
  }



  if(distance > 4){
  digitalWrite(LEDG1, LOW);
  digitalWrite(LEDG2, LOW);
  digitalWrite(LEDZ1, LOW);
  digitalWrite(LEDZ2, LOW);
  digitalWrite(LEDC, LOW);
  }
  delay(1000*fastener);
}