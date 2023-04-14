#include "class.h"

int main() {
    int count=0, lucky=0;
    bool error= false;
        cout << "Enter how many object you want input" << endl;
        do {
            cin >> count;
            if (count > 0) {
                cin.ignore();
                person listPeople[count];
                for (int i = 0; i < count; i++) {
                    listPeople[i].enterData();
                }

                cout << endl << "Start list people" << endl;
                for (int l = 0; l < count; ++l) {
                    listPeople[l].getDataAboutPerson();
                }

                cout << endl << "List lucky people" << endl;
                for (int j = 0; j < count; j++) {
                    lucky = listPeople[j].countLuckyPerson();
                    if (lucky == 1) {
                        listPeople[j].getDataAboutPerson();
                    }
                }
            } else {
                cout << "Invalid input" << endl;
                error= true;
                cin.clear();
                cin.ignore();
            }
        } while (error);
    return 0;
}
