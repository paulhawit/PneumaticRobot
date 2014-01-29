#include "Drivetrain.h"
#include "../Robotmap.h"
#include "CANJaguar.h"
#include "../Commands/DriveDefault.h"

const int EncoderCodesPerRev = 360; //Needs to be changed for the encoder that is installed
CANJaguar *jagRight;
CANJaguar *jagLeft;
RobotDrive *drive;
Drivetrain::Drivetrain() :
	Subsystem("Drivetrain") {
	jagRight = new CANJaguar(JAGRIGHT_ID);
	jagLeft = new CANJaguar(JAGLEFT_ID);
	drive = new RobotDrive(jagRight, jagLeft);
}

void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveDefault());
}
//This controls the jag based on the desired rpm using the builtin PID control
void Drivetrain::DriveSpeed(float rpmRight, float rpmLeft) {
	if (jagRight->GetControlMode() != CANJaguar::kSpeed) { // if the jag is not in Speed control mode 
		jagRight->ChangeControlMode(CANJaguar::kSpeed);
		jagRight->SetSpeedReference(CANJaguar::kSpeedRef_Encoder);//Possible Quad encoder not sure of the difference
		jagRight->SetPID(0.6, 0.01, 0.0);//Will need to be tuned
		jagRight->ConfigEncoderCodesPerRev(EncoderCodesPerRev);
		jagRight->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		jagRight->EnableControl();
	}
	if (jagLeft->GetControlMode() != CANJaguar::kSpeed) { // if the jag is not in Speed control mode 
		jagLeft->ChangeControlMode(CANJaguar::kSpeed);
		jagLeft->SetSpeedReference(CANJaguar::kSpeedRef_Encoder);//Possible Quad encoder not sure of the difference
		jagLeft->SetPID(0.6, 0.01, 0.0);//Will need to be tuned
		jagLeft->ConfigEncoderCodesPerRev(EncoderCodesPerRev);
		jagLeft->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		jagLeft->EnableControl();
	}
	jagRight->Set(rpmRight);
	jagLeft->Set(rpmLeft);

}
//This controls the jag based on position using its builtin PID control
void Drivetrain::DrivePosition(float rotationsRight, float rotationsLeft) {
	if (jagRight->GetControlMode() != CANJaguar::kPosition) {
		jagRight->ChangeControlMode(CANJaguar::kPosition);
		jagRight->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
		jagRight->SetPID(0.0, 0.0, 0.0);
		jagRight->ConfigEncoderCodesPerRev(EncoderCodesPerRev);
		jagRight->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		jagRight->EnableControl(0.0);
	}
	if (jagLeft->GetControlMode() != CANJaguar::kPosition) {
		jagLeft->ChangeControlMode(CANJaguar::kPosition);
		jagLeft->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
		jagLeft->SetPID(0.0, 0.0, 0.0);
		jagLeft->ConfigEncoderCodesPerRev(EncoderCodesPerRev);
		jagLeft->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		jagLeft->EnableControl(0.0);
	}
	jagRight->Set(rotationsRight);
	jagLeft->Set(rotationsLeft);
}

//This disables the jag's PID control
void Drivetrain::DriveEnd() {
	jagRight->DisableControl();
	jagLeft->DisableControl();
}
