/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/


#include "autonomous.h"
#include "task.h"
#include "autopath.h"
#include<iostream>
#undef __ARM_NEON__
#undef __ARM_NEON


using namespace vex;
 
// A global instance of competition
competition Competition;

void runAuto(){
  int a = Brain.timer(msec);
  switch (autoRoutine)
  {
  case 0:
    break;
  case 1 :
    break;
  case 2:
    break;
  default:
    break;
  } 
  cout << "time used: "<<Brain.timer(msec)-a <<endl;
}

void autonomous(void) {
  runAuto();
  
}

void usercontrol(void) {
  // User control code here, inside the loop
  
    delay(20); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  
}

//='//
// Main will set up the competition functions and callbacks.
//
int main() {
  delay(200);
  Controller1.Screen.clearScreen();
  task HYBRID_LOCOMOTION(HybridLocomotion);
  delay(200);
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  while (true) {
    delay(100);
  }
}
