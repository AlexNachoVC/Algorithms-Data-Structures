#pragma once

using namespace std;

class Base {
private:
    int *arreglo;
    int size;
    void merge(int left, int mid, int right);
    void mergeSort(int left, int right);
    int partition(int start, int end);
    void quickSort(int start, int end);

public:
    Base();
    ~Base();
    void setSize(int newSize);
    void inicializar();
    void imprimir();
    
    //O(n^2)
    void bubbleSort();

    //O(n^2)
    void insertionSort();

    //O(n^2)
    void selectionSort();

    //O(n log(n))
    void mergeSortExecute();

    void quickSortExecute();

    
};
