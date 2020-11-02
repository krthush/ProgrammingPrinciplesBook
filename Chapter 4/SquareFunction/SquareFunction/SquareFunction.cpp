// creates a table of chars with their corresponding int values
#include "../../../std_lib_facilities.h"


int square(int x) {

	// definitions
	int i = 0;
	int result = 0;

	for (i = 0; i < x; i++)
	{
		result += x;
	}

	return result;
}

int main() {

	cout << square(2) << '\n'; // print 4 
	cout << square(10) << '\n'; // print 100
}
