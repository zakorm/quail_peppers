#include "PORTS.hpp"

//PORTS CHANGE

brain Brain;
controller Controller1;


//SENSORS

inertial inertial_sensor(PORT10);
rotation rotation_forwards(PORT15);
rotation rotation_arm(PORT11);
bumper bottom_bumper(Brain.ThreeWirePort.C);
distance claw_dist(PORT3);

//MOTORS

motor left_front_drive(PORT12);
motor left_back_drive(PORT13);
motor_group left_drive(left_front_drive, left_back_drive);

motor right_front_drive(PORT16);
motor right_back_drive(PORT14);
motor_group right_drive(right_front_drive, right_back_drive);

motor arm_left(PORT7);
motor arm_right(PORT8, true);
motor_group arm_motors(arm_left, arm_right);

motor claw_motor(PORT1);