#include "../../include/main.h"
#include "globals.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);

// drive train
pros::Motor leftFrontMotor(4, MOTOR_GEAR_BLUE, 1);
pros::Motor rightFrontMotor(3, MOTOR_GEAR_BLUE);
pros::Motor leftBackMotor(18, MOTOR_GEAR_BLUE, 1);
pros::Motor rightBackMotor(6, MOTOR_GEAR_BLUE);
pros::Motor leftMidMotor(4, MOTOR_GEAR_BLUE); 
pros::Motor rightMidMotor(9, MOTOR_GEAR_BLUE, 1); 

// disc mechanisms
pros::Motor intake(19);
pros::Motor intake2(20, 1);
pros::Motor &roller = intake;
pros::Motor &roller2 = intake2;
pros::Motor flywheel(1, MOTOR_GEAR_BLUE, 1); 
pros::Motor flywheel2(2, MOTOR_GEAR_BLUE);

// sensors
pros::Vision vision_sensor(13);
pros::Imu imu_sensor(16);
pros::Optical optical_sensor(17);

// pneumatics pistons
pros::ADIDigitalOut expander1_piston(3);
pros::ADIDigitalOut expander2_piston(4);
pros::ADIDigitalOut flywheel_piston(1);

int autonSelection = SKILLS; // default auton selected