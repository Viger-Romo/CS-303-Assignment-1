/*Viger Romo   CS-303 Assignment 1     2/8/2024*/
#include "function.h"


int main() {

    //Exception handing
    try {

        //Opens the data file and checks if it opens
        ifstream inputFile("A1Input.txt");
        if (!inputFile.is_open()) {
            throw runtime_error("Could not open file");
        }

        int count = 0; //Counts the size
        int temp; //Hold the current value from the data file

        while (inputFile >> temp) { //Goes through whole data file
            count++;
        }
        int* arr = new int[count]; //Creates an arr to hold the data from the data with.

        inputFile.close();

        //Does the same thing as before but this time add the data values to the array.
        ifstream inputFile2("A1Input.txt");
        if (!inputFile2.is_open()) {
            throw runtime_error("Could not open file");
        }
        for (int i = 0; i < count; i++) {
            inputFile2 >> arr[i];
        }

        inputFile2.close();

        //Menu to choose which function to pick
        cout << "Please choose a function to use." << endl;
        cout << "(1) Check if integer exits in array" << endl;
        cout << "(2) Modify array value" << endl;
        cout << "(3) Add integer to end of array" << endl;
        cout << "(4) Replace array index value with 0" << endl;

        cout << "\nPlease choose a number: ";
        int choice;
        cin >> choice; //Gets user input
        
        int temp2; //Will be used to get more user input

        if (choice == 1) {
            cout << "\nPlease enter an integer to search for: ";
            cin >> temp2;
            cout << "The index of the integer is: " << findArrayInt(arr, count, temp2) << endl; //Function checks if the integer is in the array.
        }
        else if (choice == 2) {
            pair<int, int> values; //pair is used to hold two values, the old value and the new value when the function returns them
            cout << "\nPlease enter an index to modify: ";
            cin >> temp2;

            cout << "Please enter a new value: ";
            values = modifyArrayValue(arr, count, temp2); //Function changes a value of the array by using an index and a new value from the user
            cout << "\nThe old value of " << values.first << " was replaced by " << values.second << endl; 
        }
        else if (choice == 3) {
            addArrayInteger(arr, count); //Adds an integer to the end of the array.
            cout << "\n" << arr[count-1] << " was added to the end of the list." << endl; 
        }
        else if (choice == 4) {
            cout << "\nPlease enter an index to replace with 0: ";
            cin >> temp2;
            replaceArrayIndex(arr, temp2, count); //Replaces the index element with zero
            cout << "\n Element at index: " << temp2 << " was replaced with a zero." << endl;
        }
    }

    catch (runtime_error& e) { //Catches errros thrown from the fuctions.
        cout << e.what() << endl;
    }
}