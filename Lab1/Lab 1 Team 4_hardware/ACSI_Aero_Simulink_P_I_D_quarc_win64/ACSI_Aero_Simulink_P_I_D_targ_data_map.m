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
    ;% Auto data (ACSI_Aero_Simulink_P_I_D_P)
    ;%
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_P.PIDController_D
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PIDController1_D
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PIDController_I
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PIDController1_I
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PIDController_InitialConditionF
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PIDController1_InitialCondition
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PIDController_InitialConditio_e
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PIDController1_InitialConditi_e
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PIDController_N
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PIDController1_N
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PIDController_P
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PIDController1_P
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Green_color
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Yellow_color
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PitchBiasRemoval_end_time
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PitchBiasRemoval_start_time
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.PitchBiasRemoval_switch_id
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILReadTimebase_clock
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILReadTimebase_analog_channels
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILWrite_analog_channels
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 2;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILReadTimebase_encoder_channel
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 4;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILReadTimebase_other_channels
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 6;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILWrite_other_channels
	  section.data(5).logicalSrcIdx = 22;
	  section.data(5).dtTransOffset = 10;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILReadTimebase_samples_in_buff
	  section.data(6).logicalSrcIdx = 23;
	  section.data(6).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 46;
      section.data(46)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_P.u4V_UpperSat
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.u4V_LowerSat
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.x_avg_n_Y0
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.unity_Value
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.UnitDelay_InitialCondition
	  section.data(5).logicalSrcIdx = 28;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Sumk1n1xk_InitialCondition
	  section.data(6).logicalSrcIdx = 29;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.zero_Y0
	  section.data(7).logicalSrcIdx = 30;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Vbiased_Y0
	  section.data(8).logicalSrcIdx = 31;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Vunbiased_Y0
	  section.data(9).logicalSrcIdx = 32;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Stepstart_time_Y0
	  section.data(10).logicalSrcIdx = 33;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Stepstart_time_YFinal
	  section.data(11).logicalSrcIdx = 34;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Stepend_time_Y0
	  section.data(12).logicalSrcIdx = 35;
	  section.data(12).dtTransOffset = 11;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Stepend_time_YFinal
	  section.data(13).logicalSrcIdx = 36;
	  section.data(13).dtTransOffset = 12;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOTerminate
	  section.data(14).logicalSrcIdx = 37;
	  section.data(14).dtTransOffset = 13;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOExit
	  section.data(15).logicalSrcIdx = 38;
	  section.data(15).dtTransOffset = 14;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOStart
	  section.data(16).logicalSrcIdx = 39;
	  section.data(16).dtTransOffset = 15;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOEnter
	  section.data(17).logicalSrcIdx = 40;
	  section.data(17).dtTransOffset = 16;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOFinal
	  section.data(18).logicalSrcIdx = 41;
	  section.data(18).dtTransOffset = 17;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOFinal
	  section.data(19).logicalSrcIdx = 42;
	  section.data(19).dtTransOffset = 18;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIHigh
	  section.data(20).logicalSrcIdx = 43;
	  section.data(20).dtTransOffset = 21;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AILow
	  section.data(21).logicalSrcIdx = 44;
	  section.data(21).dtTransOffset = 22;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOHigh
	  section.data(22).logicalSrcIdx = 45;
	  section.data(22).dtTransOffset = 23;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOLow
	  section.data(23).logicalSrcIdx = 46;
	  section.data(23).dtTransOffset = 24;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOInitial
	  section.data(24).logicalSrcIdx = 47;
	  section.data(24).dtTransOffset = 25;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOWatchdog
	  section.data(25).logicalSrcIdx = 48;
	  section.data(25).dtTransOffset = 26;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOInitial
	  section.data(26).logicalSrcIdx = 49;
	  section.data(26).dtTransOffset = 27;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOWatchdog
	  section.data(27).logicalSrcIdx = 50;
	  section.data(27).dtTransOffset = 30;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Internal_A
	  section.data(28).logicalSrcIdx = 51;
	  section.data(28).dtTransOffset = 33;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Internal_B
	  section.data(29).logicalSrcIdx = 52;
	  section.data(29).dtTransOffset = 43;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Internal_C
	  section.data(30).logicalSrcIdx = 53;
	  section.data(30).dtTransOffset = 47;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Internal_A_i
	  section.data(31).logicalSrcIdx = 54;
	  section.data(31).dtTransOffset = 49;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Internal_B_k
	  section.data(32).logicalSrcIdx = 55;
	  section.data(32).dtTransOffset = 59;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Internal_C_p
	  section.data(33).logicalSrcIdx = 56;
	  section.data(33).dtTransOffset = 63;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Internal_D
	  section.data(34).logicalSrcIdx = 57;
	  section.data(34).dtTransOffset = 71;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.NoControl_Value
	  section.data(35).logicalSrcIdx = 58;
	  section.data(35).dtTransOffset = 75;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.MotorEnable_Threshold
	  section.data(36).logicalSrcIdx = 59;
	  section.data(36).dtTransOffset = 77;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.LEDColour_Threshold
	  section.data(37).logicalSrcIdx = 60;
	  section.data(37).dtTransOffset = 78;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Countstorads_Gain
	  section.data(38).logicalSrcIdx = 61;
	  section.data(38).dtTransOffset = 79;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Pitchref_Amplitude
	  section.data(39).logicalSrcIdx = 62;
	  section.data(39).dtTransOffset = 81;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Pitchref_Frequency
	  section.data(40).logicalSrcIdx = 63;
	  section.data(40).dtTransOffset = 82;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Yawref_Amplitude
	  section.data(41).logicalSrcIdx = 64;
	  section.data(41).dtTransOffset = 83;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Yawref_Frequency
	  section.data(42).logicalSrcIdx = 65;
	  section.data(42).dtTransOffset = 84;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Saturation_UpperSat
	  section.data(43).logicalSrcIdx = 66;
	  section.data(43).dtTransOffset = 85;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Saturation_LowerSat
	  section.data(44).logicalSrcIdx = 67;
	  section.data(44).dtTransOffset = 86;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Saturation1_UpperSat
	  section.data(45).logicalSrcIdx = 68;
	  section.data(45).dtTransOffset = 87;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.Saturation1_LowerSat
	  section.data(46).logicalSrcIdx = 69;
	  section.data(46).dtTransOffset = 88;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIConfiguration
	  section.data(2).logicalSrcIdx = 71;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOWatchdog
	  section.data(3).logicalSrcIdx = 72;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIInitial
	  section.data(4).logicalSrcIdx = 73;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 75;
	  section.data(2).dtTransOffset = 2;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 76;
	  section.data(3).dtTransOffset = 4;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 77;
	  section.data(4).dtTransOffset = 6;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 78;
	  section.data(5).dtTransOffset = 10;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOChannels
	  section.data(6).logicalSrcIdx = 79;
	  section.data(6).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 81;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 82;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 83;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 84;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 85;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 86;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 87;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 88;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 89;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 90;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 91;
	  section.data(12).dtTransOffset = 11;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 92;
	  section.data(13).dtTransOffset = 12;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 93;
	  section.data(14).dtTransOffset = 13;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 94;
	  section.data(15).dtTransOffset = 14;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 95;
	  section.data(16).dtTransOffset = 15;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 96;
	  section.data(17).dtTransOffset = 16;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 97;
	  section.data(18).dtTransOffset = 17;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 98;
	  section.data(19).dtTransOffset = 18;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 99;
	  section.data(20).dtTransOffset = 19;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 100;
	  section.data(21).dtTransOffset = 20;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 101;
	  section.data(22).dtTransOffset = 21;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 102;
	  section.data(23).dtTransOffset = 22;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 103;
	  section.data(24).dtTransOffset = 23;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 104;
	  section.data(25).dtTransOffset = 24;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 105;
	  section.data(26).dtTransOffset = 25;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 106;
	  section.data(27).dtTransOffset = 26;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 107;
	  section.data(28).dtTransOffset = 27;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 108;
	  section.data(29).dtTransOffset = 28;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 109;
	  section.data(30).dtTransOffset = 29;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 110;
	  section.data(31).dtTransOffset = 30;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 111;
	  section.data(32).dtTransOffset = 31;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 112;
	  section.data(33).dtTransOffset = 32;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 113;
	  section.data(34).dtTransOffset = 33;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 114;
	  section.data(35).dtTransOffset = 34;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILReadTimebase_Active
	  section.data(36).logicalSrcIdx = 115;
	  section.data(36).dtTransOffset = 35;
	
	  ;% ACSI_Aero_Simulink_P_I_D_P.HILWrite_Active
	  section.data(37).logicalSrcIdx = 116;
	  section.data(37).dtTransOffset = 36;
	
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
    ;% Auto data (ACSI_Aero_Simulink_P_I_D_B)
    ;%
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_B.Internal
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.MotorEnable
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 2;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.Countstorads
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 4;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.Sum
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 6;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.Pitchref
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 7;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.Yawref
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 8;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.FilterCoefficient
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 9;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.FilterCoefficient_c
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 10;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.TmpSignalConversionAtInternalIn
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 11;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.IntegralGain
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 13;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.IntegralGain_i
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 14;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.Stepend_time
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 15;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.Count
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 16;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.Sum_j
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 17;
	
	  ;% ACSI_Aero_Simulink_P_I_D_B.div
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 18;
	
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
    nTotSects     = 7;
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
    ;% Auto data (ACSI_Aero_Simulink_P_I_D_DW)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.Sumk1n1xk_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AIMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AIMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOMinimums
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOMaximums
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AOVoltages
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_FilterFrequency
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILReadTimebase_Task
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILWrite_PWORK
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.Pitch_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.Yaw_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_AIConfigValues
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_DOStates
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 3;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_QuadratureModes
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 5;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_InitialEICounts
	  section.data(5).logicalSrcIdx = 17;
	  section.data(5).dtTransOffset = 9;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILReadTimebase_EncoderBuffer
	  section.data(6).logicalSrcIdx = 18;
	  section.data(6).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_DW.SwitchCase_ActiveSubsystem
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.SwitchCaseActionSubsystem2_Subs
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.SwitchCaseActionSubsystem1_Subs
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.SwitchCaseActionSubsystem_Subsy
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.EnabledMovingAverage_SubsysRanB
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ACSI_Aero_Simulink_P_I_D_DW.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ACSI_Aero_Simulink_P_I_D_DW.EnabledMovingAverage_MODE
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
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


  targMap.checksum0 = 600995082;
  targMap.checksum1 = 895382310;
  targMap.checksum2 = 4048983063;
  targMap.checksum3 = 2775504548;

