#include <ctime>
#include <iostream>
#include "Base.h"

// Constructor para asignar memoria para el arreglo en el heap
Base::Base() : arreglo(nullptr), size(0) {}

// Destructor para liberar memoria
Base::~Base() {
    if (arreglo != nullptr) {
        delete[] arreglo;
        arreglo = nullptr;
    }
}

void Base::setSize(int newSize) {
    if (arreglo != nullptr) {
        delete[] arreglo;
        arreglo = nullptr;
    }
    size = newSize;
    arreglo = new (nothrow) int[size];
    if (arreglo == nullptr) {
        cerr << "Error: No se pudo asignar memoria para el arreglo." << endl;
        size = 0;
    }
}

void Base::inicializar() {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arreglo[i] = rand() % 100;
    }
};

void Base::imprimir() {
    for (int i = 0; i < size; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
};

void Base::bubbleSort() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int tmp = arreglo[j + 1];
                arreglo[j + 1] = arreglo[j];
                arreglo[j] = tmp;
            }
        }
    }
}

void Base::insertionSort() {
    for (int i = 0; i < size; i++) {
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
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
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

void Base::merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    
    for (int i = 0; i < n1; i++)
        leftArray[i] = arreglo[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arreglo[mid + 1 + j];

    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arreglo[k] = leftArray[i];
            i++;
        } else {
            arreglo[k] = rightArray[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        arreglo[k] = leftArray[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arreglo[k] = rightArray[j];
        j++;
        k++;
    }

    
    delete[] leftArray;
    delete[] rightArray;
}

void Base::mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }
}

void Base::mergeSortExecute() {
    mergeSort(0, size - 1);
}
