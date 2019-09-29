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

//
//
void SetpointGen()
{
  //  Generates setpoints for Pitch and Yaw angles at specific times
  // Note that this is not Real-Time control. The units called seconds should be renamed..
  //
    if (milisecs>=1000){seconds++; milisecs=0;}
     if (seconds >= 4 && seconds <8 ){
      desired[0] = 0.35;
       desired[1] = 0;
      LEDRed = 0;
      LEDGreen = 0;
      LEDBlue = 999;
      return;
      }
      
     if (seconds >= 8 && seconds <12){
       desired[0] = -0.35;
       desired[1] = 0;
      LEDRed = 999;
      LEDGreen = 500;
      LEDBlue = 0;
      return;
      }
 if (seconds >=12 && seconds <16){
      desired[0] = 0;
      desired[0] = 0;
      LEDRed = 0;
      LEDGreen = 0;
      LEDBlue = 999;
      return;
      }

      if (seconds >= 16 && seconds <20 ){
      desired[0] = 0;
       desired[1] = 0.4;
      LEDRed = 999;
      LEDGreen = 500;
      LEDBlue = 0;
      return;
      }
      
     if (seconds >= 20 && seconds <24){
      //seconds=0;
       desired[0] = 0;
       desired[1] = -0.4;
      LEDRed = 0;
      LEDGreen = 0;
      LEDBlue = 999;
      return;
      }
        if (seconds>=24){ 
       seconds=0;
       desired[0] = 0;
       desired[1] = 0;
      LEDRed = 999;
      LEDGreen = 500;
      LEDBlue = 0;
      return;
      }
      
       
      
}
void ReferenceGenerator()
{
  // check the current time
  float current = millis() ; 
  
  // time interval = current time - start time 
  float timeInt = current - start ; 
  
  // change the Pitch Period
  // if the time interval >  (i*PitchPeriod) && time interval < (i*PitchPeriod + eps) 
  if ( (timeInt > (iPitch * PitchPeriod)) && (timeInt < (iPitch * PitchPeriod + eps)) ){
    // if the PitchRef > 0 
    if (desired[0] > 0) {
      // then set PitchRef = -ref
      desired[0] = -0.5236 ; 
      iPitch += 1 ; 
      LEDGreen = 999 ; 
    }
    
    // elseif the PitchRef < 0 
    else if (desired[0] < 0) {
      // then set PitchRef = +ref
      desired[0] = 0.5236 ; 
      iPitch += 1 ; 
      LEDBlue = 999 ; 
    }
  }
  

  // change the Yaw Period
  if ( (timeInt > (iYaw * YawPeriod)) && (timeInt < (iYaw * YawPeriod + eps)) ){
    if (desired[1] > 0) {
      desired[1] = -0.7854 ; 
      iPitch += 1 ; 
    }
    
    // elseif the PitchRef < 0 
    else if (desired[1] < 0) {
      desired[1] = 0.7854 ; 
      iPitch += 1 ; 
    }
  }
}
