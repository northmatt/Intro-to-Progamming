#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;
using std::to_string;

class LargeINT {
public:
	LargeINT(vector<int> vec);

	LargeINT Add(LargeINT num2);
	LargeINT Subract(LargeINT num2);
	vector<int> GetNum();
	string GetNumString();
private:
	vector<int> num;
};