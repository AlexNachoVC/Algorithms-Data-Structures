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
            j--;
        }       
        arreglo[j + 1] = key;
    }
}

void Base::selectionSort() {
    for (int i = 0; i < SIZE - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arreglo[j] < arreglo[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            int tmp = arreglo[minIndex];
            arreglo[minIndex] = arreglo[i];
            arreglo[i] = tmp;
        }
    }
}