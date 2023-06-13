#include "menu.cpp"

int main() {
    string valueType;
    int size;
    cout <<"Enter size:";
    cin >> size;
    cout << "Enter the value type: ";
    cin >> valueType;
    if (valueType=="int"){
        menu<int>(size);
    } else if (valueType=="string") {
        menu<string>(size);
    } else if (valueType == "float"){
        menu<float>(size);
    } else{
        cout<<"Not correct type"<<endl;
    }
    return 0;
}
