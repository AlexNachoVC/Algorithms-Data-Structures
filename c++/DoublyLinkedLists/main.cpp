#include "DoublyLinkedListTemplate.hpp"
#include <iostream>

using namespace std;

int main() {
    DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.prepend(0);
    list.printListForwards();
    list.printListBackwards();
    return 0;
}