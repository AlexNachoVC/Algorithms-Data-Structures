#pragma once
#include "../DoublyLinkedLists/DoublyLinkedListTemplate.hpp"


template <typename T>
class HashTable {
private:
    DoublyLinkedList<T> *table;
    unsigned int size;

    unsigned int getIndex(T data);
    HashFunction hashFunction;
public:
    using HashFunction = unsigned int (*)(T&, unsigned int tableSize);

    HashTable() {
        table = nullptr;
        size = 0;
    }
    ~HashTable() { deleteTable(); };

    bool createTable(unsigned int nSize, HashFunction HashFunction);
    void deleteTable();
    bool insert(int data);
    bool remove(int data);
    T *search(T data);
    void print();

};