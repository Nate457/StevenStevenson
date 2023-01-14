#include "../../include/main.h"
#include "globals.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);

// drive train
pros::Motor leftFrontMotor(13, MOTOR_GEAR_BLUE,1);
pros::Motor rightFrontMotor(18, MOTOR_GEAR_BLUE, 0);
pros::Motor leftBackMotor(11, MOTOR_GEAR_BLUE, 0);
pros::Motor rightBackMotor(19, MOTOR_GEAR_BLUE, 0);
pros::Motor leftMidMotor(12, MOTOR_GEAR_BLUE,1); 
pros::Motor rightMidMotor(20, MOTOR_GEAR_BLUE, 1); 

// disc mechanisms
pros::Motor intake(14, 1);
pros::Motor &roller = intake;
pros::Motor &indexer = intake;  // the flex wheel indexer for the shooter
pros::Motor flywheel(15, MOTOR_GEAR_BLUE);  

// sensors
pros::Vision vision_sensor(17);
pros::Imu imu_sensor(16);
pros::Optical optical_sensor(1);

// pneumatics pistons
pros::ADIDigitalOut expander1_piston(5);
pros::ADIDigitalOut expander2_piston(4);
pros::ADIDigitalOut side_piston(3);
pros::ADIDigitalOut side2_piston(2);
pros::ADIDigitalOut leveler(3, 1);
pros::ADIDigitalOut flywheel_piston(8,1);  // the gate for the flywheel

int autonSelection = SKILLS; // default auton selected