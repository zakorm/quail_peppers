#pragma once
#include "vex.h"
using namespace vex;
//PORTS

extern brain Brain;
extern controller Controller1;


//SENSORS
extern inertial inertial_sensor;
extern rotation rotation_forwards;
extern rotation rotation_arm;
extern bumper bottom_bumper;
extern distance claw_dist;


//MOTORS
extern motor left_front_drive;
extern motor left_back_drive;
extern motor_group left_drive;

extern motor right_front_drive;
extern motor right_back_drive;
extern motor_group right_drive;

extern motor arm_left;
extern motor arm_right;
extern motor_group arm_motors;

extern motor claw_motor;