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
namespace Chrono {
	Date::Date(int yy, int mm, int dd) {

		// check that (y,m,d) is a valid date 

		if (dd <= 0) throw Invalid(); // d must be positive 

		if (mm < 1 || 12 < mm) throw Invalid();

		int days_in_month = Date::get_days_in_month(mm);

		if (days_in_month < dd) throw Invalid();

		y = yy;
		m = mm;
		d = dd;
	}
	// helper functions
	// increase dd by n days
	void Date::add_day(Date& dd, int n) {
		if (n < 0) throw Invalid();

		// add run checks and relevant no. of day, then run recursively with days add
		int days_in_month = Date::get_days_in_month(dd.m);
		if (dd.d + n <= days_in_month) {
			dd.d += n;
		}
		else {
			if (dd.m == 12) {
				dd.y += 1;
				dd.m = 1;
			}
			else {
				dd.m += 1;
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
	int Date::get_days_in_month(int m) {
		int days_in_month = 31; // most months have 31 days
		switch (m) {
		case 2: // the length of February varies 
			days_in_month = 28;
			break;
		case 4: case 6: case 9: case 11:
			days_in_month = 30; // the rest have 30 days 
			break;
		default:
			break;
		}
		return days_in_month;
	}
}