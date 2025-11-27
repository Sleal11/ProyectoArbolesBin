#include "persona.hpp"
#include <string>
#include <unordered_map>
#include <list>

class Reino {
public:
    Reino();
    ~Reino();

    bool cargar_csv(const std::string& ruta);
    bool guardar_csv(const std::string& ruta);

    void construir_arbol(); // conectar padres e hijos
    void mostrar_debug() const;

    void mostrar_sucesion() const; // mostrar linea de sucesion actual (solo vivos)
    void asignar_nuevo_rey_por_muerte_o_edad(); // reasigna si rey muerto o >=70

    Persona* buscar_por_id(int id) const;
    Persona* obtener_rey_actual() const;

    bool editar_persona(int id, const std::string& nombre, const std::string& apellido,
                        char genero, int edad, bool esta_muerto, bool fue_rey, bool es_rey);

    void marcar_muerto(int id);

private:
    std::unordered_map<int, Persona*> personas; // id -> Persona*
    Persona* ancestro; // primer rey (ancestro)
    Persona* rey_actual;

    void limpiar();
    void eliminar_todo();

    // generar lista de candidatos por primogenitura (pref L then R) desde un nodo
    void recolectar_primogenitura(Persona* nodo, std::list<Persona*>& salida) const;

    // filtra segun reglas (varones <70 preferidos, fallback a mujer>15 más joven)
    Persona* elegir_sucesor_desde_lista(const std::list<Persona*>& candidatos) const;

    // distancia/closer to primogenito branch used for tie-break female
    std::string ruta_rama(Persona* p) const;

    static std::list<std::string> split_csv_line(const std::string& linea);
    void actualizar_rey_actual();
};

#endif
