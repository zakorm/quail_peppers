#pragma once
#include "vex.h"
//PORTS

brain Brain = brain();

controller Controller1 = controller();


//SENSORS
inertial inertial_sensor = inertial(PORT10);
rotation rotation_forwards = rotation(PORT15);
rotation rotation_arm = rotation(PORT11);
bumper bottom_bumper = bumper(Brain.ThreeWirePort.C);
distance claw_dist = distance(PORT3);


//MOTORS
motor left_front_drive = motor(PORT16);
motor left_back_drive = motor(PORT14);
motor_group left_drive = motor_group(left_front_drive, left_back_drive);

motor right_front_drive = motor(PORT12);
motor right_back_drive = motor(PORT13);
motor_group right_drive = motor_group(right_front_drive, right_back_drive);

motor arm_left = motor(PORT7);
motor arm_right = motor(PORT8, true);
motor_group arm_motors = motor_group(arm_left, arm_right);

motor claw_motor = motor(PORT1);