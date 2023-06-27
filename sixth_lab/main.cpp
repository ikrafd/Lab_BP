#include "menu.cpp"

int main() {
    string valueType;
    int size;
    cout <<"Enter size:";
    cin >> size;
    bool Error = false;
    do {
        cout << "Enter the value type (int, string, float, char): ";
        cin >> valueType;
        if (valueType == "int") {
            menu<int>(size);
        } else if (valueType == "string") {
            menu<string>(size);
        } else if (valueType == "float") {
            menu<float>(size);
        } else if (valueType == "char") {
            menu<char>(size);
        } else {
            Error = true;
            cout << "Not correct type" << endl;
        }
    } while (Error);
    return 0;
}
