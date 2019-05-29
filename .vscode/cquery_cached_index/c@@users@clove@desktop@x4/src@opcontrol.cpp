#include "main.h"
#include "flywheelutil\flywheel.hpp"
#include "C:\Users\clove\Desktop\X4\src\robotUtil\initRobot.hpp"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
 //Front Right Motor: -2
 //Front Left Motor: 1
 //Back Right Motor: -10
 //Back Left Motor: 9
 //Intake: 8
 //Indexer: 3
 //Flywheel: 6
 //Scraper

//bool //intakeOn = false;
//bool //intakeRevOn = false;
bool flywheelOn = true;
//auto pot = AsyncControllerFactory::posPID(-4, scraperPot.get_value(), 0.001, 0.0, 0.0001);
//float potError = 0;
//float potTarget = 3100;
//pros::ADILineSensor flywheelSensor(2);
double tRPM = 470*5;

void opcontrol() {
  intake.setGearing(AbstractMotor::gearset::green);
  flywheel-> setGearing(AbstractMotor::gearset::blue);
  indexer.setGearing(AbstractMotor::gearset::blue);
  scraper.setBrakeMode(AbstractMotor::brakeMode::hold);
  indexer.setBrakeMode(AbstractMotor::brakeMode::hold);
  pros::Task doubleShot_Task (doubleShotTask, (void*)flywheelOn,TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"DoubleShotTask");
  pros::Task scraperOpTask (scraperTask, (void*)flywheelOn,TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"ScraperTask");
  pros::Task intakeOpTask (intakeTask, (void*)flywheelOn,TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"IntakeTask");
  //pros::Task my_Task (flywheelControlTask, (void*)flywheelOn,TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"My Task");
  //pros::delay(3000);
  //gyro.reset();



	while(true){

    //std::cout << scraper.getPosition() << '\n';
    flywheelControlTask((void*)flywheelOn);



















    //pros::delay(1000);
    //gyro(3,1);
    //controller.setText(1, 1,std::to_string(gyro.get()));
    //pros::delay(100);
    //controller.clearLine(1);
    //gyro.get_value());
    if(turnOnFlywheel.changedToPressed()){
      flywheel->moveVelocity(560);
    //flywheelControlTask((void*)flywheelOn);
    }
  //  cout << "RPM: ";
  if(reverseButton.changedToPressed()){
    while(reverseButton.isPressed()){
  intake.moveVelocity(-200);
  indexer.moveVelocity(-600);
  drive.arcade(controller.getAnalog(ControllerAnalog::leftY),controller.getAnalog(ControllerAnalog::rightX));

}

  }




  //  pros::Task spinFlywheel (flywheelControlTask,(double)tRPM, TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"Flywheel");
    //intake.moveVelocity();
  //  flywheelControl(tRPM);
    //flywheelA.setMaxVelocity(536);
    //flywheelA.moveVelocity(535);




if(placeholder.changedToPressed()){
      //doubleShot();
    }
    drive.arcade(controller.getAnalog(ControllerAnalog::leftY),controller.getAnalog(ControllerAnalog::rightX));

		pros::delay(20);
	}
}
