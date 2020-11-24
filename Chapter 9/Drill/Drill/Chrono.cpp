#include "Chrono.h";

/* q1 */
//namespace Chrono {
//	std::ostream& operator<<(std::ostream& os, const Date& d)
//	{
//		return os << '(' << d.y << ',' << int(d.m) << ',' << d.d << ')';
//	}
//	// helper functions
//	void init_day(Date& dd, int y, int m, int d) {
//
//		// check that (y,m,d) is a valid date 
//
//		if (d <= 0) throw Invalid(); // d must be positive 
//
//		if (m < 1 || 12 < m) throw Invalid();
//
//		int days_in_month = get_days_in_month(dd.m);
//
//		if (days_in_month < d) throw Invalid();
//
//		// if it is, use it to initialize dd 
//		dd.d = d;
//		dd.m = m;
//		dd.y = y;
//	}
//	// increase dd by n days
//	void add_day(Date& dd, int n) {
//
//		if (n < 0) throw Invalid ();
//
//		// add run checks and relevant no. of day, then run recursively with days add
//		int days_in_month = get_days_in_month(dd.m);
//		if (dd.d + n <= days_in_month) {
//			dd.d += n;
//		} else {
//			if (dd.m == 12) {
//				dd.y += 1;
//				dd.m = 1;
//			}
//			else {
//				dd.m += 1;
//			}
//			n -= (days_in_month - dd.d) + 1;
//			dd.d = 1;
//			Chrono::add_day(dd, n);
//		}
//	}
//	int get_days_in_month(int m) {
//		int days_in_month = 31; // most months have 31 days
//		switch (m) {
//		case 2: // the length of February varies 
//			days_in_month = 28;
//			break;
//		case 4: case 6: case 9: case 11:
//			days_in_month = 30; // the rest have 30 days 
//			break;
//		default:
//			break;
//		}
//		return days_in_month;
//	}
//}

/* q2 */
//namespace Chrono {
//	std::ostream& operator<<(std::ostream& os, const Date& d)
//	{
//		return os << '(' << d.y << ',' << int(d.m) << ',' << d.d << ')';
//	}
//	Date::Date(int yy, int mm, int dd) {
//
//		// check that (y,m,d) is a valid date 
//
//		if (dd <= 0) throw Invalid(); // d must be positive 
//
//		if (mm < 1 || 12 < mm) throw Invalid();
//
//		int days_in_month = get_days_in_month(mm);
//
//		if (days_in_month < dd) throw Invalid(); 
//
//		y = yy;
//		m = mm;
//		d = dd;
//	}
//	// helper functions
//	// increase dd by n days
//	void Date::add_day(Date& dd, int n) {
//		if (n < 0) throw Invalid();
//
//		// add run checks and relevant no. of day, then run recursively with days add
//		int days_in_month = get_days_in_month(dd.m);
//		if (dd.d + n <= days_in_month) {
//			dd.d += n;
//		}
//		else {
//			if (dd.m == 12) {
//				dd.y += 1;
//				dd.m = 1;
//			}
//			else {
//				dd.m += 1;
//			}
//			n -= (days_in_month - dd.d) + 1;
//			dd.d = 1;
//			Date::add_day(dd, n);
//		}
//	}
//	int get_days_in_month(int m) {
//		int days_in_month = 31; // most months have 31 days
//		switch (m) {
//		case 2: // the length of February varies 
//			days_in_month = 28;
//			break;
//		case 4: case 6: case 9: case 11:
//			days_in_month = 30; // the rest have 30 days 
//			break;
//		default:
//			break;
//		}
//		return days_in_month;
//	}
//}


/* q3 */
//namespace Chrono {
//	Date::Date(int yy, int mm, int dd) {
//
//		// check that (y,m,d) is a valid date 
//
//		if (dd <= 0) throw Invalid(); // d must be positive 
//
//		if (mm < 1 || 12 < mm) throw Invalid();
//
//		int days_in_month = Date::get_days_in_month(mm);
//
//		if (days_in_month < dd) throw Invalid();
//
//		y = yy;
//		m = mm;
//		d = dd;
//	}
//	// helper functions
//	// increase dd by n days
//	void Date::add_day(Date& dd, int n) {
//		if (n < 0) throw Invalid();
//
//		// add run checks and relevant no. of day, then run recursively with days add
//		int days_in_month = Date::get_days_in_month(dd.m);
//		if (dd.d + n <= days_in_month) {
//			dd.d += n;
//		}
//		else {
//			if (dd.m == 12) {
//				dd.y += 1;
//				dd.m = 1;
//			}
//			else {
//				dd.m += 1;
//			}
//			n -= (days_in_month - dd.d) + 1;
//			dd.d = 1;
//			Date::add_day(dd, n);
//		}
//	}
//	// cout
//	std::ostream& operator<<(std::ostream& os, Date& d)
//	{
//		return os << '(' << d.year() << ',' << int(d.month()) << ',' << d.day() << ')';
//	}
//	// private functions
//	int Date::get_days_in_month(int m) {
//		int days_in_month = 31; // most months have 31 days
//		switch (m) {
//		case 2: // the length of February varies 
//			days_in_month = 28;
//			break;
//		case 4: case 6: case 9: case 11:
//			days_in_month = 30; // the rest have 30 days 
//			break;
//		default:
//			break;
//		}
//		return days_in_month;
//	}
//}

