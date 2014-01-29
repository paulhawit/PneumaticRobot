#include "Shoot.h"

Shoot::Shoot() {
	// Use Requires() here to declare subsystem dependencies
	Requires(pneumaticShooter);
	
}

// Called just before this Command runs the first time
void Shoot::Initialize() {
	
	//shooter->ShooterPosition(0,0);
	
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	/*shooter->ShooterPosition(400,400);
			Wait (0.2);
	shooter->ShooterPosition(-400,-400);
			Wait (0.1);
		*/	
	pneumaticShooter->shootersolenoid->Set(true);
	
		}


// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Shoot::End() {
	//shooter->ShooterEnd();
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
	//shooter->ShooterEnd();
}
