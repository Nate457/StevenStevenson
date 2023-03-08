#include "../include/main.h"
#include "../globals/globals.hpp"
#include "../lib/movement.hpp"
#include "../lib/helper_functions.hpp"
#include "../lib/scoring.hpp"
#include "pros/vision.h"

using namespace pros;

void test() {
    // initial setup
       vector center = {};
    leveler.set_value(1);
    unsigned timeElapsed = 0;
    unsigned desiredSpeed = 2720;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // shoot preloads and turn roller
    move_straight(50, 80, &center);
    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;

}