/* q4 */
//namespace Chrono {
//	Date::Date(int yy, Month mm, int dd)
//		:y{ yy }, m{ mm }, d{ dd }
//	{
//
//		// check that (y,m,d) is a valid date 
//
//		if (dd <= 0) throw Invalid(); // d must be positive 
//
//		if (mm < Month::jan || Month::dec < mm) throw Invalid();
//
//		int days_in_month = Date::get_days_in_month(mm);
//
//		if (days_in_month < dd) throw Invalid();
//	}
//	// helper functions
//	// increase dd by n days
//	void Date::add_day(Date& dd, int n) {
//		if (n < 0) throw Invalid();
//
//		// add run checks and relevant no. of day, then run recursively with days add
//		int days_in_month = Date::get_days_in_month(dd.m);
//		if (dd.d + n <= days_in_month) {
//			dd.d += n;
//		}
//		else {
//			if (dd.m == Month::dec) {
//				dd.y += 1;
//				dd.m = Month::jan;
//			}
//			else {
//				dd.m = Month(int(m) + 1);
//			}
//			n -= (days_in_month - dd.d) + 1;
//			dd.d = 1;
//			Date::add_day(dd, n);
//		}
//	}
//	// cout
//	std::ostream& operator<<(std::ostream& os, Date& d)
//	{
//		return os << '(' << d.year() << ',' << int(d.month()) << ',' << d.day() << ')';
//	}
//	// private functions
//	int Date::get_days_in_month(Month m) {
//		int days_in_month = 31; // most months have 31 days
//		switch (m) {
//		case Month::feb: // the length of February varies 
//			days_in_month = 28;
//			break;
//		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
//			days_in_month = 30; // the rest have 30 days 
//			break;
//		default:
//			break;
//		}
//		return days_in_month;
//	}
//}

/* q5 */
namespace Chrono {
	Date::Date(int yy, Month mm, int dd)
		:y{ yy }, m{ mm }, d{ dd }
	{
		// check that (y,m,d) is a valid date 
		if (!is_date(yy, mm, dd)) throw Invalid{};
	}
	const Date& default_date() {
		static Date dd{ 2001, Month::jan, 1 }; // start of 21st century 
		return dd; 
	}
	Date::Date() 
		:y{ default_date().year() }, 
		m{ default_date().month() }, 
		d{ default_date().day() } 
	{ 
	}
	// helper functions
	bool is_date(int y, Month m, int d) {

		if (d <= 0) return false; // d must be positive 

		if (m < Month::jan || Month::dec < m) return false;

		int days_in_month = get_days_in_month(m);

		if (days_in_month < d) return false;

		return true;
	}
	// increase dd by n days
	void Date::add_day(Date& dd, int n) {
		if (n < 0) throw Invalid();

		// add run checks and relevant no. of day, then run recursively with days add
		int days_in_month = get_days_in_month(dd.m);
		if (dd.d + n <= days_in_month) {
			dd.d += n;
		}
		else {
			if (dd.m == Month::dec) {
				dd.y += 1;
				dd.m = Month::jan;
			}
			else {
				dd.m = Month(int(m) + 1);
			}
			n -= (days_in_month - dd.d) + 1;
			dd.d = 1;
			Date::add_day(dd, n);
		}
	}
	// cout
	std::ostream& operator<<(std::ostream& os, const Date& d)
	{
		return os << '(' << d.year() << ',' << int(d.month()) << ',' << d.day() << ')';
	}
	// private functions
	int get_days_in_month(Month m) {
		int days_in_month = 31; // most months have 31 days
		switch (m) {
		case Month::feb: // the length of February varies 
			days_in_month = 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days_in_month = 30; // the rest have 30 days 
			break;
		default:
			break;
		}
		return days_in_month;
	}
}