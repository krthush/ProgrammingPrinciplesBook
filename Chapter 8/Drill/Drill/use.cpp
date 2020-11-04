#include "my.h";
#include "../../../std_lib_facilities.h"

void swap_v(int a, int b) {
	int temp; 
	temp = a, a = b; 
	b = temp;
};

void swap_r(int& a, int& b) {
	int temp;
	temp = a, a = b;
	b = temp;
};

void swap_cr(const int& a, const int& b) {
	int temp;
	//temp = a, a = b;
	//b = temp;
};

namespace X {
	int var;
	void print() {
		cout << var;
	}
}

namespace Y {
	int var;
	void print() {
		cout << var;
	}
}

namespace Z {
	int var;
	void print() {
		cout << var;
	}
}

int main() {

	//foo = 7;
	//print_foo();
	//print(99);

	//int x = 7; 
	//int y = 9; 

	//swap_v (x, y); // replace ? by v, r, or cr 
	//cout << x << y << '\n';

	//swap_v(7,9);
	//cout << x << y << '\n';

	//const int cx = 7; 
	//const int cy = 9; 

	//swap_v(cx,cy);
	//cout << cx << cy << '\n';

	//swap_v(7.7,9.9);
	//cout << cx << cy << '\n';

	//double dx = 7.7; 
	//double dy = 9.9; 

	//swap_v(dx,dy);
	//cout << dx << dy << '\n';

	//swap_v(7.7,9.9);
	//cout << dx << dy << '\n';

	X::var = 7;
	X::print(); // print X’s var

	using namespace Y; 
		
	var = 9; 
	print(); // print Y’s var 
		
	{ 
		using Z::var; 
		using Z::print; 
		var = 11; 
		print(); // print Z’s var 
	} 
		
	print(); // print Y’s var 
	X::print(); // print X’s var 

}
