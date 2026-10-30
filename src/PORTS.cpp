#include "PORTS.hpp"

//PORTS CHANGE

brain Brain;
controller Controller1;


//SENSORS

inertial inertial_sensor(PORT11);
rotation rotation_forwards(PORT15);
rotation rotation_arm(PORT12);
bumper bottom_bumper(Brain.ThreeWirePort.C);
distance claw_dist(PORT3);

//MOTORS

motor left_front_drive(PORT10, true);
motor left_back_drive(PORT9, true);
motor_group left_drive(left_front_drive, left_back_drive);

motor right_front_drive(PORT8);
motor right_back_drive(PORT7);
motor_group right_drive(right_front_drive, right_back_drive);

motor arm_left(PORT2);
motor arm_right(PORT5, true);
motor_group arm_motors(arm_left, arm_right);

motor claw_motor(PORT1);