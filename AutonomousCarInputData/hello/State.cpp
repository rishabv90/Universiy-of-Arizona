//
//  State.cpp
//  Project4
//
//  Created by Weixiang Deng on 10/26/18.
//  Copyright © 2018 1. All rights reserved.
//

#include "State.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
State::State(double x1, double x2, double x3, double x4, double timestamp){
    _xpos = x1;
    _ypos = x1;
    _tire_angle = x3;
    _heading = x4;
    _timestamp = timestamp;
}

State::State(){
    _xpos = 0.0;
    _ypos = 0.0;
    _tire_angle = 0.0;
    _heading = 0;
    _timestamp = 0.0;
}
