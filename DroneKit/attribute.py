### Dependencies
from dronekit import connect, VehicleMode, LocationGlobalRelative, APIException
import time
import socket
import math
import argparse

### Function
def connectCopter():
    parser = argparse.ArgumentParser()
    parser.add_argument('--connect')
   
    args = parser.parse_args()
    
    connection_string = args.connect
    
    if not connection_string:
        import dronekit_sitl
        sitl = dronekit_sitl.start_default()
        connection_string = sitl.connection_string()

        print(f"Connecting to SITL ({connection_string})")
    else:
        print(f"Connecting to {connection_string}")
    
    vehicle = connect(connection_string, wait_ready=True)
    print("Connected Succussfuly!")
    
    return vehicle 

### Main Executable
vehicle = connectCopter()

### Attributes
print("Attributes: \n")

# APM Version
vehicle.wait_ready('autopilot_version')
print(f"Version: {vehicle.version}")

# Does the firmware support the companion pc to set the Attitude?
print(f"Supports set attitude from companion: {vehicle.capabilities.set_attitude_target_local_ned}")

# Read the actual position (long, lat, alt)
print(f"Position: {vehicle.location.global_relative_frame}")

# Read the actual attitude (roll, pitch, yaw)
print(f"Attitude: {vehicle.attitude}")

# Read the actual velocity (m/s)
print(f"Velocity (speed): {vehicle.velocity}m/s") # North, East, Down

# When did we recieve last heartbeat?
print(f"Last Heartbeat: {vehicle.last_heartbeat}")

# Is the vehicle ready to arm?
print(f"Is the vehicle armable: {vehicle.is_armable}")

# What is the total groundspeed?
print(f"Groundspeed: {vehicle.groundspeed}") # This is settable

# What is the actual Flight Mode?
print(f"Mode :{vehicle.mode.name}") # This is settable

