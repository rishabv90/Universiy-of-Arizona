//
//  vehicleSimulator.hpp
//  Project4
//
//  Created by Weixiang Deng on 10/26/18.
//  Copyright © 2018 1. All rights reserved.
//

#ifndef vehicleSimulator_h
#define vehicleSimulator_h
#include "Input.h"
#include "Vehicle.h"
#include "State.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class vehicleSimulator{
private:
    vector<Input> data;
public:
    void sort();
    bool vaildate();
    void read(ifstream&);
    void output(ofstream&);
};
#endif /* vehicleSimulator_h */
