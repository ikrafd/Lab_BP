#include <functional>
#include <iostream>
#include <iomanip>
using namespace std;


template<typename ValueType>
struct Entry {
    string key;
    ValueType value;
    bool deleted;

    Entry() : deleted(true) {}
};

template<typename ValueType>
class HashTable {
    Entry <ValueType> *table;
    int sizeTable;
    int occupiedCells = 0;
public:

    class Iterator{
    private:
        const HashTable<ValueType>&hashTable;
        Entry<ValueType>* currentEntry;
        Entry<ValueType>* tableEnd;

    public:
        Iterator(Entry<ValueType>* entry, Entry<ValueType>* end, const HashTable<ValueType>& ht);

        Entry<ValueType>& operator*() const;

        Iterator& operator++();

        bool operator==(const Iterator& other) const;

        bool operator!=(const Iterator& other) const;
    };
    Iterator beginTable() const;
    Iterator endTable() const;

    HashTable(int);
    ~HashTable();
    int getSize();
    void insert(const string &key, const ValueType &value);
    void remove(const string &key);
    int hashFunction(const string&);
    int findIndex(string);
    ValueType findValue(string);
    void removeAll();
    void output();
    int getOccupied();
};
