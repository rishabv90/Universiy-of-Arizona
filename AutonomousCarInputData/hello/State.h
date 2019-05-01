#ifndef STATE_H
#define STATE_H
/*************/
/*
 * File: State.h
 * Author: Your Name
 * NetID: Your NetID
 * Date:
 *
 * Description: (enter your description of what this file does).
 */

// M_PI and other variables are defined in here
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>

// the MAX and MIN values for tire angle are used
// in the setTireAngle method
#define MAX_TIRE_ANGLE 0.5236
#define MIN_TIRE_ANGLE -0.5236
// 2PI is important for values of heading
#define M_TWO_TIMES_PI (2*M_PI)

/* Note: comments in this file thusfar are insufficient for
 a perfect grade in comments */

/* Class comment goes here */
class State{
private:
    double _xpos; // vehicle position, forward (x1)
    double _ypos; // vehicle position, left/right (x2)
    double _tire_angle; // tire angle (radians) (x3)
    double _heading; // heading (radians) (x4)
    double _timestamp; // time stamp at which this state is measured
    
public:
    // constructs a new State object with these initial values
    State(double x1, double x2, double x3, double x4, double timestamp);
    // constructs an empty State object
    State();
    
    double getXPos() const{return _xpos;}; // returns the _xpos
    void setXPos(double xpos){_xpos = xpos;}; // sets the _xpos
    double getYPos() const{return _ypos;}; // returns the _ypos
    void setYPos(double ypos){_ypos = ypos;}; // sets the _ypos
    double getTireAngle() const{return _tire_angle;}; // returns the _tire_angle
    void setTireAngle(double angle){_tire_angle = angle;}; // sets the _tire_angle
    double getHeading() const{return _heading;}; // gets the _heading
    void setHeading(double heading){_heading = heading;}; // sets the _heading
    double getTimeStamp() const{return _timestamp;}; // gets the _timestamp
    void setTimeStamp(double timestamp){_timestamp = timestamp;}; // sets the _timestamp
};

#endif // STATE_H
