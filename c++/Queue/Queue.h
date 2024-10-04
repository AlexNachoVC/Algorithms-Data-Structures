#pragma once

class Node {
public:
    int Data;
    Node *next;

    Node();
}; 

class Queue {
private: 
    Node *head;
    Node *tail;

public: 
    Queue();
    ~Queue();
    bool enqueue(int value);
    bool deque();
    int peek();
};