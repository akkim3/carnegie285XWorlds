#pragma once
#include "main.h"

extern Motor intake;
extern Motor* flywheel;
extern Motor indexer;
extern Motor scraper;
extern ControllerButton doubleShotTest;
void doubleShotTask(void* enable);
void scraperTask(void* enable);
void intakeTask(void* enable);
void resetScraper();
void doubleShot();
void slowDoubleShot();
extern bool doubleShotOnBool;
void scrape();
void flipCap();
void adjustScraper(void* enable);
extern ChassisControllerIntegrated drive;
extern AsyncMotionProfileController profileController;

extern pros::ADILineSensor flywheelSensor;
extern ADIGyro gyro;

extern float potError;
extern float potTarget;

extern Controller controller;
extern ControllerButton flywheelShoot;
extern ControllerButton placeholder;
extern ControllerButton intakeFwd;
extern ControllerButton scraperButton;


extern ControllerButton turnOnFlywheel;
extern ControllerButton reverseButton;
extern ControllerButton upButton;
extern ControllerButton dwButton;
extern ControllerButton leButton;
extern ControllerButton rtButton;

extern MotorGroup rightDrive;
extern MotorGroup leftDrive;
