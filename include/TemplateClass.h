#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

#include <string>
#include <stdexcept>  // Para manejar excepciones

class TemplateClass {
    public:
        TemplateClass();
        ~TemplateClass();

        void dotSomething() const;

    private:
        int data_;
    };
    
#endif  // TEMPLATECLASS_H