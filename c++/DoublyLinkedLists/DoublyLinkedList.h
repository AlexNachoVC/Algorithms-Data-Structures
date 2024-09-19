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
    bool deleteElement(int value); 
    bool deleteAtBeginning(int value);
    bool deleteAtEnd(int value);
    bool deleteAt(int value, int position);
    void deleteLinkedList();
    void printList();
};