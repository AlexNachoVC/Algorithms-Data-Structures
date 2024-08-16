#pragma once

using namespace std;

#define SIZE 20

class Base {
private:
    int arreglo[SIZE];

public:
    void inicializar();
    void imprimir();
    void bubbleSort();
    void insertionSort();
};
