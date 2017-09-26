// master_sender.ino
// Refer to the "slave_receiver" example for use with this
#include <Wire.h>

#define redled A0
#define greenled A1
#define blueled A2

const int SLAVE_ADDRESS = 1;
char incomingByte = 0;

void rgbLED(int, int, int);

void setup() {  
  Wire.begin();         // join I2C bus as a Master
  
  Serial.begin(9600);
  Serial.println("Type something to send:");
  
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(blueled, OUTPUT);
  rgbLED(255, 255, 255);
}

void loop() {
  switch(incomingByte) {
       case '6':
            rgbLED(255, 0, 0);
          break;
        case '7':
          rgbLED(0, 255, 0);
          break;
        case '8':
          rgbLED(0, 0, 255);
          break;
        case '9':
        break;
        default:
        break;
    }
}

void rgbLED(int Rnum, int Gnum, int Bnum){
  analogWrite(redled, Rnum);
  analogWrite(greenled, Gnum);
  analogWrite(blueled, Bnum);
}

void serialEvent() {
  // read one byte from serial port
  incomingByte = Serial.read();

  // send the received data to slave
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(incomingByte);
  Wire.endTransmission();
}
