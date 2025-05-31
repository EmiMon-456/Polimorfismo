#include "MatrixOp.h"
#include <cassert>
#include <iostream>

using namespace std;

void B1_Test(){
    cout << "Testing B1" << std::endl;

    MatrixOp C(2,2), D(2,2);
    C.set(0, 0, 1.0); C.set(0, 1, 2.0);
    C.set(1, 0, 3.0); C.set(1, 1, 4.0);
    D.set(0, 0, 5.0); D.set(0, 1, 6.0);
    D.set(1, 0, 7.0); D.set(1, 1, 8.0);

    MatrixOp A = C + D;  // Suma de matrices
    MatrixOp B = C - D;  // Resta de matrices

    // Verificar resultados de la operación
    assert(A.get(0, 0) == 6.0 && A.get(0, 1) == 8.0);
    assert(A.get(1, 0) == 10.0 && A.get(1, 1) == 12.0);
    assert(B.get(0, 0) == -4.0 && B.get(0, 1) == -4.0);
    assert(B.get(1, 0) == -4.0 && B.get(1, 1) == -4.0);

    cout << "Test B1 passed: Operaciones de matrices realizadas correctamente." << std::endl;

    //Dimensiones incompatibles de las matrices
    try{
        MatrixOp F(2,3);
        MatrixOp G = A + F;
        assert(false); // Si no se lanza una excepción, falla el test
    }
    catch (const std::invalid_argument& e) {
        cout << "Test B1 passed: " << e.what() << " Argumentos inválidos" << std::endl; // Se espera una excepción
    }
}

int main() {
    B1_Test();
    cout << "Todos los tests pasaron correctamente." << std::endl;
    return 0;  // Indicar que el programa terminó correctamente
}