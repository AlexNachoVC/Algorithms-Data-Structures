#pragma once
#include "../DoublyLinkedLists/DoublyLinkedListTemplate.hpp"

#include <iostream>

class HashTable {
private:
    DoublyLinkedList<int> *table;
    unsigned int size;

    unsigned int hashX(int data); // Change the "X" data type to the needed one
    unsigned int hashToIndex(int hash);
public:
    HashTable() {
        table = nullptr;
        size = 0;
    }
    ~HashTable() { deleteTable(); };

    bool createTable(unsigned int nSize);
    void deleteTable();
    bool insert(int data);
    bool remove(int data);
    int *search(string name);

};