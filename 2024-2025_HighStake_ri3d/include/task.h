#ifndef _TASK_
#define _TASK_
#include "declaration.h"
#include "robot-config.h"
#include <iostream>
#undef __ARM_NEON__
#undef __ARM_NEON

int HybridLocomotion(){
    float control_x = 0;
    float control_y = 0;
    float slope_before = -1;
    float int_before = 1;
    float solve_x = 0;
    float solve_y = 0;
    while (1) {
        // user input velocity from the controller
        control_x = Ch4;
        control_y = Ch3;
        /* First we can derive the polar equation r = 1 / (cos PI/4 ± θ), 
        where 𝑟 is the maximum velocity vector of the robot car, 
        and 𝜃 is the absolute value of the car’s angle.
        Transforming it to Cartesian equation, we simply get y = -x + 1
        */
        // setting the direction of locomotion by changing the sign of the slope
        float xdrive_exp_slope = slope_before *  sign(control_x) * sign(control_y);
        // setting the maximum velocity by changing the intercept
        float xdrive_exp_int = int_before * control_y ;
        float direction_slope;     
        if(fabs(control_y) < 0.001) direction_slope = 0;
        if(fabs(control_x) < 0.001) direction_slope = 100;
        if(fabs(control_x) > 0.001 && fabs(control_y) > 0.001) direction_slope = control_y / control_x;
        if(fabs(direction_slope) > 10) {
            // simply move linearly
            LB.spin(fwd, (-control_y - Ch1) * 120, vex::voltageUnits::mV);
            LM.spin(fwd, (-control_y - Ch1 * 0.62) * 120, vex::voltageUnits::mV);
            LF.spin(fwd, (-control_y - Ch1) * 120, vex::voltageUnits::mV);
            RB.spin(fwd, (control_y - Ch1) * 120, vex::voltageUnits::mV);
            RM.spin(fwd, (control_y - Ch1 * 0.62) * 120, vex::voltageUnits::mV);
            RF.spin(fwd, (control_y - Ch1) * 120, vex::voltageUnits::mV);
            //cout<<"in drive forward"<<endl;
        } else if (fabs(direction_slope) <= 0.1) {
            // simply move horizontally
            LB.spin(fwd, (control_x - Ch1)*120, vex::voltageUnits::mV);
            LF.spin(fwd, (-control_x - Ch1)*120, vex::voltageUnits::mV);
            RB.spin(fwd, (control_x - Ch1)*120, vex::voltageUnits::mV);
            RF.spin(fwd, (-control_x - Ch1)*120, vex::voltageUnits::mV);
        } else {
            /* 
            integrate the velocity-vector of the x-drive wheels and linear wheels and set 
            appropriate power to the motor to maximize locomotion velocity
            */
            solve_x = (2 * xdrive_exp_int) / (direction_slope - xdrive_exp_slope);
            solve_y = xdrive_exp_slope * solve_x + xdrive_exp_int;
            
            LM.spin(fwd, (-control_y - Ch1 * 0.62)*120, vex::voltageUnits::mV);
            RM.spin(fwd, (control_y - Ch1 * 0.62)*120, vex::voltageUnits::mV);
            //cout<<"solve_x: "<<solve_x<<" solve_y: "<<solve_y<<endl; 
            LF.spin(fwd, (-solve_x - solve_y - Ch1) * 120, vex::voltageUnits::mV);
            LB.spin(fwd, (solve_x - solve_y - Ch1) * 120, vex::voltageUnits::mV);
            RF.spin(fwd, (-solve_x + solve_y - Ch1) * 120, vex::voltageUnits::mV);
            RB.spin(fwd, (solve_x + solve_y - Ch1) * 120, vex::voltageUnits::mV);
        }
        delay(10);
    }
    

    return 0;
}


#endif
