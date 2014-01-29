#ifndef GRIPPER_H
#define GRIPPER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author sarmad
 */
class Gripper: public Subsystem {
private:
	
	
	
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Gripper();
	void InitDefaultCommand();
	Compressor *compressor;
	Solenoid *gripperSolenoid;
};

#endif
