#include "Base.h"

void Base::inicializar() {
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arreglo[i] = rand() % 100;
    }
};

void Base::imprimir() {
    for (int i = 0; i < SIZE; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
};