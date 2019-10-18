/*
Quanser QUBE Servo Startup - ACSI

An example using the Arduino UNO board to communicate with the Quanser QUBE Servo
through the microcontroller interface panel.  This implements a pseudo-controller
to demonstrate sensor read and motor write functionality.

Select 250000 baud on the Arduino Serial Tested with Arduino Software (IDE) 1.6.7.

Original file created 2016 by Quanser Inc.
www.quanser.com

Modified for ACSI 2017 by Bin Xu
www.cmu.edu
*/

// include the QUBE Servo library
#include "QUBEServo.h"

// include ACSI_lib header
#include "ACSI_lib.h"

// include the SPI library and the math library
#include <SPI.h>
#include <math.h>

// Don't touch the setup unless you decide to use interrupts
void setup() {
  // set the slaveSelectPin as an output
  pinMode (slaveSelectPin, OUTPUT);
  
  // initialize SPI
  SPI.begin();
  LEDRed = 0;
  LEDGreen = 500;
  LEDBlue = 500;
  // initialize serial communication at 250000 baud
  // (Note that 250000 baud must be selected from the drop-down list on the Arduino
  // Serial Monitor for the data to be displayed properly.)
  Serial.begin(250000);
}

float Desired  = M_PI/2; // Pre-set the desired angle as 90deg. We're going to go between 90 and -90 deg for our reference
bool new_ref = true; // Pre-set the new ref flag as true so we can imediately begin the controller
int counter = 0; // counter for rgb gammer ya
unsigned long PrevTime = 0;
float hidden_states1 = 0.0;
float hidden_states2 = 0.0;

float K_A[2][2] = {
  {1.9, -0.9},
  {1.0, 0}
};

float K_B1 = 0.5;
float K_B2 = 0.0;

float K_C1 = -0.4;
float K_C2 = 0.4;

float K_D = 2.5;



// fuckckckckcc
int Kp = 15;
int Ki = 8;
int Kd = 5;
float derivative = 0;
float last_error = 0; // Holds the previous error used for the PID controller
float integral = 0; // Holds the total error accumulated over a singer reference signals life span
float error = 0; // error between cur and ref angles
float CurTime = 0.0;
unsigned long new_ref_time;   

float reference = 0;
bool bool_t0 = true;
bool bool_t1 = true;
bool bool_A0 = true;

