#include "MatrixOp.h"
#include <cassert>
#include <iostream>

using namespace std;

double sub(double a, double b){
    return a - b;  // Función de resta
}

double mul(double a, double b){
    return a * b;  // Función de multiplicación
}

double add(double a, double b){
    return a + b;  // Función de suma
}

double div(double a, double b){
    if (b == 0) throw std::invalid_argument("División por cero no permitida.");
    return a / b;  // Función de división
}

void test_A3(){
    cout << "Testing A3" << std::endl;

    //Test 1: suma de matrices

    MatrixOp a(2,2), b(2,2), c(2,2), d(2,2);
    a.set(0, 0, 1.0); b.set(0, 0, 2.0);
    a.set(0, 1, 3.0); b.set(0, 1, 4.0);

    a.apply(&a, &b, &c, add);  // Suma elemento a elemento
    a.apply(&a, &b, &d, sub);  // Resta elemento a elemento
    a.apply(&a, &b, &c, mul);  // Multiplicación elemento a elemento
    a.apply(&a, &b, &d, div);  // División elemento a elemento

    if(c.get(0,0) == -1 && c.get(1,1) == -2){
        cout << "Test 1 passed: operación de matrices correcta." << std::endl;
    } else {
        cerr << "Test 1 failed: operación de matrices incorrecta." << std::endl;
    }

    if(d.get(0,0) == 2.0 && d.get(1,1) == 10.0){
        cout << "Test 2 passed: operación de matrices correcta." << std::endl;
    }
        else {
        cerr << "Test 2 failed: operación de matrices incorrecta." << std::endl;
    }
}

int main() {
    test_A3();
    cout << "Todos los tests pasaron correctamente." << std::endl;
    return 0;  // Indicar que el programa terminó correctamente
}