/*
CS-210: Project 3 - Grocery Tracking Program
Developer: Justin Carlo Florida
Date: 04/17/2026
*/

#include <iostream>
#include <fstream>
#include <map>
#include "GroceryItem.h"
using namespace std;

// loading data from input file into map
map<string, GroceryItem*> LoadData() {
    map<string, GroceryItem*> items; // map to store item name and GroceryItem pointer
    ifstream file("CS210_Project_Three_Input_File.txt"); // opening input file

    // checking if file opened correctly
    if (!file.is_open()) {
        cout << "Error opening input file.\n";
        return items; // returning empty map if file fails
    }

    string name; // stores one item name at a time

    // reading each item from file
    while (file >> name) { // reading input safely / avoiding eof() issues and stops when read fails
        // checking if item already exists in map
        if (items.count(name) > 0) {
            items.at(name)->AddItem(); // increasing quantity if item exists
        }
        else {
            GroceryItem* newItem = new GroceryItem(name, 1); // creating new item with quantity 1
            items.emplace(name, newItem); // adding new item to map
        }
    }

    file.close(); // manually close file before returning

    return items; //done executing, returning map
}

// constructor definition from GroceryItem.h
GroceryItem::GroceryItem(string n, int q) {
    name = n;  // assigning item name
    quantity = q; // assigning starting quantity
}

// returning item name
string GroceryItem::GetName() const {
    return name;
}

// returning item quantity
int GroceryItem::GetQuantity() const {
    return quantity;
}

// increasing quantity by one
void GroceryItem::AddItem() {
    quantity++;
}

// displaying menu options
void DisplayMenu() {
    cout << "1. Search Item\n";
    cout << "2. Print All Frequencies\n";
    cout << "3. Print Histogram\n";
    cout << "4. Exit\n\n";
	cout << "Please select an option: ";
}

// option 1, searching for a specific item
void SearchItem(map<string, GroceryItem*>& items) { 
    string name;
    cout << "\nEnter item (case-sensitive, e.g., Garlic): ";
    cin >> name;
	cout << endl;

    //checking if item exists in map
    if (items.count(name) > 0) {
        cout << name << " appears " << items.at(name)->GetQuantity() << " times\n";
		cout << "____________________________________________________________\n\n";
    }
    else {
        cout << "\nItem not found\n";
		cout << "____________________________________________________________\n\n";
    }
    // option 1 done executing, going back to main()
}

// option 2, printing all item frequencies
void PrintAll(map<string, GroceryItem*>& items) { 
    cout << "\nGrocery Purchase Frequency Report:\n\n";

    // looping through map and printing item with quantity
    for (auto it = items.begin(); it != items.end(); ++it) {
        cout << it->second->GetName() << " " << it->second->GetQuantity() << endl;
    }
	cout << "____________________________________________________________\n\n";
    // option 2 done executing, going back to main()
}

// option 3, printing histogram
void PrintHistogram(map<string, GroceryItem*>& items) { 
    cout << "\nGrocery Item Frequency Histogram:\n\n";

    // looping through map and printing histogram
    for (auto it = items.begin(); it != items.end(); ++it) { 
        cout << it->second->GetName() << " ";

        int qty = it->second->GetQuantity(); // storing quantity for star count

        for (int i = 0; i < qty; i++) { // printing one star per quantity
            cout << "*";
        }

        cout << endl;
    }
    cout << "____________________________________________________________\n\n";
    // option 3 done executing, going back to main()
}

// option 4, exiting program + farewell
void ExitProgram() {
    cout << "_____________________________________________________________\n";
    cout << "\nExiting program...\n\nThank you for using the Corner Grocer Item Tracking System.\n\nDeveloper: Justin Carlo Florida\n\n";
	//option 4 done executing, program will end in main()
}

// displaying invalid input message
void InvalidInput() {
    cout << "\nInvalid choice.. Please select 1, 2, 3, or 4.\n";
    cout << "____________________________________________________________\n\n";
    // InvalidInput() done executing, going back to main()
}

// creating backup file for accumulated data
void CreateBackup(map<string, GroceryItem*>& items) {
    ofstream outFile("frequency.dat"); // opening output file

    // checking if output file opened correctly
    if (!outFile.is_open()) {
        cout << "Error creating backup file.\n";
        return; // stopping function if file fails
    }

    // looping through map and writing item data to file
    for (auto it = items.begin(); it != items.end(); ++it) {
        outFile << it->second->GetName() << " "
            << it->second->GetQuantity() << endl;
    }

    outFile.close(); // closing output file
    // done creating backup file
}

// clearing dynamically allocated memory
void ClearData(map<string, GroceryItem*>& items) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        delete it->second;
    }
    items.clear(); // clearing map after deleting pointers
    // done clearing data
}

void StartUp() {
	cout << "Loading Corner Grocer purchase data...\n"; // simulating loading process for user experience
	cout << "Data loaded successfully.\n\n"; // simulating successful load message for user experience
	// done executing, only once on startup before the menu loop, going back to main()
}

int main() { 
    int choice = 0; //starting choice 0

	StartUp(); // declaring StartUp() function to execute before menu loop

	// repeating menu until user selects option 4 to exit
    while (choice != 4) {
        map<string, GroceryItem*> items = LoadData(); // reloading file data each loop, getting items

        CreateBackup(items); // creating backup file after loading data

		DisplayMenu(); // calling DisplayMenu() to show options
		cin >> choice; // getting user choice

        // checking for invalid non-numeric input
        if (cin.fail()) {
            cin.clear(); // clearing fail state
            cin.ignore(1000, '\n'); // ignoring bad input
            InvalidInput(); // calling InvalidInput() to execute
            ClearData(items); // clearing allocated memory
            continue; // restarting loop
        }

        // processing menu choice
        switch (choice) {
        case 1:
			SearchItem(items); // calling SearchItem() to execute for option 1
            break;
        case 2:
            PrintAll(items); // calling PrintAll() to execute for option 2
            break;
        case 3:
			PrintHistogram(items); // calling PrintHistogram() to execute for option 3
            break;
        case 4:
			ExitProgram(); // calling ExitProgram() to execute option 4, will end program in main()
            break;
        default:
			InvalidInput(); // calling InvalidInput() to execute
            break;
        }

        ClearData(items); // clearing memory before next loop
    }
    

    return 0;
}