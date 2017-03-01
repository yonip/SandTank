#include <enes100.h>

SoftwareSerial mySerial(8, 9);
Marker marker(3);
RF_Comm rf(&mySerial, &marker);
string name = "Materials";
int num = 5;

void setup()
{
  rf.startMission();
  Serial.begin(9600);
}
 
void loop() 
{
  if (rf.updateLocation())
  {
  Serial.println("Huzzah!");
  Serial.print("Team " +name + "'s (#" + num + ") X coordinate is: ");
  Serial.println(marker.x);
  }
  else
  {
    Serial.println("Jeepers! Something’s gone wrong...");
  }
  rf.println("Can you hear me now?");
  delay(500);
}
