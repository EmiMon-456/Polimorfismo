#ifndef MatrixOp_H
#define MatrixOp_H

/**
 * @file MatrixOp.h.h
 * @brief Definición de TemplateClass.
 * @date YYYY-MM-DD
 * @author Camilo Duque
 *
 */
#pragma once
#include <string>
class MatrixOp {
   public:
    // Constructor and Destructor
    MatrixOp(int rows, int cols);
    ~MatrixOp();
    // Método set para asignar el valor v en la posición (i, j)
    void set(int i, int j, double v);
    // Método set para asignar el valor v en la posición (i, j)
    double get(int i, int j) const;
    // Metodos para obtener el número de filas y columnas
    int getRows() const { return rows_; };
    int getCols() const { return cols_; };

   private:
    double *data_;  // Puntero a los datos de la matriz
    int rows_;      // Número de filas
    int cols_;      // Número de columnas
};

#endif  // MatrixOp_H
