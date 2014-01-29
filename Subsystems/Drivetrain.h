#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Daniel
 */
class Drivetrain: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANJaguar *jagRight;
	CANJaguar *jagLeft;
	RobotDrive *drive;
	
	
public:
	Drivetrain();
	void InitDefaultCommand();
	void DriveSpeed(float rpmRight, float rpmLeft);
	void DrivePosition(float rotationsRight, float rotationsLeft);
	void DriveEnd();
};

#endif
