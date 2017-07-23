#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	CTE_sum = 0.0;
	firstMeasurement = true;
}

void PID::UpdateError(double CTE) {

	double CTE_diff;

	if (firstMeasurement) {
		CTE_diff = 0.0;
		firstMeasurement = false;
	}
	else {
		CTE_diff = CTE - last_CTE;
	}

  p_error = Kp * CTE;
  i_error = Kd * CTE_diff;
  d_error = Ki * CTE_sum;

	last_CTE = CTE;
}

double PID::TotalError() {
	return -p_error -i_error -d_error;
}

