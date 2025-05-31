/**
 * @file main.cpp
 * @brief Punto de entrada del programa.
 * @date YYYY-MM-DD
 */

#include <iostream>
#include "MatrixOp.h"
#include "TemplateClass.h"
using namespace std;

double sub(double a, double b) {
    return a - b;  // Función de resta
}

double mul(double a, double b) {
    return a * b;  // Función de multiplicación
}

double add(double a, double b) {
    return a + b;  // Función de suma
}

double div(double a, double b) {
    if (b == 0) throw std::invalid_argument("División por cero no permitida.");
    return a / b;  // Función de división
}

int main() {
    MatrixOp M(3, 3);
    for (int i = 0; i < M.getRows(); ++i) {
        for (int j = 0; j < M.getCols(); ++j) {
            M.set(i, j,
                  i * M.getCols() + j + 1.0);  // Asignar valores a la matriz
        }
    }

    // Mostrar la matriz
    std::cout << "Matriz M:" << std::endl;
    for (int i = 0; i < M.getRows(); ++i) {
        for (int j = 0; j < M.getCols(); ++j) {
            std::cout << M.get(i, j) << " ";  // Imprimir cada elemento
        }
        std::cout << std::endl;  // Nueva línea al final de cada fila
    }
    // Mostrar el número de filas y columnas
    std::cout << "Número de filas: " << M.getRows() << std::endl;
    std::cout << "Número de columnas: " << M.getCols() << std::endl;
    return 0;  // Indicar que el programa terminó correctamente

    MatrixOp a(2,2), b(2,2), c(2,2), d(2,2);
    a.set(1.0, 0.0, 1.0); b.set(0.0, 1.0, 2.0);
    a.set(0.0, 1.0, 3.0); b.set(0.0, 3.0, 4.0);

    a.apply(&a, &b, &c, add);  // Suma elemento a elemento
    a.apply(&a, &b, &d, sub);  // Resta elemento a elemento
    a.apply(&a, &b, &c, mul);  // Multiplicación elemento a elemento
    a.apply(&a, &b, &d, div);  // División elemento a elemento

    // Imprimir resultados
    cout << "Matriz C - Resta: " << std::endl;
    c.printAt(0, 0); c.printAt(0, 1);
    c.printAt(1, 0); c.printAt(1, 1);

    cout << "Matriz D - División: " << std::endl;
    d.printAt(0, 0); d.printAt(0, 1);
    d.printAt(1, 0); d.printAt(1, 1);

    cout << "Matriz C - Suma: " << std::endl;
    c.printAt(0, 0); c.printAt(0, 1);
    c.printAt(1, 0); c.printAt(1, 1);

    cout << "Matriz D - Multiplicación: " << std::endl;
    d.printAt(0, 0); d.printAt(0, 1);
    d.printAt(1, 0); d.printAt(1, 1);

    MatrixOp E(3, 3);
    E.set(0.0, 0.0, 1.0); E.set(0.0, 1.0, 2.0); 
    E.set(0.0, 2.0, 3.0); E.set(1.0, 0.0, 4.0);

    cout << "Diagonal de la matriz M:" << std::endl;
    M.forEachDiagonal(&MatrixOp::printAt);  // Iterar sobre la diagonal y mostrar valores

    MatrixOp A(2,2), B(2,2);
    A.set(8.0, 0.0, 1.0); A.set(2.0, 0.0, 2.0);
    A.set(1.0, 0.0, 3.0); A.set(1.0, 3.0, 4.0);
    B.set(0.0, 4.0, 5.0); B.set(5.0, 7.0, 6.0);
    B.set(1.0, 0.0, 7.0); B.set(4.0, 6.0, 8.0);

    MatrixOp C = A + B;  // Suma de matrices
    MatrixOp D = A - B;  // Resta de matrices

    cout << "Sobrecarga de operadores:" << std::endl;
    cout << "C[0, 0] = " << C.get(0, 0) << ", C[0, 1] = " << C.get(0, 1) << std::endl;
    cout << "C[1, 0] = " << C.get(1, 0) << ", C[1, 1] = " << C.get(1, 1) << std::endl;
    cout << "D[0, 0] = " << D.get(0, 0) << ", D[0, 1] = " << D.get(0, 1) << std::endl;
    cout << "D[1, 0] = " << D.get(1, 0) << ", D[1, 1] = " << D.get(1, 1) << std::endl;

    MatrixOp E2(3, 3);
    E2.set(0.0, 0.0, 1.0); E2.set(0.0, 1.0, 2.0); E2.set(0.0, 2.0, 3.0);
    E2.set(1.0, 0.0, 4.0); E2.set(1.0, 1.0, 5.0); E2.set(1.0, 2.0, 6.0);
    E2.set(2.0, 0.0, 7.0); E2.set(2.0, 1.0, 8.0); E2.set(2.0, 2.0, 9.0);

    double maxElement = maxValue<double>(E.getData(), E.getRows() * E.getCols());
    cout << "El valor máximo en la matriz E es: " << maxElement << std::endl;

    IMatrix *mat = new MatrixOp(3, 3);

    dynamic_cast<MatrixOp*>(mat)->set(0, 0, 1.0); //Elemento en la posición (0, 0)
    dynamic_cast<MatrixOp*>(mat)->set(0, 1, 2.0); //Elemento en la posición (0, 1)
    dynamic_cast<MatrixOp*>(mat)->set(0, 2, 3.0); //Elemento en la posición (0, 2)
    dynamic_cast<MatrixOp*>(mat)->set(1, 0, 4.0); //Elemento en la posición (1, 0)
    dynamic_cast<MatrixOp*>(mat)->set(1, 1, 5.0); //Elemento en la posición (1, 1)
    dynamic_cast<MatrixOp*>(mat)->set(1, 2, 6.0); //Elemento en la posición (1, 2)
    dynamic_cast<MatrixOp*>(mat)->set(2, 0, 7.0); //Elemento en la posición (2, 0)
    dynamic_cast<MatrixOp*>(mat)->set(2, 1, 8.0); //Elemento en la posición (2, 1)
    dynamic_cast<MatrixOp*>(mat)->set(2, 2, 9.0); //Elemento en la posición (2, 2)

    cout << "Determinante de la matriz: " << mat->determinant() << std :: endl;
    return 0;  // Indicar que el programa terminó correctamente
}
