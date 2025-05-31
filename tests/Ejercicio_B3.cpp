#include "MatrixOp.h"
#include <cassert>
#include <iostream>

using namespace std;

void B3test(){
    cout << "Testing B3" << std::endl;

    //Test 1: MAtriz 2x2
    IMatrix *mat2x2 = new MatrixOp(2, 2);
    dynamic_cast<MatrixOp*>(mat2x2)->set(0, 0, 1.0);
    dynamic_cast<MatrixOp*>(mat2x2)->set(0, 1, 2.0);
    dynamic_cast<MatrixOp*>(mat2x2)->set(1, 0, 3.0);
    dynamic_cast<MatrixOp*>(mat2x2)->set(1, 1, 4.0);

    double det2x2 = mat2x2->determinant();
    assert(det2x2 == (1*4-2*3));  // Determinante de una matriz 2x2

    cout << "Test 1 passed: Determinante de matriz 2x2 correcto." << std::endl;

    delete mat2x2;  // Liberar memoria

    MatrixOp *mat3x3 = new MatrixOp(3, 3);
    mat3x3->set(0, 0, 1.0); mat3x3->set(0, 1, 2.0); mat3x3->set(0, 2, 3.0);
    mat3x3->set(1, 0, 4.0); mat3x3->set(1, 1, 5.0); mat3x3->set(1, 2, 6.0);
    mat3x3->set(2, 0, 7.0); mat3x3->set(2, 1, 8.0); mat3x3->set(2, 2, 9.0);

    double det3x3 = mat3x3->determinant();
    double expectedDet3x3 = 1*(5*9-6*8) - 2*(4*9-6*7) + 3*(4*8-5*7);

    assert(det3x3 == expectedDet3x3);  // Determinante de una matriz 3x3
    cout << "Test 2 passed: Determinante de matriz 3x3 correcto." << std::endl;

    //test 3: dimensiones incompatibles o no soportadas
    try{ 
        MatrixOp mat4x4(4, 4);
        mat4x4.determinant();  // Intentar calcular el determinante de una matriz 4x4
        assert(false);  // Si no se lanza una excepción, falla el test
    }
    catch (const std::logic_error& e) {
        cout << "Test 3 passed: " << e.what() << " Argumentos inválidos" << std::endl; // Se espera una excepción
    }
}

int main() {
    B3test();
    cout << "Todos los tests pasaron correctamente." << std::endl;
    return 0;  // Indicar que el programa terminó correctamente
}