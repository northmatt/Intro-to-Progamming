#pragma once

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::ostream;
using std::istream;
using std::string;
using std::to_string;

class Time {
public:
	Time() {}
	Time(int _hour, int _minute, int _second);
	~Time() {}

	friend ostream& operator<<(ostream& oStr, const Time _this) {
		if (_this.hour < 10)
			oStr << "0";
		oStr << to_string(_this.hour) + ":";

		if (_this.minute < 10)
			oStr << "0";
		oStr << to_string(_this.minute) + ":";

		if (_this.second < 10)
			oStr << "0";
		oStr << to_string(_this.second);

		return oStr;
	}

private:
	int second{0};
	int minute{0};
	int hour{0};
};