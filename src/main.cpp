#include "vex.h"
#include "movement.hpp"
#include "lift.hpp"
#include "PORTS.hpp"

using namespace vex;



competition Competition;


//CHANGING VARS

float move_mod = 0.8f;
float turn_mod = 0.6f;
//left:right * 2
float friction_ratio = 0.675f;



//init globals


int Screen_precision = 0, Console_precision = 0, Controller1_precision = 0;

bool printinertial, descore_state, Lift_state, True_state, Lift_step, Lower_step, Spinner_state, April_state, Aprilstate_1, Aprilstate_0, Aprilstate_2, Aprilstate_3, Aprilstate_4;






//Debug


void print_stuff() {
  while (true) {
    Brain.Screen.setCursor(1, 1);
    
    Brain.Screen.print(inertial_sensor.rotation(degrees));
    
  wait(5, msec);
  }
}


//calls and activations



//WHEN STARTED
//TREADING

// "when started" hat block
int whenStarted1() {
  while(true) {
    print_stuff();
  }
  return 0;
}

// "when started" hat block
int whenStarted2() {
  // Aprilstate_0 = false;
  // Aprilstate_1 = false;
  // Aprilstate_2 = false;
  // Aprilstate_3 = false;
  // Aprilstate_4 = false;
  inertial_sensor.startCalibration();
  while (inertial_sensor.isCalibrating()) { task::sleep(50); }
  Brain.Screen.print("done");
  // inertial_sensor.setRotation(0.0, degrees);
  // rotation_forwards.setPosition(0.0, degrees);
  // rotation_arm.setPosition(0.0, degrees);
  // left_drive.setStopping(brake);
  // right_drive.setStopping(brake);
  // Screen_precision = 0;
  return 0;
}

int whenStarted3() {
  return 0;
}



int onauton_autoncontrol_0() {
  turn_left_distance(90);
  Forward_distance(300);
  return 0;
}


// "when driver control" hat block
int ondriver_drivercontrol_0() {
  while (true) {
    left_drive.setVelocity((Controller1.Axis3.position() * move_mod + Controller1.Axis1.position() * turn_mod) * friction_ratio, percent);
    right_drive.setVelocity((Controller1.Axis3.position() * move_mod - Controller1.Axis1.position() * turn_mod) / friction_ratio, percent);
    left_drive.spin(forward);
    right_drive.spin(forward);
  wait(5, msec);
  }
  return 0;
}


//WHEN CONTROLLER BUTTON PRESSED


// "when Controller1 ButtonR1 pressed" hat block
void onevent_Controller1ButtonR1_pressed_0() {
  claw_motor.spin(forward);
}

// "when Controller1 ButtonR2 pressed" hat block
void onevent_Controller1ButtonR2_pressed_0() {
  claw_motor.spin(reverse);
}

// "when Controller1 ButtonUp pressed" hat block
void onevent_Controller1ButtonUp_pressed_0() {
  Lift_step_func();
}

// "when Controller1 ButtonDown pressed" hat block
void onevent_Controller1ButtonDown_pressed_0() {
  Lower_step_func();
}

// "when Controller1 ButtonY pressed" hat block
void onevent_Controller1ButtonY_pressed_0() {
  if (Lift_state) {
    Lift_to_highest();
  }
  else {
    Lower_to_lowest();
  }
  Lift_state = !Lift_state;
}





//driver and auton stuff
//!!!DO NOT CHANGE!!!


void VEXcode_driver_task() {
  // Start the driver control tasks....
  vex::task drive0(ondriver_drivercontrol_0);
  while(Competition.isDriverControl() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  drive0.stop();
  return;
}

void VEXcode_auton_task() {
  // Start the auton control tasks....
  vex::task auton0(onauton_autoncontrol_0);
  while(Competition.isAutonomous() && Competition.isEnabled()) {this_thread::sleep_for(10);}

  return;
}



//main




int main() {
  vex::competition::bStopTasksBetweenModes = false;
  Competition.autonomous(VEXcode_auton_task);
  Competition.drivercontrol(VEXcode_driver_task);


  // register event handlers
  Controller1.ButtonR1.pressed(onevent_Controller1ButtonR1_pressed_0);
  Controller1.ButtonR2.pressed(onevent_Controller1ButtonR2_pressed_0);
  Controller1.ButtonUp.pressed(onevent_Controller1ButtonUp_pressed_0);
  Controller1.ButtonDown.pressed(onevent_Controller1ButtonDown_pressed_0);
  Controller1.ButtonY.pressed(onevent_Controller1ButtonY_pressed_0);

  wait(15, msec);
  vex::task ws1(whenStarted2);
  vex::task ws2(whenStarted3);
  whenStarted1();
}