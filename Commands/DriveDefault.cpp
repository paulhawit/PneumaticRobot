#include "DriveDefault.h"

DriveDefault::DriveDefault() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);	
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void DriveDefault::Initialize() {
	drivetrain->DriveSpeed(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void DriveDefault::Execute() {
	float move = oi->driveStick->GetY();
	float turn = oi->driveStick->GetX();
	int maxSpeed = 100;
	double maxTurnSpeed = maxSpeed * 0.50;
	float rightMotorMove = (move * maxSpeed);
	float leftMotorMove = (move * maxSpeed);
	float rightMotorTurn = (turn * (maxTurnSpeed));
	float leftMotorTurn = -(turn * (maxTurnSpeed));
	float rightMotorOut = rightMotorMove + rightMotorTurn;
	float leftMotorOut = leftMotorMove + leftMotorTurn;
	drivetrain-> DriveSpeed(rightMotorOut, -1*(leftMotorOut));
	
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDefault::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveDefault::End() {
	drivetrain->DriveEnd();
	//	drivetrain->ArcadeDrive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDefault::Interrupted() {
	drivetrain->DriveEnd();
}
