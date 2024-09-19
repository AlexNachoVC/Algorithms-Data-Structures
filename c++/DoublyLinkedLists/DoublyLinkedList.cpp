#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

Node::Node(int data) {
    this->data = data;
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
    Node *newNode = new(nothrow) Node(value);
    if (!newNode) {
        return false;
    }

    if (!head) {
        head = newNode;
        return true;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return true;
}

bool DoublyLinkedList::append(int value) {
    Node *newNode = new(nothrow) Node(value);
    if (!newNode) {
        return false;
    }

    if (!tail) {
        tail = newNode;
        return true;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    return true;
}

bool DoublyLinkedList::insertAt(int value, int position) {
    if (position < 1) {
        return false;
    }

    if (position == 1) {
        prepend(value);
        return true;
    }

    Node *newNode = new(nothrow) Node(value);
    if (!newNode) {
        return false;
    }

    Node *tmp = head;

    for (int i = 1; tmp != nullptr && i < position - 1; i++) {
        tmp = tmp->next;
    }

    if (tmp == nullptr) {
        return false;
    }

    newNode->next = tmp->next;
    newNode->prev = tmp;
    if (tmp->next != nullptr) {
        tmp->next->prev = newNode;
    }
    tmp->next = newNode;
    return true;
}

bool DoublyLinkedList::insertOnOrder(int value) {
    Node *newNode = nullptr;
    newNode = new (nothrow) Node(value);

    if (!newNode) {
        return false;
    }

    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        return true;
    }

    if (value < head->data) {
        newNode->next = head;
        head = newNode;
        return true;
    }

    Node *current = head;
    while (current->next && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return true;
}

