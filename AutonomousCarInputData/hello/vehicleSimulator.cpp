//
//  vehicleSimulator.cpp
//  Project4
//
//  Created by Weixiang Deng on 10/26/18.
//  Copyright © 2018 1. All rights reserved.
//

#include "vehicleSimulator.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
void vehicleSimulator::read(ifstream& inp){

	//printf("HERE In READ FUNCTION\n\n");

//    ifstream inp;
    double vel;
    double time;
    double anglerate;
    string str;
//    inp.open(filename);
    while (getline(inp,str)){
        istringstream all(str);
        all>>time;
        all>>vel;
        all>>anglerate;
		//printf("%lf, %lf, %lf",time, vel, anglerate);
        Input a(vel,anglerate,time);
        data.push_back(a);
    }


}

int Partition(vector<Input>& numbers, int i, int k) {
    int l = 0;
    int h = 0;
    int midpoint = 0;
    double pivot = 0;
    Input temp;
    bool done = false;
    
    // Pick middle element as pivot
    midpoint = i + (k - i) / 2;
    pivot = numbers.at(midpoint).getTimeStamp();
    
    l = i;
    h = k;
    
    while (!done) {
        
        // Increment l while numbers[l] < pivot
        while (numbers.at(l).getTimeStamp() < pivot) {
            ++l;
        }
        
        // Decrement h while pivot < numbers[h]
        while (pivot < numbers.at(h).getTimeStamp()) {
            --h;
        }
        
        // If there are zero or one elements remaining,
        // all numbers are partitioned. Return h
        if (l >= h) {
            done = true;
        }
        else {
            // Swap numbers[l] and numbers[h],
            // update l and h
            temp = numbers.at(l);
            numbers.at(l) = numbers.at(h);
            numbers.at(h) = temp;
            
            ++l;
            --h;
        }
    }
    
    return h;
}
void Quicksort(vector<Input>& numbers, int i, int k) {
    int j = 0;
    
    // Base case: If there are 1 or zero elements to sort,
    // partition is already sorted
    if (i >= k) {
        return;
    }
    // Partition the data within the array. Value j returned
    // from partitioning is location of last element in low partition.
    j = Partition(numbers, i, k);
    
    // Recursively sort low partition (i to j) and
    // high partition (j + 1 to k)
    Quicksort(numbers, i, j);
    Quicksort(numbers, j + 1, k);
}

void vehicleSimulator::sort(){
    Quicksort(data,0,int(data.size())-1);
}

bool vehicleSimulator::vaildate(){
	

    bool status = true;
    int i;
    double duration;

	

    if (data.at(0).getTimeStamp() != 0.0){
        status = false;
    }
    
    for (i = 0; i< data.size();i++){
		//printf("%lf,%lf,%lf,%lf\n\n", data.at(i).getVelocity(), data.at(i).getTireAngleRate(), data.at(i).getTimeStamp(), data.at(i + 1).getTimeStamp() - data.at(i).getTimeStamp());

        if (data.at(i).getVelocity() < 0 || data.at(i).getVelocity() > 30){
            status = false;
			printf("getvelocity < or > than 0 or 30 !!!!!!!!! \n");
        }
		else { printf("getvelocity is good \n"); }

		if (data.at(i).getTimeStamp() < 0){
            status = false;
			printf("Time stamp < or > than 0 or 30!!!!!!!/n");
        }
		else { printf("TimeStamp is good \n"); }


        if (data.at(i).getTireAngleRate() > MAX_TIRE_ANGLE || data.at(i).getTireAngleRate() < MIN_TIRE_ANGLE){
            status = false;
			printf("Angle rate up or below!!!!!\n");
        }
		else { printf("Angle rate is good\n"); }

        if (i+1<data.size()){
            duration = data.at(i+1).getTimeStamp() - data.at(i).getTimeStamp();
            if (duration < 0.005 || duration > 0.201){
                status = false;
				printf("%lf,   Duration BAD!!!! \n", duration);
            }
			else { printf("duration is good\n"); }
        }
		
    }
    return status;
}

void vehicleSimulator::output(ofstream& outFS){
	printf("In OUTPUT function\n\n");

    if (vaildate() == false){
		printf("VALIDATE == FALSE\n\n");
        return;
    }
//        ofstream outFS;
        Vehicle A;
//        outFS.open(filename);
        int i;
        double duration;

		printf("Before forloop\n");

        for (i = 0; i< data.size();i++){
			printf("%d\n\n", i);

            if (i == data.size()-1){
                duration =0.200;
            }
            else{
                duration = data.at(i+1).getTimeStamp()-data.at(i).getTimeStamp();
            }
            A.stateUpdate(data.at(i), duration);
            outFS<<A.getState().getTimeStamp()<<","<<A.getState().getXPos()<<","<<A.getState().getYPos()<<","<<A.getState().getTireAngle()<<","<<A.getState().getHeading()<<endl;
			//printf("\n%lf, %lf,%lf,%lf,%lf\n", A.getState().getTimeStamp(), A.getState().getXPos(), A.getState().getYPos(), A.getState().getTireAngle(), A.getState().getHeading());
		}
	
        outFS.close();
}
