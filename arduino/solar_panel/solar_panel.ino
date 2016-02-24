// Wire Slave Receiver
#include <Wire.h>
#include<stdlib.h>


#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;

void setup() {
    pinMode(13, OUTPUT);
    Serial.begin(9600); // start serial for output
    // initialize i2c as slave
    Wire.begin(SLAVE_ADDRESS);
    //Wire.begin(8); // join i2c bus with address #8

    // define callbacks for i2c communication
    Wire.onReceive(receiveData);
    Wire.onRequest(sendData);

    Serial.println("Ready!");
}

int voltage = 0;

void loop() {
    delay(100);

    // send data every second
    //Wire.beginTransmission(SLAVE_ADDRESS); // transmit to device #8
    //Wire.write(14);
    //Wire.endTransmission();    // stop transmitting
    Serial.println(voltage);
    voltage++;
    
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
// callback for received data
void receiveData(int byteCount){

//    while(1 < Wire.available()) {
      while(Wire.available()) {
        number = Wire.read();
        Serial.print("data received:");
        Serial.println(number);

        if (number == 1){

            if (state == 0){
                digitalWrite(13, HIGH); // set the LED on
                state = 1;
            }
            else{
                digitalWrite(13, LOW); // set the LED off
                state = 0;
            }
        }
    }
    //int x = Wire.read();    // receive byte as an integer
  //Serial.println(x);         // print the integer
}

char outstr[15];
String stringOne = "";
// callback for sending data
void sendData(){
    //Wire.write(voltage);
    //Wire.write("volt,");
    //Wire.write(voltage);
    dtostrf(voltage,5,2,outstr);
    stringOne = String("volt,") + outstr + String("\n");
    stringOne.toCharArray(outstr,15);
    Wire.write(outstr);
    //Wire.write("\n");
}
