////
//
void AeroGains()
{
  //Calculates voltage to be applied to Front and Back Motors K*u
float OutP=0;
float OutY=0;
for (int it=0; it<4;it++){

OutP=OutP+Error[it]*gainP[it];
OutY=OutY+Error[it]*gainY[it];
}
  Vmotors[0]=OutP;
  Vmotors[1]=OutY;
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
        desired[0] = -0.5235;
        PitchOn = false;
      } else {
        desired[0] = 0.5235;
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
        desired[1] = -0.7853;
        YawOn = false;
      } else {
        desired[1] = 0.7853;
        YawOn = true;
      }
  }
  
}
