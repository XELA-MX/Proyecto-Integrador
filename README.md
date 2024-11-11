# Proyecto: Simulador de draft de la NBA

Este proyecto simula un draft de la NBA, ofreciendo una experiencia interactiva donde los usuarios pueden participar en la selección de jugadores para diferentes equipos de la liga. El sistema utiliza una estructura de datos de lista doblemente enlazada para almacenar y manipular eficientemente la información de los jugadores, permitiendo un acceso rápido y flexible a los datos en ambas direcciones.

El proyecto implementa el algoritmo Quicksort para ordenar a los jugadores según diferentes criterios estadísticos, como puntos por juego (PPG), calificación defensiva y porcentaje de tiros de tres puntos. Esta implementación permite una clasificación rápida y eficiente de los jugadores, crucial para el proceso de selección durante el draft.

Además, el sistema incorpora características avanzadas como:

1. Lectura y escritura de archivos para manejar datos de jugadores y equipos.
2. Selección aleatoria de equipos y generación de recomendaciones estratégicas.
3. Interfaz de usuario interactiva que permite a los participantes tomar decisiones informadas durante el draft.
4. Simulación realista del proceso de draft, incluyendo selecciones automáticas para equipos controlados por la computadora.
   
Este proyecto no solo simula el  proceso de un draft de la NBA, sino que también demuestra la aplicación práctica de estructuras de datos avanzadas y algoritmos de ordenamiento en un contexto deportivo real.

## Descripción del avance 1

En este avance, se ha implementado la estructura básica del simulador de draft, incluyendo:
* Lectura de datos de jugadores desde un archivo
* Implementación de una lista doblemente enlazada para almacenar jugadores
* Algoritmo Quicksort para ordenar jugadores por diferentes estadísticas
* Simulación básica del proceso de draft

## Descripción del avance 2
En este avance, se han realizado las siguientes mejoras:
* Implementación de la función para imprimir la lista en orden original, preorder e inorder en un archivo de texto
* Adición de comentarios sobre la complejidad y tiempo de ejecución de cada función
* Modificación de la función destructor para guardar los resultados en archivos de texto.

## Cambios sobre el primer avance
- [x] Adición de nuevas funciones: Se agregaron las funciones ImprimirOrdenLista, PreOrder e InOrder para imprimir la lista en diferentes órdenes. Esto mejora la visualización de los resultados del draft.
- [x] Mejora en la documentación: Se añadieron comentarios sobre la complejidad temporal de cada función, lo que facilita el análisis del rendimiento del programa.
- [x] Ampliación de la funcionalidad de guardado: Se modificó el destructor y la función SimularDraft para guardar los resultados en archivos de texto, permitiendo un mejor seguimiento de los resultados del draft.

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

> g++ -std=c++17 main.cpp -o app


## Instrucciones para ejecutar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

> ./app


# Descripción de las entradas del avance de proyecto

**El proyecto requiere dos archivos de entrada:**

`jugadores.txt` : Contiene la información de los jugadores en el formato:

> Nombre,PPG,Defense Rating,%3p

### Ejemplo:

> LeBron James,25.7,106.2,34.6
> Kevin Durant,29.9,108.3,38.3

`equipos_nba.txt` : Lista de equipos de la NBA (se genera automáticamente si no existe)

# Descripción de las salidas del avance de proyecto

El programa muestra en la consola:

1. Bienvenida y estadísticas iniciales
2. Equipo seleccionado aleatoriamente para el usuario
3. Recomendaciones de draft
4. Top 5 jugadores disponibles según la estadística elegida
5. Proceso de selección de jugadores
6. Resultados finales del draft


# Desarrollo de competencias

## SICT0301: Evalúa los componentes

Despúes del análisis de complejidad para el algoritmo Quicksort implementado en el proyecto. La complejidad temporal promedio de Quicksort es O(n log n), donde n es el número de jugadores. 
En el peor caso (cuando la lista está ya ordenada o inversamente ordenada), la complejidad puede llegar a O(n^2). 
La implementación se puede observar en las funciones `Quicksort` y `Partition` de la clase `Draft`.

Adicionalmente, se ha realizado un análisis de complejidad para todas las funciones del programa:

### Funciones Privadas

* bool Archivo_Existe(const std::string &) - 	O(1) - 	Operación de tiempo constante para verificar la existencia de un archivo.
* void EsperarEnter() -	O(1) -	Espera una entrada del usuario, operación de tiempo constante.
* void GenerarListaDeEquipos(const std::vector<std::string> &) -	O(n)	- Itera sobre n equipos para escribirlos en un archivo.
* void LimpiarConsola() -	O(1) -	Ejecuta un comando del sistema, considerado de tiempo constante.
* void LeerArchivo(const std::string &) -	O(n) -	Lee n líneas del archivo, procesando cada una en tiempo constante.
* void BubbleSort() -	O(n^2) -	Implementación típica de Bubble Sort con complejidad cuadrática.
* std::string SeleccionarEquipoAleatorio() -	O(1)	- Selecciona un equipo aleatorio de un vector, operación de tiempo constante.
* std::vector<std::string> ObtenerRecomendaciones(const std::string &equipo) -	O(1) -	Selecciona un número fijo de recomendaciones aleatorias.
* void Quicksort(Node *low, Node *high, int statChoice)	O(n log n) promedio, - O(n^2) - peor caso	Implementación de Quicksort.
* Node *Partition(Node *low, Node *high, int statChoice) -	O(n) -	Recorre n elementos entre low y high.
* void ImprimirOrdenLista(const std::string&) -	O(n) -	Recorre la lista de jugadores tres veces.
* void PreOrder(Node* node, std::ofstream& file) -	O(n) -	Visita cada nodo del árbol una vez.
* void InOrder(Node* node, std::ofstream& file) -	O(n) -	Visita cada nodo del árbol una vez.

