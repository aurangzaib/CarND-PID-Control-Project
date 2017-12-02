#include "PID.h"
#include <iostream>
#include <cmath>

using namespace std;

/*
* TODO: Complete the PID class.
*/

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

double PID::TotalSteeringError() {

  // default steering value
  double error = 0.0;

  // calculate steering value
  error -= Kp * p_error;
  error -= Kd * d_error;
  error -= Ki * i_error;

  // limit steering value
  if (error > 1) error = 1;
  else if (error < -1) error = -1;

  return error;
}

double PID::TotalThrottleError() {

  // default throttle value
  double error = 0.61;

  // calculate throttle value
  error -= Kp * p_error;
  error -= Kd * d_error;
  error -= Ki * i_error;

  // limit throttle value
  if (error > 0.70) error = 0.70;
  else if (error < -1) error = -1;

  return error;
}