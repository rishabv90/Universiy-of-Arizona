#ifndef vehicleSimulator_h
#define vehicleSimulator_h


#include <stdio.h>
#include <vector>
#include <fstream>
#include "Vehicle.h"


using namespace std;
class vehicleSimulator{
private:

	double x1=0;
	double x2=0;
	double x3=0;
	double x4=0;
	double x1Time=0;
	double x2Time=0;
	double x3Time=0;
	double x4Time=0;
    vector<Input> readData;//data read will be stored in this vector form after reading
	vector<Input> outData; //after writing

public:
	void readFile(ifstream&);
	bool testAnswer1() const { return 1; };
	bool testAnswer2() const { return 0; };
    void sort(); //quicksort here as per the question
    bool vaildate(); //making sure the data we read is correct as per the question
    void writeFile(ofstream&);//writing in the outputfile as a csv
};

#endif

