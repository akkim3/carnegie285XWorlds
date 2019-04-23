#include "main.h"
#include "flywheelutil\flywheel.hpp"
#include "C:\Users\clove\Desktop\X4\src\robotUtil\initRobot.hpp"
#include <iostream>
#include <cstdio>
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
 Controller controller;
 ControllerButton flywheelShoot (ControllerDigital::R1);
 ControllerButton placeholder (ControllerDigital::R2);
 ControllerButton intakeFwd (ControllerDigital::L1);
 ControllerButton intakeRev (ControllerDigital::L2);


 ControllerButton changeRPMUp (ControllerDigital::X);
 ControllerButton changeRPMDown (ControllerDigital::Y);
 ControllerButton upButton (ControllerDigital::up);
 ControllerButton dwButton (ControllerDigital::down);
 ControllerButton leButton (ControllerDigital::left);
  ControllerButton rtButton (ControllerDigital::right);
//bool //intakeOn = false;
//bool //intakeRevOn = false;
bool flywheelOn = true;
//auto pot = AsyncControllerFactory::posPID(-4, scraperPot.get_value(), 0.001, 0.0, 0.0001);
//float potError = 0;
//float potTarget = 3100;
//pros::ADILineSensor flywheelSensor(2);
double tRPM = 470*5;
void resetScraper(){
  scraper.moveVoltage(10000);
  pros::delay(500);
  if(scraper.isStopped()){
    scraper.moveVoltage(0);
    pros::delay(200);
    scraper.move_relative(-345, 200);

    pros::delay(750);
    //if(scraper.isStopped()){
    scraper.tarePosition();
  //}
  }

}

void opcontrol() {
  intake.setGearing(AbstractMotor::gearset::green);
  flywheel-> setGearing(AbstractMotor::gearset::blue);
  indexer.setGearing(AbstractMotor::gearset::blue);
  scraper.setBrakeMode(AbstractMotor::brakeMode::hold);
  indexer.setBrakeMode(AbstractMotor::brakeMode::hold);



	while(true){

    std::cout << scraper.getPosition() << '\n';
//pros::Task my_Task (flywheelControlTask, (void*)flywheelOn,TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"My Task");
    flywheelControlTask((void*)flywheelOn);
  //  cout << "RPM: ";


    if (upButton.changedToPressed()) {
      scraper.moveAbsolute(360, 200);
    }
    if (upButton.changedToReleased()) {
      scraper.moveAbsolute(0, 200);
    }
    if (intakeRev.changedToPressed()) {
      scraper.moveAbsolute(360, 200);
    }
    if (intakeRev.changedToReleased()) {
      scraper.moveAbsolute(0, 200);
    }
    if(leButton.changedToPressed()){
      scraper.moveAbsolute(-150,200);
    }
    if(rtButton.changedToPressed()){
    //adjustScraper(true);
    resetScraper();
    //  pros::Task scraper_Task (adjustScraper, (void*)flywheelOn,TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"ScraperTask");
    }



  //  pros::Task spinFlywheel (flywheelControlTask,(double)tRPM, TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"Flywheel");
    //intake.moveVelocity();
  //  flywheelControl(tRPM);
    //flywheelA.setMaxVelocity(536);
    //flywheelA.moveVelocity(535);

  if(intakeFwd.isPressed() && !intakeRev.isPressed() && !placeholder.isPressed() && !flywheelShoot.isPressed()){



     intake.moveVelocity(200);



     }



   else if(intakeRev.isPressed() && !intakeFwd.isPressed() && !placeholder.isPressed() && !flywheelShoot.isPressed()){



//       intake.moveVelocity(-200);
//doubleShot();


       }



   else if(intakeRev.isPressed() && intakeFwd.isPressed() && !placeholder.isPressed() && !flywheelShoot.isPressed()){



         intake.moveVelocity(-120);



         indexer.moveVelocity(-120);



         }



 else if(!intakeRev.isPressed() && !intakeFwd.isPressed() && placeholder.isPressed() && !flywheelShoot.isPressed()){

   //scraper.moveAbsolute(360, 200);





         }



 else if(intakeRev.isPressed() && !intakeFwd.isPressed() && placeholder.isPressed() && !flywheelShoot.isPressed() ){

         }
         else if(!intakeRev.isPressed() && !intakeFwd.isPressed() && !placeholder.isPressed() && flywheelShoot.isPressed() ){
           indexer.moveVelocity(600);
           intake.moveVelocity(200);
    }
   else{
       intake.moveVelocity(0);

       indexer.moveVelocity(0);
     }
  /*  if(flywheelShoot.isPressed()){

    }else{
      indexer.moveVelocity(0);
      intake.moveVelocity(0);
    }
*/
    if(placeholder.changedToPressed()){
      doubleShot();
      //  pros::Task doubleShot_Task (doubleShotTask, (void*)flywheelOn,TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"DouleShotTask");

    }
  /*  if(changeRPMUp.changedToPressed()){
      flywheelControl(460*5);
    }
    if(changeRPMDown.changedToPressed()){5
      flywheelControl(420*5);
    }
    */
    drive.arcade(controller.getAnalog(ControllerAnalog::leftY),controller.getAnalog(ControllerAnalog::rightX));
    //drive.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightX));
		pros::delay(20);
	}
}
