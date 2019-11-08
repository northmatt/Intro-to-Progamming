#pragma once

#include <iostream>
#include <random>
#include <time.h>
#include "LargeINT.h"

using std::cout;
using std::endl;
using std::rand;

LargeINT operator+(LargeINT vec1, LargeINT vec2) {
	return LargeINT{ vec1.Add(vec2).GetNum() };
}

LargeINT operator-(LargeINT vec1, LargeINT vec2) {
	return LargeINT{ vec1.Subract(vec2).GetNum() };
}