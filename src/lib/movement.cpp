#include "../include/main.h"
#include "../globals/globals.hpp"
#include "helper_functions.hpp"
#include "movement.hpp"
#include "pros/motors.h"

#include <cmath>
#include <math.h>
#include <vector>

/** Moves the robot continuously based on voltage. A negative
 * value moves the robot backwards, while a positive
 * value moves the robot forwards.
 * 
 * @param leftVolt the voltage of the motors on the left side
 * of the drive train, from -127 to 127 volts
 * @param rightVolt the voltage of the motors on the right side
 * of the drive train, from -127 to 127 volts
 */
void move(const int leftVolt, const int rightVolt){
    leftFrontMotor = leftVolt; leftMidMotor = leftVolt; leftBackMotor = leftVolt;
    rightFrontMotor = rightVolt; rightMidMotor = rightVolt; rightBackMotor = rightVolt;
}

/** Turns the robot to an absolute angle
 * 
 * @param baseLeftVolt the base voltage for the left motors in volts, from -127 to 127
 * @param baseRightVolt the voltage for the right motors in volts, from -127 to 127
 * @param desiredAngle in degrees in the interval (0, 360]
 * @param pCenter the pointer to the vector data structure for the robot
 */
void turn(const int baseLeftVolt, const int baseRightVolt, double desiredAngle, vector *pCentre) {
    int prevErrorHeading = 0, integralHeading = 0;
    pCentre->desiredHeading = desiredAngle;
    double currAngle = imu_sensor.get_heading();
    
    if (baseLeftVolt > baseRightVolt) {
        if (currAngle < desiredAngle) {
            while (currAngle < desiredAngle) { 
                currAngle = imu_sensor.get_heading();         
                move(baseLeftVolt + PID(currAngle, desiredAngle, 0.3, 0, 0, prevErrorHeading, integralHeading), 
                        baseRightVolt - PID(currAngle, desiredAngle, 0.3, 0, 0, prevErrorHeading, integralHeading));
                
                pros::delay(8);
            }
        }
        else if (currAngle > desiredAngle) {
            desiredAngle = desiredAngle + (360 - currAngle);
            currAngle = 0; double prevAngle = imu_sensor.get_heading();
            
            while (currAngle + 2 < desiredAngle) {
                if (imu_sensor.get_heading() - prevAngle < -2) 
                    prevAngle = imu_sensor.get_heading();
                currAngle += imu_sensor.get_heading() - prevAngle;
                
                move(baseLeftVolt + PID(currAngle, desiredAngle, 0.3, 0, 0, prevErrorHeading, integralHeading), 
                        baseRightVolt - PID(currAngle, desiredAngle, 0.3, 0, 0, prevErrorHeading, integralHeading));
                
                prevAngle = imu_sensor.get_heading();  
                pros::delay(8);
            }
        }
    }
    else {
        if (0 <= currAngle && desiredAngle > currAngle) {
            desiredAngle = -(currAngle + (360 - desiredAngle));
            currAngle = 0; double prevAngle = imu_sensor.get_heading();
            
            while (currAngle - 2 > desiredAngle) {
                if (imu_sensor.get_heading() - prevAngle > 2) 
                    prevAngle = imu_sensor.get_heading();
                currAngle += imu_sensor.get_heading() - prevAngle;
                
                move(baseLeftVolt + PID(currAngle, desiredAngle, 0.2, 0, 0, prevErrorHeading, integralHeading), 
                        baseRightVolt - PID(currAngle, desiredAngle, 0.2, 0, 0, prevErrorHeading, integralHeading));
                
                prevAngle = imu_sensor.get_heading();
                pros::delay(8);
            }
        }
        else if (currAngle < 360 && currAngle > desiredAngle) {
            desiredAngle = desiredAngle - 360;
            currAngle -= 360;  
            
            while (currAngle > desiredAngle) {
                currAngle = imu_sensor.get_heading() - 360;
                move(baseLeftVolt + PID(currAngle, desiredAngle, 0.2, 0, 0, prevErrorHeading, integralHeading), 
                        baseRightVolt - PID(currAngle, desiredAngle, 0.2, 0, 0, prevErrorHeading, integralHeading));
                
                pros::delay(8);
            }
        }
    }
    move(MOTOR_BRAKE_BRAKE, MOTOR_BRAKE_BRAKE);
    pros::delay(100);
    pCentre->heading = imu_sensor.get_heading(); 
}

