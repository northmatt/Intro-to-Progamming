#include "largestThree.h"

int LargestThree::largestThree(int nums[], int size) {
	int temp{ 0 };

	for (int i = 0; i < size; i++)
		if (nums[i] > temp)
			temp = nums[i];
	
	return temp;
}

void LargestThree::run() {
	int inputs[3];
	
	cin >> inputs[0] >> inputs[1] >> inputs[2];

	cout << largestThree(inputs, 3);
}
