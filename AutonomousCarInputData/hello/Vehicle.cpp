//
//  Vehicle.cpp
//  Project4
//
//  Created by Weixiang Deng on 10/26/18.
//  Copyright © 2018 1. All rights reserved.
//

#include "Vehicle.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

Vehicle::Vehicle(){
    _state = State();
}

void Vehicle::setState(State x){
    _state = x;
}
void Vehicle::stateUpdate(Input u, double duration){
    double x1,x2,x3,x4,xt1,xt2,xt3,xt4;
//    x3 = u.getTireAngleRate();
//    x4 = u.getVelocity()/L*sin(x3);
//    x2 = u.getVelocity()*cos(x3)*sin(x4);
//    x1 = u.getVelocity()*cos(x3)*cos(x4);
    State temp;
    x3 = _state.getTireAngle();
    x4 = _state.getHeading();
    x1 = _state.getXPos();
    x2 = _state.getYPos();
    
    xt3 = x3 + duration*u.getTireAngleRate();
    if (xt3 > MAX_TIRE_ANGLE){
        xt3 = MAX_TIRE_ANGLE;
    }
    else if (xt3< MIN_TIRE_ANGLE){
        xt3 = MIN_TIRE_ANGLE;
    }
    xt4 = x4 + duration*u.getVelocity()/L*sin(x3);
    while (xt4 > M_TWO_TIMES_PI){
        xt4 -= M_TWO_TIMES_PI;
    }
    while (xt4 < 0){
        xt4 += M_TWO_TIMES_PI;
    }
    xt2 = x2 + duration*u.getVelocity()*cos(x3)*sin(x4);
    xt1 = x1 + duration*u.getVelocity()*cos(x3)*cos(x4);
    
    //State x = State(xt1,xt2,xt3,xt4,u.getTimeStamp());
    temp.setXPos(xt1);
    temp.setYPos(xt2);
    temp.setTireAngle(xt3);
    temp.setHeading(xt4);
    temp.setTimeStamp(u.getTimeStamp()+duration);
    setState(temp);
}

State Vehicle::getState( ) const{
    return _state;
}
