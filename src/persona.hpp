#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <string>

struct Persona {
    int id;
    std::string nombre;
    std::string apellido;
    char genero; // 'H' o 'M'
    int edad;
    int id_padre;
    bool esta_muerto;
    bool fue_rey;
    bool es_rey;

    // árbol binario de descendencia (máx 2 hijos)
    Persona* primogenito; // hijo izquierdo
    Persona* segundo;     // hijo derecho
    Persona* padre;

    Persona();
    Persona(int id_,
            const std::string& nombre_,
            const std::string& apellido_,
            char genero_,
            int edad_,
            int id_padre_,
            bool esta_muerto_,
            bool fue_rey_,
            bool es_rey_);
    std::string nombre_completo() const;
};

#endif
