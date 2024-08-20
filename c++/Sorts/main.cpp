#include "Base.h"
#include <iostream>

int main() {
    Base base;

    base.inicializar();
    base.imprimir();
    base.bubbleSort();
    base.imprimir();
    cout << endl;

    base.inicializar();
    base.imprimir();
    base.insertionSort();
    base.imprimir();
    cout << endl;

    base.inicializar();
    base.imprimir();
    base.selectionSort();
    base.imprimir();
    cout << endl;

    cout << base.factorial(4);
    return 0;
}