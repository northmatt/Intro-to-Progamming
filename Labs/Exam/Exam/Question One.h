#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::ifstream;
using std::string;
using std::getline;
using std::tolower;

void StartQ1();
void SetupArray(string inpWord, int inpArray[]);
bool TestArray(int mainArray[], int tempArray[]);