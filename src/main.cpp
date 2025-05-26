/**
 * @file main.cpp
 * @brief Punto de entrada para demo de sobrecarga, templates y polimorfismo.
 * @author Camilo Duque
 * @details Este archivo contiene el punto de entrada principal del programa,
 *          donde se demuestran las características de sobrecarga de funciones,
 *          plantillas de funciones y clases, así como el uso de interfaces
 *          abstractas y clases concretas.
 */

#include <iostream>

#include "Example.h"

int main() {
    std::cout << "\n=== Demo Sobrecarga (2.1) ===\n";
    Example ex(5);
    std::cout << "add(int): 2 + 3 = " << ex.add(2, 3) << "\n";
    std::cout << "add(double): 2.5 + 3.7 = " << ex.add(2.5, 3.7) << "\n";

    std::cout << "\n=== Demo Template Función (2.2) ===\n";
    std::cout << "maxValue<int>(4,7) = " << Example::maxValue<int>(4, 7)
              << "\n";
    std::cout << "maxValue<string>(\"foo\",\"bar\") = "
              << Example::maxValue<std::string>("foo", "bar") << "\n";

    std::cout << "\n=== Demo Clase Abstracta e Interface (3.2) ===\n";
    IShape* shape = new Circle(3.0);
    std::cout << "Circle radius = " << static_cast<Circle*>(shape)->getRadius()
              << "\n";
    std::cout << "Circle area   = " << shape->area() << "\n";
    delete shape;

    std::cout << "\n=== Demo Plantilla de Clase (4.1) ===\n";
    Box<int> intBox(123);
    std::cout << "Box<int> holds = " << intBox.getContent() << "\n";
    intBox.setContent(456);
    std::cout << "Box<int> now  = " << intBox.getContent() << "\n";

    return 0;
}