void turn2(const int baseLeftVolt, const int baseRightVolt, double desiredAngle, vector *pCentre) {
    int prevErrorHeading = 0, integralHeading = 0;
    pCentre->desiredHeading = desiredAngle;
    double currAngle = imu_sensor.get_heading();
    
    if (baseLeftVolt > baseRightVolt) {
        if (currAngle < desiredAngle) {
            while (currAngle < desiredAngle) { 
                currAngle = imu_sensor.get_heading();         
                move(baseLeftVolt + PID(currAngle, desiredAngle, 0.5, 0, 0, prevErrorHeading, integralHeading), 
                        baseRightVolt - PID(currAngle, desiredAngle, 0.5, 0, 0, prevErrorHeading, integralHeading));
                
                pros::delay(8);
            }
        }
        else if (currAngle > desiredAngle) {
            desiredAngle = desiredAngle + (360 - currAngle);
            currAngle = 0; double prevAngle = imu_sensor.get_heading();
            
            while (currAngle + 2 < desiredAngle) {
                if (imu_sensor.get_heading() - prevAngle < -2) 
                    prevAngle = imu_sensor.get_heading();
                currAngle += imu_sensor.get_heading() - prevAngle;
                
                move(baseLeftVolt + PID(currAngle, desiredAngle, 0.5, 0, 0, prevErrorHeading, integralHeading), 
                        baseRightVolt - PID(currAngle, desiredAngle, 0.5, 0, 0, prevErrorHeading, integralHeading));
                
                prevAngle = imu_sensor.get_heading();  
                pros::delay(8);
            }
        }
    }
    else {
        if (0 <= currAngle && desiredAngle > currAngle) {
            desiredAngle = -(currAngle + (360 - desiredAngle));
            currAngle = 0; double prevAngle = imu_sensor.get_heading();
            
            while (currAngle - 2 > desiredAngle) {
                if (imu_sensor.get_heading() - prevAngle > 2) 
                    prevAngle = imu_sensor.get_heading();
                currAngle += imu_sensor.get_heading() - prevAngle;
                
                move(baseLeftVolt + PID(currAngle, desiredAngle, 0.5, 0, 0, prevErrorHeading, integralHeading), 
                        baseRightVolt - PID(currAngle, desiredAngle, 0.5, 0, 0, prevErrorHeading, integralHeading));
                
                prevAngle = imu_sensor.get_heading();
                pros::delay(8);
            }
        }
        else if (currAngle < 360 && currAngle > desiredAngle) {
            desiredAngle = desiredAngle - 360;
            currAngle -= 360;  
            
            while (currAngle > desiredAngle) {
                currAngle = imu_sensor.get_heading() - 360;
                move(baseLeftVolt + PID(currAngle, desiredAngle, 0.5, 0, 0, prevErrorHeading, integralHeading), 
                        baseRightVolt - PID(currAngle, desiredAngle, 0.5, 0, 0, prevErrorHeading, integralHeading));
                
                pros::delay(8);
            }
        }
    }
    move(MOTOR_BRAKE_BRAKE, MOTOR_BRAKE_BRAKE);
    pros::delay(100);
    pCentre->heading = imu_sensor.get_heading(); 
}

