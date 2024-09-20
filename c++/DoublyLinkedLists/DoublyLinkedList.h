#pragma once

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data);
};

class DoublyLinkedList {
private: 
    Node *head;
    Node *tail;
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