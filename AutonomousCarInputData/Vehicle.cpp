#include <stdio.h>
#include <iostream>
#include "Vehicle.h"
//#include "State.h"
using namespace std;

//Private members
//making private variable "_state" of Vehicle a STATE object from state.h

Vehicle::Vehicle() {
    _state = State();
}
//setting the value for state
void Vehicle::setState(State x) {
    _state = x;
}

//public members
//get state function

State Vehicle::getState() const {
	
	return _state;
}

void Vehicle::stateUpdate(Input u, double duration) {
	State initial; //using a state variale for initial state
	
	//euqation of motion declaration from state.cpp file
	double x1; 
	x1 = _state.getXPos(); //x1 is translational forward motion (position x),

	double x2;
	x2 = _state.getYPos(); // x2 is translational left/right motion (position y)

	double x3; 
	x3 = _state.getTireAngle();// x3 is the tire angle

	double x4; 
	x4 = _state.getHeading();//x4 is the heading of the vehicle

	double x1Time;
	x1Time = x1 + (duration * u.getVelocity() * cos(x3) * cos(x4)); //x1(t+∆t)  = x1(t) + ∆t u1(t) cos(x3(t)) cos(x4(t))

	double x2Time;
	x2Time = x2 + (duration * u.getVelocity() * cos(x3) * cos(x4));//x2(t + ∆t) = x2(t) + ∆t u1(t) cos(x3(t)) sin(x4(t))

	double x3Time; 
	x3Time = x3 * (duration * u.getTireAngleRate());//x3 (t+∆t) = x3 (t) +  ∆t u2(t)					 
	/*The value for x3 (tire angle) must always be between [􀀀-0.5236, 0.5236] radians/sec (i.e., ±π/ 6 radians/sec). 
	If a value is commanded outside this range, then x3 should saturate using the above range.
	Ex: If the tire angle rate is commanded to be the value 0.7156, the tire angle rate should equal the maximum value of 0.5236. */
	if (x3Time < MIN_TIRE_ANGLE) {
		x3Time = MIN_TIRE_ANGLE;
	}else if (x3Time > MAX_TIRE_ANGLE ){
		x3Time = MAX_TIRE_ANGLE;
	}

	double x4Time;
	x4Time = x4 + ((duration*u.getVelocity()*sin(x3) / L));//x4(t + ∆t) = x4(t) + ∆t u1(t) (1 / L) sin(x3(t))
	/*
	The heading should always be between [0, 2). 
	If the heading is a negative value, the heading should be converted into the range [0, 2) by repeatedly adding 2 .
	Ex: If the heading is -.5, the heading can be converted to -0.5+2 = 1.5.
	*/
	while (x4Time < 0) {
		x4Time = x4Time + M_TWO_TIMES_PI;
	}
	while (x4Time > M_TWO_TIMES_PI) {
		x4Time = x4Time - M_TWO_TIMES_PI;
	}

	double newTimeStamp;
	newTimeStamp = u.getTimeStamp() + duration;

	//Now we set the newly found inputs to INITIAL STATE
	initial.setTimeStamp(newTimeStamp);
	initial.setXPos(x1Time);
	initial.setYPos(x2Time);
	initial.setTireAngle(x3Time);
	initial.setHeading(x4Time);
	setState(initial); //update state finally
}









