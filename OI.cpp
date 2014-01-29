#include "OI.h"
#include "Commands/Shoot.h"
#include "Commands/OpenGripper.h"
#include "Commands/CloseGripper.h"
#include "Commands/PneumaticShoot.h"

OI::OI() {
	// Process operator interface input here.
	driveStick = new Joystick(1);
	shooterButton = new JoystickButton(driveStick, 1);
	shooterButton->WhenPressed(new PneumaticShoot());
	gripperButton = new JoystickButton (driveStick, 5);
	gripperButton->WhenPressed(new OpenGripper());
	gripperButton->WhileHeld(new CloseGripper());
	
}
