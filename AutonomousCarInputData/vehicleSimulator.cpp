#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "vehicleSimulator.h"
#include <string>

using namespace std;

/*
The value for x3 (tire angle) must always be between [􀀀-0.5236, 0.5236] radians/sec (i.e., ±π/ 6 radians/sec).
If a value is commanded outside this range, then x3 should saturate using the above range.
Ex: If the tire angle rate is commanded to be the value 0.7156, the tire angle rate should equal the maximum value of 0.5236.

The heading should always be between [0, 2).
If the heading is a negative value, the heading should be converted into the range [0, 2) by repeatedly adding 2 .
Ex: If the heading is -.5, the heading can be converted to -0.5+2 = 1.5.
*/

bool vehicleSimulator::vaildate() {
	double deltaT;
	bool flag = true; //flag if true that means readData is valid, else not.
	int i, j, k, l, lineCount;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	lineCount = 0;

	if (readData.at(0).getTimeStamp() == 1009) {
		printf("error in data reaching Validate");
		flag = false;
	}
	if (readData.at(0).getTimeStamp() != 0.0) {
		flag = false;
	}

	for (i = 0; i < readData.size(); i++) {
		lineCount += 1;

		if (i + 1 < readData.size()) {
			deltaT = readData.at(i + 1).getTimeStamp() - readData.at(i).getTimeStamp();
			if (deltaT < 0.005 || deltaT > 0.201) {
				flag = false;
			}
		}
		if (readData.at(i).getTireAngleRate() > MAX_TIRE_ANGLE) {
			flag = false;
			printf("tireAngle range is greater than max tire angle as per question \n\n");
		}
		if (readData.at(i).getTireAngleRate() < MIN_TIRE_ANGLE) {
			flag = false;
			printf("tireAngle range is less than min tire angle as per question \n\n");
		}
		if (readData.at(i).getVelocity() < 0 || readData.at(i).getVelocity() > 30) {
			flag = false;
			printf("OUT OF BOUNDS for velocity !!\n");
		}
		if (readData.at(i).getTimeStamp() < 0) {
			flag = false;
			printf("Invalid Time\n");
		}
	}
	return flag;
}

void vehicleSimulator::readFile(ifstream& inputFile){

	int lineCount = 0;
	string fileLine;
    double velocity;
    double tireAngle;
	double timeTaken;
    

    while (getline(inputFile,fileLine)){
        istringstream all(fileLine);
        
		all>>timeTaken;
        all>>velocity;
        all>>tireAngle;
		lineCount += 1;

        Input readValue(velocity,tireAngle,timeTaken);
        readData.push_back(readValue);
    }
	if (lineCount < 0)
	{
		printf("\n\nSome Error in Reading file\\n\n\n\n");
	}
}




void vehicleSimulator::writeFile(ofstream& outputFile){
	if (vaildate() != false) {
		int i = 0;
		double deltaT;
		Vehicle mercedes; // object used to write
		Vehicle porche; //test variable

		for (i = 0; i < readData.size(); i++) {
			if (i != readData.size() - 1) {
				deltaT = readData.at(i + 1).getTimeStamp() - readData.at(i).getTimeStamp();
				}
			if (i == readData.size() - 1) {
				deltaT = 0.200;
			}
			//store in Vehicle object
			mercedes.stateUpdate(readData.at(i), deltaT);
			//csv format for t,x1,x2,x3,x4\n
			outputFile << mercedes.getState().getTimeStamp() << "," << mercedes.getState().getXPos() << "," << mercedes.getState().getYPos() << "," << mercedes.getState().getTireAngle() << "," << mercedes.getState().getHeading() << endl;
		}
	}
	else {
		printf("NOT valid");
		//return 0;
	}

}

int Partition(vector<Input>& numbers, int i, int k) {
	bool complete = false;
	Input initial;
	int midpoint = 0;
	double pivot = 0;
	int l = 0;
	int h = 0;

	midpoint = i + (k - i) / 2;
	pivot = numbers.at(midpoint).getTimeStamp();

	l = i;
	h = k;

	while (!complete) {
		while (numbers.at(l).getTimeStamp() < pivot) {
			++l;
		}
		while (pivot < numbers.at(h).getTimeStamp()) {
			--h;
		}
		if (l >= h) {
			done = true;
		}
		else {
			initial = numbers.at(l);
			numbers.at(l) = numbers.at(h);
			numbers.at(h) = initial;

			++l;
			--h;
		}
	}

	return h;
}

void Quicksort(vector<Input>& numbers, int i, int k) {
	int j = 0;

	if (i >= k) {
		return;
	}

	j = Partition(numbers, i, k);

	Quicksort(numbers, i, j);
	Quicksort(numbers, j + 1, k);
}

void vehicleSimulator::sort() {
	Quicksort(readData, 0, int(readData.size()) - 1);
}