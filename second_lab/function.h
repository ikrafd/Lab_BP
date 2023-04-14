#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstring>

using namespace std;

//struct for write data about patient
struct listOfPatient{
    char lastName[21]; //last name of patient
    int day; //year
    int month;
    int year;
    int hour; //time
    int minutes;
};

void creatFile(const string&); // write data in file
string removeRecord(const string&);
int compareTime(listOfPatient &patient);
void creatTwoListOfPatient(const string&); // creat two new file with patient
int compareDay(listOfPatient &patientDay);
void outputFile(const string&); // output data from file
