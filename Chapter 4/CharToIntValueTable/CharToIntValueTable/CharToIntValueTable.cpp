// creates a table of chars with their corresponding int values
#include "../../../std_lib_facilities.h"

/* for version */
int main() {

	// definitions
	int starting_lowercase_char = char('a');
	int starting_uppercase_char = char('A');
	int starting_number_char = char('0');
	int chars_in_alphabet = 26;
	int chars_in_numbers = 10;

	cout << "Characters in lowercase alphabet: \n \n";

	for (int i = starting_lowercase_char; i < starting_lowercase_char + chars_in_alphabet; i++)
	{
		cout << char(i) << '\t' << i << '\n';
	}

	cout << '\n';
	cout << "Characters in uppercase alphabet: \n \n";

	for (int i = starting_uppercase_char; i < starting_uppercase_char + chars_in_alphabet; i++)
	{
		cout << char(i) << '\t' << i << '\n';
	}
	
	cout << '\n';
	cout << "Characters in numbers: \n \n";

	for (int i = starting_number_char; i < starting_number_char + chars_in_numbers; i++)
	{
		cout << char(i) << '\t' << i << '\n';
	}

}

/* while version */
//int main() {
//
//	// definitions
//	int starting_char = char('a');
//	int chars_in_alphabet = 26;
//	int i = starting_char; // start from int val of a 
//
//	while (i < starting_char + chars_in_alphabet) {
//		cout << char(i) << '\t' << i << '\n';
//		++i; // increment i (that is, i becomes i+1) 
//	}
//
//}