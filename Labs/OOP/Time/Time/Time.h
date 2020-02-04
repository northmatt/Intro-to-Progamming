#pragma once

#include <iostream>
using std::ostream;

class Time {
public:
	Time() {}
	Time(int _hour, int _minute, int _second);
	~Time() {}

	Time operator+(Time _time1);

	Time operator-(Time _time1);

	Time operator*(int _amount);

	int operator/(Time _time1);

	Time operator++(int);

	Time operator--(int);

	friend ostream& operator<<(ostream& oStr, Time _time) {
		//check to see if the time is past 12hrs, meaning it is PM and will remove 12hrs from the 24hr format
		bool isPM{ false };
		if (_time.hour > 12) {
			_time.hour -= 12;
			isPM = true;
		}

		//makes it display "09" instead of "9" for single digit numbers (9:9:9 vs 09:09:09)
		if (_time.hour < 10)
			oStr << "0";
		oStr << _time.hour << ":";

		if (_time.minute < 10)
			oStr << "0";
		oStr << _time.minute << ":";

		if (_time.second < 10)
			oStr << "0";
		oStr << _time.second;

		//displays AM/PM depending on first variable
		oStr << ((isPM) ? " PM" : " AM");

		return oStr;
	}
private:
	//utility function for fixing up the time variables to proper 24hr format (23hr, 59min, 59sec) max / (0hr, 0min, 0sec) min
	void fixTime(Time& _time);

	int hour{ 0 };
	int minute{ 0 };
	int second{ 0 };
};