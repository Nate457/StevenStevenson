#include "../include/main.h"
#include "../globals/globals.hpp"
#include "../lib/movement.hpp"
#include "../lib/helper_functions.hpp"
#include "../lib/scoring.hpp"
#include "pros/vision.h"

using namespace pros;

void prog_skills() {
    // initial setup
    vector center = {};
    leveler.set_value(1);
    unsigned timeElapsed = 0;
    unsigned desiredSpeed = 1730;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // shoot preloads and turn roller
     while (desiredSpeed != INT16_MAX) {
        delay(12);
    }
    shoot(270);
    desiredSpeed = 2160;
    intake = 127;

    move_straight(-32.7, -53.0, &center, MOTOR_BRAKE_BRAKE);
    turn(0, -32, 90, &center);
    intake = 0;
    move_straight(0.6, -41.0); delay(200); turn_rollerN(true); delay(200);
    intake = 127;
    
    //pick up first stack turn second roller 
    move_straight(24.2, 37.0, &center, MOTOR_BRAKE_BRAKE);
    turn(-30, 0, 8, &center);
    intake = 0;
    move_straight(1.6, -49.0); delay(200); turn_rollerN(true); delay(200);


    //shoot
    move_straight(2.9, 49.0, &center);
    intake = 127;
    turn(23, -23, 85.4, &center);
    move_straight(27.4, 51.0, &center, MOTOR_BRAKE_BRAKE);
    pros::delay(450);
    shoot(360);

    desiredSpeed = 2260;
    // go back
    turn(0, -28, 90, &center);
    intake = 127;
    move_straight(-22.2, -51.0, &center, MOTOR_BRAKE_BRAKE);
    turn(-23, 23, 45, &center);

    // pick up and shoot x 2
    move_straight(33.0, 45.0, &center, MOTOR_BRAKE_BRAKE);
    turn(24, -24, 114, &center);
    pros::delay(550);
    shoot(410);
    turn(-23, 23, 48, &center);
    intake = 127;
    move_straight(53.0, 51.0, &center, MOTOR_BRAKE_BRAKE);
    turn(20, -20, 111, &center);
    pros::delay(200);
    turn(19, -19, 174.2, &center);
    move_straight(19.0, 51.0, &center, MOTOR_BRAKE_BRAKE);
    shoot(410);
    intake = 127;
    turn(19, -19, 175.5, &center);

    // third roller
    move_straight(-26.0, -51.0, &center, MOTOR_BRAKE_BRAKE);
    turn(0, -29, 272, &center);
    intake = 0;
    move_straight(2.2, -45.0); delay(100); turn_rollerN(true); delay(100);

    //pick up stack turn fourth roller 
    intake = 127;
    move_straight(22.8, 37.0, &center, MOTOR_BRAKE_BRAKE);
    turn(-30, 0, 184, &center);
    intake = 0;
    move_straight(3.4, -41.0); delay(100); turn_rollerN(true); delay(100);

    
    //shoot
    move_straight(3.2, 49.0, &center);
    desiredSpeed = 2140;
    intake = 127;
    turn(24, 0, 220, &center);
    pros::delay(200);
    turn(24, 0, 265.9, &center);
    move_straight(25.0, 51.0, &center, MOTOR_BRAKE_BRAKE);
    shoot(360);
    intake = 127;

    // go back
    desiredSpeed = 2200;
    move_straight(-22.3, -53.0, &center, MOTOR_BRAKE_BRAKE);
    turn(-23, 23, 225, &center);

    // pick up and shoot x 2
    move_straight(30.9, 41.0, &center, MOTOR_BRAKE_BRAKE);
    turn(23, -23, 295, &center);
    pros::delay(550);
    shoot(360);
    intake = 127;
    turn(-23, 23, 225, &center);
    move_straight(54.5, 64.0, &center, MOTOR_BRAKE_BRAKE);
    turn(23, -23, 354, &center);

    // go to mid line

    move_straight(-8.0, -58.0, &center, MOTOR_BRAKE_BRAKE);
    turn(23, -23, 40.5, &center);
    side_piston.set_value(1);
    pros::delay(20);
    side2_piston.set_value(1);
    pros::delay(20);
    side4_piston.set_value(1);
    pros::delay(20);
    side5_piston.set_value(1);
    pros::delay(20);
    side6_piston.set_value(1);
    pros::delay(1000);
    expander2_piston.set_value(1);
    pros::delay(20);
    side3_piston.set_value(1);
    pros::delay(20);




    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;
}