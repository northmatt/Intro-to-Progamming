#include "Time.h"

int main() {
	Time test1(1, 1, 30);
	Time test2(0, 0, 0);
	std::cout << test1 << "\n" << test2 << "\n" << test1 / test2;
}