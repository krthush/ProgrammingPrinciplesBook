// program that accepts form input and writes a letter
#include "../../../std_lib_facilities.h"

int main() {

	// definitions
	string first_name = ""; // string variable
	string friend_name = "";
	char friend_sex = 0;
	int age = 0;

	// form input
	cout << "Enter the name of the person you want to write to?\n";
	cin >> first_name; // read a string 
	cout << "What is their age?\n";
	cin >> age; // read a int
	if (age <= 0 || age >= 110) {
		simple_error("You're kidding!");
	}
	cout << "What is your other friend's name?\n";
	cin >> friend_name; // read a string 
	cout << "What is your other friend's sex (enter a single letter - m for male, f for female)?\n";
	cin >> friend_sex; // read a char

	// letter output
	cout << "Dear " << first_name << ",\n" 
		<< "\tHow are you? I'm fine.\n" 
		<< "I miss you, would be really nice to have a catch up soon...\n"
		<< "Have you seen " << friend_name << " lately?\n";
	if (friend_sex == 'm') {
		cout << "If you see " << friend_name << " please ask him to call me?\n";
	}
	else {
		cout << "If you see " << friend_name << " please ask her to call me?\n";
	}
	cout << "I hear you just had a birthday and you are " << age << " years old.\n";
	if (age < 12) {
		cout << "Next year you will be " << age + 1 << ".\n";
	}
	else if (age == 17) {
		cout << "Next year you will be able to vote.\n";
	}
	else if (age > 70) {
		cout << "I hope you are enjoying retirement.\n";
	}
	cout << "Yours sincerely,\n\n\nThushaan";
}