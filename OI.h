#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:

public:
	OI();
	Joystick *driveStick;
	JoystickButton *shooterButton;
	JoystickButton *gripperButton;
};

#endif
