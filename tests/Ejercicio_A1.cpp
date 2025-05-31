#include "MatrixOp.h"
#include <cassert>
#include <iostream>

using namespace std;

void test_construct(){

    cout << "Testing constructor..." << std::endl;

    // Test 1: creación de una matriz con dimensiones válidas
    // Verifica que la matriz se crea correctamente con las dimensiones dadas
    MatrixOp mat(3, 4);
    assert(mat.getRows() == 3 && mat.getCols() == 4);
    cout << "Test 1 passed." << std::endl;

    // Test 2 set y get
    mat.set(0, 0, 1.0);
    assert(mat.get(0, 0) == 1.0);
    cout << "Test 2 passed." << std::endl;

    //test 3:
    try {
        mat.set(3, 4, 5.0); // Intentar acceder a una posición fuera de los límites
        assert(false); // Si no se lanza una excepción, falla el test
    } catch (const std::out_of_range& e) {
        cout << "Test 3 passed: " << e.what() << std::endl; // Se espera una excepción
    }
}

void test_destroy(){
    cout << "Pruebas de destructor..." << std::endl;
    MatrixOp* mat = new MatrixOp(10, 10);
    delete mat; // Verifica que no se produzcan fugas de memoria al destruir la matriz
    cout << "Test destroy passed." << std::endl;
}

int main(){
    test_construct();
    test_destroy();
    cout << "Todos los tests pasaron correctamente." << std::endl;
    return 0; // Indica que el programa terminó correctamente
}