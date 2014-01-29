#ifndef PNEUMATICSHOOTER_H
#define PNEUMATICSHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author sarmad
 */
class PneumaticShooter: public Subsystem {
private:
	
	
	
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	PneumaticShooter();
	void InitDefaultCommand();
	Solenoid *shootersolenoid;
};

#endif
