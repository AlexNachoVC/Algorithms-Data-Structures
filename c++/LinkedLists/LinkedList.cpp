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
