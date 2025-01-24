#ifndef _AUTO_
#define _AUTO_
#include "declaration.h"
using namespace vex;

void driveForward(float v){
  v*=120;
  LB.spin(fwd, v, vex::voltageUnits::mV);
  LM.spin(fwd, v, vex::voltageUnits::mV);
  LF.spin(fwd, v, vex::voltageUnits::mV);
  RB.spin(fwd, -v, vex::voltageUnits::mV);
  RM.spin(fwd, -v, vex::voltageUnits::mV);
  RF.spin(fwd, -v, vex::voltageUnits::mV);
}



#endif