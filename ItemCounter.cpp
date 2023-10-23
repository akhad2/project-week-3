// ItemCounter.cpp
//Akhad Alimov

#include "ItemCounter.h"
#include <fstream>
#include <iostream>
using namespace std;
ItemCounter::ItemCounter() {}

void ItemCounter::readFromFile(const string& filename) { //const used here and below since we are not modifying text 
    ifstream file(filename);  //opens the file for reading,  used filename for modularity purposes
    string item;
    while (file >> item)    // if the read text matches then it will increment the count
        ++item_counts[item];
}

void ItemCounter::writeToFile(const string& filename) { 
    ofstream file(filename); //ofstream used since this function will be writing
    for (const auto& pair : item_counts) // auto used for pair since it is not clear what the limit is for count
        file << pair.first << ": " << pair.second << endl; // ,.first prints item name, .second prints count
}

int ItemCounter::getCount(const string& item) {
    return item_counts[item]; //definition for the header class. uses item_counts from above
}

void ItemCounter::printAll() {
    for (const auto& pair : item_counts) // definition for header class and for loop to print all with quantity
        cout << pair.first << ": " << pair.second << endl; 
}

void ItemCounter::printHistogram() {
    for (const auto& pair : item_counts) //same as above but instead of number it uses *
        cout << pair.first << ": " << string(pair.second, '*') << endl;
}

