#include "Queue.h"
#include <iostream>

using namespace std;

Node::Node(int value) {
    Data = value;
    next = nullptr;
}

Queue::Queue() {
    head = nullptr;
    tail = nullptr;
}

Queue::~Queue() {
    while (head) {
        deque();
    }
}

bool Queue::enqueue(int value) {
    Node *newNode = new (nothrow) Node(value);
    if (!newNode) {
        return false;
    }

    if (!tail) {
        tail = head = newNode;  
        return true;
    }

    tail->next = newNode;
    tail = newNode;

    return true;
}

bool Queue::deque() {
    if (!head) {
        return false;
    }

    Node *tmp = head;
    head = head->next;
    tmp->next = nullptr;
    delete tmp;

    return true;
}

int Queue::peek() {
    if (head != nullptr) {
        return head->Data;
    }
    throw runtime_error("Queue is empty");
}

void Queue::printQueue() {
    Node *curr = head;

    while (curr) {
        cout << curr->Data << " ";
        curr = curr->next;
    }
    cout << "\n";
}