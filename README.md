# Proyecto: Simulador de draft de la NBA

Este proyecto simula un draft de la NBA, donde se seleccionan jugadores para diferentes equipos basándose en sus estadísticas.
Utiliza una estructura de datos de lista doblemente enlazada para almacenar y manipular la información de los jugadores, y emplea el algoritmo Quicksort para ordenarlos según diferentes criterios.

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
* Modificación de la función SimularDraft y el destructor para guardar los resultados en archivos de texto****

## Cambios sobre el primer avance
[ * ] Adición de nuevas funciones: Se agregaron las funciones ImprimirOrdenLista, PreOrder e InOrder para imprimir la lista en diferentes órdenes. Esto mejora la visualización de los resultados del draft.
[ * ] Mejora en la documentación: Se añadieron comentarios sobre la complejidad temporal de cada función, lo que facilita el análisis del rendimiento del programa.
[ * ] Ampliación de la funcionalidad de guardado: Se modificó el destructor y la función SimularDraft para guardar los resultados en archivos de texto, permitiendo un mejor seguimiento de los resultados del draft.

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

* `ImprimirOrdenLista`: O(n) donde n es el número de jugadores
* `PreOrder y InOrder`: O(n) donde n es el número de nodos en el árbol
* `LeerArchivo`: O(n) donde n es el número de líneas en el archivo
* `BubbleSort`: O(n^2) donde n es el número de jugadores
* `SeleccionarEquipoAleatorio`: O(1)
* `ObtenerRecomendaciones`: O(1)

## SICT0302: Toma decisiones

* El algoritmo Quicksort es el mejor algoritmo para ordenar los jugadores debido a su eficiencia promedio de O(n log n) y su capacidad para ordenar "in-place", lo que es perfecto para conjuntos de datos grandes.
* Se utiliza una lista doblemente enlazada para almacenar los jugadores, permitiendo así inserciones y eliminaciones eficientes en ambos extremos de la lista, excelente a la hora de realizar operaciones a la hora de simular el draft.
* La implementación de Quicksort se adapta a diferentes criterios a la hora de ser llamada (PPG, Defense Rating, Three Point Percentage), demostrando flexibilidad en la toma de decisiones algorítmicas.


## SICT0303: Implementa acciones científicas

Se implementaron mecanismos eficientes para consultar información de estructuras de datos complejas como una lista doblemente enlazada que almacena objetos Player. Esto se puede ver en la función `SimularDraft()`, donde se recorre la lista de jugadores para mostrar información necesaria para el programa, y en la implementación del algoritmo Quicksort, que se puede apreciar la capacidad de manipular y consultar la estructura de datos de manera eficiente.

Además, el programa implementa una fucnión de lectura de archivos para cargar datos en las estructuras. La función `LeerArchivo()` maneja la apertura del archivo, lee cada línea, procesa la información y crea objetos Player que se añaden a la lista. El programa también verifica la existencia de un archivo de equipos y lo genera si no existe, aquí demuestro la capacidad de manejar tanto la lectura como la escritura de archivos.

Se han agregado nuevas funcionalidades para escribir los resultados en archivos de texto. Las funciones `ImprimirOrdenLista`, `PreOrder` e `InOrder` demuestran la capacidad de escribir datos estructurados en archivos de manera eficiente.

De esta manera, se demuestra la capacidad de consultar información de estructuras de datos complejas, cargar datos desde archivos y escribir resultados en archivos de manera eficiente y correcta, cumpliendo así con los requisitos de la competencia SICT0303.
