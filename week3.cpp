//Akhad Alimov

#include <iostream>
#include <unordered_map>
#include "ItemCounter.h"
using namespace std;
void print_menu() {
    //menu that will be printed whenever print_menu() is called
    cout << "type the number only.\n";
    cout << "1 - Enter an item that you are looking for: \n";
    cout << "2 - This will print all of the item(s) with the corresponding quantity: \n";
    cout << "3 - This will print all of the item(s) in a text histogram format: \n";
    cout << "4 - exit\n";
    }

int main() {
    ItemCounter counter; //header class, variable counter created
    counter.readFromFile("items.txt"); //both calls function defined in ItemCounter.cpp
    counter.writeToFile("frequency.dat");

    int choice;
    while (true) {
        print_menu(); //this will always print after cases below complete. only stops after case 4
        cin >> choice;

        switch (choice) { 
        case 1: {              // went for case as it is simpler to read and understand
            string item;  //will be used to search this string in the items.txt file
            cout << "Enter the item to search for: ";
            cin >> item;
            int count = counter.getCount(item); // function from itemcounter will assign it to count
            if (count > 0)
                cout << item << " appears " << count << " times." << std::endl;
            else                                      // if else for user experience to let them know that item is
                cout << "Item not found." << std::endl; // not there instead of showing 0
                
            break; // returns to menu
        }
        case 2:
            counter.printAll(); // function from itemcounter.cpp
            break;
        case 3:
            counter.printHistogram(); //function from itemcounter.cpp
            break;
        case 4:
            return 0; // instead of break like above, this line will exit the while loop
        default:
            cout << "Invalid choice. Please try again." << endl;  // if user enters number besides 1,2,3,4
        }

        // Update data in file after each operation
        counter.writeToFile("frequency.dat"); // updating to dat file with counter
    }

    return 0;
}


