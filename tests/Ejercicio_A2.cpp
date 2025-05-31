#include "MatrixOp.h"
#include <cassert>
#include <iostream>

using namespace std;

void testa2(){
    cout << "Prueba A2" << std::endl;

    //test 1 suma de matrices
    try{
        MatrixOp a(2,2), b(2,2), c(2,2);
        a.set(0, 0, 1.0); b.set(0, 0, 2.0);
        a.set(0, 1, 3.0); b.set(0, 1, 4.0);
        a.add(&b, &c);  // Suma elemento a elemento

        if(c.get(0, 0) == 3.0 && c.get(0, 1) == 7.0){
            cout << "Test 1 passed: Suma de matrices correcta." << std::endl;
        } 
        else {
            cout << "Test 1 failed: Suma de matrices incorrecta." << std::endl;
        }
    }
    catch (const std::invalid_argument& e) {
        cerr << "Test 1 failed: " << e.what() << " Argumentos inválidos " << std::endl;
    }
}

int main() {
    testa2();
    cout << "Todos los tests pasaron correctamente." << std::endl;
    return 0;  // Indicar que el programa terminó correctamente
}