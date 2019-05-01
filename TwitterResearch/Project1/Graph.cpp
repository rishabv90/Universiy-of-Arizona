
#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <functional>
using namespace std;
int Graph::readfile(ifstream &inp){
    string name1;
    string name2;
    string str;
    int i, index1 = 0, index2 = 0;
    //    inp.open(filename);
    while (getline(inp,str)){
        bool appear1 = false;
        bool appear2 = false;
        istringstream al(str);
        al>>name1;
        al>>name2;
        for (i = 0; i < name1.length(); i++){
            if ( !isalnum(name1[i]) && name1[i] != '_'){
                return 0;
            }
        }
        for (i = 0; i < name2.length(); i++){
            if ( !isalnum(name2[i]) && name2[i] != '_'){
                return 0;
            }
        }
        User* new1 = new User;
        User* new2 = new User;
        for(i = 0; i < all.size(); i ++){
            if (all.at(i)->getname() == name1){
                appear1 = true;
                index1 = i;
                break;
            }
        }
        for(i = 0; i < all.size(); i ++){
            if(all.at(i)->getname() == name2){
                appear2 = true;
                index2 = i;
                break;
            }
        }
        
        if (appear1 == false){
            new1->setname(name1);
            all.push_back(new1);
            index1 = int(all.size())-1;
        }
        if (appear2 == false){
            new2->setname(name2);
            all.push_back(new2);
            index2 = int(all.size())-1;
        }
        all.at(index1)->addfollower(all.at(index2));
        all.at(index2)->addfollowing(all.at(index1));
    }
    return 1;
}

bool infunc (string name, vector<User*> a, string self){
    bool s = false;
    for (int i = 0; i < a.size();i++){
        if (a.at(i)->getname() == name){
            s = true;
        }
    }
    if (name == self){
        s = true;
    }
    return s;
}

bool compare (string a, string b){
    bool s = true;
    for (int i = 0 ; i < a.length(); i++){
        if (a[i] > b[i]){
            s  = true;
            break;
        }
        if (a [i] < b[i]){
            s = false;
            break;
        }
    }
    return s;
}

int Partition(vector<User*>& numbers, int i, int k) {
    int l = 0;
    int h = 0;
    int midpoint = 0;
    double pivot = 0;
    User temp;
    bool done = false;
    
    // Pick middle element as pivot
    midpoint = i + (k - i) / 2;
    pivot = numbers.at(midpoint)->getfollowersize();
    
    l = i;
    h = k;
    
    while (!done) {
        
        // Increment l while numbers[l] < pivot
        while (numbers.at(l)->getfollowersize()< pivot ) {
            ++l;
        }
//        while (numbers.at(l)->getfollowersize()< pivot || (numbers.at(l)->getname()[0] > numbers.at(midpoint)->getname()[0] && numbers.at(l)->getfollowersize() ==  pivot)) {
//            ++l;
//        }

        
        // Decrement h while pivot < numbers[h]
        while (pivot < numbers.at(h)->getfollowersize()) {
            --h;
        }
//        while (pivot < numbers.at(h)->getfollowersize() || (numbers.at(h)->getname()[0] < numbers.at(midpoint)->getname()[0] && numbers.at(l)->getfollowersize() ==  pivot)) {
//            --h;
//        }

        
        // If there are zero or one elements remaining,
        // all numbers are partitioned. Return h
        if (l >= h) {
            done = true;
        }
        else {
            // Swap numbers[l] and numbers[h],
            // update l and h
            swap(numbers.at(l),numbers.at(h));
            
            ++l;
            --h;
        }
    }
    
    return h;
}
void Quicksort(vector<User*>& numbers, int i, int k) {
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

using namespace std;

struct PlayerComparator
{
	// Compare 2 Player objects using name
	bool operator ()(const noed& player1, const node& player2)
	{
		if (player1.name == player2.name)
			return player1 < player2;
		return player1.name < player2.name;
	}
};


void Graph::output(ofstream & out, string name){
    int size1 = 0;
    bool appear = false;
    bool valid = true;
    vector<User*> everyone;
    string name1, name2, name3;
    int i;
    for (i = 0; i < all.size(); i ++){
        if( all.at(i)->getname() == name){
            size1 = all.at(i)->getfollowersize();
            appear = true;
            break;
        }
    }
    
    if (appear == true && valid == true){
        out<<"Looking for new accounts for "<<name<<" ("<<size1<<") to follow"<<endl;
        name1 = all.at(i)->getname();
        for (int j = 0; j < all.at(i)->getfollowingsize(); j++){

            if (infunc(all.at(i)->getfollowing().at(j)->getname(), all.at(i)->getfollowing(), name1) == false){
                everyone.push_back(all.at(i)->getfollowing().at(j));
            }
            for (int k = 0; k < all.at(i)->getfollowing().at(j)->getfollowingsize(); k++ ){
                name2 = all.at(i)->getfollowing().at(j)->getfollowing().at(k)->getname();
                if (infunc(all.at(i)->getfollowing().at(j)->getfollowing().at(k)->getname(), all.at(i)->getfollowing(),name1) == false){
                    everyone.push_back(all.at(i)->getfollowing().at(j)->getfollowing().at(k));
                }
                for (int s = 0; s < all.at(i)->getfollowing().at(j)->getfollowing().at(k)->getfollowingsize();s++){
                    name3 =all.at(i)->getfollowing().at(j)->getfollowing().at(k)->getfollowing().at(s)->getname();
                    if (infunc(all.at(i)->getfollowing().at(j)->getfollowing().at(k)->getfollowing().at(s)->getname(), all.at(i)->getfollowing(),name1) == false){
                        everyone.push_back(all.at(i)->getfollowing().at(j)->getfollowing().at(k)->getfollowing().at(s));
                    }
                }
            }
        }
        
        Quicksort(everyone, 0, int(everyone.size())-1);
        reverse(everyone.begin(), everyone.end());
        Quicksort(everyone, 0, int(everyone.size())-1);
        reverse(everyone.begin(), everyone.end());
        
        vector<User*> a1 = everyone;

        sort(a1.begin(),a1.end(),greater<User*>());
		
		//sort(a1->getfollowersize().begin(), a1->getfollowersize());
		
		a1.sort(PlayerComparator());

		//vector<char> items = { 'a','b','c' };
		


        for (int j =0; j < a1.size(); j ++){
			
			//printf("NUMBER 1\n");
			cout << a1.at(j)->getname() << " (" << a1.at(j)->getfollowersize() << ")" << endl;
			

			
        }
    }
}

