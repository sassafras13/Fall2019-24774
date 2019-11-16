'''
This script is based on the Bitcraze crazyflie-lib-python repository. It is intended to build a minimum jerk trajectory and send the position commands to a Crazyflie quadcopter in 3 dimensions. This script will make use of the data from the optical flow deck to obtain the current position and follow the trajectory waypoints. The goal location will be given by the Kinect sensor. 

The codes referenced for this one include: 
    basiclog.py
    flowsequenceSync.py
'''
#############
# LIBRARIES #
#############
import logging # this allows logging of error messages instead of printing them
import time
from threading import Timer
import matplotlib.pyplot as plt

# WHAT DO THESE LIBRARIES DO?
import cflib.crtp
from cflib.crazyflie.log import LogConfig

from cflib.crazyflie import Crazyflie # this is the class "Crazyflie", it has an __init__ function which takes in as an argument rw_cache which is the path to the read-write cache. It also has link_uri as a variable, and high_level_commander. It does a lot of work managing the connection via the radio and sending packets of data. It also uses the logging library (https://www.geeksforgeeks.org/logging-in-python/) to record errors, but I don't know if it saves that log file anywhere. It does not create a file in the Crazyflie class definition, so maybe something else that calls the Crazyflie class creates the log file. We should figure out where those are. 

from cflib.crazyflie.syncCrazyflie import SyncCrazyflie # this is a wrapper class around the Crazyflie class that handles asynchronous communication of Crazyflie API "and turns it into a blocking function"?

from cflib.positioning.position_hl_commander import PositionHlCommander # this library makes it easy to write scripts to move the Crazyflie around. It requires a positioning support (they recommend the Loco positioning system https://www.bitcraze.io/loco-pos-system/ which they developed as a way of identifiying tags around the room and determining position based on those tags). If you use the HL commander as a context manager (use the WITH keyword). A context manager (https://www.geeksforgeeks.org/context-manager-in-python/) handles resources so that you don't have too many files open at the same time.  Inside a context manager block, files are opened and closed so that they do not consume resources outside the block. This class allows you to select either a PID or Mellinger (?) controller. (Is this a low-level controller?) Take-off runs automatically when the context is created. When the context goes out of scope (i.e. when the context manager block ends) the landing function is run automatically. 

###############
# DEFINITIONS #
###############

# URI to the Crazyflie to connect to (i.e. the radio identification of the Crazyflie)
uri = 'radio://0/80/250K' # MAY NEED TO EDIT THIS

#############
# SETUP LOG #
#############

# logging.basicConfig(filename="test.log", format='%(asctime)s %(message)s', filemode='w')

logging.basicConfig(level=logging.ERROR)


########
# MAIN #
########

if __name__ == '__main__':
    cflib.crtp.init_drivers(enable_debug_driver=False) # this initializes all the drivers. Adds all the drivers that are not for debugging to a list called "CLASSES". Does not explicitly seem to establish a connection via the radio but maybe it is initialized inside one of the drivers. NEED TO LOG THIS DATA AND FIND A WAY TO READ THE LOG. 

    with SyncCrazyflie(uri, cf=Crazyflie(rw_cache='./cache')) as scf: # This is creating a context manager so everything opened inside here will be closed at the end of this block. 

        cf = scf.cf # this line links the SyncCrazyflie class instance with the Crazyflie class instance as a wrapper

        cf.param.set_value('kalman.resetEstimation','1') # this sets the value for the supplied parameter. It uses a Table Of Contents (toc) to look up the parameter. 
        time.sleep(0.1)
        cf.param.set_value('kalman.resetEstimation','0')
        time.sleep(2)

        for i in range(100):
            send_position_setpoint(i*0.01,i*0.01,i*0.01,0) # send_position_setpoint(self, x, y, z, yaw)
            time.sleep(0.1)

        cf.commander.send_stop_setpoint()




##############
# EXTRA CODE #
##############
        # with PositionHlCommander(scf, default_height=0.5) as pc: # This is another context manager that creates an instance of the class PositionHlCommander. Notice that it sets the default height to 0.5m. 
            

