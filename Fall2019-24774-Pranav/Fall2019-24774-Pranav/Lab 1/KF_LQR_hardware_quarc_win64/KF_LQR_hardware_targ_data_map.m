  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (KF_LQR_hardware_P)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_P.Green_color
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KF_LQR_hardware_P.Yellow_color
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% KF_LQR_hardware_P.PitchBiasRemoval_end_time
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% KF_LQR_hardware_P.PitchBiasRemoval_start_time
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% KF_LQR_hardware_P.PitchBiasRemoval_switch_id
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_P.HILReadTimebase_clock
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_P.HILReadTimebase_analog_channels
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KF_LQR_hardware_P.HILWrite_analog_channels
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 2;
	
	  ;% KF_LQR_hardware_P.HILReadTimebase_encoder_channel
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 4;
	
	  ;% KF_LQR_hardware_P.HILReadTimebase_other_channels
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 6;
	
	  ;% KF_LQR_hardware_P.HILWrite_other_channels
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 10;
	
	  ;% KF_LQR_hardware_P.HILReadTimebase_samples_in_buff
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 57;
      section.data(57)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_P.Lykyhatkk1_Y0
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KF_LQR_hardware_P.u4V_UpperSat
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% KF_LQR_hardware_P.u4V_LowerSat
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% KF_LQR_hardware_P.x_avg_n_Y0
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 3;
	
	  ;% KF_LQR_hardware_P.unity_Value
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 4;
	
	  ;% KF_LQR_hardware_P.UnitDelay_InitialCondition
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 5;
	
	  ;% KF_LQR_hardware_P.Sumk1n1xk_InitialCondition
	  section.data(7).logicalSrcIdx = 18;
	  section.data(7).dtTransOffset = 6;
	
	  ;% KF_LQR_hardware_P.zero_Y0
	  section.data(8).logicalSrcIdx = 19;
	  section.data(8).dtTransOffset = 7;
	
	  ;% KF_LQR_hardware_P.Vbiased_Y0
	  section.data(9).logicalSrcIdx = 20;
	  section.data(9).dtTransOffset = 8;
	
	  ;% KF_LQR_hardware_P.Vunbiased_Y0
	  section.data(10).logicalSrcIdx = 21;
	  section.data(10).dtTransOffset = 9;
	
	  ;% KF_LQR_hardware_P.Stepstart_time_Y0
	  section.data(11).logicalSrcIdx = 22;
	  section.data(11).dtTransOffset = 10;
	
	  ;% KF_LQR_hardware_P.Stepstart_time_YFinal
	  section.data(12).logicalSrcIdx = 23;
	  section.data(12).dtTransOffset = 11;
	
	  ;% KF_LQR_hardware_P.Stepend_time_Y0
	  section.data(13).logicalSrcIdx = 24;
	  section.data(13).dtTransOffset = 12;
	
	  ;% KF_LQR_hardware_P.Stepend_time_YFinal
	  section.data(14).logicalSrcIdx = 25;
	  section.data(14).dtTransOffset = 13;
	
	  ;% KF_LQR_hardware_P.HILInitialize_OOTerminate
	  section.data(15).logicalSrcIdx = 26;
	  section.data(15).dtTransOffset = 14;
	
	  ;% KF_LQR_hardware_P.HILInitialize_OOExit
	  section.data(16).logicalSrcIdx = 27;
	  section.data(16).dtTransOffset = 15;
	
	  ;% KF_LQR_hardware_P.HILInitialize_OOStart
	  section.data(17).logicalSrcIdx = 28;
	  section.data(17).dtTransOffset = 16;
	
	  ;% KF_LQR_hardware_P.HILInitialize_OOEnter
	  section.data(18).logicalSrcIdx = 29;
	  section.data(18).dtTransOffset = 17;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AOFinal
	  section.data(19).logicalSrcIdx = 30;
	  section.data(19).dtTransOffset = 18;
	
	  ;% KF_LQR_hardware_P.HILInitialize_OOFinal
	  section.data(20).logicalSrcIdx = 31;
	  section.data(20).dtTransOffset = 19;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AIHigh
	  section.data(21).logicalSrcIdx = 32;
	  section.data(21).dtTransOffset = 22;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AILow
	  section.data(22).logicalSrcIdx = 33;
	  section.data(22).dtTransOffset = 23;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AOHigh
	  section.data(23).logicalSrcIdx = 34;
	  section.data(23).dtTransOffset = 24;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AOLow
	  section.data(24).logicalSrcIdx = 35;
	  section.data(24).dtTransOffset = 25;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AOInitial
	  section.data(25).logicalSrcIdx = 36;
	  section.data(25).dtTransOffset = 26;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AOWatchdog
	  section.data(26).logicalSrcIdx = 37;
	  section.data(26).dtTransOffset = 27;
	
	  ;% KF_LQR_hardware_P.HILInitialize_OOInitial
	  section.data(27).logicalSrcIdx = 38;
	  section.data(27).dtTransOffset = 28;
	
	  ;% KF_LQR_hardware_P.HILInitialize_OOWatchdog
	  section.data(28).logicalSrcIdx = 39;
	  section.data(28).dtTransOffset = 31;
	
	  ;% KF_LQR_hardware_P.PitchRef_Amplitude
	  section.data(29).logicalSrcIdx = 40;
	  section.data(29).dtTransOffset = 34;
	
	  ;% KF_LQR_hardware_P.PitchRef_Frequency
	  section.data(30).logicalSrcIdx = 41;
	  section.data(30).dtTransOffset = 35;
	
	  ;% KF_LQR_hardware_P.YawRef_Amplitude
	  section.data(31).logicalSrcIdx = 42;
	  section.data(31).dtTransOffset = 36;
	
	  ;% KF_LQR_hardware_P.YawRef_Frequency
	  section.data(32).logicalSrcIdx = 43;
	  section.data(32).dtTransOffset = 37;
	
	  ;% KF_LQR_hardware_P.Constant_Value
	  section.data(33).logicalSrcIdx = 44;
	  section.data(33).dtTransOffset = 38;
	
	  ;% KF_LQR_hardware_P.Constant1_Value
	  section.data(34).logicalSrcIdx = 45;
	  section.data(34).dtTransOffset = 39;
	
	  ;% KF_LQR_hardware_P.X0_Value
	  section.data(35).logicalSrcIdx = 46;
	  section.data(35).dtTransOffset = 40;
	
	  ;% KF_LQR_hardware_P.Internal_D
	  section.data(36).logicalSrcIdx = 47;
	  section.data(36).dtTransOffset = 44;
	
	  ;% KF_LQR_hardware_P.Saturation_UpperSat
	  section.data(37).logicalSrcIdx = 48;
	  section.data(37).dtTransOffset = 52;
	
	  ;% KF_LQR_hardware_P.Saturation_LowerSat
	  section.data(38).logicalSrcIdx = 49;
	  section.data(38).dtTransOffset = 53;
	
	  ;% KF_LQR_hardware_P.NoControl_Value
	  section.data(39).logicalSrcIdx = 50;
	  section.data(39).dtTransOffset = 54;
	
	  ;% KF_LQR_hardware_P.MotorEnable_Threshold
	  section.data(40).logicalSrcIdx = 51;
	  section.data(40).dtTransOffset = 56;
	
	  ;% KF_LQR_hardware_P.LEDColour_Threshold
	  section.data(41).logicalSrcIdx = 52;
	  section.data(41).dtTransOffset = 57;
	
	  ;% KF_LQR_hardware_P.Countstorads_Gain
	  section.data(42).logicalSrcIdx = 53;
	  section.data(42).dtTransOffset = 58;
	
	  ;% KF_LQR_hardware_P.Internal_A
	  section.data(43).logicalSrcIdx = 54;
	  section.data(43).dtTransOffset = 60;
	
	  ;% KF_LQR_hardware_P.Internal_B
	  section.data(44).logicalSrcIdx = 55;
	  section.data(44).dtTransOffset = 61;
	
	  ;% KF_LQR_hardware_P.Internal_C
	  section.data(45).logicalSrcIdx = 56;
	  section.data(45).dtTransOffset = 62;
	
	  ;% KF_LQR_hardware_P.Internal_D_p
	  section.data(46).logicalSrcIdx = 57;
	  section.data(46).dtTransOffset = 63;
	
	  ;% KF_LQR_hardware_P.Internal_InitialCondition
	  section.data(47).logicalSrcIdx = 58;
	  section.data(47).dtTransOffset = 64;
	
	  ;% KF_LQR_hardware_P.Internal_A_n
	  section.data(48).logicalSrcIdx = 59;
	  section.data(48).dtTransOffset = 65;
	
	  ;% KF_LQR_hardware_P.Internal_B_d
	  section.data(49).logicalSrcIdx = 60;
	  section.data(49).dtTransOffset = 66;
	
	  ;% KF_LQR_hardware_P.Internal_C_i
	  section.data(50).logicalSrcIdx = 61;
	  section.data(50).dtTransOffset = 67;
	
	  ;% KF_LQR_hardware_P.Internal_D_a
	  section.data(51).logicalSrcIdx = 62;
	  section.data(51).dtTransOffset = 68;
	
	  ;% KF_LQR_hardware_P.Internal_InitialCondition_i
	  section.data(52).logicalSrcIdx = 63;
	  section.data(52).dtTransOffset = 69;
	
	  ;% KF_LQR_hardware_P.A_Value
	  section.data(53).logicalSrcIdx = 64;
	  section.data(53).dtTransOffset = 70;
	
	  ;% KF_LQR_hardware_P.B_Value
	  section.data(54).logicalSrcIdx = 65;
	  section.data(54).dtTransOffset = 86;
	
	  ;% KF_LQR_hardware_P.C_Value
	  section.data(55).logicalSrcIdx = 66;
	  section.data(55).dtTransOffset = 94;
	
	  ;% KF_LQR_hardware_P.KalmanGainL_Value
	  section.data(56).logicalSrcIdx = 67;
	  section.data(56).dtTransOffset = 102;
	
	  ;% KF_LQR_hardware_P.D_Value
	  section.data(57).logicalSrcIdx = 68;
	  section.data(57).dtTransOffset = 110;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AIConfiguration
	  section.data(2).logicalSrcIdx = 70;
	  section.data(2).dtTransOffset = 1;
	
	  ;% KF_LQR_hardware_P.HILInitialize_DOWatchdog
	  section.data(3).logicalSrcIdx = 71;
	  section.data(3).dtTransOffset = 2;
	
	  ;% KF_LQR_hardware_P.HILInitialize_EIInitial
	  section.data(4).logicalSrcIdx = 72;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 2;
	
	  ;% KF_LQR_hardware_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 75;
	  section.data(3).dtTransOffset = 4;
	
	  ;% KF_LQR_hardware_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 76;
	  section.data(4).dtTransOffset = 6;
	
	  ;% KF_LQR_hardware_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 77;
	  section.data(5).dtTransOffset = 10;
	
	  ;% KF_LQR_hardware_P.HILInitialize_OOChannels
	  section.data(6).logicalSrcIdx = 78;
	  section.data(6).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 80;
	  section.data(2).dtTransOffset = 1;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 81;
	  section.data(3).dtTransOffset = 2;
	
	  ;% KF_LQR_hardware_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 82;
	  section.data(4).dtTransOffset = 3;
	
	  ;% KF_LQR_hardware_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 83;
	  section.data(5).dtTransOffset = 4;
	
	  ;% KF_LQR_hardware_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 84;
	  section.data(6).dtTransOffset = 5;
	
	  ;% KF_LQR_hardware_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 85;
	  section.data(7).dtTransOffset = 6;
	
	  ;% KF_LQR_hardware_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 86;
	  section.data(8).dtTransOffset = 7;
	
	  ;% KF_LQR_hardware_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 87;
	  section.data(9).dtTransOffset = 8;
	
	  ;% KF_LQR_hardware_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 88;
	  section.data(10).dtTransOffset = 9;
	
	  ;% KF_LQR_hardware_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 89;
	  section.data(11).dtTransOffset = 10;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 90;
	  section.data(12).dtTransOffset = 11;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 91;
	  section.data(13).dtTransOffset = 12;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 92;
	  section.data(14).dtTransOffset = 13;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 93;
	  section.data(15).dtTransOffset = 14;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 94;
	  section.data(16).dtTransOffset = 15;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 95;
	  section.data(17).dtTransOffset = 16;
	
	  ;% KF_LQR_hardware_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 96;
	  section.data(18).dtTransOffset = 17;
	
	  ;% KF_LQR_hardware_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 97;
	  section.data(19).dtTransOffset = 18;
	
	  ;% KF_LQR_hardware_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 98;
	  section.data(20).dtTransOffset = 19;
	
	  ;% KF_LQR_hardware_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 99;
	  section.data(21).dtTransOffset = 20;
	
	  ;% KF_LQR_hardware_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 100;
	  section.data(22).dtTransOffset = 21;
	
	  ;% KF_LQR_hardware_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 101;
	  section.data(23).dtTransOffset = 22;
	
	  ;% KF_LQR_hardware_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 102;
	  section.data(24).dtTransOffset = 23;
	
	  ;% KF_LQR_hardware_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 103;
	  section.data(25).dtTransOffset = 24;
	
	  ;% KF_LQR_hardware_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 104;
	  section.data(26).dtTransOffset = 25;
	
	  ;% KF_LQR_hardware_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 105;
	  section.data(27).dtTransOffset = 26;
	
	  ;% KF_LQR_hardware_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 106;
	  section.data(28).dtTransOffset = 27;
	
	  ;% KF_LQR_hardware_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 107;
	  section.data(29).dtTransOffset = 28;
	
	  ;% KF_LQR_hardware_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 108;
	  section.data(30).dtTransOffset = 29;
	
	  ;% KF_LQR_hardware_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 109;
	  section.data(31).dtTransOffset = 30;
	
	  ;% KF_LQR_hardware_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 110;
	  section.data(32).dtTransOffset = 31;
	
	  ;% KF_LQR_hardware_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 111;
	  section.data(33).dtTransOffset = 32;
	
	  ;% KF_LQR_hardware_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 112;
	  section.data(34).dtTransOffset = 33;
	
	  ;% KF_LQR_hardware_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 113;
	  section.data(35).dtTransOffset = 34;
	
	  ;% KF_LQR_hardware_P.HILReadTimebase_Active
	  section.data(36).logicalSrcIdx = 114;
	  section.data(36).dtTransOffset = 35;
	
	  ;% KF_LQR_hardware_P.HILWrite_Active
	  section.data(37).logicalSrcIdx = 115;
	  section.data(37).dtTransOffset = 36;
	
	  ;% KF_LQR_hardware_P.Enable_Value
	  section.data(38).logicalSrcIdx = 116;
	  section.data(38).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (KF_LQR_hardware_B)
    ;%
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_B.PitchRef
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KF_LQR_hardware_B.YawRef
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% KF_LQR_hardware_B.X0
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% KF_LQR_hardware_B.MemoryX
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% KF_LQR_hardware_B.Reshapexhat
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 10;
	
	  ;% KF_LQR_hardware_B.Sum2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 14;
	
	  ;% KF_LQR_hardware_B.Internal
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 18;
	
	  ;% KF_LQR_hardware_B.Saturation
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 20;
	
	  ;% KF_LQR_hardware_B.MotorEnable
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 22;
	
	  ;% KF_LQR_hardware_B.Countstorads
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 24;
	
	  ;% KF_LQR_hardware_B.Sum
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 26;
	
	  ;% KF_LQR_hardware_B.Internal_c
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 27;
	
	  ;% KF_LQR_hardware_B.Internal_f
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 28;
	
	  ;% KF_LQR_hardware_B.Akxhatkk1
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 29;
	
	  ;% KF_LQR_hardware_B.Bkuk
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 33;
	
	  ;% KF_LQR_hardware_B.Add
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 37;
	
	  ;% KF_LQR_hardware_B.Stepend_time
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 41;
	
	  ;% KF_LQR_hardware_B.Count
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 42;
	
	  ;% KF_LQR_hardware_B.Sum_m
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 43;
	
	  ;% KF_LQR_hardware_B.div
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 44;
	
	  ;% KF_LQR_hardware_B.Ckxhatkk1
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 45;
	
	  ;% KF_LQR_hardware_B.Dkuk
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 47;
	
	  ;% KF_LQR_hardware_B.yhatkk1
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 49;
	
	  ;% KF_LQR_hardware_B.Sum_d
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 51;
	
	  ;% KF_LQR_hardware_B.Product3
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 53;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (KF_LQR_hardware_DW)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KF_LQR_hardware_DW.Sumk1n1xk_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% KF_LQR_hardware_DW.HILInitialize_AIMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% KF_LQR_hardware_DW.HILInitialize_AIMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% KF_LQR_hardware_DW.HILInitialize_AOMinimums
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% KF_LQR_hardware_DW.HILInitialize_AOMaximums
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% KF_LQR_hardware_DW.HILInitialize_AOVoltages
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% KF_LQR_hardware_DW.HILInitialize_FilterFrequency
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_DW.HILReadTimebase_Task
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_DW.HILWrite_PWORK
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KF_LQR_hardware_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% KF_LQR_hardware_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 3;
	
	  ;% KF_LQR_hardware_DW.Scope2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 5;
	
	  ;% KF_LQR_hardware_DW.Scope3_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 7;
	
	  ;% KF_LQR_hardware_DW.Scope4_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 9;
	
	  ;% KF_LQR_hardware_DW.Scope5_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 16;
	  section.data(7).dtTransOffset = 10;
	
	  ;% KF_LQR_hardware_DW.Scope6_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 17;
	  section.data(8).dtTransOffset = 11;
	
	  ;% KF_LQR_hardware_DW.Scope7_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 18;
	  section.data(9).dtTransOffset = 12;
	
	  ;% KF_LQR_hardware_DW.Scope8_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 19;
	  section.data(10).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KF_LQR_hardware_DW.HILInitialize_AIConfigValues
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% KF_LQR_hardware_DW.HILInitialize_DOStates
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 3;
	
	  ;% KF_LQR_hardware_DW.HILInitialize_QuadratureModes
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 5;
	
	  ;% KF_LQR_hardware_DW.HILInitialize_InitialEICounts
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 9;
	
	  ;% KF_LQR_hardware_DW.HILReadTimebase_EncoderBuffer
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_DW.MemoryX_IWORK
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_DW.SwitchCase_ActiveSubsystem
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KF_LQR_hardware_DW.SwitchCaseActionSubsystem2_Subs
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% KF_LQR_hardware_DW.SwitchCaseActionSubsystem1_Subs
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% KF_LQR_hardware_DW.SwitchCaseActionSubsystem_Subsy
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 3;
	
	  ;% KF_LQR_hardware_DW.EnabledMovingAverage_SubsysRanB
	  section.data(5).logicalSrcIdx = 31;
	  section.data(5).dtTransOffset = 4;
	
	  ;% KF_LQR_hardware_DW.MeasurementUpdate_SubsysRanBC
	  section.data(6).logicalSrcIdx = 32;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% KF_LQR_hardware_DW.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% KF_LQR_hardware_DW.EnabledMovingAverage_MODE
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 2;
	
	  ;% KF_LQR_hardware_DW.MeasurementUpdate_MODE
	  section.data(3).logicalSrcIdx = 35;
	  section.data(3).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3347256247;
  targMap.checksum1 = 492568938;
  targMap.checksum2 = 718339741;
  targMap.checksum3 = 32063684;

