#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

/**
 * @file Example.hpp
 * @brief Definiciones de plantillas de Box<T>.
 * @author Camilo Duque
 * @details Este archivo contiene la implementación de la clase Box, que es una
 * plantilla que permite almacenar un contenido de tipo T. Se utiliza para
 * demostrar el uso de plantillas en C++.
 */

#pragma once

template <typename T>
Box<T>::Box(const T& content) : content_(content) {
    // Constructor de Box
}

template <typename T>
Box<T>::~Box() {
    // Destructor de Box
}

template <typename T>
T Box<T>::getContent() const {
    return content_;
}

template <typename T>
void Box<T>::setContent(const T& content) {
    content_ = content;
}

#endif  // EXAMPLE_HPP
