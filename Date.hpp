#pragma once


namespace DrakeOnline {

    enum Month {JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

    struct Date {
        Month month;
        // Allocate 5 bits to this variable (surprisingly is a max of 31)
        unsigned int day : 5;
        unsigned int year;
    };

}
