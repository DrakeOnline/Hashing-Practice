
#include "Person.hpp"


namespace DrakeOnline {

    // Shorthand Constructor using a member initialization list (for speed)
    // Also uses aggregate initialization for birthday
    Person::Person(std::string name, Month month, unsigned int day, unsigned int year)
    : name{name}, birthday{month, day, year} {
        key = birthday.day%10;
    }

    unsigned int Person::GetKey() {
        return key;
    }

    std::string Person::PrintMonth() const {
        switch(birthday.month) {
            case  1 : return "January";
            case  2 : return "February";
            case  3 : return "March";
            case  4 : return "April";
            case  5 : return "May";
            case  6 : return "June";
            case  7 : return "July";
            case  8 : return "August";
            case  9 : return "September";
            case 10 : return "October";
            case 11 : return "November";
            case 12 : return "December";
        }
    }

    // Override output operator
    std::ostream& operator<<(std::ostream& os, Person const& person) {
        return os << "(" << person.key << ", " << person.name << ", " << person.birthday.day << " " << person.PrintMonth() << " " << person.birthday.year << ")";
    }

}
