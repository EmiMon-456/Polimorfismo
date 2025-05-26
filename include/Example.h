#ifndef EXAMPLE_H
#define EXAMPLE_H

/**
 * @file Example.h
 * @brief Declaraciones para demos de polimorfismo y templates.
 * @author Camilo Duque
 * @details Este archivo contiene las declaraciones de clases y funciones
 *          que demuestran el uso de polimorfismo, templates y sobrecarga de
 * funciones
 */

#pragma once

#include <string>

// 3.2 Interfaz abstracta
class IShape {
   public:
    virtual ~IShape() = default;
    virtual double area() const = 0;
};

// 3.2 Implementación concreta
class Circle : public IShape {
   public:
    Circle(double r);
    ~Circle();
    double area() const override;
    double getRadius() const;
    void setRadius(double r);

   private:
    double radius_;
};

// 4.1 Plantilla de clase
template <typename T>
class Box {
   public:
    Box(const T& content);
    ~Box();
    T getContent() const;
    void setContent(const T& content);

   private:
    T content_;
};

// 2.1 & 2.2 Clase con métodos sobrecargados y template de función
class Example {
   public:
    Example(int v);
    ~Example();

    // setter / getter
    void setValue(int v);
    int getValue() const;

    // 2.1 Sobrecarga de funciones
    int add(int a, int b) const;
    double add(double a, double b) const;

    // 2.2 Template de función (inline)
    template <typename T>
    static T maxValue(T a, T b) {
        return (a > b) ? a : b;
    }

   private:
    int value_;
};

#include "Example.hpp"  // definiciones de plantillas

#endif  // EXAMPLE_H