void loop() {
  
  // after the Arduino power is cycled or the reset pushbutton is pressed, call the resetQUBEServo function
  // Don't touch
  if (startup) {
    resetQUBEServo();
    startup = false;
  }
  
  // if the difference between the current time and the last time an SPI transaction
  // occurred is greater than the sample time, start a new SPI transaction
  // Alternatively, use a timer interrupt
  unsigned long currentMicros = micros();
  if (currentMicros - previousMicros >= sampleTime) {
    previousMicros = previousMicros + sampleTime;  

  // Set the reference point here. The function definition can be found in the QUBEServo.h file. This is also the place where we set the flag for a new reference for the timer.  
  // The reference siganl generator function 
  // 1 second = 1e6 microsecond
  unsigned long Interval = 5e6;

  // Check if the pitch ref should be switched
  if((currentMicros - PrevTime) >= Interval) {
      PrevTime = currentMicros;
      new_ref = true;
      bool_t0 = true;
      bool_t1 = true;
      bool_A0 = true;
      if (counter%2==0) {
      LEDRed = 0;
      LEDGreen = 500;
      LEDBlue = 500;
      Desired = M_PI/2;
      new_ref_time = micros();
    } else {
      LEDRed = 500;
      LEDGreen = 500;
      LEDBlue = 0;
      Desired = -M_PI/2;
      new_ref_time = micros();
      bool_t0 = true;
      bool_t1 = true;
      bool_A0 = true;
    }
    counter += 1;
  }
  //Serial.println(Desired);
  // Simple function for reading from sensors.  Data are read into global variables.  For variable definitions, see ACSI_lib.h.
  readSensors();
  // This will define the data that will be displayed at the serial terminal.
  //displayData.buildString(theta, alpha, currentSense, moduleID, moduleStatus);

//  // Here we're going to define the motor voltage to be sent to the arm. Everything that isn't defined under here is defined in the QUBEServo files
//  // Now we're going to define all of the arrays of things we need like gains and time delays natural frequencies etc.
  float wn = 9; // Natural frequency of the system
  float zeta = 0.1; // Dampening found in the system. In this case I guess it would be air resistance?
  float K = exp(-zeta*M_PI/sqrt(1-zeta*zeta)); // gain
  
  float A0 = 1/(1+2*K+K*K);
  float A1 = (2*K)/(1+2*K+K*K);
  float A2 = (K*K)/(1+2*K+K*K);     
  float t0 = M_PI/(wn*sqrt(1-zeta*zeta))*1000000;
  float t1 = 2*M_PI/(wn*sqrt(1-zeta*zeta))*1000000;
  //Serial.print(t0);Serial.print("  ");Serial.println(t1);
  
////  // If this is a new reference signal make sure to start the timer
  //Serial.print(new_ref);
  if(new_ref){

    if(bool_A0){
      reference = A0*Desired; // This is the constant gain 
      bool_A0 = false;
    }
    //Serial.println(A0);
    //Serial.println(A0*Desired);
//    new_ref_time = micros();
    //total_error = 0; // accumulates error over time. Resets for every new reference
   //Serial.println(Desired);    
  CurTime = micros();
  //Serial.print(CurTime); Serial.print("  "); Serial.println(new_ref_time);
  if (CurTime - new_ref_time >= t0 && bool_t0){
    reference += A1*Desired;
    //Serial.print("Entered t0 at: "); Serial.println((CurTime - new_ref_time)/1000000.0);
     bool_t0 = false;
  }
  
  // Check to see if we add the third signal or not
  if (CurTime - new_ref_time >= t1 && bool_t1){
    reference += A2*Desired;
    //Serial.print("Entered t1 at: ");Serial.println((CurTime - new_ref_time)/1000000.0);
    bool_t1 = false;
    new_ref = false;
    //Serial.println("");
  }

  }
//  // Check to see if we add the second signal or not
//  CurTime = micros();
//  if (CurTime - new_ref_time >= t0){
//    reference += A1*Desired;
//    Serial.print("Entered t0 at: "); Serial.println((CurTime - new_ref_time)/1000000);
//  }
//  
//  // Check to see if we add the third signal or not
//  if (CurTime - new_ref_time >= t1){
//    reference += A2*Desired;
//    Serial.print("Entered t1 at: ");Serial.println((CurTime - new_ref_time)/1000000);
//  }
    error = reference + theta;
    Serial.println(reference);
//    error = Desired + theta;
//    Serial.println(Desired);
  
  //Serial.print(reference);Serial.print("  ");Serial.println(Desired);
  motorVoltage = K_C1*hidden_states1 + K_C2*hidden_states2 + K_D*error;
  hidden_states1 = K_A[0][0]*hidden_states1 + K_A[0][1]*hidden_states2 + K_B1*error;
  hidden_states2 = K_A[1][0]*hidden_states1 + K_A[1][1]*hidden_states2 + K_B2*error;
//  Serial.println(K_A[1][0]);
//
//
//
//
//  
//  Serial.print("Desired- ");Serial.println(Desired);
//  Serial.print("Current- ");Serial.println(theta);
//  Serial.print("Error- ");Serial.println(error);



//   Check for saturation
  float max_voltage = 3.5;
  float min_voltage = -3.5;
  if (motorVoltage >= max_voltage){
    motorVoltage = max_voltage;
  }
  if (motorVoltage <= min_voltage) {
    motorVoltage = min_voltage;
  }

  //This command actually writes the data to the Qube servo
  driveMotor();
  }

  
  // print data to the Arduino Serial Monitor in between SPI transactions
  // (Note that the Serial.print() function is time consuming.  Printing the entire
  // string at once would exceed the sample time required to balance the pendulum.)
  else {  //We're in between samples
    // only print if there's a string ready to be printed, and there's enough time before the next SPI transaction
    if ( (displayData.dDataReady) && (currentMicros - previousMicros <= (sampleTime - 100)) ) {
      // if there is room available in the serial buffer, print one character
      if(Serial.availableForWrite() > 0) {
        Serial.print(displayData.dData[displayData.dDataIndex]);
        displayData.dDataIndex = displayData.dDataIndex + 1;
        // if the entire string has been printed, clear the flag so a new string can be obtained
        if(displayData.dDataIndex == displayData.dData.length()) {
          displayData.dDataReady = false;
        }
      }
    }
  }
}
