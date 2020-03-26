
#include "Person.hpp"


namespace DrakeOnline {

    // Shorthand Constructor using a member initialization list (for speed)
    // Also uses aggregate initialization for birthday
    Person::Person(std::string name, Month month, unsigned int day, unsigned int year)
    : name{name}, birthday{month, day, year} {}

    // Override output operator
    std::ostream& operator<<(std::ostream& os, Person const &person) {
        return os << person.name << " " << person.birthday.month << " " << person.birthday.day << " " << person.birthday.year;
    }

}
