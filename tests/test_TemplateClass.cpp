/**
 * @file test_TemplateClass.cpp
 * @brief Pruebas unitarias para TemplateClass.
 * @date YYYY-MM-DD
 */

#include "../include/TemplateClass.h"
#include <cassert>
#include <iostream>

int main() {
    TemplateClass obj;
    obj.doSomething();
    assert(true);
    std::cout << "Test passed" << std::endl;
    return 0;
}
