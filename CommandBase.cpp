#include "CommandBase.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Gripper.h"
#include "Subsystems/PneumaticShooter.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
Drivetrain* CommandBase::drivetrain = NULL;
Shooter* CommandBase::shooter = NULL;
PneumaticShooter* CommandBase::pneumaticShooter = NULL;
Gripper* CommandBase::gripper = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drivetrain = new Drivetrain();
	pneumaticShooter = new PneumaticShooter ();
	shooter = new Shooter ();
	gripper = new Gripper ();
	oi = new OI();
}
