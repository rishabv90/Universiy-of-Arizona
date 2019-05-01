

#include <iostream>
#include <fstream>
#include "Graph.h"
int main(int argc, const char * argv[]) {
    int vaild;
    Graph a;
    if( argc != 4 ) {
        printf("Usage: sna inputFile userName outputFile\n");
        return EXIT_FAILURE;
    }
    ifstream inp;
    inp.open(argv[1]);
    //inp.open("input2.txt");
    if (!inp.is_open()){
        cout << "Could not open file myfile.txt." << endl;
        return 1;
    }
    vaild = a.readfile(inp);
    
    ofstream outFS;
    
    outFS.open(argv[3]);
    //outFS.open("output.txt");
    if (!outFS.is_open()) {
        cout << "Could not open file myoutfile.txt." << endl;
        return 1;
    }
    if (vaild == 1){
        a.output(outFS, argv[2]);
    }
    return 0;
}

