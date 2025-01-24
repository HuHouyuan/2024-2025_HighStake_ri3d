#ifndef _CONFIG_
#define _CONFIG_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

using namespace vex;
using namespace std;
brain Brain;
#undef __ARM_NEON__
#undef __ARM_NEON

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
controller Controller1 = controller(primary);
motor LF = motor(PORT1, ratio18_1, 0);
motor LM = motor(PORT2, ratio18_1, 0);
motor LB = motor(PORT3, ratio18_1, 0);
motor RF = motor(PORT10, ratio18_1, 0);
motor RM = motor(PORT9, ratio18_1, 0);
motor RB = motor(PORT8, ratio18_1, 0);
inertial Gyro = inertial(PORT12);

void vexcodeInit(void);

#endif