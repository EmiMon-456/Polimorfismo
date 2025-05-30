/**
 * @file TemplateClass.cpp
 * @brief Implementación de TemplateClass.
 * @date YYYY-MM-DD
 * @author Camilo Duque
 *
 */

#include "MatrixOp.h"

#include <iostream>

MatrixOp::MatrixOp(int rows, int cols)
    : rows_(rows), cols_(cols), data_(nullptr) {
    if (rows_ <= 0 || cols_ <= 0) {
        throw std::invalid_argument(
            "Rows and columns must be positive integers.");
    }
    data_ = new double[rows_ * cols_];
    for (int i = 0; i < rows_ * cols_; ++i) {
        data_[i] = 0.0;  // Initialize all elements to zero
    }
}
MatrixOp::~MatrixOp() {
    delete[] data_;   // Free allocated memory
    data_ = nullptr;  // Avoid dangling pointer
}

// Setter
void MatrixOp::set(int i, int j, double v) {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_)
        throw std::out_of_range("Index out of range.");
    data_[i * cols_ + j] = v;
}
// Getter
double MatrixOp::get(int i, int j) const {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_)
        throw std::out_of_range("Index out of range.");
    return data_[i * cols_ + j];
}
