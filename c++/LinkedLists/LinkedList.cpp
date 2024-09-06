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

void LinkedList::deleteLinkedList() {
    if (!head) {
        return;
    }
    while (head) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

bool LinkedList::deleteElement(int element) {
    if (!head) {
        return false;
    }

    if (head->dato == element) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }

    Node *current = head;
    Node *previous = nullptr;

    while (current && current->dato != element) {
        previous = current;
        current = current->next;
    }

    if (!current) {
        return false;
    }

    previous->next = current->next;
    delete current;
    return true;

}