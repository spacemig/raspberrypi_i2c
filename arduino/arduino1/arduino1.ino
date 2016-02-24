// Wire Master Writer
// Writes data to an I2C/TWI slave device

#include <Wire.h>


void setup() {
    pinMode(13, OUTPUT);
    
    Wire.begin(); // join i2c bus (address optional for master)
    
    Serial.begin(9600); // start serial for output
    Serial.println("Ready");
    
}

byte x = 0;

void loop() {
  delay(1000);
  Serial.println("Ready");

  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  x++;
}




