#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "robot-config.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include<cmath>
using namespace std;

#define TIMER           Brain.timer(vex::timeUnits::msec)

#define Ch1             Controller1.Axis1.position(percent)
#define Ch2             Controller1.Axis2.position(percent)
#define Ch3             Controller1.Axis3.position(percent)
#define Ch4             Controller1.Axis4.position(percent)

#define BA              Controller1.ButtonA.pressing()
#define BB              Controller1.ButtonB.pressing()
#define BX              Controller1.ButtonX.pressing()
#define BY              Controller1.ButtonY.pressing()

#define L1              Controller1.ButtonL1.pressing()
#define L2              Controller1.ButtonL2.pressing()
#define R1              Controller1.ButtonR1.pressing()
#define R2              Controller1.ButtonR2.pressing()

#define UP              Controller1.ButtonUp.pressing()
#define DOWN            Controller1.ButtonDown.pressing()
#define LEFT            Controller1.ButtonLeft.pressing()
#define RIGHT           Controller1.ButtonRight.pressing()

#define SDFile          "t.h"

#define getCataEncoder  (cat.position(deg))
#define getLimitValue   (lmt.value())
#define getLimit2Value  (lmt2.value())
#define getDis          (dis.objectDistance(mm))
#define isSDInserted    (Brain.SDcard.isInserted())
#define isFileExists    (Brain.SDcard.exists(SDFile))
#define sign(x)         (x==0?0:(x>0?1:-1))
#define sgn(x)          (x > 0 ? 1 : -1)
#define getGyro         Gyro.rotation()
#define mygyro          Gyro
#define IGR             initGyroRotation
#define delay           vexDelay
#define PI              M_PI
#define cap(x, cap)     (fabs(x) > cap ?  sign(x) * cap : x)   

int autoRoutine = 0;

#endif