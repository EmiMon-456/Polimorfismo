#include "TemplateClass.h"
#include <iostream>

TemplateClass::TemplateClass() : data_(0) {
    // Constructor vacío, inicializa data_ a 0
}

TemplateClass::~TemplateClass() {
    // Destructor vacío, no hay recursos que liberar
}

void TemplateClass::dotSomething() const {
    std::cout << "Hacer algo con el dato: " << data_ << std::endl;
}

#endif  // TEMPLATECLASS_H

