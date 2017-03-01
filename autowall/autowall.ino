#include <enes100.h>
#include <fr_tank.h>

SoftwareSerial mySerial(8, 9);
Marker marker(3);
RF_Comm rf(&mySerial, &marker);
DFRTank tank;
int state;
final int NONE = 0;
// go from starting point to in front of possible exit 1
final int ALIGN_TO_ONE = 1;
// go from in front of possible exit 1 through. stop and abot if wall
final int DRIVE_TO_ONE = 2;
// abort exit one and approach exit 2
final int ALIGN_TO_TWO = 4;
// drive through exit 2. pass go. collect 200. even if theres a wall
final int DRIVE_TO_TWO = 8;

// top point
final int topx;
final int topy;
// bottom point
final int botx;
final int boty;

// the x and y of the points to go to.
int p1x;
int p1y;
int p2x;
int p2y;

void setup() {
  tank.init();
  rf.startMission();
  Serial.begin(9600);
}

void loop() {
  if (rf.updateLoation()) {
    switch (state) {
      case NONE:
        if (abs(topy-marker.y) > abs(boty-marker.y)) {
          // distance to top is larger, try bottom first
          p1x = botx;
          p1y = boty;
          p2x = topx;
          p2y = topy;
        } else {
          // distance to bot is larger, try top first
          p1x = topx;
          p1y = topy;
          p2x = botx;
          p2y = boty;
        }
        state = ALIGN_TO_ONE;
        break;
      case ALIGN_TO_ONE:
        if (
    }
  }
}

void move(int left, int right) {
  tank.setLeftMotorPWM(left);
  tank.setRightMotorPWM(right);
}

