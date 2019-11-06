// LargeINT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "LargeINT.h"

LargeINT::LargeINT(vector<int> vec) {
	num = vec;
}

LargeINT LargeINT::Add(LargeINT large2) {
	vector<int> outNum;
	vector<int> num2;

	num2 = large2.GetNum();
	
	//simply add all digits together from both vectors
	if (num.size() < num2.size()) {
		outNum = num2;

		for (unsigned int i = 0; i < num2.size(); i++) {
			if (i >= num2.size() - num.size())
				outNum[i] = num[i - (num2.size() - num.size())] + num2[i];
			else
				outNum[i] = num2[i];
		}
	} else {
		outNum = num;

		for (unsigned int i = 0; i < num.size(); i++) {
			if (i >= num.size() - num2.size())
				outNum[i] = num[i] + num2[i - (num.size() - num2.size())];
			else
				outNum[i] = num[i];
		}
	}
	
	//deal with carrying for all ints but largest decimal place
	int carryIn{ 0 };
	for (unsigned int i = outNum.size(); i > 0; i--) {
		unsigned int pos{ 0 };
		pos = i - 1;

		outNum[pos] += carryIn;

		carryIn = outNum[pos] / 10;
		outNum[pos] -= carryIn * 10;
	}

	if (carryIn > 0)
		outNum.insert(outNum.begin(), carryIn);

	return outNum;
}

LargeINT LargeINT::Subract(LargeINT num2) {
	return LargeINT({0});
}

vector<int> LargeINT::GetNum() {
	return num;
}

string LargeINT::GetNumString() {
	string outNum = "";
	
	for (int currentNum : num) {
		outNum += to_string(currentNum) + " ";
	}

	return outNum;
}
