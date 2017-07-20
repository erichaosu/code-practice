//============================================================================
// Name        : praactice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <list>
#include "../include/practice.h"

using namespace std;

vector<int> solution::twoSum(vector<int>& nums, int target) {
    int i;
    vector<int> v(2);
    std::unordered_map<int,int> *lookupMap = new std::unordered_map<int,int>();
    for (i =0; i< nums.size(); i++){    
        int compliment = target - nums[i];
        auto it = lookupMap->find(compliment);
        if (compliment > 0 && it != lookupMap->end() ){
            v = {nums[i], compliment};
            return v;
        }else {
            lookupMap->insert({nums[i],i});
        }
    }
    v = {0,0}; 
    return  v;      
}

int main() {
    // twosum one-pass hash lkup solution
    vector<int> vec;
    vector<int> testVector;
    solution sol;
    testVector ={8,7,6,5,4,3,2,1};
    vec = sol.twoSum(testVector, 9);
    cout<<"sum of {" <<vec[0]<<","<<vec[1]<<"}"<<endl;
    cout << "hello Bryan!!"<<endl;
     
}
