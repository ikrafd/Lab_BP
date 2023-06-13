
#include "hash_table.h"

template<typename ValueType>
HashTable<ValueType>::Iterator::Iterator(Entry<ValueType> *entry, Entry<ValueType> *end, const HashTable<ValueType>& ht)
        : currentEntry(entry), tableEnd(end), hashTable(ht) {
}

template<typename ValueType>
Entry<ValueType> &HashTable<ValueType>::Iterator::operator*() const {
    return *currentEntry;
}

template<typename ValueType>
typename HashTable<ValueType>::Iterator &HashTable<ValueType>::Iterator::operator++() {
    ++currentEntry;
    while (currentEntry != tableEnd && currentEntry->deleted) {
        ++currentEntry;
    }
    return *this;
}

template<typename ValueType>
bool HashTable<ValueType>::Iterator::operator==(const HashTable::Iterator &other) const   {
    return currentEntry == other.currentEntry;
}

template<typename ValueType>
bool HashTable<ValueType>::Iterator::operator!=(const HashTable::Iterator &other) const   {
    return !(*this == other);
}

template<typename ValueType>
typename HashTable<ValueType>::Iterator HashTable<ValueType>::beginTable() const {
    int index = 0;
    while (index < sizeTable && table[index].deleted) {
        ++index;
    }
    return Iterator(table + index, table + sizeTable, *this);
}

template<typename ValueType>
typename HashTable<ValueType>::Iterator HashTable<ValueType>::endTable() const {
    return Iterator(table + sizeTable, table + sizeTable, *this);
}

template< typename ValueType>
HashTable<ValueType>::HashTable(int tableSize): sizeTable(tableSize)  {
    table = new Entry<ValueType>[sizeTable];
}

template< typename ValueType>
HashTable<ValueType>::~HashTable() {
    delete[] table;
}

template< typename ValueType>
int HashTable<ValueType>::getSize() {
    return sizeTable;
}

template< typename ValueType>
int HashTable<ValueType>::getOccupied() {
    return occupiedCells;
}

template<typename ValueType>
void HashTable<ValueType>::remove(const string &key) {
    int index = findIndex(key);
    if (index != -1) {
        table[index].key.clear();
        table[index].deleted = true;
        occupiedCells--;
        cout<<key<<" deleted successful"<<endl;
    }else{
        cout<<"[WARNING]: Key not found\n";
    }

}

template< typename ValueType>
void HashTable<ValueType>::insert(const string &key, const ValueType &value) {
    int index = hashFunction(key);
    while (!table[index].deleted && !table[index].key.empty()) {
            if (table[index].key == key && !table[index].deleted) {
                cout << "[WARNING]: Key already existed. Value updated\n";
                table[index].value = value;
                return ;
            }
            index = (index + 1) % sizeTable;
    }

    table[index].key = key;
    table[index].value = value;
    table[index].deleted = false;
    occupiedCells++;
}

template<typename ValueType>
int HashTable<ValueType>::hashFunction(const string& key) {
    int hashVal = 0;
    for (char ch : key)
        hashVal += ch;
    return hashVal % sizeTable;
}

template<typename ValueType>
int HashTable<ValueType>::findIndex(const string key) {
    int index = hashFunction(key);

    while (!table[index].deleted) {
        if (table[index].key == key) {
            return index;
        }
        index = (index + 1) % sizeTable;
    }
    return -1;
}

template<typename ValueType>
ValueType HashTable<ValueType>::findValue(const string key) {
    int index = hashFunction(key);

    while (!table[index].deleted) {
        if (table[index].key == key) {
            return table[index].value;
        }
        index = (index + 1) % sizeTable;
    }
    throw runtime_error("key not found");
}

template<typename ValueType>
void HashTable<ValueType>::removeAll() {
    for (Iterator it = beginTable(); it != endTable(); ++it) {
        (*it).deleted = true;
        (*it).key.clear();
    }
    occupiedCells = 0;
}

template<typename ValueType>
void HashTable<ValueType>::output() {
    Iterator its = beginTable();
    if (its != endTable()) {
        cout << left << setw(10) << "Key:" << setw(10) << "Value:" << endl;
        for ( Iterator it = beginTable(); it != endTable(); ++it) {
            cout << left << setw(10) << (*it).key << setw(10) << (*it).value << endl;
        }
    } else{
        cout<<"This table empty"<<endl;
    }
}


