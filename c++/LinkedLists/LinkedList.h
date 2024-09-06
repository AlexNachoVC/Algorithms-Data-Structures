#pragma once 

class Node {
public: 
    int dato;
    Node *next;

    Node();
};

class LinkedList {
private:
    Node *head;
public:
    LinkedList();
    ~LinkedList();
    bool insertAtEnd(int value);
    bool insertAtBeginning(int value);
    
    void printList();
    void deleteLinkedList();
    bool deleteElement(int element);
};