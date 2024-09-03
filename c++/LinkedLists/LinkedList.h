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
    void printList();

};