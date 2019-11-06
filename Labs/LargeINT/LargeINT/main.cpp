#include "main.h"

int main() {
	LargeINT theNum{ {9, 9, 9, 9} };
	LargeINT theNum2( {9, 9, 9, 9} );

	theNum = theNum + theNum2;

	cout << "Num: " << theNum.GetNumString() << endl;

	return 0;
}