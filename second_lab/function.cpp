#include "function.h"

void creatFile(const string& fileName){
    char dot, colon;
    string line, lineT, timeS, lastName;
    listOfPatient startList{};
    ofstream writeInFile(fileName, ios::binary|ios::app);
    cin.clear();
    if(writeInFile) {
        cout << "Enter list of patient like Stark 20.04.2023 15:12" << endl;
        cout << "Enter ~ for stop or other symbol for continue" << endl;
        while (line != "~") {
            int day=0, month=0, year=0, leapYear=0, hour=-1, minutes=-1;
            getline(cin, line);
            if (line != "~") {
                istringstream myStream(line);
                string word;
                myStream >> lastName >> day >> dot >> month >> dot >> year >> hour >> colon >> minutes;
                if (((year % 100 != 0) && (year % 4 == 0)) || ((year % 100 == 0) && (year % 400 == 0))) {
                    leapYear = 1;
                } else {
                    leapYear = 0;
                }
                int daysInMonth[] = {31, 28 + leapYear, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                if ((day > daysInMonth[month - 1]) || (day < 1) || (year < 1) || (month < 1) || (month > 12) ||
                    (year > 2023) || (hour < 0) || (hour > 24) || (minutes < 0) || (minutes > 59)||(lastName.length()>20)) {
                    cout << "You have mistake" << endl;
                } else {
                    strncpy(startList.lastName, lastName.c_str(), 20);
                    startList.lastName[20] = '\0';
                    startList.year = year;
                    startList.month = month;
                    startList.day = day;
                    startList.hour = hour;
                    startList.minutes = minutes;
                    writeInFile.write((char *) &startList, sizeof(listOfPatient));
                }
            }
        }
    } else{
        cout<<"Can`t open file"<<endl;
    }
    writeInFile.close();
}

string removeRecord(const string& fileName){
    listOfPatient structForTime{};
    string nameNewFile="newFile.bin";
    ifstream file(fileName, ios::binary);
    ofstream newFile(nameNewFile, ios::binary);
    if((file)&&(newFile)) {
        while (file.read((char *) &structForTime, sizeof(listOfPatient))) {
            if (compareTime(structForTime) == 1) {
                newFile.write((char *) &structForTime, sizeof(structForTime));
            } else if (compareTime(structForTime) == 0) {
                cout << "Can`t compare" << endl;
            }
        }
    } else{
        cout<<"Can`t open file"<<endl;
    }
    file.close();
    newFile.close();
    return nameNewFile;
}

int compareTime(listOfPatient &patientTime){
    double seconds=0;
    time_t now = time(nullptr); // отримуємо поточний час
    struct tm* startTm = localtime(&now);
    startTm->tm_min = patientTime.minutes;
    startTm->tm_hour = patientTime.hour;

    time_t myTime=mktime(startTm);
    if (myTime == -1) {
        cerr << "Error: invalid calendar time.\n";
        return 0;
    }
    seconds= difftime(now, myTime);
    if (seconds < 0) {
        return 1;
    } else if (seconds > 0) {
        return -1;
    }
}

void creatTwoListOfPatient(const string& fileNameS){
    listOfPatient structForDate{};
    string nameFileSecondPatient="secondPatient.bin", nameFileOtherPatient="other_patient.bin";
    ifstream file(fileNameS, ios::binary);
    ofstream secondPatient(nameFileSecondPatient, ios::binary);
    ofstream otherPatient(nameFileOtherPatient, ios::binary);
    if ((file)&&(secondPatient)&&(otherPatient)) {
        while (file.read((char *) &structForDate, sizeof(listOfPatient))) {
            if (compareDay(structForDate) == 1) {
                secondPatient.write((char *) &structForDate, sizeof(structForDate));
            } else if (compareDay(structForDate) == -1) {
                otherPatient.write((char *) &structForDate, sizeof(structForDate));
            }
        }
    } else {
        cout<<"Can`t open file"<<endl;
    }
    file.close();
    secondPatient.close();
    otherPatient.close();


    cout<<"Second:"<<endl;
    outputFile(nameFileSecondPatient);
    cout<<"Other:"<<endl;
    outputFile(nameFileOtherPatient);
}

int compareDay(listOfPatient &patientDay){
    int day=0;
    time_t now = time(nullptr); // отримуємо поточний час
    struct tm* startTm = localtime(&now);
    startTm->tm_mday = patientDay.day;
    startTm->tm_mon = patientDay.month-1;
    startTm->tm_year=patientDay.year-1900;

    time_t myTime=mktime(startTm);
    if (myTime == -1) {
        cerr << "Error: invalid calendar time.\n";
        return 0;
    }
    day = int (difftime(now, myTime)/86400);
    if ((day < 11)&&(day>0)) {
        return 1;
    }else if ((day >= 11)||(day<=0)){
        return -1;
    }
}

void outputFile(const string& fileName){
    listOfPatient structForRead{};
    ifstream fln(fileName, ios::binary);
    cout << "List of patient: \n";
    if(fln) {
        while (fln.read((char *) &structForRead, sizeof(listOfPatient))) {
            cout << structForRead.lastName << ' ' << structForRead.day << '.' << structForRead.month << '.'
                 << structForRead.year << ' ' << structForRead.hour << ':' << structForRead.minutes << endl;
        }
    }else{
        cout<<"Can`t open file"<<endl;
    }
    cout << endl;
    fln.close();
}
