#include "C:\Users\clove\Desktop\X4\src\robotUtil\initrobot.hpp"
#include "main.h"

Motor scraper (4, true, AbstractMotor::gearset::green);;
Motor intake (8, false, AbstractMotor::gearset::green);
Motor* flywheel = new okapi::Motor(7);
Motor indexer (3,false, AbstractMotor::gearset::blue);
pros::ADILineSensor flywheelSensor(2);
float potError = 0;
float potTarget = 3100;
ADIGyro gyro(3,1);
ControllerButton doubleShotTest (ControllerDigital::A);
ControllerButton reverseButton (ControllerDigital::B);

Controller controller;
ControllerButton flywheelShoot (ControllerDigital::R1);
ControllerButton placeholder (ControllerDigital::R2);
ControllerButton intakeFwd (ControllerDigital::L1);
ControllerButton scraperButton (ControllerDigital::L2);

bool doubleShotOnBool = false;
ControllerButton turnOnFlywheel (ControllerDigital::X);
ControllerButton changeRPMDown (ControllerDigital::Y);
ControllerButton upButton (ControllerDigital::up);
ControllerButton dwButton (ControllerDigital::down);
ControllerButton leButton (ControllerDigital::left);
 ControllerButton rtButton (ControllerDigital::right);

//auto controller = AsyncControllerFactory::posPID(1, ADIEncoder('A', 'B'), 0.001, 0.0, 0.0001);
void doubleShotTask(void* enable){
  while(true){
      if(placeholder.changedToPressed()){
          doubleShotOnBool = true;
          indexer.moveVelocity(600);
          intake.moveVelocity(200);
          pros::delay(180);//120
          scraper.moveAbsolute(-120, 200);
          pros::delay(2000);
          scraper.moveAbsolute(0, 200);
          indexer.moveVelocity(0);
          intake.moveVelocity(0);
          doubleShotOnBool = false;
          }
          pros::delay(10);

        }

}


void intakeTask(void* enable){
  while(true){
    if(!doubleShotOnBool){
      if(intakeFwd.isPressed() && !scraperButton.isPressed() && !placeholder.isPressed() && !flywheelShoot.isPressed()){
        intake.moveVelocity(200);
      } else if(scraperButton.isPressed() && !intakeFwd.isPressed() && !placeholder.isPressed() && !flywheelShoot.isPressed()) {
      } else if(scraperButton.isPressed() && intakeFwd.isPressed() && !placeholder.isPressed() && !flywheelShoot.isPressed()){
        intake.moveVelocity(-200);
        indexer.moveVelocity(-200);
      } else if(!scraperButton.isPressed() && !intakeFwd.isPressed() && placeholder.isPressed() && !flywheelShoot.isPressed()){
      } else if(scraperButton.isPressed() && !intakeFwd.isPressed() && placeholder.isPressed() && !flywheelShoot.isPressed() ){
      } else if(!scraperButton.isPressed() && !intakeFwd.isPressed() && !placeholder.isPressed() && flywheelShoot.isPressed() ){
         indexer.moveVelocity(600);
         intake.moveVelocity(200);
      } else {
         intake.moveVelocity(0);
         indexer.moveVelocity(0);
      }
    }
    pros::delay(10);
  }
}


void scraperTask(void* enable){
  while(true){
    if(!doubleShotOnBool){
    if (upButton.changedToPressed()) {
      scraper.moveVelocity(-100);
    }
    if (upButton.changedToReleased()) {
      scraper.moveVelocity(0);
      scraper.tarePosition();
    }
    if (dwButton.changedToPressed()) {
      scraper.moveVelocity(100);
    }
    if (dwButton.changedToReleased()) {
      scraper.moveVelocity(0);
      scraper.tarePosition();
    }
    if (scraperButton.changedToPressed()) {
      scraper.moveAbsolute(360, 200);
    }
    if (scraperButton.changedToReleased()) {
      scraper.moveAbsolute(0, 200);
    }
    if(leButton.changedToPressed()){
      scraper.moveAbsolute(-150,200);
    }
    if(rtButton.changedToPressed()){
    //adjustScraper(true);
    resetScraper();
    //drive.turnAngle(90_deg);
    }
  }
  pros::delay(10);

}
}

void doubleShot(){
  indexer.moveVelocity(600);
  intake.moveVelocity(200);
  pros::delay(120);
  scraper.moveAbsolute(-120, 200);
  pros::delay(900);
  scraper.moveAbsolute(0, 200);
}
void slowDoubleShot(){
  indexer.moveVelocity(600);
  intake.moveVelocity(200);
  pros::delay(150);
  indexer.moveVelocity(0);
  intake.moveVelocity(0);
  scraper.moveAbsolute(-120,200);
  pros::delay(500);
  indexer.moveVelocity(600);
  intake.moveVelocity(200);
  pros::delay(500);
  indexer.moveVelocity(0);
  intake.moveVelocity(0);
  scraper.moveAbsolute(0,200);
}

void scrape(){
  intake.moveVelocity(200);
  scraper.moveAbsolute(280,200);
  drive.setMaxVelocity(75);
  pros::delay(200);
  drive.moveDistanceAsync(-1_ft);
  intake.moveVelocity(200);
  pros::delay(200);
  scraper.moveAbsolute(360,200);
  pros::delay(500);
  scraper.moveAbsolute(0,200);
  intake.moveVelocity(200);
  drive.setMaxVelocity(150);
  drive.moveDistance(1_ft);
}
void flipCap(){
  scraper.moveAbsolute(360,200);
  //drive.moveDistanceAsync(-1_ft);
  drive.setMaxVelocity(200);
  drive.moveDistanceAsync(2.5_ft);
    pros::delay(200);
    scraper.moveAbsolute(0,200);
    drive.setMaxVelocity(200);

}
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


void adjustScraper(void* enable){
potError = potTarget - 1;//scraperPot.get_value();
while(enable){
if(abs(potError) > 20){
  scraper.moveRelative((-potError),100);

} else{
  //intake.moveVelocity(100);
  scraper.tarePosition();
}
pros::delay(50);
}
}
//}
 ChassisControllerIntegrated drive = ChassisControllerFactory::create(
   {1,9},
   {-10,-2},
   AbstractMotor::gearset::green,
   {4.125_in, 12.5_in}//11.75
 );

 



 MotorGroup rightDrive({1,9});
 MotorGroup leftDrive({-10,-2});

 AsyncMotionProfileController profileController = AsyncControllerFactory::motionProfile(
   2,  // Maximum linear velocity of the Chassis in m/s
   2,  // Maximum linear acceleration of the Chassis in m/s/s
   8, // Maximum linear jerk of the Chassis in m/s/s/s
  drive // Chassis Controller
 );
