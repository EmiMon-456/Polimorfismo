/**
 * @file TemplateClass.cpp
 * @brief Implementación de TemplateClass.
 * @date YYYY-MM-DD
 * @author Camilo Duque
 *
 */

#include "MatrixOp.h"
#include <iostream>
using namespace std;


//Constructor
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

//Destructor
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

//Suma de matrices
void MatrixOp::add(const MatrixOp *other, MatrixOp *result) const {
    if(other->cols_ == this->cols_ && other->rows_ == this->rows_) {
        for(int k = 0; k < rows_; k++) {
            result->data_[k] = this->data_[k] + other->data_[k];
        }
    }
    else {
        throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para la suma.");
    }
}

//Aplicar función anónima
void MatrixOp::apply(const MatrixOp* A, const MatrixOp* B, MatrixOp* out, OpFunc op) const {
    for(int k = 0; k < rows_ * cols_; k++){
        out->data_[k] = op(A->data_[k], B->data_[k]);
    }
}

//Recibe la función miembro y la aplica a cada elemento de la diagonal
void MatrixOp::forEachDiagonal(void (MatrixOp::*fn)(int i, int j) const) const {
    for (int i = 0; i < min(rows_, cols_); i++) {
        (this->*fn)(i, i);  // Llama a la función miembro con los índices de la diagonal
    }
}

//Muestra el valor en la posición (i, j)
void MatrixOp::printAt(int i, int j) const{
    cout << get(i,j) << std :: endl;
}

MatrixOp MatrixOp::operator+(const MatrixOp &other) const {
    if(other.rows_ == this->rows_ && other.cols_ == this->cols_){
        MatrixOp result(rows_,cols_);
        for (int k = 0; k <rows_ * cols_; k++) {
            result.data_[k] = this->data_[k] + other.data_[k];
        }
        return result;
    }
    throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para la suma.");
    
}

MatrixOp MatrixOp::operator-(const MatrixOp &other) const {
    if(other.rows_ == this->rows_ && other.cols_ == this->cols_){
        MatrixOp result(rows_,cols_);
        for (int k = 0; k <rows_ * cols_; k++) {
            result.data_[k] = this->data_[k] - other.data_[k];
        }
        return result;
    }
    throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para la resta.");
}

double MatrixOp::determinant() const {
    if (this->rows_ == 2 && this->cols_ == 2) {
        //Determinante de una matriz 2x2
        return get(0,0)*get(1,1) - get(0,1)*get(1,0);
    }
    else if(this->rows_ == 3 && this->cols_ == 3) {
        //Determinante de una matriz 3x3
        double a = get(0, 0), b = get(0, 1), c = get(0, 2);
        double d = get(1, 0), e = get(1, 1), f = get(1, 2);
        double g = get(2, 0), h = get(2, 1), i = get(2, 2);
        return a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h;
    }
    else {
        throw std::logic_error("Únicamente se soportan matrices 2x2 y 3x3 para el cálculo del determinante.");
    }
}