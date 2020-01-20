// LargeINT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "LargeINT.h"

LargeINT::LargeINT(vector<int> vec) {
	vec = Cleanup(vec);
	num = vec;
}

LargeINT::LargeINT(int inNum) {
	unsigned int numSize{ 0 };
	int currentNum{ 0 };
	bool isNegative{ false };

	if (inNum < 0) {
		inNum *= -1;
		isNegative = true;
	}

	numSize = 1 + log10(inNum);
		
	for (size_t i = 0; i < numSize; i++) {
		int powNum = static_cast<int>(pow(10, numSize - i));

		currentNum = inNum;
		currentNum -= (inNum / powNum) * powNum;
		currentNum /= pow(10, numSize - i - 1);

		num.push_back(currentNum);
	}

	if (isNegative)
		num[0] *= -1;
}

LargeINT LargeINT::Add(LargeINT large2) {
	vector<int> outNum;
	vector<int> num2;
	bool isNegative{ false };

	num2 = large2.GetNum();

	if (num[0] >= 0 && num2[0] < 0) {
		num2[0] *= -1;
		return Subract(num2);
	}

	if (num[0] < 0 && num2[0] >= 0) {
		outNum = num;
		num = num2;
		num2 = outNum;
		num2[0] *= -1;

		return Subract(num2);
	}

	if (num[0] < 0 && num2[0]) {
		num[0] *= -1;
		num2[0] *= -1;
		isNegative = true;
	}

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

		if (-9 <= outNum[pos] && outNum[pos] <= -1)
			carryIn -= 1;

		outNum[pos] -= carryIn * 10;
	}

	if (carryIn != 0)
		outNum.insert(outNum.begin(), carryIn);

	outNum = Cleanup(outNum);

	if (isNegative)
		outNum[0] *= -1;

	return outNum;
}

LargeINT LargeINT::Subract(LargeINT large2) {
	vector<int> outNum;
	vector<int> num2;
	bool isNegative{ false };

	num2 = large2.GetNum();

	if (num2[0] < 0) {
		num2[0] *= -1;
		return Add(num2);
	}

	if (num[0] < 0) {
		num[0] *= -1;
		outNum = Add(num2).GetNum();
		outNum[0] *= -1;
		return outNum;
	}

	if (num2.size() == num.size())
		for (unsigned int i = 0; i < num.size(); i++) {
			if (num2[i] > num[i]) {
				isNegative = true;
				break;
			} else if (num2[i] < num[i])
				break;
		}

	if (num2.size() > num.size() && num2[0] > 0 || isNegative) {
		outNum = num;
		
		num = num2;
		num2 = outNum;

		isNegative = true;
	}

	int negNum = num[0] / abs(num[0]);
	//simply add all digits together from both vectors
	if (num.size() < num2.size()) {
		outNum = num2;

		for (unsigned int i = 0; i < num2.size(); i++) {
			if (i >= num2.size() - num.size())
				outNum[i] = num[i - (num2.size() - num.size())] - num2[i];
			else
				outNum[i] = num2[i];
		}
	} else {
		outNum = num;

		for (unsigned int i = 0; i < num.size(); i++) {
			if (i >= num.size() - num2.size())
				outNum[i] = num[i] - num2[i - (num.size() - num2.size())];
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

		if (-9 <= outNum[pos] && outNum[pos] <= -1)
			carryIn -= 1;

		outNum[pos] -= carryIn * 10;
	}

	if (carryIn != 0)
		outNum.insert(outNum.begin(), carryIn);

	outNum = Cleanup(outNum);

	if (isNegative)
		outNum[0] *= -1;

	return outNum;
}

vector<int> LargeINT::Cleanup(vector<int> vec) {
	while (vec[0] == 0) {
		vec.erase(vec.begin());
	}

	return vec;
}

vector<int> LargeINT::GetNum() {
	return num;
}

string LargeINT::GetNumString() {
	string outNum = "";
	
	for (int currentNum : num) {
		outNum += to_string(currentNum);
	}

	return outNum;
}
