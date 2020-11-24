// Drill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Chrono.h";

/* q1 */
//int main()
//{
//    Chrono::Date today;
//    //Chrono::init_day(today, 2004, 13, -5); // oops!
//    Chrono::init_day(today, 1979, 6, 25);
//    Chrono::Date tomorrow = today;
//    Chrono::add_day(tomorrow, 1);
//    std::cout << "Today: " << today << " Tomorrow: " << tomorrow;
//}

/* q2 */
//int main()
//{
//    //Chrono::Date today { 2004, 13, -5 };// oops!
//    Chrono::Date today{ 1979, 6, 25 };
//    Chrono::Date tomorrow = today;
//    tomorrow.add_day(tomorrow, 1);
//    std::cout << "Today: " << today << " Tomorrow: " << tomorrow;
//}

/* q3 */
int main()
{
    //Chrono::Date today { 2004, 13, -5 };// oops!
    Chrono::Date today{ 1979, 6, 25 };
    Chrono::Date tomorrow = today;
    tomorrow.add_day(tomorrow, 1);
    std::cout << "Today: " << today << " Tomorrow: " << tomorrow;
}