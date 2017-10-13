#include <SoftwareSerial.h>
SoftwareSerial BT(11, 12);   // RX & TX
 
void setup()
{
  BT.begin(9600);
  Serial.begin(9600);
  Serial.println("Enter commands:");
}
 
void loop()
{
  if (BT.available())
  {
    char data = BT.read();
    Serial.print(data);
  }
  if (Serial.available())
    BT.write(Serial.read());
}
