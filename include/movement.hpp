#pragma once
#include "vex.h"
#include "PORTS.hpp"

// over
float Kp = 0.16f;
// under
float Ki = 0.0f;
// ratio/sensitivity
float Kd = 0.24f;

int max_speed = 27;

int min_speed = 1;


// User defined function
void turn_right_distance(double turn_right_distance__distance) {

  inertial_sensor.setRotation(0.0, degrees);
  float dir_left = turn_right_distance__distance - inertial_sensor.rotation(degrees);
  float Integral = 0.0;
  float Previous_dir_left = 0.0;

    left_drive.spin(forward);
    right_drive.spin(forward);

  while ((fabs(dir_left) > 0.5)) {
    
    
    dir_left = turn_right_distance__distance - inertial_sensor.rotation(degrees);
    Integral = Integral + dir_left;

    float Deriviative = dir_left - Previous_dir_left;
    float Rotation_correction = Kp * dir_left + (Ki * Integral + Kd * Deriviative);


    if (Rotation_correction > max_speed) {
      left_drive.setVelocity(max_speed, percent);
      right_drive.setVelocity(-max_speed, percent);
    } else if (Rotation_correction < min_speed) {
      left_drive.setVelocity(min_speed, percent);
      right_drive.setVelocity(-min_speed, percent);
    } else {
      left_drive.setVelocity(Rotation_correction, percent);
      right_drive.setVelocity(-(Rotation_correction), percent);
    }
    
    Previous_dir_left = dir_left;

  wait(5, msec);
  }
  left_drive.stop();
  right_drive.stop();
}


// User defined function
void turn_left_distance(double turn_left_distance__distance) {
  inertial_sensor.setRotation(0.0, degrees);

  float dir_left = turn_left_distance__distance + inertial_sensor.rotation(degrees);
  float Integral = 0.0f;
  float Previous_dir_left = 0.0f;

  left_drive.spin(forward);
  right_drive.spin(forward);
  while ((fabs(dir_left) > 0.5f)) {

    dir_left = turn_left_distance__distance + inertial_sensor.rotation(degrees);
    Integral = Integral + dir_left;

    float Deriviative = dir_left - Previous_dir_left;
    float Rotation_correction = Kp * dir_left + (Ki * Integral + Kd * Deriviative);
    
    if (Rotation_correction > max_speed) {
      left_drive.setVelocity(-max_speed, percent);
      right_drive.setVelocity(max_speed, percent);
    } else if (Rotation_correction < min_speed) {
      left_drive.setVelocity(-min_speed, percent);
      right_drive.setVelocity(min_speed, percent);
    } else {
      left_drive.setVelocity(-(Rotation_correction), percent);
      right_drive.setVelocity(Rotation_correction, percent);
    }
    Previous_dir_left = dir_left;
  wait(5, msec);
  }
  left_drive.stop();
  right_drive.stop();
}













void Forward_distance(double Forward_distance__distance) {
  left_drive.setPosition(0.0f, degrees);
  right_drive.setPosition(0.0f, degrees);
  inertial_sensor.setRotation(0.0f, degrees);

  float error = Forward_distance__distance - rotation_forwards.position(degrees);
  float Integral = 0.0f;
  float Previous_error = 0.0f;

  left_drive.spin(forward);
  right_drive.spin(forward);

  while (((left_drive.position(degrees) + right_drive.position(degrees)) / 2.0 < Forward_distance__distance)) {

    error = Forward_distance__distance - rotation_forwards.position(degrees);
    Integral = Integral + error;

    float Deriviative = error - Previous_error;
    float Rotation_correction = Kp * error + Ki * Integral + Kd * Deriviative;

    //upper bound
    if (error > max_speed) {
      left_drive.setVelocity(max_speed, percent);
      right_drive.setVelocity(max_speed, percent);
    }

    //lower bound
    else if (error < min_speed) {
      left_drive.setVelocity(min_speed, percent);
      right_drive.setVelocity(min_speed, percent);
    } 

    else {
      left_drive.setVelocity((error + Rotation_correction), percent);
      right_drive.setVelocity((error - Rotation_correction), percent);
    }
    
    Previous_error = error;

  wait(5, msec);
  }
  left_drive.stop();
  right_drive.stop();
}





void Backward_Distance(double Backward_Distance__Distance) {
  left_drive.setPosition(0.0, degrees);
  right_drive.setPosition(0.0, degrees);
  inertial_sensor.setRotation(0.0, degrees);


  float error = Backward_Distance__Distance + rotation_forwards.position(degrees);
  float Integral = 0.0f;
  float Previous_error = 0.0f;

  left_drive.spin(forward);
  right_drive.spin(forward);

  while ((fabs(left_drive.position(degrees) + right_drive.position(degrees))) / 2.0f < Backward_Distance__Distance) {

    error = Backward_Distance__Distance + rotation_forwards.position(degrees);
    Integral = Integral + error;

    float Deriviative = error - Previous_error;
    float Rotation_correction = Kp * error + (Ki * Integral + Kd * Deriviative);

    //upper bound
    if (error > max_speed) {
      left_drive.setVelocity(-max_speed, percent);
      right_drive.setVelocity(-max_speed, percent);
    } 
    
    //lower bound
    else if (error < min_speed) {
      left_drive.setVelocity(-min_speed, percent);
      right_drive.setVelocity(-min_speed, percent);
    } 
    
    else {
      left_drive.setVelocity(-(error + Rotation_correction), percent);
      right_drive.setVelocity(-(error - Rotation_correction), percent);
    }

    Previous_error = error;

  wait(5, msec);
  }

  left_drive.stop();
  right_drive.stop();
}
