#ifndef OPENGRIPPER_H
#define OPENGRIPPER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author sarmad
 */
class OpenGripper: public CommandBase {
public:
	OpenGripper();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
