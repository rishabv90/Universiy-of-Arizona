

#ifndef Graph_h
#define Graph_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "node.h"
#include <fstream>
#include <sstream>
using namespace std;
class Graph{
private:
    vector<User*> all;
public:
    int readfile(ifstream& inp);
    void output(ofstream&,string name);
	bool comparator(const User& lhs, const User& rhs);
};


#endif /* Graph_hpp */
