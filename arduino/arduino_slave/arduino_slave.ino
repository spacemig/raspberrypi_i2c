// Wire Slave Receiver
#include <Wire.h>

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

void loop() {
    delay(100);
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

// callback for sending data
void sendData(){
    Wire.write(number);
}
