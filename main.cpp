// |====================================================|
// |    Title:      Hashing Practice                    |
// |    Author:     Drake G. Cummings                   |
// |    Purpose:    To practice using multimaps in C++  |
// |    Date:       March 26th, 2020                    |
// |====================================================|

#include <iostream>
#include <map>
#include "Person.hpp"

using namespace std;

int main() {

    // Create Persons
    DrakeOnline::Person GeorgeJr(  "George W. Bush",    DrakeOnline::JULY,       6, 1946);
    DrakeOnline::Person Bill(      "Bill Clinton",      DrakeOnline::AUGUST,    19, 1946);
    DrakeOnline::Person Millard(   "Millard Fillmore",  DrakeOnline::JANUARY,    7, 1800);
    DrakeOnline::Person Bob(       "Bob Dole",          DrakeOnline::JULY,      22, 1923);
    DrakeOnline::Person GeorgeSr(  "George G.W. Bush",  DrakeOnline::JUNE,      12, 1924);
    DrakeOnline::Person Mick(      "Mick Jagger",       DrakeOnline::JULY,      26, 1943);
    DrakeOnline::Person Elton(     "Elton John",        DrakeOnline::MARCH,     25, 1947);




    // ____________________ 10 BUCKET CHAIN ____________________
    std::multimap<int, DrakeOnline::Person> tenBucketChain;

    // Insert People into four bucket hash table
    tenBucketChain.insert(make_pair(  GeorgeJr.GetKey(),  GeorgeJr  ));
    tenBucketChain.insert(make_pair(      Bill.GetKey(),      Bill  ));
    tenBucketChain.insert(make_pair(   Millard.GetKey(),   Millard  ));
    tenBucketChain.insert(make_pair(       Bob.GetKey(),       Bob  ));
    tenBucketChain.insert(make_pair(  GeorgeSr.GetKey(),  GeorgeSr  ));
    tenBucketChain.insert(make_pair(      Mick.GetKey(),      Mick  ));
    tenBucketChain.insert(make_pair(     Elton.GetKey(),     Elton  ));

    // Printing
    cout << endl;
    cout << "Chaining with 10 buckets:" << endl;
    for(short int i = 0; i < 10; i++) {
        pair<multimap<int,DrakeOnline::Person>::iterator, multimap<int,DrakeOnline::Person>::iterator> range;
        range = tenBucketChain.equal_range(i);

        cout << "h[" << i << "]==";
        for(multimap<int,DrakeOnline::Person>::iterator it = range.first; it!=range.second; ++it) {
            cout << ' ' << it->second;
        }
        cout << endl;
    }
    cout << endl << endl;




    // ____________________ FOUR BUCKET CHAIN ____________________
    std::multimap<int, DrakeOnline::Person> fourBucketChain;

    // Insert People into four bucket hash table
    fourBucketChain.insert(make_pair(  GeorgeJr.GetKey()%4,  GeorgeJr  ));
    fourBucketChain.insert(make_pair(      Bill.GetKey()%4,      Bill  ));
    fourBucketChain.insert(make_pair(   Millard.GetKey()%4,   Millard  ));
    fourBucketChain.insert(make_pair(       Bob.GetKey()%4,       Bob  ));
    fourBucketChain.insert(make_pair(  GeorgeSr.GetKey()%4,  GeorgeSr  ));
    fourBucketChain.insert(make_pair(      Mick.GetKey()%4,      Mick  ));
    fourBucketChain.insert(make_pair(     Elton.GetKey()%4,     Elton  ));

    // Printing
    cout << "Chaining with 4 buckets:" << endl;
    for(short int i = 0; i < 4; i++) {
        pair<multimap<int,DrakeOnline::Person>::iterator, multimap<int,DrakeOnline::Person>::iterator> range;
        range = fourBucketChain.equal_range(i);

        cout << "h[" << i << "]==";
        for(multimap<int,DrakeOnline::Person>::iterator it = range.first; it!=range.second; ++it) {
            cout << ' ' << it->second;
        }
        cout << endl;
    }
    cout << endl << endl;




    // ____________________ OPEN ADDRESSING ____________________
    std::multimap<int, DrakeOnline::Person> openAddressing;

    // Insert People into four bucket hash table

    openAddressing.insert(make_pair(GeorgeJr.GetKey(), GeorgeJr));

    short int i = 0;
    while(openAddressing.find(Bill.GetKey()+i) != openAddressing.end()){
        i++;
    }
    openAddressing.insert(make_pair(Bill.GetKey()+i, Bill));
    i = 0;


    while(openAddressing.find(Millard.GetKey()+i) != openAddressing.end()){
        i++;
    }
    openAddressing.insert(make_pair(Millard.GetKey()+i, Millard));
    i = 0;


    while(openAddressing.find(Bob.GetKey()+i) != openAddressing.end()){
        i++;
    }
    openAddressing.insert(make_pair(Bob.GetKey()+i, Bob));
    i = 0;


    while(openAddressing.find(GeorgeSr.GetKey()+i) != openAddressing.end()){
        i++;
    }
    openAddressing.insert(make_pair(GeorgeSr.GetKey()+i, GeorgeSr));
    i = 0;


    while(openAddressing.find(Mick.GetKey()+i) != openAddressing.end()){
        i++;
    }
    openAddressing.insert(make_pair(Mick.GetKey()+i, Mick));
    i = 0;


    while(openAddressing.find(Elton.GetKey()+i) != openAddressing.end()){
        i++;
    }
    openAddressing.insert(make_pair(Elton.GetKey()+i, Elton));
    i = 0;


    // Printing
    cout << "Open Addressing:" << endl;
    for(short int i = 0; i < 10; i++) {
        pair<multimap<int,DrakeOnline::Person>::iterator, multimap<int,DrakeOnline::Person>::iterator> range;
        range = openAddressing.equal_range(i);

        cout << "h[" << i << "]==";
        for(multimap<int,DrakeOnline::Person>::iterator it = range.first; it!=range.second; ++it) {
            cout << ' ' << it->second;
        }
        cout << endl;
    }
    cout << endl;




    return 0;
}
