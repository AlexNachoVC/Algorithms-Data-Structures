#include "HashTable.h"

using namespace std;

bool HashTable::createTable(unsigned int nSize) {
    if (nSize == 0 || table) {
        return false;
    }

    table = new(nothrow) DoublyLinkedList<int>[nSize];

    if (!table) {
        return false;
    }
    size = nSize;
    return true;
}

void HashTable::deleteTable() {
    if (table) {
        delete [] table;
        table = nullptr;
        size = 0;
    }
}

unsigned int HashTable::hashX(int data) {
    string name;
    unsigned int hashValue = 0, len = 0;

    name = "name"; //dato.getName(). switch this to the corresponding X data type;
    len = name.length();

    for (unsigned int l = 0; l < len; l++) {
        hashValue = hashValue + name[l];
    }
    return hashValue % size;
}

unsigned int HashTable::hashToIndex(int hash) {
    int hashIndex = 0;
    return (hashIndex = hash % size);
}

bool HashTable::insert(int data) {
    unsigned int index = 0;

    if (!table) {
        return false;
    }

    index = hashToIndex(data);
    return table[index].append(data);
}

bool HashTable::remove(int data) {
    return true;
}

int *HashTable::search(string name) {
    unsigned int index = 0;

    if (!table) {
        return nullptr;
    }

    index = hashX(data);
    return table[index].search(info);
}