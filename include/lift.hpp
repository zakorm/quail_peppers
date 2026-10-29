#pragma once
#include "vex.h"
#include "PORTS.hpp"
using namespace vex;

float rotation_to_position;



// User defined function
void Lift_step_func() {
  rotation_to_position = rotation_arm.position(degrees) + 180.0;
  while (!(rotation_arm.position(degrees) >= rotation_to_position)) {
    arm_motors.spin(forward);
  wait(5, msec);
  }
  arm_motors.stop();
}

// User defined function
void Lower_step_func() {
  rotation_to_position = rotation_arm.position(degrees) - 180.0;
  if (rotation_to_position > 0.0) {
    while (!(rotation_arm.position(degrees) <= rotation_to_position || bottom_bumper.pressing())) {
      arm_motors.spin(reverse);
    wait(5, msec);
    }
    arm_motors.stop();
  }
  else {
    arm_motors.stop();
  }
}

// User defined function
void Lift_to_highest() {
  arm_motors.spin(forward);
  waitUntil((claw_dist.objectDistance(mm) > 100.0));
  arm_motors.stop();
}

// User defined function
void Lower_to_lowest() {
  arm_motors.spin(reverse);
  waitUntil(bottom_bumper.pressing());
  arm_motors.stop();
}
