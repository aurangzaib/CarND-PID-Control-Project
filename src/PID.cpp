#include "PID.h"
#include <iostream>
#include <cmath>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double kp, double ki, double kd) {
  Kp = kp;
  Ki = ki;
  Kd = kd;
  p_error = 0;
  i_error = 0;
  d_error = 0;
}

void PID::UpdateError(double cte) {

  // update pid errors
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::CalculateSteering() {

  // default steering value
  double steering = 0.0;

  // calculate steering value
  steering -= Kp * p_error;
  steering -= Kd * d_error;
  steering -= Ki * i_error;

  // limit steering value
  if (steering > 1) steering = 1;
  else if (steering < -1) steering = -1;

  return steering;
}

double PID::CalculateThrottle() {

  // default throttle value
  double throttle = 0.61;

  // calculate throttle value
  throttle -= Kp * p_error;
  throttle -= Kd * d_error;
  throttle -= Ki * i_error;

  // limit throttle value
  if (throttle > 0.70) throttle = 0.70;
  else if (throttle < -1) throttle = -1;

  return throttle;
}