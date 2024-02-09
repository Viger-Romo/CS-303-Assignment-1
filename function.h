#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <utility>
using namespace std;

//Functions to be used

int findArrayInt(int* array, int size, int value);

pair<int, int> modifyArrayValue(int* array, int size, int index);

void addArrayInteger(int*& array, int& size);

int replaceArrayIndex(int* array, int index, int size);