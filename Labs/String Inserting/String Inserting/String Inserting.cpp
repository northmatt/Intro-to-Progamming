#include "String Inserting.h"

string SubStr(string inStr, size_t start, size_t end) {
	string outStr{ "" };

	for (size_t i = start; i < end; i++)
		outStr += inStr[i];

	return outStr;
}

string InsStr(string inStr1, string inStr2, size_t pos) {
	if (pos > inStr1.length())
		return "Index is out of range of string";
	
	return SubStr(inStr1, 0, pos) + inStr2 + SubStr(inStr1, pos, inStr1.length());
}
