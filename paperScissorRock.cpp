
#include <Servo.h>

Servo servo_5;
Servo servo_6;
Servo servo_4;
int count=0;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()

{
  servo_5.attach(5);
  servo_6.attach(6);
  servo_4.attach(4);
  Serial.begin(9600);
  servo_5.write(0);
  servo_4.write(0);
  servo_6.write(0);
    pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
}


void loop()
{
    digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(8, LOW);
  digitalWrite(11, HIGH);
  Serial.print("Checking if a hand came");
  if (0.01723 * readUltrasonicDistance(10, 9) < 10) {
    count = random(1,100);
    Serial.println(count);
    if (count%3 == 0) {
      Serial.println("Activating motor 1");
      servo_5.write(90);
      delay(1000);
      servo_5.write(0);
    }
    if (count%3 == 1) {
      Serial.println("Activating motor 2");
      servo_6.write(90);
      delay(1000);
      servo_6.write(0);
    }
    if (count%3 == 2) {
      Serial.println("Activating motor 3");
      servo_4.write(90);
      delay(1000);
      servo_4.write(0);
    }
  }
}