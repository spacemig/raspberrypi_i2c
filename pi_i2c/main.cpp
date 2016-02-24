#include <iostream>
#include <errno.h>
#include <unistd.h>

#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port

//#include <wiringPiI2C.h>

#define BOARD RASPBERRY_PI
#include "gnublin/gnublin.h"
// ERROR: //home/pi/test/pi_i2c: /usr/lib/arm-linux-gnueabihf/libstdc++.so.6: version `GLIBCXX_3.4.20' not found (required by //home/pi/test/pi_i2c
// RESOLVED: after updating wheezy to jessie

using namespace std;

int main() //int argc, char *argv[]
{
    cout << "Hello I2C!" << endl;


    //    int file_i2c;
    //    int length;
    //    char buffer[60] = {0};

    //    //----- OPEN THE I2C BUS -----
    //    char *filename = (char*)"/dev/i2c-1";
    //    if ((file_i2c = open(filename, O_RDWR)) < 0)
    //    {
    //        //ERROR HANDLING: you can check errno to see what went wrong
    //        cout << "Failed to open the i2c bus" << endl;
    //        //return;
    //    }

    //    int addr = 0x04;          //<<<<<The I2C address of the slave
    //    if (ioctl(file_i2c, I2C_SLAVE, addr) < 0)
    //    {
    //        cout << "Failed to acquire bus access and/or talk to slave." << endl;
    //        //ERROR HANDLING; you can check errno to see what went wrong
    //        //return;
    //    }


    //    while (1) {
    //        //----- READ BYTES -----
    //        length = 15;			//<<< Number of bytes to read
    //        if (read(file_i2c, buffer, length) != length)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
    //        {
    //            //ERROR HANDLING: i2c transaction failed
    //            cout << "Failed to read from the i2c bus." << endl;
    //        }
    //        else
    //        {
    //            string dataIn = string(buffer);
    //            std::size_t found = dataIn.find("\n");
    //            if (found!=std::string::npos) {
    //                //std::cout << "first 'needle' found at: " << found << '\n';
    //                dataIn = dataIn.substr(0,found);
    //            }
    //            cout << "Data read: " << dataIn << endl;
    //        }

    //        usleep(1e5);
    //    }




    gnublin_i2c i2c;

    i2c.setAddress(0x04); // set the address of the slave you want to read/write

    //        unsigned char buffer[8];
    unsigned char RxBuf[15];

    //    buffer[0]=0x22;

    //    //i2c.send()
    //    //i2c.send(buffer,5);
    //    i2c.send(0x04, buffer, 2);   //send 2 bytes from buffer to register-address 0x12

    while (1) {
        i2c.receive(RxBuf, 15);       // read 3 bytes and store them in RxBuf
        //i2c.receive(0x23, RxBuf, 3);  // read from  tegister-address 0x23 3 bytes and store them in RxBuf

        string dataIn = string((const char *) RxBuf);
        std::size_t found = dataIn.find("\n");
        if (found!=std::string::npos) {
            //std::cout << "first 'needle' found at: " << found << '\n';
            dataIn = dataIn.substr(0,found);
        }
        cout << "Data read: " << dataIn << endl;
        usleep(1e5);
    }

    return 0;
}
