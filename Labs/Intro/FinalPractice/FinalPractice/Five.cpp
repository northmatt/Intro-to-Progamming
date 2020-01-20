#include "Five.h"

int getDoubleAmount(string _usrInp) {
	char prevInp{ ' ' };
	int doubleAmt{ 0 };
	int doubleAmtTest{ 0 };

	for (char curChar : _usrInp) {
		if (curChar == prevInp) {
			doubleAmtTest++;
		} else {
			if (doubleAmtTest == 1)
				doubleAmt++;
	
			doubleAmtTest = 0;
		}

		prevInp = curChar;
	}

	if (doubleAmtTest == 1)
		doubleAmt++;

	return doubleAmt;
}
