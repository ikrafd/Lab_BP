#include "menu.h"

int chooseTask(){
    int choose = 0;
    do {
        cout << "Enter number for choose:\n"
                "1 - Get size\n"
                "2 - Enter element\n"
                "3 - Find element\n"
                "4 - Delete element\n"
                "5 - Output table\n"
                "6 - Clean table\n"
                "7 - Begin table\n"
                "8 - End table\n"
                "9 - For end" << endl;
        cin >> choose;
    } while (1>choose | choose>9);
    return choose;
}


template <typename valueType>
void menu(int size){
    int choose;
    valueType value;
    string key;
    char enter;
    HashTable <valueType> table(size);
    do {
        choose = chooseTask();
        switch (choose) {
            case 1:
                cout << "Table size: " << table.getSize() << endl << "Fill: "<<table.getOccupied()<< endl;
                break;
            case 2:
                enter = 'y';
                do {
                    if (enter=='y') {
                        if (table.getOccupied()<table.getSize()) {
                            cout << "Enter key and value:";
                            cin >> key >> value;
                            table.insert(key, value);
                            cout << "Do you want add more? y/n"<<endl;
                            cin >> enter;
                        }else{
                            cout<<"Can`t add more"<<endl;
                            enter = 'n';
                        }
                    } else if (enter!='n'){
                        cout<<"Not correct choose"<<endl;
                    }
                } while (enter!='n');
                break;
            case 3:
                cout << "Enter key:";
                cin >> key;
                try {
                    cout << "Find value:" << table.findValue(key) << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 4:
                cout << "Enter key:";
                cin >> key;
                table.remove(key);
                break;
            case 5:
                cout<<"Hash table"<<endl;
                table.output();
                break;
            case 6:
                table.removeAll();
                cout<<"All data clear"<<endl;
                break;
            case 7:
                table.outputBegin();
                break;
            case 8:
                table.outputEnd();
                break;
        }
    } while (choose!=9);
}
