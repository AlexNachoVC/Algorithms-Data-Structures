#include "Base.h"
#include <iostream>

int main() {
    Base base;
    Base base2;
    Base base3;

    base.inicializar();
    base.imprimir();
    base.bubbleSort();
    base.imprimir();
    cout << endl;

    base2.inicializar();
    base2.imprimir();
    base2.insertionSort();
    base2.imprimir();
    cout << endl;

    base3.inicializar();
    base3.imprimir();
    base3.selectionSort();
    base3.imprimir();
    cout << endl;

    return 0;
}