void turn3(const int baseLeftVolt, const int baseRightVolt, double desiredAngle, vector *pCentre){
    double off_set = 180 - desiredAngle;
    pCentre->desiredHeading = desiredAngle;
    double current_angle = imu_sensor.get_heading();
    double previous_angle = imu_sensor.get_heading();
    while (abs(current_angle+off_set-180) > 1){
    if (abs(current_angle+off_set-180) > 1.1*abs(previous_angle+off_set-180))
    {
        break;
    }
        move(baseLeftVolt*(0.35+abs(current_angle+off_set-180)/250), baseRightVolt*(0.35+abs(current_angle+off_set-180)/250));
        previous_angle = current_angle;
        current_angle = imu_sensor.get_heading();
        pros::delay(14);
    };
    move(-baseLeftVolt/6, -baseRightVolt/6);
    pros::delay(90);
    move(MOTOR_BRAKE_HOLD, MOTOR_BRAKE_HOLD);
    pros::delay(190);
    current_angle = imu_sensor.get_heading();
    pros::delay(34);
    if (abs(current_angle+off_set-180) > 0.8)
    {
     move(-(baseLeftVolt/1.5+sgn(baseLeftVolt)*4), -(baseRightVolt/1.5+sgn(baseRightVolt)*4));
      while (abs(current_angle+off_set-180) > 0.6){
        current_angle = imu_sensor.get_heading();
        pros::delay(14);
    };   

    move(baseLeftVolt/6, baseRightVolt/6);
    pros::delay(90);
    move(MOTOR_BRAKE_HOLD, MOTOR_BRAKE_HOLD);
    }
    pros::delay(60);
    pCentre->heading = imu_sensor.get_heading(); 
    
    };

/** Moves the robot a given distance forwards or backwards
 * 
 * @param desiredDist the distance to travel, in inches
 * @param pCenter the pointer to the vector data structure for the robot
 * @param stopType the type of brake mechanism the robot uses
 */
void move_straight(const double desiredDist, vector *pCenter, decltype(MOTOR_BRAKE_BRAKE) stopType) {
    const unsigned baseVolt = 30;
    double prevLeftPos = leftMidMotor.get_position(), prevRightPos = rightMidMotor.get_position();   // the previous motor encoder value of each side of the drive train
    double currDist = 0;
    
    int prevErrorDist = 0, integralDist = 0;
    int prevErrorHeading = 0, integralHeading = 0;
    while (abs(currDist) < abs(desiredDist)) {
        const double volt = (desiredDist < 0) ? PID(currDist, desiredDist, 2, 0, -0.2, prevErrorDist, integralDist) - baseVolt
                                            : PID(currDist, desiredDist, 2, 0, -0.2, prevErrorDist, integralDist) + baseVolt;
        if (pCenter->desiredHeading > 180)
            move(volt + PID(get_heading(), pCenter->desiredHeading-360, 1.5, 0.01, 1, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading-360, 1.5, 0.01, 1, prevErrorHeading, integralHeading));
        else
            move(volt + PID(get_heading(), pCenter->desiredHeading, 1.5, 0.01, 1, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading, 1.5, 0.01, 1, prevErrorHeading, integralHeading));

        currDist += (leftMidMotor.get_position()-prevLeftPos + rightMidMotor.get_position()-prevRightPos)/2 
                    * motorToWheelRatio/360*(M_PI*wheelDiam);
        
        prevLeftPos = leftMidMotor.get_position(), prevRightPos = rightMidMotor.get_position();
        pros::delay(8);
    }
    if (stopType == MOTOR_BRAKE_BRAKE)
        move(stopType, stopType);
    pros::delay(200);
    pCenter->heading = imu_sensor.get_heading();
}

void move_straight(const double desiredDist, const int volt, vector *pCenter, decltype(MOTOR_BRAKE_BRAKE) stopType) {
    double prevLeftPos = leftMidMotor.get_position(), prevRightPos = rightMidMotor.get_position();   // the previous motor encoder value of each side of the drive train
    double currDist = 0;

    int prevErrorDist = 0, integralDist = 0;
    int prevErrorHeading = 0, integralHeading = 0;
    while (abs(currDist) < abs(desiredDist)) {
        if (pCenter->desiredHeading > 180)
            move(volt + PID(get_heading(), pCenter->desiredHeading-360, 1.0, 0.01, 1, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading-360, 1.0, 0.01, 1, prevErrorHeading, integralHeading));
        else
            move(volt + PID(get_heading(), pCenter->desiredHeading, 1.0, 0.01, 1, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading, 1.0, 0.01, 1, prevErrorHeading, integralHeading));
        
        currDist += (leftMidMotor.get_position()-prevLeftPos + rightMidMotor.get_position()-prevRightPos)/2 
                    * motorToWheelRatio/360*(M_PI*wheelDiam);
        
        prevLeftPos = leftMidMotor.get_position(), prevRightPos = rightMidMotor.get_position();
        pros::delay(8);
    }
    if (stopType == MOTOR_BRAKE_BRAKE)
        move(stopType, stopType);
    pros::delay(200);
    pCenter->heading = imu_sensor.get_heading();
}

