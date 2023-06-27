#include "menu.cpp"

int main() {
    string valueType, keyType;
    int size;
    cout <<"Enter size:";
    cin >> size;
    cout << "Enter the key type: ";
    cin >> keyType;
    cout << "Enter the value type: ";
    cin >> valueType;
    if (keyType=="int"&&valueType=="int"){
        menu<int>(size);
    } else if (valueType=="string") {
        menu<string>(size);
    } else if (valueType == "float"){
        menu<float>(size);
    } else if (valueType == "char"){
        menu<float>(size);
    }else{
        cout<<"Not correct type"<<endl;
    }
    return 0;
}
