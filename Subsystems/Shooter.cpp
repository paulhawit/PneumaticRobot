#include "Shooter.h"
#include "../Robotmap.h"
#include "../Commands/Shoot.h"

const int EncoderCodesPerRev = 360;

Shooter::Shooter() : Subsystem("Shooter") {
	
	rightShooterJaguar = new CANJaguar (RIGHTSHOOTERJAG_ID);
	leftShooterJaguar = new CANJaguar (LEFTSHOOTERJAG_ID);
	
}
    
void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Shoot());
}

void Shooter::ShooterPosition(float rotationsRight, float rotationsLeft){
	if (rightShooterJaguar->GetControlMode() != CANJaguar::kPosition) {
		rightShooterJaguar->ChangeControlMode(CANJaguar::kPosition);
		rightShooterJaguar->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
		rightShooterJaguar->SetPID(0.0, 0.0, 0.0);
		rightShooterJaguar->ConfigEncoderCodesPerRev(EncoderCodesPerRev);
		rightShooterJaguar->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		rightShooterJaguar->EnableControl(0.0);
	}
	if (leftShooterJaguar->GetControlMode() != CANJaguar::kPosition) {
		leftShooterJaguar->ChangeControlMode(CANJaguar::kPosition);
		leftShooterJaguar->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
		leftShooterJaguar->SetPID(0.0, 0.0, 0.0);
		leftShooterJaguar->ConfigEncoderCodesPerRev(EncoderCodesPerRev);
		leftShooterJaguar->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		leftShooterJaguar->EnableControl(0.0);
	}
	rightShooterJaguar->Set(rotationsRight);
	leftShooterJaguar->Set(rotationsLeft);
}

void Shooter::ShooterEnd() {
	rightShooterJaguar->DisableControl();
	leftShooterJaguar->DisableControl();
} 

// Put methods for controlling this subsystem
// here. Call these from Commands.
