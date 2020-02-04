#include "Time.h"

Time::Time(int _hour, int _minute, int _second) {
	hour = _hour;
	minute = _minute;
	second = _second;
	fixTime(*this);
}

Time Time::operator+(Time _time1) {
	_time1.hour += hour;
	_time1.minute += minute;
	_time1.second += second;

	fixTime(_time1);

	return _time1;
}

Time Time::operator-(Time _time1) {
	Time _timeTemp(hour, minute, second);
	_timeTemp.hour -= _time1.hour;
	_timeTemp.minute -= _time1.minute;
	_timeTemp.second -= _time1.second;

	fixTime(_timeTemp);

	return _timeTemp;
}

Time Time::operator*(int _amount) {
	Time _time1(hour, minute, second);
	_time1.hour *= _amount;
	_time1.minute *= _amount;
	_time1.second *= _amount;

	fixTime(_time1);

	return _time1;
}

int Time::operator/(Time _time1) {
	int amount1{ hour * 3600 + minute * 60 + second };
	int amount2{ _time1.hour * 3600 + _time1.minute * 60 + _time1.second };

	return amount1 / amount2;
}

Time Time::operator++(int) {
	second += 1;

	fixTime(*this);

	return *this;
}

Time Time::operator--(int) {
	second -= 1;

	fixTime(*this);

	return *this;
}

void Time::fixTime(Time& _time) {
	while (_time.second >= 60) {
		_time.second -= 60;
		_time.minute += 1;
	}

	while (_time.minute >= 60) {
		_time.minute -= 60;
		_time.hour += 1;
	}

	while (_time.hour >= 24)
		_time.hour -= 24;

	while (_time.second < 0) {
		_time.second += 60;
		_time.minute -= 1;
	}

	while (_time.minute < 0) {
		_time.minute += 60;
		_time.hour -= 1;
	}

	while (_time.hour < 0)
		_time.hour += 24;
}
