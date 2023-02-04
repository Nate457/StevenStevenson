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
    unsigned desiredSpeed = 2910;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // turn roller
    intake = 127;
    move_straight(-7.0, -48, &center);
    turn(0, -34, 99, &center);
    move_straight(-1.0, &center); delay(200); turn_rollerN(false); delay(200);
    intake = 127;
    // shoot preloads
    move_straight(5.6, &center);
    while (desiredSpeed != INT16_MAX) {
        delay(10);
    }
    desiredSpeed = 2900;
    turn(-27, 27, 96, &center);
    shoot(530);
    move_straight(-2.8,-41, &center);
    desiredSpeed = 2845;

    // pick up row of 3 discs
    intake = 127;
    turn(-29,29,45,&center);
    move_straight(45.3, 55.0, &center);
    turn(23,-23, 116.4,&center);
    move_straight(1.5, 50.0,&center);
    pros::delay(550);
    shoot(830);
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