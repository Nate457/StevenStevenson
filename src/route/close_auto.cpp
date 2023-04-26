#include "../include/main.h"
#include "../globals/globals.hpp"
#include "../lib/movement.hpp"
#include "../lib/helper_functions.hpp"
#include "../lib/scoring.hpp"
#include "pros/vision.h"

using namespace pros;

void close_a() {
      // initial setup
    vector center = {};
    leveler.set_value(1);
    unsigned timeElapsed = 0;
    unsigned desiredSpeed = 2660;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // shoot preloads and turn roller
    move_straight(-0.5, &center); delay(50); turn_rollerN(false); delay(50);
    move_straight2(5.0, 60.0,3,2, &center);
    intake=127;
    delay(20);
    turn3(-40, 40, 350.2, &center);
    move_straight2(4.6,  50.0,3,2, &center);
    
    pros::delay(50);


     while (desiredSpeed != INT16_MAX) {
        delay(15);
    }
    desiredSpeed = 2660;
    pros::delay(550);
    shoot(650);
    

    intake = 127;
    pros::delay(30);
    move_straight2(-7.4,-50.0,3,2, &center);


    //pick up next 3 discs and shoot them
    desiredSpeed = 2585;
    pros::delay(20);
    turn3(40, -40, 41.8, &center);
    pros::delay(20);
    move_straight2(38.5,72,3,2, &center);
    pros::delay(20);
    turn3(-38,38, 327.1, &center);
    pros::delay(20);
    shoot(620);
    center.heading = 329.1; 
    desiredSpeed = 2465; 
    intake = 127;
    pros::delay(20);
    move_straight2(3.5, 58.0,3,2, &center);
    pros::delay(1240);
    shoot(490);



    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;

}