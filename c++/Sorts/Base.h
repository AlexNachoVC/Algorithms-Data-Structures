#pragma once
#include <ctime>
#include <iostream>

using namespace std;

#define SIZE 20

class Base {
private:
    int arreglo[SIZE];

public:
    void inicializar();
    void imprimir();
};
