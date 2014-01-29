#include "Gripper.h"
#include "../Commands/CloseGripper.h"
#include "../Robotmap.h"

Gripper::Gripper() : Subsystem("Gripper") {
	
	compressor = new Compressor (1,1);
	gripperSolenoid = new Solenoid (1);
	gripperSolenoid = new Solenoid (3,1);
	
}
    
void Gripper::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new CloseGripper());
	compressor->Start();
	
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