/** Moves the robot a given amount of time forwards or backwards
 * 
 * @param time the time to travel for, in seconds
 * @param volt the voltage for the drive train motors
*/
void move_straight(const float time, const int volt) {
    static unsigned timeElapsed = 0;    // in milliseconds
    pros::Task track_time(stopwatch, &timeElapsed);
    while (timeElapsed < time * 1000) {
        move(volt, volt);
        pros::delay(1);
    }
    track_time.remove();
    move(MOTOR_BRAKE_HOLD, MOTOR_BRAKE_HOLD);
}

/** Moves the robot forwards until the light sensor
 * detects the roller.
 * 
 * @param volt the voltage for the motors, from -127 to 127
 */
void move_straight(const int volt, vector* pCenter) {
    int prevErrorHeading = 0, integralHeading = 0;
    while (optical_sensor.get_proximity() < 255) {
        if (pCenter->desiredHeading > 180)
            move(volt + PID(get_heading(), pCenter->desiredHeading-360, 0.6, 0.01, 1, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading-360, 0.6, 0.01, 1, prevErrorHeading, integralHeading));
        else
            move(volt + PID(get_heading(), pCenter->desiredHeading, 0.6, 0.01, 1, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading, 0.6, 0.01, 1, prevErrorHeading, integralHeading));
        pros::delay(8);
    }
    move(MOTOR_BRAKE_HOLD, MOTOR_BRAKE_HOLD);
    pros::delay(100);
    pCenter->heading = imu_sensor.get_heading();
}

