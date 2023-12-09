#include <Servo.h> // Librairie du Servo moteur SG09
#include <AFMotor.h> // Librairie du Moteur DC

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

Servo servoMotor;       

int relayPin = 9;       // Broche du relais pour l'électroaimant
int servoPin = 10;

void setup() {
  pinMode(relayPin, OUTPUT);
  servoMotor.attach(servoPin);
  Serial.begin(9600);
  servoMotor.write(0);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    switch (command) {
      case 'F':
        moveForward();
        break;
      case 'B':
        moveBackward();
        break;
      case 'L':
        turnLeft();
        break;
      case 'R':
        turnRight();
        break;
      case 'U':
        liftLoad();
        break;
      case 'D':
        dropLoad();
        break;
      default:
        stopRobot();
    }
  }
}

void moveForward() {
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void moveBackward() {
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void turnLeft() {
  motor1.setSpeed(200);
  motor1.run(BACKWARD);
  motor2.setSpeed(200);
  motor2.run(BACKWARD);
  motor3.setSpeed(200);
  motor3.run(FORWARD);
  motor4.setSpeed(200);
  motor4.run(FORWARD);
}

void turnRight() {
  motor1.setSpeed(200);
  motor1.run(FORWARD);
  motor2.setSpeed(200);
  motor2.run(FORWARD);
  motor3.setSpeed(200);
  motor3.run(BACKWARD);
  motor4.setSpeed(200);
  motor4.run(BACKWARD);
}

void stopRobot() {
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}

void liftLoad() {
  digitalWrite(relayPin, HIGH);  // Activer l'électroaimant
  servoMotor.write(90);   // Position pour lever la charge
  delay(500);
}

void dropLoad() {
  digitalWrite(relayPin, LOW);   // Désactiver l'électroaimant
  servoMotor.write(0);    // Position pour baisser la charge
  delay(500);
}
