#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  /*
  * initialize PID errors
  */
  p_error = i_error = d_error = 0;

  /*
  * initialize coefficients
  */
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  /* corresponding python code in the lecture ..
  diff_cte = cte - prev_cte
  prev_cte = cte
  int_cte += cte
  */
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  return p_error + i_error + d_error;
}
