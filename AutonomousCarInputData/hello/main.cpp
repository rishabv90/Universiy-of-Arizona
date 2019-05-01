//
//  main.cpp
//  Project4
//
//  Created by Weixiang Deng on 10/26/18.
//  Copyright © 2018 1. All rights reserved.
//

#include <iostream>
#include "vehicleSimulator.h"
#include <fstream>
int main(int argc, const char * argv[]) {
    // insert code here...
	
	
	vehicleSimulator s;
	if( argc != 3 ) {
        printf("Usage: Here\n\n");
        return EXIT_FAILURE;
    }

	
    ifstream inp;
    inp.open(argv[1]);
    if (!inp.is_open()){
        cout << "Could not open file myfile.txt." << endl;
        return 1;
    }	
    s.read(inp);
    
    ofstream outFS;
    outFS.open(argv[2]);
    if (!outFS.is_open()) {
        cout << "Could not open file myoutfile.txt." << endl;
        return 1;
    }

	s.sort();
	s.output(outFS);

    return 0;
}
