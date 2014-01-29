#include "CloseGripper.h"

CloseGripper::CloseGripper() {
	// Use requires() here to declare subsystem dependencies
	Requires(gripper);
}

// Called just before this Command runs the first time
void CloseGripper::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void CloseGripper::Execute() {
	
	gripper->gripperSolenoid->Set(false);
	
}

// Make this return true when this Command no longer needs to run execute()
bool CloseGripper::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CloseGripper::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseGripper::Interrupted() {
}