### Funciones Públicas

* Draft() -	O(n) -	Constructor que lee n jugadores del archivo.
* void set_number_of_players(int) -	O(1) -	Asigna un valor, operación de tiempo constante.
* int get_number_of_players() -	O(1) -	Devuelve un valor, operación de tiempo constante.
* void SimularDraft() -	O(n log n) -	Dominada por la llamada a Quicksort.
* ~Draft() -	O(1) -	Destructor con operaciones de tiempo constante.

## SICT0302: Toma decisiones

## 1. Algoritmo Quicksort

### Descripción

El algoritmo **Quicksort** es un método que funciona seleccionando un pivote, luego particiona el arreglo en dos subarreglos (elementos menores y mayores que el pivote), y ordena recursivamente cada subarreglo. Este proceso se repite hasta que los subarreglos se reducen a tamaños manejables o ya están ordenados.

### Eficiencia

- **Complejidad promedio**: O(n log n), lo que lo hace uno de los algoritmos más rápidos en promedio para tareas de ordenación.
- **Ordenación "in-place"**: No requiere memoria adicional significativa, ya que reordena los elementos dentro del mismo arreglo. Esto lo convierte en una opción eficiente en términos de uso de memoria.

### Justificación

Quicksort es ideal para ordenar grandes volúmenes de datos. En aplicaciones como la simulación de un draft de jugadores, donde se necesitan múltiples ordenaciones según métricas como **PPG (Puntos por partido)**, **Defensive Rating**, o **Three Point Percentage**, Quicksort permite ejecutar estas ordenaciones sin pérdida de rendimiento. Su eficiencia promedio de O(n log n) garantiza un rendimiento estable, incluso con conjuntos de datos extensos, proporcionando flexibilidad y velocidad al sistema.

---

## 2. Lista Doblemente Enlazada

### Descripción

Una **lista doblemente enlazada** es una estructura de datos lineal donde cada nodo contiene un puntero al nodo siguiente y al nodo anterior. Esto permite recorrer la lista en ambas direcciones (adelante y atrás), facilitando la inserción y eliminación de elementos en cualquier posición sin necesidad de mover los demás elementos.

### Eficiencia

- **Acceso**: Al ser una estructura secuencial, el acceso a un elemento en una lista doblemente enlazada tiene complejidad O(n).
- **Inserción y Eliminación**: Las operaciones de inserción y eliminación en cualquier posición son rápidas, con una complejidad de O(1) en promedio, siempre y cuando se tenga un puntero al nodo en cuestión.

### Justificación

Una lista doblemente enlazada es particularmente útil en sistemas donde es necesario mantener un historial o mover elementos de una lista a otra, como en un sistema de draft donde jugadores pueden ser transferidos entre diferentes listas (por ejemplo, lista de jugadores activos y lista de reservas). La capacidad de mover nodos de forma eficiente, sin reasignación de memoria, permite una administración más dinámica de los jugadores dentro de la simulación.

---

## SICT0303: Implementa acciones científicas

Se implementaron mecanismos eficientes para consultar información de estructuras de datos complejas como una lista doblemente enlazada que almacena objetos Player. Esto se puede ver en la función `SimularDraft()`, donde se recorre la lista de jugadores para mostrar información necesaria para el programa, y en la implementación del algoritmo Quicksort, que se puede apreciar la capacidad de manipular y consultar la estructura de datos de manera eficiente.

Además, el programa implementa una fucnión de lectura de archivos para cargar datos en las estructuras. La función `LeerArchivo()` maneja la apertura del archivo, lee cada línea, procesa la información y crea objetos Player que se añaden a la lista. El programa también verifica la existencia de un archivo de equipos y lo genera si no existe, aquí demuestro la capacidad de manejar tanto la lectura como la escritura de archivos.

Se han agregado nuevas funcionalidades para escribir los resultados en archivos de texto. Las funciones `ImprimirOrdenLista`, `PreOrder` e `InOrder` demuestran la capacidad de escribir datos estructurados en archivos de manera eficiente.

De esta manera, se demuestra la capacidad de consultar información de estructuras de datos complejas, cargar datos desde archivos y escribir resultados en archivos de manera eficiente y correcta, cumpliendo así con los requisitos de la competencia SICT0303.
