#include <Servo.h>

Servo motor;
int okuma;
int derece;

void setup() {
  motor.attach(3);
}

void loop() {
  okuma = analogRead(A0);
  derece = map(okuma, 0, 1023, 0, 180);
  motor.write(derece);
}
