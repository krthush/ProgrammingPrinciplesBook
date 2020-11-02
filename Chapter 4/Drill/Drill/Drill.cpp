// Drill from Chapter 4
#include "../../../std_lib_facilities.h"

int main() {

	// Constants
	// Base unit assumed to be cm
	const double m_to_cm = 100;
	const double in_to_cm = 2.54;
	const double ft_to_cm = 30.48;

	// Definitions
	double input = 0;
	string unit = "";
	bool firstInput = true;
	double min = 0;
	double max = 0;
	double value = 0;
	double sum = 0;
	vector <double> values;

	cout << "Enter a measurement followed by a unit. \nAccepted units are cm, m, in, ft (example input: 5ft). \n";

	while (cin >> input >> unit) {

		if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft") {

			cout << input << unit;

			// Convert to base unit (cm) for value
			if (unit == "cm") {
				value = input;
			}
			else if (unit == "m") {
				value = input * m_to_cm;
			}
			else if (unit == "in") {
				value = input * in_to_cm;
			}
			else {
				value = input * ft_to_cm;
			}

			sum += value / m_to_cm;
			values.push_back(value/m_to_cm);

			if (firstInput) { // Make sure that first input is datum for min/max
				min = value;
				max = value;
				firstInput = false;
				cout << " - " << value << "cm - First value (Smallest & Largest) \n";
			}
			else if (value < min) {
				cout << " - " << value << "cm - Smallest value \n";
				min = value;
			}
			else if (value > max) {
				cout << " - " << value << "cm - Largest value \n";
				max = value;
			}
			else {
				cout << " - " << value << "cm\n";
			}

		}
		else {

			cout << "Illegal unit, input rejected! \n";

		}

	}

	cout << "Sum: " << sum << "m, Largest value: " << max << "cm, Smallest value: " << min << "cm \n";

	cout << "Values: \n";
	sort(values);
	for (double x : values) {
		cout << x << "m \n";
	}

}

// pre 6
//int main() {
//	double value_1;
//	double value_2;
//	double precision = 1.0/100;
//	while (cin>>value_1>>value_2) {
//		if (value_1 == value_2) {
//			cout << value_1 << " " << value_2 << " Equal Numbers \n";
//		}
//		else if (value_1 > value_2) {
//			cout << value_1 << " " << value_2;
//			if ((value_1 - value_2) < precision)
//				cout << " Close Numbers \n";
//			else
//				cout << '\n';
//		}
//		else {
//			cout << value_2 << " " << value_1;
//			if ((value_2 - value_1) < precision)
//				cout << " Close Numbers \n";
//			else
//				cout << '\n';
//		}
//	}
//}
