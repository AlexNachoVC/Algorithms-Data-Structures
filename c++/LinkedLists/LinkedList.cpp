#include "LinkedList.h"
#include <iostream>

using namespace std;

Node::Node() {
    next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {   
    deleteLinkedList();
}

bool LinkedList::insertAtEnd(int value) {
    Node *tmp = nullptr, *newNode = nullptr;
    newNode = new (nothrow) Node;

    if (!newNode) {
        return false;
    }

    newNode->dato = value;
    if (!head) {
        head = newNode;
        return true;
    }

    tmp = head;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    return true;
}

void LinkedList::printList() {
    Node *tmp = head;

    while (tmp) {
        cout << tmp->dato << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}

