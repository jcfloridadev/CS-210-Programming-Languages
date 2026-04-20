/*
CS-210: Project 3 - Grocery Tracking Program
Developer: Justin Carlo Florida
Date: 04/17/2026
*/

#pragma once
#include <string>

// GroceryItem class
// Encapsulates grocery data (name and quantity)
// class only stores data and logic related to the item
// no cin or cout

class GroceryItem {
    //encapsulation: private members are hidden from outside the class
private: 
    std::string name; //name of the grocery item (used as key for the map)
    int quantity; //quantity for purchase frequency

public:
    // Constructor
	// initializes the name and quantity of the grocery item
	// quantity adds 1 when item is found in the input file

    GroceryItem(std::string name, int quantity);

    std::string GetName() const; //getter for item name
	int GetQuantity() const; //getter for how many times the item appears in the input file

    void AddItem();
};