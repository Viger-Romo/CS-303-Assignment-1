#include "function.h"

int findArrayInt(int* array, int size, int value) { //Finds if the integer exists in the array and returns the index where that value is
    for (int i = 0; i < size; i++) {
        if (array[i] == value) { //checks if the current index has the value.
            return i; //Returns the index
        }
    }
    throw runtime_error("There is no value of that number at any index in the array."); //Throws error if the value is not in the array
}
pair<int, int> modifyArrayValue(int* array, int size, int index) { //Modifys a value of the array using an index chosen by the user and a new value by the user
    pair<int, int> values; //Will hold the old value and the new value
    
    string newValue;

    cin >> newValue; //Gets user input 
    if (isdigit(newValue[0])) { //Checks if the user input is a digit, if not will throw an error
        int curNewValue = stoi(newValue); //Converts user input to a integer
        
        for (int i = 0; i < size; i++) {
            if (i == index) {
                values.first = array[i]; //Gives the first value in pair as the old value
                array[i] = curNewValue; //Changes to new value
                values.second = array[i];//Gives the second value in  pair as the new value
                return values;//Returns the pair values
            }
        }
     }
     else {
        throw runtime_error("The user input of " + newValue + " is not a valid input."); //Throws an error is the user input for value is not a digit
     }
    throw runtime_error("There is no index of that number for this array.");//Throws an error is the index chosen exceeds the range of the array
}

void addArrayInteger(int*& array, int& size) { //Adds an integer to the end of the list.
    int* newArray = new int[size + 1]; //Creates new array with one size more

    cout << "\nPlease enter an integer to add to the end of the array: ";

    string element;
    cin >> element; //Get string user input
    if (isdigit(element[0])) { //Checks if user input is a integer, will through error is not.
        int curNewElement = stoi(element); //Convets user input into an integer to put into the array.
        
        for (int i = 0; i < size; i++) { //Adds all the values from the pervious array to the new array.
            newArray[i] = array[i];
        }
        newArray[size] = curNewElement;//Adds to the end of the list.
        delete[] array; //Delets the previous array.
        array = newArray;//Previous array now equals the new array
        size++;//Updates the size of the array
    }
    else {
        throw runtime_error("The user input of " + element + " is not a valid input.");//Throws error if the user input is not a digit
    }
}

int replaceArrayIndex(int* array, int index, int size) { //Function will replace the index element with a zero
    for (int i = 0; i < size; i++) {
        if (i == index) { //Checks if the index chosen is equal with the current array index
            array[i] = 0; //Changes to zero
            return 0; //Returns a 0 to avoid throwing a runtime error.
        }
    }
    throw runtime_error("There is no index of that number for this array."); //Throws a runtime error if the index exceeds the range of the array
}