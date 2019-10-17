/*
24-774 Advanced Control System Integration
*/

#ifndef ACSI_lib_h
#define ACSI_lib_h

// extern const int slaveSelectPin;

extern bool startup;  // true the first time the sketch is run after the Arduino power is cycled or the reset pushbutton is pressed

extern unsigned long previousMicros;  // used to store the last time the SPI data was written
extern const long sampleTime;  // set the sample time (the interval between SPI transactions) to 1000us = 1ms

// set pin 10 as the slave select for the Quanser QUBE
// (Note that if a different pin is used for the slave select, pin 10 should be set as
// an output to prevent accidentally putting the Arduino UNO into slave mode.)
extern const int slaveSelectPin;

// initialize the SPI data to be written
extern byte mode;                      // normal mode = 1
extern byte writeMask;         // Bxxxxxx11 to enable the motor, Bxxx111xx to enable the LEDs, Bx11xxxxx to enable writes to the encoders
extern byte LEDRedMSB;                 // red LED command MSB
extern byte LEDRedLSB;                // red LED command LSB
extern byte LEDGreenMSB;               // green LED command MSB
extern byte LEDGreenLSB;               // green LED command LSB
extern byte LEDBlueMSB;                 // blue LED command MSB
extern byte LEDBlueLSB;                // blue LED command LSB
extern byte encoder0ByteSet[3];  // encoder0 is set to this value only when writes are enabled with writeMask
extern byte encoder1ByteSet[3];  // encoder1 is set to this value only when writes are enabled with writeMask
extern byte motorMSB;               // motor command MSB must be B1xxxxxxx to enable the amplifier
extern byte motorLSB;                  // motor command LSB

// initialize the SPI data to be read
extern byte moduleIDMSB;               // module ID MSB (module ID for the QUBE Servo is 777 decimal)
extern byte moduleIDLSB;               // module ID LSB
extern byte encoder0Byte[3];     // arm encoder counts
extern byte encoder1Byte[3];     // pendulum encoder counts
extern byte tach0Byte[3];        // arm tachometer
extern byte moduleStatus;              // module status (the QUBE Servo sends status = 0 when there are no errors)
extern byte currentSenseMSB;           // motor current sense MSB 
extern byte currentSenseLSB;           // motor current sense LSB

// global variables for LED intensity (999 is maximum intensity, 0 is off)
extern int LEDRed;
extern int LEDGreen;
extern int LEDBlue;

// Setup global variables for wrap up function
extern float alpha;  // pendulum angle in radians
extern float theta;  // arm angle in radians
extern float currentSense;
extern int moduleID;
extern float motorVoltage;

//Setup serial builder
extern Display displayData;

void readSensors();
void driveMotor();
void resetQUBEServo();

#endif
