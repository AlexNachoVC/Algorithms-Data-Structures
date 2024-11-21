#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DLLNode::DLLNode(int data) {
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
};

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    deleteLinkedList();
}

bool DoublyLinkedList::prepend(int value) {
    DLLNode *newNode = new(nothrow) DLLNode(value);
    if (!newNode) {
        return false;
    }

    if (!head) {
        head = tail = newNode;
        return true;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return true;
}

bool DoublyLinkedList::append(int value) {
    DLLNode *newNode = new(nothrow) DLLNode(value);
    if (!newNode) {
        return false;
    }

    if (!tail) {
        tail = head = newNode;
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
        return prepend(value);
    }

    DLLNode *newNode = new(nothrow) DLLNode(value);
    if (!newNode) {
        return false;
    }

    DLLNode *tmp = head;

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
    DLLNode *newNode = nullptr;
    newNode = new (nothrow) DLLNode(value);

    if (!newNode) {
        return false;
    }

    newNode->next = nullptr;

    if (!head) {
        head = tail = newNode;
        return true;
    }

    if (value < head->data) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return true;
    }

    DLLNode *current = head;
    while (current->next && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next) {
        current->next->prev = newNode;
    } else {
        tail = newNode;
    }

    current->next = newNode;
    return true;
}

bool DoublyLinkedList::deleteElement(int element) {
    if (!head) {
        return false;
    }

    if (head->data == element) {
        DLLNode *tmp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete tmp;
        return true;
    }

    DLLNode *current = head;

    while (current && current->data != element) {
        current = current->next;
    }

    if (!current) {
        return false;
    }

    if (current->next) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }

    if (current->prev) {
        current->prev->next = current->next;
    }

    delete current;
    return true;
}

bool DoublyLinkedList::deleteAtBeginning() {
    if (!head) {
        return false;
    }

    DLLNode *tmp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete tmp;
    return true;
}

bool DoublyLinkedList::deleteAtEnd() {
    if (!head) {
        return false;
    }

    DLLNode *tmp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete tmp;
    return true;
}

bool DoublyLinkedList::deleteAt(int position) {
    if (!head || position < 1) {
        return false;
    }

    if (position == 1) {
        return deleteAtBeginning();
    }

    DLLNode *tmp = head;

    for (int i = 1; tmp != nullptr && i < position; i++) {
        tmp = tmp->next;
    }

    if (tmp == nullptr) {
        return false;
    }

    if (tmp->next != nullptr) {
        tmp->next->prev = tmp->prev;
    }
    if (tmp->prev != nullptr) {
        tmp->prev->next = tmp->next;
    }

    delete tmp;
    return true;
}

void DoublyLinkedList::deleteLinkedList() {
    while (head) {
        DLLNode *tmp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete tmp;
    }
    tail = nullptr;
}

void DoublyLinkedList::printListForwards() {
    if (!head) {
        return;
    }

    DLLNode *tmp = head;

    while (tmp) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}

void DoublyLinkedList::printListBackwards() {
    if (!head) {
        return;
    }

    DLLNode *tmp = tail;

    while (tmp) {
        cout << tmp->data << " ";
        tmp = tmp->prev;
    }
    cout << "\n";
}