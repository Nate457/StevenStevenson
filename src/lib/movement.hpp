#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../include/main.h"
#include "pros/motors.h"

struct vector {
    double x = 0, y = 0;
    double dist = 0, heading = 0, desiredHeading = 0;
};

extern void move(const int leftVolt, const int rightVolt);
extern void move_straight(const double desiredDist, vector *pCenter, decltype(MOTOR_BRAKE_BRAKE) stopType = MOTOR_BRAKE_BRAKE);
extern void move_straight(const double desiredDist, const int volt, vector *pCenter, decltype(MOTOR_BRAKE_BRAKE) stopType = MOTOR_BRAKE_BRAKE);
extern void move_straight(const float time, const int volt);
extern void move_straight(const int volt, vector *pCenter);

extern void turn(const int baseLeftVolt, const int baseRightVolt, double desiredAngle, vector *pCentre);
extern void turn2(const int baseLeftVolt, const int baseRightVolt, double desiredAngle, vector *pCentre);
extern void turn3(const int baseLeftVolt, const int baseRightVolt, double desiredAngle, vector *pCentre);
extern void turn4(const int baseLeftVolt, const int baseRightVolt, double desiredAngle, vector *pCentre);
extern void move_straight2(const double dist, const int baseVolt, const double accel, const double deccel, vector *pCenter);
extern void ms2(const double dist, const int baseVolt, const double accel, const double deccel, vector *pCenter);

#endif