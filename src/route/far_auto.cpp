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
    unsigned timeElapsed = 0;
    unsigned desiredSpeed = 3354;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // turn roller
    move_straight(15.9, &center);
    turn(35, 0, 89, &center);
    move_straight(53, &center); delay(400); turn_roller(90); delay(400);
    
    // shoot preloads
    move_straight(-3.0, &center);
    turn(29, -29, 93, &center);
    while (desiredSpeed != INT16_MAX) {
        delay(15);
    }
    desiredSpeed = 3420;
    shoot(1300);
    move_straight(1.5, 40.0,&center);
    desiredSpeed = 3105;

    // pick up row of 3 discs

    turn(29,-29,219,&center);
    intake = 127;
    move_straight(67.3, 51.0, &center);
    turn(-29,29,140.5,&center);
    move_straight(1.5, 50.0,&center);
    shoot(1800);
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

    master.print(0, 0, "%d", timeElapsed);
 }