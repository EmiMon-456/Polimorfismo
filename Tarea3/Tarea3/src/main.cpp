/**
 * @file main.cpp
 * @brief Punto de entrada del programa.
 * @date YYYY-MM-DD
 */

#include <iostream>

#include "MatrixOp.h"

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
}
