/*
    22 What is an iterator?
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set> 

using namespace std;

int main() {

    vector<int> a = {1,2,3};

    //Iterator for vector
    for(auto it = a.begin();it != a.end();it++) {
        cout<<*it<<endl;
    }

    unordered_map<int,int> hashMap;

    hashMap[1] = 3;
    hashMap[5] = 23;
    hashMap[7] = 77;
    hashMap[2] = 12;

    //This has been integrated in c++ 17 and wasn't there before.
    for(auto [key, value]:hashMap) {
        cout<<"Key = "<<key<<", value = "<<value<<endl;
    }

    cout<<"*************Before C++ 17**************"<<endl;

    //Here is the older way
    for(auto it = hashMap.begin();it != hashMap.end(); it++) {
        cout<<"Key = "<<it->first<<", Value = "<<it->second<<endl;
    }
    

    set<int> randomSet;
    randomSet.insert(12);
    randomSet.insert(1);
    randomSet.insert(6);
    randomSet.insert(3);

    cout<<"********************Iterator for set.********************\n";
    for(auto it = randomSet.begin(); it != randomSet.end();it++) {
        cout<<*it<<endl;
    }


    map<int, string> orderedMap;
    orderedMap[3] = "three";
    orderedMap[1] = "one";
    orderedMap[2] = "two";

    cout << "********************Iterator for map (sorted by key)********************\n";
    for (auto it = orderedMap.begin(); it != orderedMap.end(); ++it) {
        cout << "Key = " << it->first << ", Value = " << it->second << endl;
    }

    cout<<"********************Using Key and value****************\n";
    for(auto [key, value] : orderedMap) {
        cout<<"Key = "<<key<<", value = "<<value<<endl;
    }

    return 0;
}