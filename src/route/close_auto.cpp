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
    unsigned desiredSpeed = 2655;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // shoot preloads and turn roller
    move_straight(-0.5, &center); delay(50); turn_rollerN(false); delay(50);
    move_straight2(6.6, 60.0,3,2, &center);
    intake=127;
    turn3(-43, 43, 348.0, &center);
    move_straight2(5.2,  69.0,3,2, &center);
    
    pros::delay(50);


     while (desiredSpeed != INT16_MAX) {
        delay(15);
    }
    desiredSpeed = 2655;
    pros::delay(350);
    shoot(750);
    

    intake = 127;
    pros::delay(30);
    move_straight2(-10.8,-89,3,2, &center);


    //pick up next 3 discs and shoot them
    desiredSpeed = 2589;
    pros::delay(20);
    turn3(48, -48, 44, &center);
    pros::delay(20);
    move_straight2(43.0,76,3,2, &center);
    pros::delay(20);
    turn3(-44,44, 323.4, &center);
    pros::delay(20);
    shoot(520);
    center.heading = imu_sensor.get_heading(); 
    desiredSpeed = 2306; 
    intake = 127;
    pros::delay(20);
    move_straight2(7.6,  68.0,3,2, &center);
    pros::delay(1240);
    shoot(490);



    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;

}