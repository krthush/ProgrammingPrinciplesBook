// Program that gives an output with bleeped out bad words from input
#include "../../../std_lib_facilities.h"

int main() {

	// definitions
	vector<string> words;
	vector<string> disliked = { "Broccoli", "Carrots", "Veg" };

	cout << "Write your sentence when finished, press ENTER then CRTL+Z then ENTER on a windows system to get an output: \n";

	for (string word; cin >> word; ) // read whitespace-separated words 
		words.push_back(word); // put into vector 

	cout << "Number of words: " << words.size() << '\n';

	for (int i = 0; i < words.size(); ++i) {

		bool filterFailed = false;

		for (int j = 0; j < disliked.size(); ++j) { // is this a bad word? 
			if (words[i] == disliked[j]) {
				filterFailed = true;
				break;
			}
		}

		if (filterFailed)
			cout << "BLEEP ";
		else
			cout << words[i] << " ";

	}
}

//int main() {
//
//	// definitions
//	vector<string> words;
//	string disliked = "Broccoli";
//
//	cout << "Write your sentence when finished, press ENTER then CRTL+Z then ENTER on a windows system to get an output: \n";
//
//	for (string word; cin >> word; ) // read whitespace-separated words 
//		words.push_back(word); // put into vector 
//
//	cout << "Number of words: " << words.size() << '\n';
//
//	for (int i = 0; i < words.size(); ++i)
//		if (words[i] != disliked) // is this a bad word? 
//			cout << words[i] << " ";
//		else
//			cout << "BLEEP ";
//
//}