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
		bool isPM{ false };
		if (_time.hour > 12) {
			_time.hour -= 12;
			isPM = true;
		}

		if (_time.hour < 10)
			oStr << "0";
		oStr << _time.hour << ":";

		if (_time.minute < 10)
			oStr << "0";
		oStr << _time.minute << ":";

		if (_time.second < 10)
			oStr << "0";
		oStr << _time.second;

		oStr << ((isPM) ? " PM" : " AM");

		return oStr;
	}
private:
	void fixTime(Time& _time);

	int hour{ 0 };
	int minute{ 0 };
	int second{ 0 };
};