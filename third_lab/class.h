#ifndef CLASS_CLASS_H
#define CLASS_CLASS_H
#include <iostream>
#include <sstream>
using namespace std;

class person {
    string name;
    string lastName;
    string surname;
    int day;
    int month;
    int year;
    int countSumNumber(int num);
public:
    void enterData();
    void getDataAboutPerson();
    int countLuckyPerson();
};

#endif //CLASS_CLASS_H
