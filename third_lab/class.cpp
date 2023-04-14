#include "class.h"

void person::enterData() {
    char dash;
    string line, varName, varLastName, varSurname;
    int varDay=0, varMonth=0, varYear=0, leapYear=0;
    getline(cin, line);
    istringstream myStream(line);
    myStream>>varName>>varLastName>>varSurname>>varDay>>dash>>varMonth>>dash>>varYear;

    if (((varYear % 100 != 0) && (varYear % 4 == 0)) || ((varYear % 100 == 0) && (varYear % 400 == 0))) {
        leapYear = 1;
    } else {
        leapYear = 0;
    }
    int daysInMonth[] = {31, 28 + leapYear, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((varDay > daysInMonth[varMonth - 1]) || (varDay < 1) || (varYear < 1) || (varMonth < 1) || (varMonth > 12) ||
        (varYear > 2023) ) {
        cout << "You have mistake" << endl;
    } else {
        name = varName;
        lastName = varLastName;
        surname = varSurname;
        year = varYear;
        month = varMonth;
        day = varDay;
    }
}

void person::getDataAboutPerson() {
    cout<<name<<" "<<lastName<<" "<<surname<<" "<<day<<"-"<<month<<"-"<<year<<endl;
}

int person::countLuckyPerson() {
    int remDay, remMonth, remYear;
    remDay = countSumNumber(day)%7;
    remMonth = countSumNumber(month)%7;
    remYear = countSumNumber(year)%7;
    if ((remDay==remMonth)&&(remMonth==remYear)){
        return 1;
    } else{
        return 0;
    }
}

int person::countSumNumber(int num) {
    int totalSum = 0;
    while (num > 0) {
        int digit = num % 10;
        totalSum += digit;
        num /= 10;
    }
    return totalSum;
}
