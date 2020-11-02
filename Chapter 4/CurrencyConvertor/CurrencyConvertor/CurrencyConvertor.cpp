// convert from yen, kroner or pounds to usd
// a suffix ‘y’ or ‘k’ or ‘p’ indicates the unit of the input
// any other suffix is an error
#include "../../../std_lib_facilities.h"

/* switch version */
int main() {

	// constants
	constexpr double yen_per_usd = 0.0095; // yen amount for 1 usd
	constexpr double kroner_per_usd = 0.11; // kroner amount for 1 usd 
	constexpr double pounds_per_usd = 1.29; // pounds amount for 1 usd 
	constexpr double chinese_yuan_per_usd = 0.15; // chinese yuan amount for 1 usd 

	// definitions
	double amount = 1; // length in inches or centimeters 
	char unit = ' '; // a space is not a unit 

	cout<< "Please enter a amount followed by a unit (y or k or p or c):\n";
	cin >> amount >> unit; 

	switch (unit) {
		case 'y':
			cout << amount << " yen == " << yen_per_usd * amount << " usd\n";
			break;
		case 'k':
			cout << amount << " kroner == " << kroner_per_usd * amount << " usd\n";
			break;
		case 'p':
			cout << amount << " gbp == " << pounds_per_usd * amount << " usd\n";
			break;
		case 'c':
			cout << amount << " chinese yuan == " << chinese_yuan_per_usd * amount << " usd\n";
			break;
		default:
			cout << "Sorry, I don't know a unit called '" << unit << "'\n";
			break;
	}

}

/* ifelse version */
//int main() {
//
//	// constants
//	constexpr double yen_per_usd = 0.0095; // yen amount for 1 usd
//	constexpr double kroner_per_usd = 0.11; // kroner amount for 1 usd 
//	constexpr double pounds_per_usd = 1.29; // pounds amount for 1 usd 
//
//	// definitions
//	double amount = 1; // length in inches or centimeters 
//	char unit = ' '; // a space is not a unit 
//
//	cout<< "Please enter a amount followed by a unit (y or k or p):\n";
//	cin >> amount >> unit; 
//	
//	if (unit == 'y') 
//		cout << amount << " yen == " << yen_per_usd *amount << " usd\n";
//	else if (unit == 'k')
//		cout << amount << " kroner == " << kroner_per_usd * amount << " usd\n";
//	else if (unit == 'p')
//		cout << amount << " gbp == " << pounds_per_usd * amount << " usd\n";
//	else 
//		cout << "Sorry, I don't know a unit called '" << unit << "'\n";
//
//}