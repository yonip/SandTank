#include <dfr_tank.h>

DFRTank tank;

void setup(){
  Serial.begin(9600);
  tank.init();
}

void loop(){
  // turn right
  move(255, -255);
  delay(500);
  // turn left
  move(-255, 255);
  delay(500);
  // forward
  move(255, 255);
  delay(500);
  // backwards
  move(-255, -255);
  delay(500);
  // stop
  tank.turnOffMotors();
  delay(500);
}

void move(int left, int right) {
  tank.setLeftMotorPWM(left);
  tank.setRightMotorPWM(right);
}

