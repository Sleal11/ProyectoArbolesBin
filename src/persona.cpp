#include "persona.hpp"
#include <string>

Persona::Persona()
: id(0), nombre(""), apellido(""), genero('H'), edad(0),
  id_padre(0), esta_muerto(false), fue_rey(false), es_rey(false),
  primogenito(nullptr), segundo(nullptr), padre(nullptr) {}

Persona::Persona(int id_,
                 const std::string& nombre_,
                 const std::string& apellido_,
                 char genero_,
                 int edad_,
                 int id_padre_,
                 bool esta_muerto_,
                 bool fue_rey_,
                 bool es_rey_)
: id(id_), nombre(nombre_), apellido(apellido_), genero(genero_), edad(edad_),
  id_padre(id_padre_), esta_muerto(esta_muerto_), fue_rey(fue_rey_), es_rey(es_rey_),
  primogenito(nullptr), segundo(nullptr), padre(nullptr) {}

std::string Persona::nombre_completo() const {
    return nombre + " " + apellido + " (id:" + std::to_string(id) + ")";
}
