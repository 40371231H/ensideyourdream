// master_sender.ino
// Refer to the "slave_receiver" example for use with this
#include <Wire.h>

#define redled A0
#define greenled A1
#define blueled A2

const int SLAVE_ADDRESS = 1;
char incomingByte = 0;

void setup() {  
  Wire.begin();         // join I2C bus as a Master
  
  Serial.begin(9600);
  Serial.println("Type something to send:");
  
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(blueled, OUTPUT);
}

void loop() {
  switch(incomingByte) {
       case '6':
            analogWrite(redled, 255);
            analogWrite(greenled, 0);
            analogWrite(blueled, 0);
          break;
        case '7':
          analogWrite(redled, 0);
            analogWrite(greenled, 255);
            analogWrite(blueled, 0);
          break;
        case '8':
          analogWrite(redled, 0);
            analogWrite(greenled, 0);
            analogWrite(blueled, 255);
          break;
        case '9':
        break;
        default:
        break;
    }
}

void serialEvent() {
  // read one byte from serial port
  incomingByte = Serial.read();

  // send the received data to slave
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(incomingByte);
  Wire.endTransmission();
}
