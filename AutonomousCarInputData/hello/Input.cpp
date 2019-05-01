//
//  Input.cpp
//  Project4
//
//  Created by Weixiang Deng on 10/26/18.
//  Copyright © 2018 1. All rights reserved.
//

#include "Input.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

Input::Input(double vel, double tireAngleRate, double timestamp){
    _velocity = vel;
    _tire_angle_rate = tireAngleRate;
    _timestamp = timestamp;
}

Input::Input(){
    _velocity = 0.0;
    _tire_angle_rate = 0.0;
    _timestamp = 0.0;
}

