//definição dos pinos do sensor ultrassonico e buzzer 
const int trigPin = 2;
const int echoPin = 3;
const int buzzerPin = 4;

// variaveis de duração do som emitido pelo buzzer e distancia do sensor ultrassonico
long duration;
float distance;

#include <LiquidCrystal_I2C.h>

//initialize lcd
LiquidCrystal_I2C lcd(0x20,16,2);


void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


void loop() {
  // liga o trig e desliga ele
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //capita o sinal emitido pelo echo e converte de polegadas para cm
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  //printa no monitor serial a distancia em cm 
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  
  // se a distancia for maior que 15 o buzzer não irá ser acionado
  if (distance > 15) {
    lcd.clear();
    noTone(buzzerPin);
    lcd.print("Normal");
  } 
  
  // se a distancia for maior que dez e menor que quinze o buzzer emitira um som
  else if (distance > 10 && distance <= 15) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Status: Atencao");
	lcd.setCursor(0,1);
    lcd.print("Nivel subindo");
    tone(buzzerPin, 1000); 
    delay(200);
    noTone(buzzerPin);
    delay(800);
  } 
  
  // se a distancia for menor que dez o buzzer emitira um som mais agudo que o anterior
  else if (distance <= 10) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Status: Cheio!");
	lcd.setCursor(0,1);
    lcd.print("Acionar - SMS");
    tone(buzzerPin, 1500);
    delay(1000);
    noTone(buzzerPin);
    delay(500);
  }

  delay(500); 
}
  