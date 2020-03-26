#pragma once

#include <string>
#include <ostream>
#include "Date.hpp"


namespace DrakeOnline {

    class Person {
        public:
            Person(std::string name, Month month, unsigned int day, unsigned int year);
            friend std::ostream& operator<<(std::ostream& os, const Person& person);
        private:
            std::string name;
            Date birthday;
    };
}
