#ifndef CLOSEGRIPPER_H
#define CLOSEGRIPPER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author sarmad
 */
class CloseGripper: public CommandBase {
public:
	CloseGripper();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
