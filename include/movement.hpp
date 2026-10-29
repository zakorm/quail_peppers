#pragma once
#include "vex.h"
#include "PORTS.hpp"

float error, Integral, Deriviative, Rotation_correction, Previous_error;


float Kp = 0.16f;
float Ki = 0.0f;
float Kd = 0.24f;


// User defined function
void turn_right_distance(double turn_right_distance__distance) {

  inertial_sensor.setRotation(0.0, degrees);
  error = turn_right_distance__distance - inertial_sensor.rotation(degrees);
  Integral = 0.0;
  Previous_error = 0.0;

  while ((fabs(static_cast<float>(error)) > 0.5)) {
    
    
    error = turn_right_distance__distance - inertial_sensor.rotation(degrees);
    Integral = Integral + error;
    Deriviative = error - Previous_error;
    Rotation_correction = Kp * error + (Ki * Integral + Kd * Deriviative);
    Previous_error = error;
    if (Rotation_correction > 27.0) {
      left_drive.setVelocity(27.0, percent);
      right_drive.setVelocity(-27.0, percent);
    } else if (Rotation_correction < 1.0) {
      left_drive.setVelocity(1.0, percent);
      right_drive.setVelocity(-1.0, percent);
    } else {
      left_drive.setVelocity(Rotation_correction, percent);
      right_drive.setVelocity(-(Rotation_correction), percent);
    }
    left_drive.spin(forward);
    right_drive.spin(forward);
  wait(5, msec);
  }
  left_drive.stop();
  right_drive.stop();
}


// User defined function
void turn_left_distance(double turn_left_distance__distance) {
  inertial_sensor.setRotation(0.0, degrees);
  error = turn_left_distance__distance + inertial_sensor.rotation(degrees);
  Integral = 0.0;
  Previous_error = 0.0;
  while ((fabs(static_cast<float>(error)) > 0.5)) {

    error = turn_left_distance__distance + inertial_sensor.rotation(degrees);
    Integral = Integral + error;
    Deriviative = error - Previous_error;
    Rotation_correction = Kp * error + (Ki * Integral + Kd * Deriviative);
    Previous_error = error;
    if (Rotation_correction > 27.0) {
      left_drive.setVelocity(-27.0, percent);
      right_drive.setVelocity(27.0, percent);
    } else if (Rotation_correction < 1.0) {
      left_drive.setVelocity(-1.0, percent);
      right_drive.setVelocity(1.0, percent);
    } else {
      left_drive.setVelocity(-(Rotation_correction), percent);
      right_drive.setVelocity(Rotation_correction, percent);
    }
    left_drive.spin(forward);
    right_drive.spin(forward);
  wait(5, msec);
  }
  left_drive.stop();
  right_drive.stop();
}

// User defined function
void Forward_distance(double Forward_distance__distance) {
  left_drive.setPosition(0.0, degrees);
  right_drive.setPosition(0.0, degrees);
  inertial_sensor.setRotation(0.0, degrees);
  error = Forward_distance__distance - rotation_forwards.position(degrees);
  Integral = 0.0;
  Previous_error = 0.0;
  while (((left_drive.position(degrees) + right_drive.position(degrees)) / 2.0 < Forward_distance__distance)) {

    error = Forward_distance__distance - rotation_forwards.position(degrees);
    Integral = Integral + error;
    Deriviative = error - Previous_error;
    Rotation_correction = Kp * error + (Ki * Integral + Kd * Deriviative);
    Previous_error = error;
    if (error > 27.0) {
      left_drive.setVelocity(27.0, percent);
      right_drive.setVelocity(27.0, percent);
    } else if (error < 1.0) {
      left_drive.setVelocity(1.0, percent);
      right_drive.setVelocity(1.0, percent);
    } else {
      left_drive.setVelocity((error + Rotation_correction), percent);
      right_drive.setVelocity((error - Rotation_correction), percent);
    }
    left_drive.spin(forward);
    right_drive.spin(forward);
  wait(5, msec);
  }
  left_drive.stop();
  right_drive.stop();
}

// User defined function
void Backward_Distance(double Backward_Distance__Distance) {
  left_drive.setPosition(0.0, degrees);
  right_drive.setPosition(0.0, degrees);
  inertial_sensor.setRotation(0.0, degrees);
  error = Backward_Distance__Distance + rotation_forwards.position(degrees);
  Integral = 0.0;
  Previous_error = 0.0;
  while ((fabs(static_cast<float>(left_drive.position(degrees) + right_drive.position(degrees))) / 2.0 < Backward_Distance__Distance)) {

    error = Backward_Distance__Distance + rotation_forwards.position(degrees);
    Integral = Integral + error;
    Deriviative = error - Previous_error;
    Rotation_correction = Kp * error + (Ki * Integral + Kd * Deriviative);
    Previous_error = error;
    if (error > 27.0) {
      left_drive.setVelocity(-27.0, percent);
      right_drive.setVelocity(-27.0, percent);
    } else if (error < 1.0) {
      left_drive.setVelocity(-1.0, percent);
      right_drive.setVelocity(-1.0, percent);
    } else {
      left_drive.setVelocity(-(error + Rotation_correction), percent);
      right_drive.setVelocity(-(error - Rotation_correction), percent);
    }
    left_drive.spin(forward);
    right_drive.spin(forward);
  wait(5, msec);
  }
  left_drive.stop();
  right_drive.stop();
}
