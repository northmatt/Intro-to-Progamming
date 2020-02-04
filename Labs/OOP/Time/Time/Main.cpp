#include "Time.h"

int main() {
	Time test1(1, 1, 1);
	Time test2(0, 2, -1);
	std::cout << test1 << "\n" << test2 << "\n" << test2 * 3;
}