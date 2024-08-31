#include "Base.h"
#include <iostream>

using namespace std;

int main() {
    int newSize, elemento, opcion(0);

    cout << "Dame el numero de datos a usar: ";
    cin >> newSize;

    Base base;
    base.setSize(newSize);

    base.inicializar();

    while (opcion != 6) {
        cout << "\nElija una opcion para el sort: ";
        cout << "\n1) Bubble Sort\n" << "2) Insertion Sort\n" << "3) Selection Sort\n" << "4) Merge Sort\n" <<  "5) Quick Sort\n"  << "7) Salir\n";
        cin >> opcion;
    
        switch (opcion) {
            case 1:
                cout << "El arreglo original es: \n";
                base.imprimir();
                base.bubbleSort();
                cout << "\nEl arreglo ordenado por Bubble Sort es:" << endl;
                break;
            case 2:
                cout << "El arreglo original es: \n";
                base.imprimir();
                base.insertionSort();
                cout << "\nEl arreglo ordenado por Insertion Sort es:" << endl;
                break;
            case 3:
                cout << "El arreglo original es: \n";
                base.imprimir();
                base.selectionSort();
                cout << "\nEl arreglo ordenado por Selection Sort es:" << endl;
                break;
            case 4:
                cout << "El arreglo original es: \n";
                base.imprimir();
                base.mergeSortExecute();
                cout << "\nEl arreglo ordenado por Merge Sort es:" << endl;
                break;
            case 5:
                cout << "El arreglo original es: \n";
                base.imprimir();
                base.quickSortExecute();
                cout << "\nEl arreglo ordenado por Quick Sort es:" << endl;
                break;    
                   
            case 7:
                cout << "\nSaliendo..." << endl;
                return 0;
            default:
                cout << "\nOpcion no valida" << endl;
                return 1;
        }
        
        base.imprimir();
    }

    return 0;
}