#include "MatrixOp.h"
#include <cassert>
#include <iostream>

using namespace std;

void B2test(){
    cout << "Testing B2" << std::endl;

    MatrixOp E(3,2);

    E.set(0, 0, 1.0); E.set(0, 1, 2.0);
    E.set(1, 0, 3.0); E.set(1, 1, 4.0);
    E.set(2, 0, 5.0); E.set(2, 1, 6.0);

    double maxElement = maxValue<double>(E.getData(), E.getSize());
    assert(maxElement == 6.0);  // Verifica que el valor máximo es 6.0

    cout << "Test B2 passed: El valor máximo en la matriz E es: " << maxElement << std::endl;

    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int maxArr = maxValue<int>(arr, 10);
    assert(maxArr == 29);  // Verifica que el valor máximo en el arreglo es 29
    cout << "Test B2 passed: El valor máximo en el arreglo es: " << maxArr << std::endl;
    
}

int main() {
    B2test();
    cout << "Todos los tests pasaron correctamente." << std::endl;
    return 0;  // Indicar que el programa terminó correctamente
}