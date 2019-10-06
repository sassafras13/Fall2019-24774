  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
    ;% Auto data (Quanser_Qube_Plant_Model_Chec_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILReadEncoderTimebase_clock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILReadEncoderTimebase_channels
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILWriteAnalog_channels
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILReadEncoderTimebase_samples_
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_OOTerminate
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_OOExit
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_OOStart
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_OOEnter
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AOFinal
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_OOFinal
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AIHigh
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 8;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AILow
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 9;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AOHigh
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 10;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AOLow
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 11;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AOInitial
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 12;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AOWatchdog
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 13;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_OOInitial
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_OOWatchdog
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 17;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.Pendulumcountstorad_Gain
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 20;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.Armcountstorad_Gain
	  section.data(16).logicalSrcIdx = 19;
	  section.data(16).dtTransOffset = 21;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.SignalGenerator_Amplitude
	  section.data(17).logicalSrcIdx = 20;
	  section.data(17).dtTransOffset = 22;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.SignalGenerator_Frequency
	  section.data(18).logicalSrcIdx = 21;
	  section.data(18).dtTransOffset = 23;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.Gain_Gain
	  section.data(19).logicalSrcIdx = 22;
	  section.data(19).dtTransOffset = 24;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.Saturation_UpperSat
	  section.data(20).logicalSrcIdx = 23;
	  section.data(20).dtTransOffset = 25;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.Saturation_LowerSat
	  section.data(21).logicalSrcIdx = 24;
	  section.data(21).dtTransOffset = 26;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.ForveCCW_Gain
	  section.data(22).logicalSrcIdx = 25;
	  section.data(22).dtTransOffset = 27;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.Internal_A
	  section.data(23).logicalSrcIdx = 26;
	  section.data(23).dtTransOffset = 28;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.Internal_B
	  section.data(24).logicalSrcIdx = 27;
	  section.data(24).dtTransOffset = 36;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.Internal_C
	  section.data(25).logicalSrcIdx = 28;
	  section.data(25).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 31;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 35;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 36;
	  section.data(5).dtTransOffset = 5;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_OOChannels
	  section.data(6).logicalSrcIdx = 37;
	  section.data(6).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 39;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 40;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 41;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 42;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 43;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 44;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 45;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 46;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 47;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 48;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 49;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 50;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 51;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 52;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 53;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 54;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 55;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 56;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 57;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 58;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 59;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 60;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 61;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 62;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 63;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 64;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 65;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 66;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 67;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 68;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 69;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 70;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 71;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 72;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILReadEncoderTimebase_Active
	  section.data(36).logicalSrcIdx = 73;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Quanser_Qube_Plant_Model_Chec_P.HILWriteAnalog_Active
	  section.data(37).logicalSrcIdx = 74;
	  section.data(37).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    ;% Auto data (Quanser_Qube_Plant_Model_Chec_B)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% Quanser_Qube_Plant_Model_Chec_B.HILReadEncoderTimebase_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Quanser_Qube_Plant_Model_Chec_B.HILReadEncoderTimebase_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Quanser_Qube_Plant_Model_Chec_B.Pendulumcountstorad
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Quanser_Qube_Plant_Model_Chec_B.Armcountstorad
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Quanser_Qube_Plant_Model_Chec_B.SignalGenerator
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Quanser_Qube_Plant_Model_Chec_B.Gain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Quanser_Qube_Plant_Model_Chec_B.Saturation
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Quanser_Qube_Plant_Model_Chec_B.ForveCCW
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Quanser_Qube_Plant_Model_Chec_B.Internal
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Quanser_Qube_Plant_Model_Chec_B.TmpSignalConversionAtToFileInpo
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% Quanser_Qube_Plant_Model_Chec_B.TmpSignalConversionAtToFile1Inp
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 16;
	
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
    nTotSects     = 6;
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
    ;% Auto data (Quanser_Qube_Plant_Model_Che_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Quanser_Qube_Plant_Model_Che_DW.HILInitialize_FilterFrequency
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Quanser_Qube_Plant_Model_Che_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Quanser_Qube_Plant_Model_Che_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Quanser_Qube_Plant_Model_Che_DW.HILWriteAnalog_PWORK
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Quanser_Qube_Plant_Model_Che_DW.MotorAngletheta_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Quanser_Qube_Plant_Model_Che_DW.PendulumAnglealpha_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Quanser_Qube_Plant_Model_Che_DW.ToFile_PWORK.FilePtr
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 7;
	
	  ;% Quanser_Qube_Plant_Model_Che_DW.ToFile1_PWORK.FilePtr
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 8;
	
	  ;% Quanser_Qube_Plant_Model_Che_DW.ToWorkspace1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Quanser_Qube_Plant_Model_Che_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Quanser_Qube_Plant_Model_Che_DW.HILInitialize_DOStates
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Quanser_Qube_Plant_Model_Che_DW.HILInitialize_QuadratureModes
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Quanser_Qube_Plant_Model_Che_DW.HILInitialize_InitialEICounts
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Quanser_Qube_Plant_Model_Che_DW.HILReadEncoderTimebase_Buffer
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Quanser_Qube_Plant_Model_Che_DW.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Quanser_Qube_Plant_Model_Che_DW.ToFile1_IWORK.Count
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
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


  targMap.checksum0 = 2736340377;
  targMap.checksum1 = 1542066953;
  targMap.checksum2 = 1784244549;
  targMap.checksum3 = 3545839787;

