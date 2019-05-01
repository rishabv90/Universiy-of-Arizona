#ifndef VEHICLE_H
#define VEHICLE_H
/*************/
/*
 * File: Vehicle.h
 * Author: Your Name
 * NetID: Your NetID
 * Date:
 *
 * Description: (enter your description of what this file does).
 */

/* Note: comments in this file thusfar are insufficient for
 a perfect grade in comments */
#include "State.h"
#include "Input.h"

// wheelbase length in meters
#define L 2.6187

/* Class comment goes here */
class Vehicle {
private:
    State _state; // the current state of the vehicle
    void setState( State x ); // sets the value for _state
    
public:
    // constructs a new Vehicle object with the default State value
    Vehicle( );
    // executes the Vehicle for the duration specified
    // this method does not do any correctness checking on values in u
    /*  x_pos = x_prev + duration * velocity*cos(tire_angle)*cos(heading)
     y_pos = y_prev + duration * velocity*cos(tire_angle)*sin(heading)
     tire_angle = tire_angle_prev + duration * tire_angle_rate
     heading = heading_prev + duration * velocity*(1.0 / L)*sin(tire_angle)
     time_stamp = time_stamp_prev + duration*/
    
    void stateUpdate( Input u, double duration );
    
    State getState( ) const; // gets the value for _state
};

#endif // VEHICLE_H
