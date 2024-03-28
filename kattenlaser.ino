#include <Servo.h>

const int laser = 12;
const int motion = 7;
Servo servo_1;
Servo servo_2;

void setup() {
  pinMode(laser, OUTPUT);
  pinMode(motion, INPUT);

  servo_1.attach(13);
  servo_2.attach(8);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(motion) == HIGH) {
    digitalWrite(laser, HIGH);

    int randomPosition1 = random(0, 180);
    int randomPosition2 = random(20, 80);
    int randomDelay = random(1000, 1500);

    servo_1.write(randomPosition1);
    servo_2.write(randomPosition2);

    delay(randomDelay);
  } else {
    digitalWrite(laser, LOW);
  }

}