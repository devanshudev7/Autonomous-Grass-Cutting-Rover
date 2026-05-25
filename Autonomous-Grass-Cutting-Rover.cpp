#include <Servo.h> 
Servo myServo; 

// Ultrasonic pins 
#define trigPin   2 
#define echoPin   3 

// Motor driver pins 
#define ENA   5 
#define IN1   8 
#define IN2   9 
#define IN3  10 
#define IN4  11 
#define ENB   6 

// Servo & cutter pins 
#define servoPin   4 
#define cutterPin  7 

long duration; 
int  distance; 

void setup() { 
  Serial.begin(9600); 
  pinMode(trigPin,  OUTPUT); 
  pinMode(echoPin,  INPUT); 
  pinMode(ENA,      OUTPUT); 
  pinMode(ENB,      OUTPUT); 
  pinMode(IN1,      OUTPUT); 
  pinMode(IN2,      OUTPUT); 
  pinMode(IN3,      OUTPUT); 
  pinMode(IN4,      OUTPUT); 
  pinMode(cutterPin,OUTPUT); 
  myServo.attach(servoPin); 
  myServo.write(90);   // Center position 
  delay(1000); 
} 

int getDistance() { 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0.034 / 2; 
  return distance; 
} 

void moveForward() { 
  analogWrite(ENA, 180); 
  analogWrite(ENB, 180); 
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW); 
  digitalWrite(cutterPin, HIGH);   // Cutter ON 
} 

void stopMotors() { 
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, LOW); 
  digitalWrite(cutterPin, LOW);    // Cutter OFF 
} 

void turnLeft() { 
  analogWrite(ENA, 150); 
  analogWrite(ENB, 150); 
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH); 
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW); 
} 

void turnRight() { 
  analogWrite(ENA, 150); 
  analogWrite(ENB, 150); 
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH); 
} 

void loop() { 
   myServo.write(90); 
  delay(500); 
  int frontDistance = getDistance(); 

  if (frontDistance > 20) { 
    moveForward(); 
  } else { 
    stopMotors(); 
    delay(500); 

    myServo.write(150);            // Look Left 
    delay(700); 
    int leftDistance = getDistance(); 

    myServo.write(30);             // Look Right 
    delay(700); 
    int rightDistance = getDistance(); 

    myServo.write(90); 
    delay(500); 

    if (leftDistance > rightDistance) { 
      turnLeft(); 
      delay(600); 
    } else { 
      turnRight(); 
      delay(600); 
    } 
    stopMotors(); 
  } 
}