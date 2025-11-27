#include "reino.hpp"
#include "persona.hpp"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void mostrar_menu() {
    cout << "\n---- Menu ----\n";
    cout << "1) Cargar CSV (bin/datos.csv)\n";
    cout << "2) Mostrar linea de sucesion actual (solo vivos)\n";
    cout << "3) Marcar persona como muerta (y reasignar si es rey)\n";
    cout << "4) Forzar reasignacion de rey (p.ej por edad)\n";
    cout << "5) Editar datos de una persona (no id ni id_padre)\n";
    cout << "6) Guardar CSV (bin/datos_out.csv)\n";
    cout << "7) Mostrar debug del arbol (todos)\n";
    cout << "0) Salir\n";
    cout << "Elija opcion: ";
}

int main() {
    Reino reino;
    bool ejecutando = true;
    while (ejecutando) {
        mostrar_menu();
        int op;
        if (!(cin >> op)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (op == 1) {
            if (reino.cargar_csv("bin/datos.csv")) {
                cout << "CSV cargado y arbol construido.\n";
            } else {
                cout << "Error al cargar CSV.\n";
            }
        } else if (op == 2) {
            reino.mostrar_sucesion();
        } else if (op == 3) {
            cout << "Ingrese id a marcar muerto: ";
            int id;
            cin >> id;
            reino.marcar_muerto(id);
        } else if (op == 4) {
            reino.asignar_nuevo_rey_por_muerte_o_edad();
        } else if (op == 5) {
            cout << "Ingrese id a editar: ";
            int id;
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Persona* p = reino.buscar_por_id(id);
            if (!p) { cout << "id no encontrado.\n"; continue; }
            cout << "Nombre actual: " << p->nombre << ". Nuevo (enter para mantener): ";
            string nombre; getline(cin, nombre);
            if (nombre.empty()) nombre = p->nombre;
            cout << "Apellido actual: " << p->apellido << ". Nuevo (enter para mantener): ";
            string apellido; getline(cin, apellido);
            if (apellido.empty()) apellido = p->apellido;
            cout << "Genero actual: " << p->genero << ". Nuevo (H/M) o enter para mantener: ";
            string g; getline(cin, g);
            char genero = p->genero;
            if (!g.empty()) genero = g[0];
            cout << "Edad actual: " << p->edad << ". Nuevo (enter para mantener): ";
            string edad_s; getline(cin, edad_s);
            int edad = p->edad;
            if (!edad_s.empty()) edad = stoi(edad_s);
            cout << "Esta muerto? actual(" << p->esta_muerto << ") 0/1: ";
            string muerto_s; getline(cin, muerto_s);
            bool esta_muerto = p->esta_muerto;
            if (!muerto_s.empty()) esta_muerto = (stoi(muerto_s)!=0);
            cout << "Fue rey? actual(" << p->fue_rey << ") 0/1: ";
            string fue_s; getline(cin, fue_s);
            bool fue_rey = p->fue_rey;
            if (!fue_s.empty()) fue_rey = (stoi(fue_s)!=0);
            cout << "Set as rey? actual(" << p->es_rey << ") 0/1: ";
            string es_s; getline(cin, es_s);
            bool es_rey = p->es_rey;
            if (!es_s.empty()) es_rey = (stoi(es_s)!=0);
            if (reino.editar_persona(id, nombre, apellido, genero, edad, esta_muerto, fue_rey, es_rey)) {
                cout << "Persona editada.\n";
            } else cout << "Error al editar.\n";
        } else if (op == 6) {
            if (reino.guardar_csv("bin/datos_out.csv")) cout << "Guardado en bin/datos_out.csv\n";
            else cout << "Error al guardar.\n";
        } else if (op == 7) {
            reino.mostrar_debug();
        } else if (op == 0) {
            ejecutando = false;
        } else {
            cout << "Opcion invalida.\n";
        }
    }
    cout << "Programa terminado.\n";
    return 0;
}
//resto
