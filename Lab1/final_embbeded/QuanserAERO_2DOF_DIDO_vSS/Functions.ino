// Function that sets the Vmotors values based on the hidden states and the error.
// Using the ss representation of the controller we do the calculation
// Y(k) = Cx(k) + Du(k)
// x(k+1) = Ax(k) + Bu(k)
// where Y is the motor voltage, u is the error, and x is the hidden states of the system
// There really is no reason to use this many for loops and is probably worse in terms of time and computations needed 
// but I'm rolling with it anyways, YORO!
void AeroDIDOcontroller()
{
  // Arrays to hold the new calculated values
  float N_HiddenStates[ArraySize1] = {0, 0, 0, 0, 0, 0};
  float N_MotorVol[ArraySize2] = {0, 0};

  // Function will run for the length of the 
  for (int a = 0; a < ArraySize1; a++) {
    
    // Calculate the motor voltages and hidden states
    for (int b = 0; b < ArraySize1; b++) {
      if (a < ArraySize2) {
        N_MotorVol[a] += K_C[a][b] * HiddenStates[b];  
      }
      N_HiddenStates[a] += K_A[a][b] * HiddenStates[b] + K_B[a][b] * Error[b];  
    }
    
    // Transfer the new values over to the loop variables
    HiddenStates[a] = N_HiddenStates[a];
    if (a < ArraySize2) {
      MotorVol[a] = N_MotorVol[a];  
    }
  }
}

// The reference siganl generator function 
// 1 second = 1e6 microsecond
void ReferenceSignalGenerator() {
  unsigned long IntervalPitch = 15.7e6;
  unsigned long IntervalYaw = 12.6e6;

  // Check if the pitch ref should be switched
  if((CurTime - PrevTimePitch) >= IntervalPitch) {
      LEDRed = 0;
      LEDGreen = 500;
      LEDBlue = 500;
      PrevTimePitch = CurTime;
      if (PitchOn) {
        Desired[0] = -0.5235;
        PitchOn = false;
      } else {
        Desired[0] = 0.5235;
        PitchOn = true;
      }
  }

  // Check if the yaw ref should be switched
  if((CurTime - PrevTimeYaw) >= IntervalYaw) {
      LEDRed = 500;
      LEDGreen = 500;
      LEDBlue = 0;
      PrevTimeYaw = CurTime;
      if (PitchOn) {
        Desired[1] = -0.7853;
        YawOn = false;
      } else {
        Desired[1] = 0.7853;
        YawOn = true;
      }
  }
  
}
