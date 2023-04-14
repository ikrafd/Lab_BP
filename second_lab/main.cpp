#include "function.h"

int main() {
    char ch = ' ';
    do{
        string fileName = "startFile.bin", newFile;
        creatFile(fileName); // write data in file
        cout<<"Start list of patient"<<endl;
        outputFile(fileName); // output creat file
        newFile = removeRecord(fileName); //remove data about some patient
        cout<<"List patient in future"<<endl;
        outputFile(newFile); // output new file
        creatTwoListOfPatient(newFile); // creat two file with patient
        cout<<"Enter * for append"<<endl;
        cin>>ch; // enter char for append
        cin.ignore(1);
    } while (ch == '*');
    return 0;
}