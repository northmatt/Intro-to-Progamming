#include "main.h"

int main() {
	LargeINT theNum1{ {2, 0, 0} };
	LargeINT theNum2( {-2, 0, 1} );
	LargeINT theNum3( {-4, 0, 0, 0} );
	LargeINT theNum4( {2, 0} );

	cout << "Num 1: " << theNum1.GetNumString() << ", Num 2: " << theNum2.GetNumString() << ", Num 3: " << theNum3.GetNumString() << ", Num 4: " << theNum4.GetNumString() << "\n" << endl;
	cout << "Num1 + Num2: " << (theNum1 + theNum2).GetNumString() << endl;
	cout << "Num1 - Num2: " << (theNum1 - theNum2).GetNumString() << endl;
	cout << "Num1 + Num3: " << (theNum1 + theNum3).GetNumString() << endl;
	cout << "Num4 - Num3: " << (theNum4 - theNum3).GetNumString() << endl;

	return 0;
}