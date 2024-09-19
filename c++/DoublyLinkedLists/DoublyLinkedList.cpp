#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

Node::Node() {
    this->prev = nullptr;
    this->next = nullptr;
};

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {

}

bool DoublyLinkedList::prepend(int value) {
    Node *newNode = new(nothrow) Node;
    if (!newNode) {
        return false;
    }

    if (!head) {
        head = newNode;
        return true;
    }

    newNode->data = value;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return true;
}

bool DoublyLinkedList::append(int value) {
    Node *newNode = new(nothrow) Node;
    if (!newNode) {
        return false;
    }

    if (!tail) {
        tail = newNode;
        return true;
    }

    newNode->data = value;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    return true;
}