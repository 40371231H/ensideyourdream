// slave_receiver.ino
// Refer to the "master_sender" example for use with this
#include <Wire.h>

const int SLAVE_ADDRESS = 1;
char incomingByte = 0;

void wait(long);
void light(int);
void lightAll();
void dark(int);
void darkAll();
void ledRun();
void blinkLED(int, int);
void dice(int);

int pos = 1;

void setup()
{
  //I2C定義接收
  Wire.begin(SLAVE_ADDRESS);    // join I2C bus as a slave with address 1
  Wire.onReceive(receiveEvent); // register event

  Serial.begin(9600);
  Serial.println("Received data:");

  //定義腳位輸出
  for (int i = 2; i <= 9; i++)
  {
    pinMode(i, OUTPUT);
  }
  ledRun();
  light(pos);
}

void loop()
{
  switch (incomingByte)
  {
  case '0':
    dice(1);
    break;
  case '1':
    dice(2);
    break;
  case '2':
    dice(3);
    break;
  case '3':
    dice(4);
    break;
  case '4':
    dice(5);
    break;
  case '5':
    dice(6);
    break;
  default:
    break;
  }
}

void wait(long interval)
{
}

void light(int led)
{
  switch (led)
  {
  case 1:
    digitalWrite(2, HIGH);
    break;
  case 2:
    digitalWrite(3, HIGH);
    break;
  case 3:
    digitalWrite(4, HIGH);
    break;
  case 4:
    digitalWrite(5, HIGH);
    break;
  case 5:
    digitalWrite(6, HIGH);
    break;
  case 6:
    digitalWrite(7, HIGH);
    break;
  case 7:
    digitalWrite(8, HIGH);
    break;
  case 8:
    digitalWrite(9, HIGH);
    break;
  }
}

void lightAll()
{
  for (int i = 1; i <= 8; i++)
  {
    light(i);
  }
}

void dark(int led)
{
  switch (led)
  {
  case 1:
    digitalWrite(2, LOW);
    break;
  case 2:
    digitalWrite(3, LOW);
    break;
  case 3:
    digitalWrite(4, LOW);
    break;
  case 4:
    digitalWrite(5, LOW);
    break;
  case 5:
    digitalWrite(6, LOW);
    break;
  case 6:
    digitalWrite(7, LOW);
    break;
  case 7:
    digitalWrite(8, LOW);
    break;
  case 8:
    digitalWrite(9, LOW);
    break;
  }
}

void darkAll()
{
  for (int i = 1; i <= 8; i++)
  {
    dark(i);
  }
}

void ledRun()
{
  for (int i = 1; i <= 8; i++)
  {
    light(i);
    delay(100);
    dark(i);
    delay(100);
  }
}

void blinkLED(int pos, int num)
{
}

void dice(int num)
{
  int MAXpos = pos + num;
  for (int i = 1; i <= num; i++)
  {
    pos++;
    light(pos);
    if (pos == MAXpos)
      break;
    delay(100);
  }
}

void receiveEvent(int howMany)
{
  while (Wire.available())
  {
    // receive one byte from Master
    incomingByte = Wire.read();
    Serial.print(incomingByte);
  }
}
