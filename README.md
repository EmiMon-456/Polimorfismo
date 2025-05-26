# Polimorfismo en C++: Definiciones y Casos de Uso Esenciales

## 1. ¿Qué es el polimorfismo?
- El **polimorfismo** (del griego “muchas formas”) permite que **el mismo nombre de función** o **el mismo tipo** opere de maneras distintas según el contexto.
- En C++ se manifiesta principalmente en dos formas:
  1. **Polimorfismo en tiempo de compilación** (compile-time)  
     - Sobrecarga de funciones  
     - Plantillas (templates)  
  2. **Polimorfismo en tiempo de ejecución** (run-time)  
     - Herencia + funciones virtuales  

---

## 2. Polimorfismo en tiempo de compilación

### 2.1. Sobrecarga de funciones
Múltiples funciones con el mismo nombre pero distinta **firma**:
```cpp
int suma(int a, int b) { return a + b; }
double suma(double a, double b) { return a + b; }

suma(1, 2);      // invoca la versión int
suma(1.5, 2.3);  // invoca la versión double
```
**Uso**: APIs limpias para operaciones similares en diferentes tipos.

### 2.2. Plantillas (Templates)
Código genérico para cualquier tipo:
```cpp
template<typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}

maximo(3, 7);       // deduce int
maximo(2.5, 1.2);   // deduce double
```
**Uso**: contenedores genéricos (`std::vector<T>`), algoritmos (`std::sort`).

---

## 3. Polimorfismo en tiempo de ejecución

### 3.1. Herencia y funciones virtuales
Llamadas dinámicas según el **tipo real** del objeto:
```cpp
struct Animal {
    virtual void hablar() const { std::cout << "Animal genérico\n"; }
    virtual ~Animal() = default;
};

struct Perro : Animal {
    void hablar() const override { std::cout << "Guau!\n"; }
};

Animal* a = new Perro();
a->hablar();  // imprime "Guau!"
delete a;
```
- `virtual` habilita vtable.
- `override` garantiza sobreescritura.
- Destructor virtual evita fugas.

**Uso**: frameworks, plugins e interfaces.

### 3.2. Clases abstractas e interfaces
Contratos obligatorios:
```cpp
struct IShape {
    virtual double area() const = 0;
    virtual ~IShape() = default;
};

struct Circulo : IShape {
    Circulo(double r) : radio(r) {}
    double area() const override { return 3.1416 * radio * radio; }
private:
    double radio;
};
```
**Uso**: arquitecturas basadas en contrato, inyección de dependencias.

---

## 4. Otros patrones polimórficos

### 4.1. Polimorfismo paramétrico con plantillas de clase
```cpp
template<typename T>
class Caja {
    T valor;
public:
    Caja(T v): valor(v) {}
    T get() const { return valor; }
};
```
**Uso**: clases genéricas (`Caja<int>`, `Caja<std::string>`).

### 4.2. Operadores sobrecargados
```cpp
struct Punto {
    int x, y;
    Punto operator+(const Punto& o) const {
        return {x + o.x, y + o.y};
    }
};
```
**Uso**: sintaxis intuitiva para tipos propios (`p1 + p2`).

---

## 5. Buenas prácticas y consejos
1. Marca siempre los métodos sobreescritos con `override`.  
2. Declara destructores de base como `virtual` si hay herencia.  
3. Evita el **slicing**: usa punteros o referencias.  
4. Prefiere polimorfismo en compile-time (templates) si no requieres flexibilidad en run-time.  
5. Documenta claramente tus interfaces y contratos.


## Ejemplo de Polimorfismo y Templates en C++

En este proyecto encontrarás un ejemplo completo que ilustra varios conceptos clave de C++ orientado a objetos y plantillas genéricas. Al final de este README se describe cada demo y cómo puedes ejecutarlo.

### Conceptos demostrados

1. **Sobrecarga de funciones (2.1)**  
   - La clase `Example` implementa dos versiones de `add()`, una que opera sobre enteros y otra sobre dobles.  
   - Permite verificar cómo el compilador selecciona la función adecuada según el tipo de los argumentos.

2. **Plantilla de función (2.2)**  
   - El método estático `Example::maxValue<T>()` muestra un ejemplo de función plantilla que calcula el máximo de dos valores de cualquier tipo.  
   - Se ejemplifica su uso con `int` y `std::string`.

3. **Clases abstractas e interfaces (3.2)**  
   - La interfaz `IShape` define un método puro `area()`.  
   - La clase `Circle` implementa `IShape`, demostrando herencia y polimorfismo en tiempo de ejecución.  
   - Se muestra la llamada dinámica a `area()` y el uso de constructores/destructores con mensajes en consola.

4. **Plantilla de clase (4.1)**  
   - La clase genérica `Box<T>` encapsula un valor de tipo `T`, con sus métodos `getContent()` y `setContent()`.  
   - Se prueba con `Box<int>` mostrando la manipulación de contenido a través de getters y setters.

5. **Uso de constructores, destructores, getters y setters**  
   - Cada clase (`Example`, `Circle`, `Box<T>`) imprime un mensaje en su constructor y destructor para visualizar el ciclo de vida de los objetos.  
   - `Circle` y `Box<T>` incluyen getters y setters para sus atributos privados, enfatizando buenas prácticas de encapsulación.


