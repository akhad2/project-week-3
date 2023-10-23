#pragma once
// ItemCounter.h
#ifndef ITEMCOUNTER_H
#define ITEMCOUNTER_H

#include <map>
#include <string>
#include <iostream>
using namespace std;

class ItemCounter {
public:
    ItemCounter();
    void readFromFile(const string& filename); //this function will read given text file and add it to the map
    void writeToFile(const string& filename); // writes output to the .dat file
    int getCount(const string& item);  //accesses map to get count of specific item
    void printAll();                   // will print all items with an item count number
    void printHistogram();             // will print all items with an item count  displayed as * instead of number
private:
    map<string, int> item_counts;  //map that will be modified using the functions above in public
};

#endif
 
