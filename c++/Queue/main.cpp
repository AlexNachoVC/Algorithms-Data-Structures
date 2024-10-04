#include "Queue.hpp"

#include <iostream>

using namespace std;

int main() {
    Queue<int> q;
    
    for (int i = 0; i < 10; i++) {
        q.enqueue(i);
    }
    q.printQueue();
    q.deque();
    q.printQueue();
    q.enqueue(10);
    q.printQueue();
    cout << q.peek() << endl;

    return 0;
}