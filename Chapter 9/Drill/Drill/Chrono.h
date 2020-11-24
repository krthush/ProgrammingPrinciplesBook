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
//namespace Chrono {
//	class Invalid { }; // to throw as exception
//	class Date {
//	public:
//		Date(int y, int m, int d); // check for valid date and initialize
//		void add_day(Date& dd, int n);
//		// nonmodifying operations:
//		int month() { return m; }
//		int day() { return d; }
//		int year() { return y; }
//	private:
//		int y; // year 
//		int m; // month in year 
//		int d; // day of month 
//		int get_days_in_month(int n);
//	};
//	// helper functions
//	std::ostream& operator<<(std::ostream& os, Date& d);
//}

/* q4 */
//namespace Chrono {
//	enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
//	class Date {
//	public:
//		class Invalid { }; // to throw as exception
//		Date(int y, Month m, int d); // check for valid date and initialize
//		void add_day(Date& dd, int n);
//		// nonmodifying operations:
//		int day() { return d; }
//		Month month() { return m; }
//		int year() { return y; }
//	private:
//		int y; // year 
//		Month m; // month in year 
//		int d; // day of month 
//		int get_days_in_month(Month m);
//	};
//	// helper functions
//	std::ostream& operator<<(std::ostream& os, Date& d);
//}

/* q5 */
namespace Chrono {
	enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
	class Date {
	public:
		class Invalid { }; // to throw as exception
		Date();
		Date(int y, Month m, int d); // check for valid date and initialize
		void add_day(Date& dd, int n);
		// nonmodifying operations:
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }
	private:
		int y; 
		Month m; 
		int d;
	};
	// helper functions
	bool is_date(int y, Month m, int d); // true for valid date 
	std::ostream& operator<<(std::ostream& os, const Date& d);
	int static get_days_in_month(Month m);
}