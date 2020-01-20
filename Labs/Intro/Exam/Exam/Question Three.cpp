#include "Question Three.h"

//fav part was tutorials/labs where you had to do self learning (however you should do review on next lecture about it for those that were lost on the tut/lab)

void StartQ3() {
	cout << "Harmonic Sum with n = 3\n";
	cout << HarmonicSum(3) << "\n";
}

double HarmonicSum(size_t percision) {
	if (percision <= 1)
		return 1;

	return HarmonicSum(percision - 1) + 1.0 / static_cast<double>(percision);
}
