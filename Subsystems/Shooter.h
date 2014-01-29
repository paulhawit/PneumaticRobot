#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author sarmad
 */
class Shooter: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	
	CANJaguar *rightShooterJaguar;
	CANJaguar *leftShooterJaguar;
	
public:
	Shooter();
	void InitDefaultCommand();
	void ShooterPosition(float rotationsRight, float rotationsLeft);
	void ShooterEnd ();
};

#endif
