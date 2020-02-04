#include "Time.h"

Time::Time(int _hour, int _minute, int _second) {
	hour = _hour;
	minute = _minute;
	second = _second;
	fixTime(*this);
}

Time Time::operator+(Time _time1) {
	//adds the time then fixes its values to the proper 24hr format
	_time1.hour += hour;
	_time1.minute += minute;
	_time1.second += second;

	fixTime(_time1);

	return _time1;
}

Time Time::operator-(Time _time1) {
	//subtracts the time then fixes its values to the proper 24hr format
	_time1.hour = hour - _time1.hour;
	_time1.minute = minute - _time1.minute;
	_time1.second = second - _time1.second;

	fixTime(_time1);

	return _time1;
}

Time Time::operator*(int _amount) {
	//multiplies the time then fixes its values to the proper 24hr format
	Time _time1(hour, minute, second);
	_time1.hour *= _amount;
	_time1.minute *= _amount;
	_time1.second *= _amount;

	fixTime(_time1);

	return _time1;
}

int Time::operator/(Time _time1) {
	//converts time into total seconds and then divides the seconds
	int amount1{ hour * 3600 + minute * 60 + second };
	int amount2{ _time1.hour * 3600 + _time1.minute * 60 + _time1.second };

	return amount1 / amount2;
}

Time Time::operator++(int) {
	//adds one to the seconds then fixes its values to the proper 24hr format
	second += 1;

	fixTime(*this);

	return *this;
}

Time Time::operator--(int) {
	//subtracts one to the seconds then fixes its values to the proper 24hr format
	second -= 1;

	fixTime(*this);

	return *this;
}

void Time::fixTime(Time& _time) {
	//if 1+ amount of whole minutes are recorded in seconds they'll be transfered to minutes
	while (_time.second >= 60) {
		_time.second -= 60;
		_time.minute += 1;
	}
	//if 1+ amount of whole hours are recorded in minutes they'll be transfered to hours
	while (_time.minute >= 60) {
		_time.minute -= 60;
		_time.hour += 1;
	}
	//if past 24 hr mark, reset the day
	while (_time.hour >= 24)
		_time.hour -= 24;

	//if negative seconds, remove the necessary amount of minutes to have a positive amount of seconds
	while (_time.second < 0) {
		_time.second += 60;
		_time.minute -= 1;
	}
	//if negative minutes, remove the necessary amount of hours to have a positive amount of minutes
	while (_time.minute < 0) {
		_time.minute += 60;
		_time.hour -= 1;
	}
	//if past 24 hr mark, reset the day
	while (_time.hour < 0)
		_time.hour += 24;
}
