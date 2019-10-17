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
  
  // initialize serial communication at 250000 baud
  // (Note that 250000 baud must be selected from the drop-down list on the Arduino
  // Serial Monitor for the data to be displayed properly.)
  Serial.begin(250000);
}
bool new_ref = true; // Pre-set the new ref flag as true so we can imediately begin the controller
int counter = 0;
unsigned long PrevTime = 0;

// Used for the sine wave reference generator
float Sample_Time = 100000;
int sin_input = 0;
float one_second = 1000000; // One second in microseconds
// We need to know how many points the sine wave should generate for a single cycle given the sample rate.
// Since we're running at 1hz we need to know how many points per second so 
float ref_sample_num = one_second/Sample_Time;
// Then we know for every cycle we need to increment the sine radian input by
float sin_increment = 2*M_PI/ref_sample_num;
double Desired = 0;

// Used for the ilc part of the code
int itter_count = 0; // Counter for how many itterations we've don so far
int itter_max = 15; // We're only doing 15 itterations 
int itter_length = 5; // How long each itteration is in seconds
int num_u_ilc = ref_sample_num * itter_length + 1; // How long the u_ilc array should be
float u_ilc[101] = {0}; // The u_ilc initialization
int u_ilc_count = 0; // Counter for were we are in each itteration
float Alpha = 5.0; // Learning rate
// I wonder if I'm asking too much for space of the arduino...
float err[101] = {0};
float tot_err = 0;

void loop() {
  
  // after the Arduino power is cycled or the reset pushbutton is pressed, call the resetQUBEServo function
  // Don't touch
  if (startup) {
    resetQUBEServo();
    startup = false;
    /////////////////////////////////////////HALP/////////////////////////////////////
    // Generate the reference signal here so we don't have to do it every loop

    /////////////////////////////////////////HALP/////////////////////////////////////
  }
  
  // if the difference between the current time and the last time an SPI transaction
  // occurred is greater than the sample time, start a new SPI transaction
  // Alternatively, use a timer interrupt
  unsigned long currentMicros = micros();
  if (currentMicros - previousMicros >= sampleTime) {
    previousMicros = previousMicros + sampleTime;  
  
  // Simple function for reading from sensors.  Data are read into global variables.  For variable definitions, see ACSI_lib.h.
  readSensors();
  
  /////////////////////////////////////////HALP/////////////////////////////////////
  

  // So now we want to start the ILC part of this code. 
  // First check how many itterations we've done
  if (itter_count < itter_max) {
    // If we still need to do more itterations go through the calculations 
    
    // Now check where we are within the itteration
    if (u_ilc_count < num_u_ilc) {
      
      // If we have more to go within the itteration go through the motions
      // The reference generator for the sine wave at 1hz. This will generate a sine wave at 1hz regardless of the sampling time.
      Desired = sin(sin_input);
      sin_input += sin_increment;
      // Now calculate the motorVoltage based on the current ilc
      err[u_ilc_count] = Desired - theta;
      tot_err += err[u_ilc_count];
      float Kp = 10.0; // Our really simple gain controller
      motorVoltage = Kp * err + u_ilc[u_ilc_count];
      driveMotor();

      // Calculate the new previous u_ilc here as well using error
      if (u_ilc_count > 0) {
        u_ilc[u_ilc_count-1] += Alpha * err; 
      }
    } else {
      // If we're at the end of the itteration increment the itter_counter and reset the u_ilc_counter
      itter_count += 1;
      u_ilc_count = 0;      
      sin_input = 0;

      // Calculate the std for the error so we can then publish it.
      float mean_err = tot_err/num_u_ilc;
      float std_tot_err = 0;
      for (int a = 0; a < num_u_ilc; a++) {
        std_tot_err += pow((err[a] - mean_err), 2); 
      }
      float std_almost_err = std_tot_err/num_u_ilc;
      float std_err = sqrt(std_almost_err);
      Serial.print(std_err); // Finally push the error to serial monitor
      
      // Even though we're restarting that doesn't mean we get to not push the motors..time waits for no one!
      Desired = sin(sin_input);
      sin_input += sin_increment;
      // Now calculate the motorVoltage based on the current ilc
      err[u_ilc_count] = Desired - theta;
      tot_err = err[u_ilc_count];
      float Kp = 10.0; // Our really simple gain controller
      motorVoltage = Kp * err[u_ilc_count] + u_ilc[u_ilc_count]; 
      driveMotor();
    }
  } else {
    
    // If we're done just loop forever doing nothing to not output anything
    for(;;){
      // You have no power here hahahaha!
    }
  }
  
  /////////////////////////////////////////HALP/////////////////////////////////////

  
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
