#include "C:\Users\clove\Desktop\X4\include\main.h"
#include "pidVelSystem.hpp"

Motor* flywheel = new okapi::Motor(7);
double flywheelRatio = 5;
using namespace flywheelLib;
flywheelLib::velPID* pid = new flywheelLib::velPID(0.35, 0.05, 0.045, 0.9);

flywheelLib::emaFilter* rpmFilter = new flywheelLib::emaFilter(0.15);

double motorSlew = 0.7;



double targetRPM = 500*5;

double currentRPM = 0;

double lastPower = 0;

double motorPower = 0;



void flywheelControl()

{

  currentRPM = rpmFilter->filter(flywheel->getActualVelocity() * flywheelRatio);



  motorPower = pid->calculate(targetRPM, currentRPM);



  if(motorPower <= 0) motorPower = 0; //Prevent motor from spinning backward



  //Give the motor a bit of a starting boost

  if(motorPower > lastPower && lastPower < 10 && motorPower > 10) lastPower = 10;



  //This slews the motor by limiting the rate of change of the motor speed

  double increment = motorPower - lastPower;

  if(abs(increment) > motorSlew) motorPower = lastPower + (motorSlew * flywheelLib::sgn(increment));

  lastPower = motorPower;



  flywheel->move(motorPower);



  //std::cout << "RPM: " << currentRPM << " Power: "<< motorPower << " Error: "<< flywheelPID.getError() << "\n";

  pros::delay(20);

}
