#include "../include/main.h"
#include "../globals/globals.hpp"
#include "../lib/movement.hpp"
#include "../lib/helper_functions.hpp"
#include "../lib/scoring.hpp"
#include "pros/vision.h"

using namespace pros;

void far_auto() {
    // initial setup
    vector center = {};
    leveler.set_value(1);
    unsigned timeElapsed = 0;
    unsigned desiredSpeed = 2700;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // turn roller
    intake = 0;
    move_straight(-8.7, -48, &center);
    turn(10, -35, 98.5, &center);
    move_straight(0.3, -49); delay(100); turn_rollerN(false); delay(100);
    intake = 127;
    // shoot preloads
    move_straight(9.81, &center);
    while (desiredSpeed != INT16_MAX) {
        delay(10);
    }
    desiredSpeed = 2595;
    pros::delay(1090);
    shoot(550);
    move_straight(-3.55,-37, &center);
    desiredSpeed = 2545;

    // pick up row of 3 discs
    intake = 127;
    turn(-31,31,42.6,&center);
    move_straight(31.5, 45.0, &center);
    turn(26,-26, 120.6,&center);
    shoot(540);
    desiredSpeed = 2465;
    intake = 127;
    move_straight(1.1, 50.0,&center);
    pros::delay(950);
    shoot(500);
    // desiredSpeed = 2720;
    // move_straight(1, 61.0, &center);
    // turn(-29,29,90,&center);
    // //pickup discs next to the goal
    // intake=127;
    // move_straight(43.0, 80.0, &center);
    // move_straight(-40.0,-61.0,&center);
    // turn(29,-29,135.0,&center);
    // move_straight(-5.0,-61.0,&center);
    // shoot(800);

    // cleanup program

    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;
 }