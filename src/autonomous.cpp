#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
 auto driveA = ChassisControllerFactory::create(
   {1,9},
   {-10,-2},
   AbstractMotor::gearset::green,
   {4.125_in, 12.125_in}
 );
 AsyncMotionProfileController profileController = AsyncControllerFactory::motionProfile(
   2,  // Maximum linear velocity of the Chassis in m/s
   2.0,  // Maximum linear acceleration of the Chassis in m/s/s
   2.5, // Maximum linear jerk of the Chassis in m/s/s/s
  driveA // Chassis Controller
 );
QLength sideCapDistance = 3.5_ft;
QLength frontFlagDistance = 4.5_ft;
QLength frontCapDistance = 4.0_ft;
QLength midFlagDistance = 1.0_ft;
QLength platformAlignDistance = -4.0_ft;
QLength alliancePlatformDistance = 4.0_ft;
QLength centerPlatformDistance = 6.0_ft;
auto pot = Potentiometer(1);
auto scraper = AsyncControllerFactory::posPID(11,pot, 0.001, 0.0, 0.0001);
 okapi::Motor intakeA {8};
 okapi::Motor flywheelAuto {7};
okapi::Motor indexerA {3};


void autonomous() {
//  profile.generatePath({Point{1_ft, 7ft, 0_deg}, Point{5_ft, 7_ft, 0_deg}}, "Cap"});
 profileController.generatePath({
  Point{0_ft, 0_ft, 0_deg},  //   (0, 0, 0)
  Point{sideCapDistance, 0_ft, 0_deg}}, //
  "Ball" // Profile name
);
profileController.setTarget("Ball");
intakeA.moveVelocity(200);
profileController.waitUntilSettled();
profileController.setTarget("Ball", true); //Go back to starting tile
profileController.waitUntilSettled();
profileController.removePath("Ball"); //Ball path removed here


driveA.turnAngle(-45_deg);
//Should shoot mid flags here

profileController.generatePath({
Point{0_ft, 0_ft, 0_deg},
Point{2_ft, 0_ft, 0_deg}},
"Scrape"
);
profileController.setTarget("Scrape");
profileController.waitUntilSettled();
profileController.setTarget("Scrape", true);
profileController.waitUntilSettled();
profileController.removePath("Scrape");

driveA.turnAngle(-45_deg);
//Should shoot top and mid flags
profileController.generatePath({
Point{0_ft, 0_ft, 0_deg},
Point{4_ft, 0_ft, 0_deg}},
"botFlag"
);
profileController.setTarget("botFlag");
profileController.waitUntilSettled();
profileController.setTarget("botFlag", true);
profileController.waitUntilSettled();
profileController.removePath("botFlag");

}
