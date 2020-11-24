#pragma once
#include <ostream>

/* q1 */
//namespace Chrono {
//	class Invalid { }; // to throw as exception
//	struct Date {
//		int y; // year 
//		int m; // month in year 
//		int d;
//		// day of month 
//	};
//	std::ostream& operator<<(std::ostream& os, const Date& d);
//	void init_day(Date& dd, int y, int m, int d);
//	void add_day(Date& dd, int n);
//	int get_days_in_month(int n);
//}

/* q2 */
//namespace Chrono {
//	class Invalid { }; // to throw as exception
//	struct Date {
//		int y; // year 
//		int m; // month in year 
//		int d; // day of month 
//		Date(int y, int m, int d); // check for valid date and initialize
//		void add_day(Date& dd, int n);
//	};
//	std::ostream& operator<<(std::ostream& os, const Date& d);
//	int get_days_in_month(int n);
//}

/* q3 */
namespace Chrono {
	class Invalid { }; // to throw as exception
	class Date {
	public:
		Date(int y, int m, int d); // check for valid date and initialize
		void add_day(Date& dd, int n);
		// nonmodifying operations:
		int month() const { return m; }
		int day() const { return d; }
		int year() const { return y; }
	private:
		int y; // year 
		int m; // month in year 
		int d; // day of month 
		int get_days_in_month(int n);
	};
	// helper functions
	std::ostream& operator<<(std::ostream& os, const Date& d);
}