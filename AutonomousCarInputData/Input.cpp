#include <stdio.h>
#include <iostream>
#include "Input.h"

using namespace std;

//initialization exactly as the input.h file
//This will be read after we readData from the input stream.
Input::Input(double vel, double tireAngleRate, double timestamp){
    _velocity = vel;
    _tire_angle_rate = tireAngleRate;
    _timestamp = timestamp;
}

//Initial state = 0
//mentioned in the document
Input::Input(){
    _velocity = 0;
    _tire_angle_rate = 0;
    _timestamp = 0;
}

double Input::getVelocity() const {
    return _velocity;
}//gives back velocity

double Input::getTireAngleRate() const {
    return _tire_angle_rate;
}//gives back tire angle rate

double Input::getTimeStamp() const {
    return _timestamp;
}//we get timestamp

void Input::setVelocity(double vel) {
    _velocity = vel;
}//setting function

void Input::setTireAngleRate(double angle) {
    _tire_angle_rate = angle;
}//setting function

void Input::setTimeStamp(double timestamp) {
    _timestamp = timestamp;
}//setting function
