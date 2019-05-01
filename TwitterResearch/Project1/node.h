

#ifndef node_h
#define node_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class User{
private:
    string name;
    vector<User*> followers;
    vector<User*> following;
public:
    int size = followers.size();
    void addfollower(User* name){followers.push_back(name);};
    void addfollowing(User* name){following.push_back(name);};
    string getname(){return name;};
    void setname (string name1){name = name1;};
    int getfollowersize(){return int(followers.size());};
    int getfollowingsize(){return int(following.size());};
    vector<User*> getfollower(){return followers;};
    vector<User*> getfollowing(){return following;};
    bool operator > (const User & rhs) const { return size > rhs.size; };
    
};
#endif /* node_hpp */
