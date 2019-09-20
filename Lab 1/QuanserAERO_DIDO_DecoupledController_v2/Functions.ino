////
//
//void AeroGains()
//{
//  //Calculates voltage to be applied to Front and Back Motors K*u
//float OutP=0;
//float OutY=0;
//for (int it=0; it<4;it++){
//
//OutP=OutP+Error[it]*gainP[it];
//OutY=OutY+Error[it]*gainY[it];
//}
//  Vmotors[0]=OutP;
//  Vmotors[1]=OutY;
//}

//
//
//void SetpointGen_Team4()
//{
//  if (milisecs>=1000){secs++; milisecs=0;Serial.println(secs);}
//  // check that pitchOn variable is true
//  if (pitchOn == 1){
//     desired[1] = 0.5236 ; // set value of pitch reference signal HIGH
//     LEDRed = 0;
//     LEDGreen = 0;
//     LEDBlue = 999 ; 
//     // check to see if we need to update pitchOn
//     if (secs%pitchRate == 0){
//      Serial.println("Pitch ON") ; 
//      Serial.println(secs%pitchRate) ; 
//      Serial.println(pitchOn) ; 
//      pitchOn = 0; // if the time is a multiple of the pitchRate then change the value
//     }
//  }
//  if (pitchOn == 0){
//    desired[1] = -0.5236 ; // set value of pitch reference signal LOW
//    LEDRed = 0;
//    LEDGreen = 999;
//    LEDBlue = 0;
//    // check to see if we need to update pitchOn
//    if (secs%pitchRate == 0){
//      Serial.println("Pitch OFF") ; 
//      Serial.println(secs%pitchRate) ; 
//      Serial.println(pitchOn) ; 
//      pitchOn = 1; // if the time is a multiple of the pitchRate then change the value
//    }
//  }
//  // can I have two if statements back to back?
//  // check that yawOn variable is true
//  if (yawOn == 1){
//     desired[0] = 0.7845; // set value of yaw reference signal HIGH
//     // check to see if we need to update yawOn
//     if (secs%yawRate == 0){
//      yawOn = 0; // if the time is a multiple of the yawRate then change the value
//     }
//  }
//  if (yawOn == 0){
//    desired[0] = -0.7854; // set value of yaw reference signal LOW
//    // check to see if we need to update yawOn
//    if (secs%yawRate == 0){
//      yawOn = 1; // if the time is a multiple of the yawRate then change the value
//    }
//  }
//  return;
//}
void SetpointGen_Team4()
{
  if (milisecs>=1000){secs++; secs2++; milisecs=0;Serial.print("Seconds (pitch):");Serial.println(secs);Serial.print("Seconds (yaw):");Serial.println(secs2);}
  // --------------------- PITCH ---------------------------------
  if (secs>=pitchRate && secs<(pitchRate+1)){
    if (pitchOn == 0){
      Serial.println("Change pitchRate to 1") ; 
      //desired[0] = 0.5236 ; // set value of pitch reference signal HIGH
      desired[0] = 0 ; 
      LEDRed = 0;
      LEDGreen = 0;
      LEDBlue = 999 ; 
      pitchOn = 1 ; 
      secs = 0 ; 
      return ; 
    }
    else {
      Serial.println("Change pitchRate to 0") ; 
      //desired[0] = -0.5236 ; // set value of pitch reference signal LOW
      desired[0] = 0 ; 
      LEDRed = 0;
      LEDGreen = 999;
      LEDBlue = 0;
      pitchOn = 0 ; 
      secs = 0 ; 
      return ; 
    }
  }
  // ----------------------- YAW -----------------------------
  if (secs2>=yawRate && secs2<(yawRate+1)){
  if (yawOn == 0){
    Serial.println("Change yawRate to 1") ; 
    //desired[1] = 0.7845; // set value of yaw reference signal HIGH    
    desired[1] = 0 ; 
//    LEDRed = 0;
//    LEDGreen = 0;
//    LEDBlue = 999 ; 
    yawOn = 1 ; 
    secs2 = 0 ; 
    return ; 
  }
  else {
    Serial.println("Change yawRate to 0") ; 
    //desired[1] = -0.7845 ; // set value of yaw reference signal LOW
    desired[1] = 0 ; 
//    LEDRed = 0;
//    LEDGreen = 999;
//    LEDBlue = 0;
    yawOn = 0 ; 
    secs2 = 0 ; 
    return ; 
  }
 }
}
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
