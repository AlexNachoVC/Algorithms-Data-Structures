#include "LinkedList.h"
#include <iostream>

using namespace std;

#define MAX_DATA 20

int main() {
    LinkedList linkedList;
    
    for (int i = 0; i < MAX_DATA; i++) {
        if(!linkedList.insertAtEnd(i)) {
            cout << "No hubo memoria\n";
            return 0;
        }
    }

    linkedList.printList();
    linkedList.insertAtBeginning(0);
    linkedList.printList();
    linkedList.deleteElement(5);
    linkedList.printList();
    linkedList.insertOnOrder(13);
    linkedList.printList();

    return 0;

}