// Drill from Chapter 4
#include "../../../std_lib_facilities.h"

int main() {

	vector<double> temps; // temperatures 
	
	for (double temp; cin>>temp; ) // read and put into temps 
		temps.push_back(temp); 

	double sum = 0; 
	double high_temp = 0; 
	double low_temp = 0; 

	if (temps.size() > 0) { // set default temp first temperature
		high_temp = temps[0];
		low_temp = temps[0];
	}
		
	for (int x : temps) { 
		if(x > high_temp) high_temp = x; // find high 
		if(x < low_temp) low_temp = x; // find low 
		sum += x; // compute sum 
	} 

	int no_of_temps = temps.size();

	if (no_of_temps > 0) {
		cout << "High temperature: " << high_temp << '\n';
		cout << "Low temperature: " << low_temp << '\n';
		cout << "Average temperature: " << sum / no_of_temps << '\n';
	}
	else {
		cout << "No temperature inputs given.";
	}

}
