/**
 * @file Example.cpp
 * @brief Implementación de Example y Circle.
 * @author Camilo Duque
 * @details Este archivo contiene la implementación de las clases Example y
 * Circle, que representan ejemplos de polimorfismo y templates.
 */

#include "Example.h"

#include <iostream>

// === Circle ===

Circle::Circle(double r) : radius_(r) {
    std::cout << "[Circle] Constructor, radius = " << radius_ << "\n";
}

Circle::~Circle() { std::cout << "[Circle] Destructor\n"; }

double Circle::area() const { return 3.141592653589793 * radius_ * radius_; }

double Circle::getRadius() const { return radius_; }

void Circle::setRadius(double r) { radius_ = r; }

// === Example ===

Example::Example(int v) : value_(v) {
    std::cout << "[Example] Constructor, value = " << value_ << "\n";
}

Example::~Example() { std::cout << "[Example] Destructor\n"; }

void Example::setValue(int v) { value_ = v; }

int Example::getValue() const { return value_; }

int Example::add(int a, int b) const { return a + b; }

double Example::add(double a, double b) const { return a + b; }