void move_straight2(const double dist, const int baseVolt, const double accel, const double deccel, vector *pCenter) {
    double duck = 8.55;

    double prevLeftPos = leftMidMotor.get_position(), prevRightPos = rightMidMotor.get_position();   // the previous motor encoder value of each side of the drive train
    double currDist = 0;

    int prevErrorDist = 0, integralDist = 0;
    int prevErrorHeading = 0, integralHeading = 0;
    if (dist > 0)
    {
    while (currDist < dist/accel){
        double volt = baseVolt * (1 + currDist/2/dist/accel);
        if (pCenter->desiredHeading > 180){
            move(volt + PID(get_heading(), pCenter->desiredHeading-360, 0.95, 0.00, 0.4, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading-360, 0.95, 0.00, 0.4, prevErrorHeading, integralHeading));
        }
        else{
            move(volt + PID(get_heading(), pCenter->desiredHeading, 0.95, 0.00, 0.4, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading, 0.95, 0.00, 0.4, prevErrorHeading, integralHeading));
        }
        currDist = (leftMidMotor.get_position()-prevLeftPos + rightMidMotor.get_position()-prevRightPos)/720 *duck;
        pros::delay(8);
    }

    while (currDist < dist - dist/deccel){
        if (pCenter->desiredHeading > 180){
            move(baseVolt + PID(get_heading(), pCenter->desiredHeading-360, 0.95, 0.00, 0.4, prevErrorHeading, integralHeading), 
                baseVolt - PID(get_heading(), pCenter->desiredHeading-360, 0.95, 0.00, 0.4, prevErrorHeading, integralHeading));
        }
        else{
            move(baseVolt + PID(get_heading(), pCenter->desiredHeading, 0.95, 0.00, 0.4, prevErrorHeading, integralHeading), 
                baseVolt  - PID(get_heading(), pCenter->desiredHeading, 0.95, 0.00, 0.4, prevErrorHeading, integralHeading));
        }
        currDist = (leftMidMotor.get_position()-prevLeftPos + rightMidMotor.get_position()-prevRightPos)/720* duck;
        pros::delay(8);
    }
    
    while (currDist < dist){
        double volt = baseVolt * (0.55 - 2.6*(dist-currDist)/(dist/deccel));
        if (volt < baseVolt/2.0)
        {
        volt = baseVolt/2.0;
        }
        if (pCenter->desiredHeading > 180){
            move(volt + PID(get_heading(), pCenter->desiredHeading-360, 0.8, 0.00, 0.2, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading-360, 0.8, 0.00, 0.2, prevErrorHeading, integralHeading));
        }
        else{
            move(volt + PID(get_heading(), pCenter->desiredHeading, 0.8, 0.00, 0.0, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading, 0.8, 0.00, 0.0, prevErrorHeading, integralHeading));
        }        
        currDist = (leftMidMotor.get_position()-prevLeftPos + rightMidMotor.get_position()-prevRightPos)/720*duck;
        pros::delay(8);
    }
    }
    else{
        while (currDist > dist/accel){
        double volt = baseVolt * (1 + currDist/2/dist/accel);
        if (pCenter->desiredHeading > 180){
            move(volt + PID(get_heading(), pCenter->desiredHeading-360, 0.95, 0.00, 0.0, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading-360, 0.95, 0.00, 0.0, prevErrorHeading, integralHeading));
        }
        else{
            move(volt + PID(get_heading(), pCenter->desiredHeading, 0.95, 0.00, 0.0, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading, 0.95, 0.00, 0.0, prevErrorHeading, integralHeading));
        }
        currDist = (leftMidMotor.get_position()-prevLeftPos + rightMidMotor.get_position()-prevRightPos)/720 *duck;
        pros::delay(8);
    }

    while (currDist > dist - dist/deccel){
        if (pCenter->desiredHeading > 180){
            move(baseVolt + PID(get_heading(), pCenter->desiredHeading-360, 0.95, 0.00, 0.4, prevErrorHeading, integralHeading), 
                baseVolt - PID(get_heading(), pCenter->desiredHeading-360, 0.95, 0.00, 0.4, prevErrorHeading, integralHeading));
        }
        else{
            move(baseVolt + PID(get_heading(), pCenter->desiredHeading, 0.95, 0.00, 0.4, prevErrorHeading, integralHeading), 
                baseVolt  - PID(get_heading(), pCenter->desiredHeading, 0.95, 0.00, 0.4, prevErrorHeading, integralHeading));
        }
        currDist = (leftMidMotor.get_position()-prevLeftPos + rightMidMotor.get_position()-prevRightPos)/720* duck;
        pros::delay(8);
    }
    
    while (currDist > dist){
        double volt = baseVolt * (0.55 - 2.6*(dist-currDist)/(dist/deccel));
        if (volt > baseVolt/2.0)
        {
        volt = baseVolt/2.0;
        }
        if (pCenter->desiredHeading > 180){
            move(volt + PID(get_heading(), pCenter->desiredHeading-360, 0.8, 0.00, 0.0, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading-360, 0.8, 0.00, 0.0, prevErrorHeading, integralHeading));
        }
        else{
            move(volt + PID(get_heading(), pCenter->desiredHeading, 0.8, 0.00, 0.0, prevErrorHeading, integralHeading), 
                volt - PID(get_heading(), pCenter->desiredHeading, 0.8, 0.00, 0.0, prevErrorHeading, integralHeading));
        }        
        currDist = (leftMidMotor.get_position()-prevLeftPos + rightMidMotor.get_position()-prevRightPos)/720*duck;
        pros::delay(8);
    }
    }
    move(-baseVolt/6, -baseVolt/6);
    pros::delay(60);
    move(MOTOR_BRAKE_BRAKE, MOTOR_BRAKE_BRAKE);
}

//20.4862499 rotation * inches/de