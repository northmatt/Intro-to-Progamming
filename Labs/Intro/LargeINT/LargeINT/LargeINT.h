#pragma once

#include <vector>
#include <string>
#include <math.h>

#include <iostream>

using std::vector;
using std::string;
using std::to_string;

class LargeINT {
public:
	LargeINT(vector<int> vec);
	LargeINT(int num);

	LargeINT Add(LargeINT num2);
	LargeINT Subract(LargeINT num2);
	vector<int> Cleanup(vector<int> vec);

	vector<int> GetNum();
	string GetNumString();
private:
	vector<int> num;
};