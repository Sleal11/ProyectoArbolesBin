# ProyectoArbolesBin
# Mini Librería de Grafos en C++: Santiago Leal

Este proyecto implementa una **mini librería de grafos en C++** utilizando listas de adyacencia, cumpliendo con los requerimientos académicos:

* Implementación simple y clara.
* Archivos separados: `.hpp`, `.cpp`, `main.cpp`.
* Lectura desde un archivo `.csv`.
* Algoritmos incluidos:

  * BFS (Recorrido en anchura)
  * DFS (Recorrido en profundidad)
  * Dijkstra (Camino más corto)

Formato del archivo CSV

El archivo `grafos.csv` define el grafo mediante aristas.

Cada fila representa una conexión:

```
nodo_origen,nodo_destino,peso
```

Ejemplo incluido:

```
0,1,4
0,2,2
1,2,1
1,3,7
2,4,3
4,3,2
3,5,1
```

**Explicación:**

* `0,1,4` significa que existe una arista de **0 a 1** con peso **4**.
* El grafo es **no dirigido**, por lo que internamente se agrega también **1 a 0**.

---

Cómo compilar el proyecto

### **Con g++ manualmente:**

Ejecuta en la carpeta raíz del proyecto:

```
g++ -std=c++11 main.cpp src/grafo.cpp -I include -o grafos
```

Esto genera el ejecutable:

```
grafos.exe (Windows)
./grafos (Linux)
```

---

 Cómo ejecutar

Una vez compilado:

```
./grafos
```

El programa **carga automáticamente** el archivo `data/grafos.csv` y muestra:

* Recorrido BFS desde nodo 0
* Recorrido DFS desde nodo 0
* Camino más corto (Dijkstra) desde nodo 0

No requiere menú ni interacción del usuario.

---

Funciones implementadas

### **1. BFS**

Muestra los nodos por niveles desde el nodo inicial.

### **2. DFS**

Muestra el recorrido en profundidad.

### **3. Dijkstra**

Imprime la distancia mínima desde el nodo 0 hacia todos los demás.
