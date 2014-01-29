#include "PneumaticShooter.h"
#include "../Robotmap.h"

PneumaticShooter::PneumaticShooter() : Subsystem("PneumaticShooter") {
	
	shootersolenoid = new Solenoid (3,2);
	
}
    
void PneumaticShooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	
	shootersolenoid->Set(true);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
