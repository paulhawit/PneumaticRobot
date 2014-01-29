#ifndef DRIVEDEFAULT_H
#define DRIVEDEFAULT_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Daniel
 */
class DriveDefault: public CommandBase {
public:
	DriveDefault();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
