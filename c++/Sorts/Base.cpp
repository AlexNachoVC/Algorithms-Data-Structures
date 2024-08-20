#include <ctime>
#include <iostream>
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

void Base::bubbleSort() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int tmp = arreglo[j + 1];
                arreglo[j + 1] = arreglo[j];
                arreglo[j] = tmp;
            }
        }
    }
}

void Base::insertionSort() {
    for (int i = 0; i < SIZE; i++) {
        int key = arreglo[i];
        int j = i - 1;

        while (j >= 0 && arreglo[j] > key ) {
            arreglo[j + 1] = arreglo[j];
            j = j + 1;
        }       
        arreglo[j + 1] = key;
    }
}

