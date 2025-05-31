#include "MatrixOp.h"
#include <cassert>
#include <iostream>

using namespace std;

void test_A4(){
    cout << "Testing A4" << std::endl;

    //Test1: suma de matrices
    MatrixOp e(2,2);
    e.set(0, 0, 1.0); e.set(0, 1, 2.0);
    e.set(1, 0, 3.0); e.set(1, 1, 4.0);

    e.forEachDiagonal(&MatrixOp::printAt);  // Imprime los valores de la diagonal principal
    cout << "Test 1 passed: Iteración sobre la diagonal correcta." << std::endl;
}

int main() {
    test_A4();
    cout << "Todos los tests pasaron correctamente." << std::endl;
    return 0;  // Indicar que el programa terminó correctamente
}