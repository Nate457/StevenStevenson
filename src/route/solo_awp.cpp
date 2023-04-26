#include "../include/main.h"
#include "../globals/globals.hpp"
#include "../lib/movement.hpp"
#include "../lib/helper_functions.hpp"
#include "../lib/scoring.hpp"
#include "pros/vision.h"

using namespace pros;

void solo_awp() {
      // initial setup
    vector center = {};
    leveler.set_value(1);
    unsigned timeElapsed = 0;
    unsigned desiredSpeed = 2620;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // shoot preloads and turn roller
    move_straight(-0.5, &center); delay(30); turn_rollerN(false); delay(30);
    pros::delay(25);
    move_straight2(3.1,80, 3,2, &center);


    //pick up next 3 discs and shoot them
    turn3(48, -48, 44.5, &center);
    intake=127;
    pros::delay(15);
    move_straight2(42.0,53, 3,2, &center);
    pros::delay(15);
    turn2(-34,34, 16.5, &center);
    pros::delay(15);
    turn3(-44,44, 322.2, &center);
    pros::delay(15);
    move_straight2(1.5,53, 3,2, &center);
    while (desiredSpeed != INT16_MAX) {
    delay(15);
    }
    desiredSpeed = 2620;
    pros::delay(205);
    shoot(460);
    desiredSpeed = 2980;
    intake = 127;
    turn3(45, -45, 44.0, &center);
    pros::delay(15);
    move_straight2(82.9,86,3,2.4, &center);
    pros::delay(15);
    turn2(-35,35, 340.0, &center);
    pros::delay(15);
    turn3(-45,45, 281.0, &center);
    shoot(550);
    pros::delay(15);
    move_straight2(-4.1,-64,3,2, &center);
    pros::delay(15);
    turn_rollerN(false); pros::delay(50);


    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;

}