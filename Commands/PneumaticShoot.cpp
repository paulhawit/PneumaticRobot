#include "PneumaticShoot.h"
#include "OpenGripper.h"
#include "Shoot.h"

PneumaticShoot::PneumaticShoot() {
        // Add Commands here:
        // e.g. AddSequential(new Command1());
        //      AddSequential(new Command2());
        // these will run in order.

        // To run multiple commands at the same time,
        // use AddParallel()
        AddParallel(new OpenGripper());
        AddSequential(new Shoot());
        // Command1 and Command2 will run in parallel.

        //Requires(gripper,pneumatic);
        //Requires(pneumaticShooter);
        // A command group will require all of the subsystems that each member
        // would require.
        // e.g. if Command1 requires chassis, and Command2 requires arm,
        // a CommandGroup containing them would require both the chassis and the
        // arm.
}
