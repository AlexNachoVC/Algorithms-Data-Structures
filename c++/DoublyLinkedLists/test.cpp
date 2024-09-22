#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

#define MAX_DATA 20

int main() {
    DoublyLinkedList DLL;

    for (int i = 0; i < MAX_DATA; i++) {
        if(!DLL.append(i)) {
            cout << "No hubo memoria\n";
            return 0;
        }
    }

    DLL.printListForwards();
    DLL.append(21);
    DLL.printListForwards();
    DLL.prepend(0);
    DLL.printListForwards();
    DLL.insertAt(100, 10);
    DLL.printListForwards();
    DLL.insertOnOrder(5);
    DLL.printListForwards();
    DLL.deleteElement(100);
    DLL.printListForwards();
    DLL.deleteAtBeginning();
    DLL.printListForwards();
    DLL.deleteAtEnd();
    DLL.printListForwards();
    DLL.deleteAt(5);
    DLL.printListForwards();
    DLL.printListBackwards();
    DLL.deleteLinkedList();
    DLL.printListForwards();

    return 0;
}