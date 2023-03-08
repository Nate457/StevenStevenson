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
    unsigned desiredSpeed = 1961;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // shoot preloads and turn roller
     while (desiredSpeed != INT16_MAX) {
        delay(12);
    }
    desiredSpeed = 1961;
    intake = 0;
    indexer.move_relative(-120, -580);
	pros::delay(510);
    indexer.move_relative(-120, -580);
    pros::delay(450);
    desiredSpeed = 2090;
    intake = 127;

    move_straight(-28.6, -65.0, &center, MOTOR_BRAKE_BRAKE);
    turn2(0, -36, 90, &center);
    intake = 0;
    move_straight(0.33, -60.0); delay(50); turn_rollerN(true); delay(50);
    intake = 127;
    
    //pick up first stack turn second roller 
    move_straight(24.06, 38.0, &center, MOTOR_BRAKE_BRAKE);
    turn2(-33, 0, 6, &center);
    intake = 0;
    move_straight(1.31, -53.0); delay(50); turn_rollerN(true); delay(50);


    //shoot
    move_straight(2.4, 58.0, &center);
    intake = 127;
    turn2(23, -23, 85.5, &center);
    move_straight(21.0, 74.0, &center, MOTOR_BRAKE_BRAKE);
    pros::delay(450);
    shoot(320);

    desiredSpeed = 2195;
    // go back
    turn2(20, -28, 90, &center);
    intake = 127;
    move_straight(-27.3, -54.0, &center, MOTOR_BRAKE_BRAKE);
    turn2(-23, 23, 45, &center);

    // pick up and shoot x 2
    move_straight(28.5, 55.0, &center, MOTOR_BRAKE_BRAKE);
    turn2(24, -24, 109.85, &center);
    pros::delay(450);
    shoot(320);
    desiredSpeed = 2060;
    turn2(-24, 24, 48, &center);
    intake = 127;
    move_straight(47.0, 55.0, &center, MOTOR_BRAKE_BRAKE);
    turn2(22, -22, 141, &center);
    pros::delay(200);
    turn2(20, -20, 173.15, &center);
    move_straight(14.0, 54.0, &center, MOTOR_BRAKE_BRAKE);
    shoot(320);
    intake = 127;
    turn2(22, -22, 181.5, &center);

    // third roller
    move_straight(-27.8, -56.0, &center, MOTOR_BRAKE_BRAKE);
    turn2(0, -30, 272, &center);
    intake = 0;
    move_straight(1.53, -60.0); delay(50); turn_rollerN(true); delay(50);

    //pick up stack turn fourth roller 
    intake = 127;
    move_straight(21.4, 36.0, &center, MOTOR_BRAKE_BRAKE);
    turn2(-30, 0, 184, &center);
    intake = 0;
    move_straight(2.25, -60.0); delay(50); turn_rollerN(true); delay(50);

    
    //shoot
    move_straight(2.9, 50.0, &center);
    desiredSpeed = 2110;
    intake = 127;
    turn2(26, 0, 221, &center);
    pros::delay(100);
    turn2(26, 0, 267.9, &center);
    move_straight(15.5, 60.0, &center, MOTOR_BRAKE_BRAKE);
    shoot(320);
    intake = 127;

    // go back
    desiredSpeed = 2250;
    move_straight(-26.3, -55.0, &center, MOTOR_BRAKE_BRAKE);
    turn2(-23, 23, 224, &center);

    // pick up and shoot x 2
    move_straight(28.6, 54.0, &center, MOTOR_BRAKE_BRAKE);
    turn2(24, -24, 292.8, &center);
    pros::delay(450);
    shoot(320);
    intake = 127;
    desiredSpeed = 2600;
    pros::delay(200);
    turn2(-25, 25, 225, &center);
    move_straight(55.5, 65.0, &center, MOTOR_BRAKE_BRAKE);
    turn2(25, -25, 339.4, &center);
    shoot(320);


    // go to mid line
    intake = 127;
    desiredSpeed = 2605;
    move_straight(-10.1, -65.0, &center, MOTOR_BRAKE_BRAKE);
    turn2(24, -24, 32.6, &center);
    // move_straight(69.5, 65.0, &center, MOTOR_BRAKE_BRAKE);
    // turn2(24, -24, 128.2, &center);
    // pros::delay(150);
    // shoot(450);

    // intake = 127;
    // turn2(-27, 27, 42.5, &center);
    // move_straight(27.5, 69.0, &center, MOTOR_BRAKE_BRAKE);

    // pros::delay(250);
    // turn2(30, -30, 140.5, &center);
    // pros::delay(70);

    // turn2(27, -27, 209.5, &center);


    side_piston.set_value(1);
    pros::delay(21);
    side2_piston.set_value(1);
    pros::delay(21);
    side4_piston.set_value(1);
    pros::delay(21);
    side5_piston.set_value(1);
    pros::delay(21);
    side6_piston.set_value(1);
    pros::delay(21);
    expander2_piston.set_value(1);
    pros::delay(21);
    side3_piston.set_value(1);
    pros::delay(21);
    pros::delay(550);
    move_straight(-5.1, -30.0, &center, MOTOR_BRAKE_BRAKE);
    move_straight(1.1, 30.0, &center, MOTOR_BRAKE_BRAKE);



    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;
}