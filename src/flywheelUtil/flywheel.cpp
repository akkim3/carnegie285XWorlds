#include "C:\Users\clove\Desktop\X4\include\main.h"
#include "pidVelSystem.hpp"
#include "C:\Users\clove\Desktop\X4\src\robotUtil\initRobot.hpp"
//Motor* flywheel = new okapi::Motor(7);
double flywheelRatio = 5;
using namespace flywheelLib;
flywheelLib::velPID* pid = new flywheelLib::velPID(0.5, 0.05, 0.055, 0.9);

flywheelLib::emaFilter* rpmFilter = new flywheelLib::emaFilter(0.15);

double motorSlew = 0.7;



double targetRPM = 500;

double currentRPM = 0;

double lastPower = 0;

double motorPower = 0;

double error = 0;

float driveVar;
float gain;
long firstCross;
float driveApprox;
double lastError = 0;
float driveZero;
float predictedDrive = 0.75;
void setFlywheelVelocity(double inputRPM){
  targetRPM = inputRPM;
    error = targetRPM - currentRPM;
    lastError = error;
    driveApprox = predictedDrive;
    firstCross = 1;
    driveZero = 0;

}
void flywheelControl()

{
  if(motorPower <= 0) motorPower = 0;


  currentRPM = rpmFilter->filter(flywheel->getActualVelocity());
  //currentRPM = flywheel->getActualVelocity();
  error = targetRPM - currentRPM;
  driveVar = driveVar + (error * gain);

  if((sgn(error) != sgn(lastError))){
    if(firstCross){
      firstCross = 0;
      driveVar = driveApprox;
    } else{

      driveVar = 0.5*(driveVar + driveZero);
    }
    driveZero = driveVar;
  }

  lastError = error;





}

void flywheelControlTask(void*param){
//  gain = 0.00085;
  gain = 0.0008;
  predictedDrive = 0.75;
  //while(true){
    setFlywheelVelocity(560);
    flywheelControl();
    if (motorPower > 127) {
      motorPower = 127;
    }
    motorPower = (driveVar*127) + 0.5;
    flywheel->move(motorPower);
  //flywheel->moveVelocity(505);
    //std::cout << currentRPM << "\n";
    pros::delay(20);
//  }

}
