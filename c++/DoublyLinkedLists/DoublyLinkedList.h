#pragma once

class DLLNode {
public:
    int data;
    DLLNode *prev;
    DLLNode *next;

    DLLNode(int data);
};

class DoublyLinkedList {
private: 
    DLLNode *head;
    DLLNode *tail;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    bool prepend(int value);
    bool append(int value);
    bool insertAt(int value, int position);
    bool insertOnOrder(int value);
    bool deleteElement(int element); 
    bool deleteAtBeginning();
    bool deleteAtEnd();
    bool deleteAt(int position);
    void deleteLinkedList();
    void printListForwards();
    void printListBackwards();
};