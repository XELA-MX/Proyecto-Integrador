# Proyecto: Simulador de draft de la NBA

Este proyecto simula un draft de la NBA, donde se seleccionan jugadores para diferentes equipos basándose en sus estadísticas.
Utiliza una estructura de datos de lista doblemente enlazada para almacenar y manipular la información de los jugadores, y emplea el algoritmo Quicksort para ordenarlos según diferentes criterios.

## Descripción del avance 1

En este avance, se ha implementado la estructura básica del simulador de draft, incluyendo:
* Lectura de datos de jugadores desde un archivo
* Implementación de una lista doblemente enlazada para almacenar jugadores
* Algoritmo Quicksort para ordenar jugadores por diferentes estadísticas
* Simulación básica del proceso de draft

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

> g++ main.cpp draft.cpp player.cpp doubly_linked_list.cpp -o simulador_draft


## Instrucciones para ejecutar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

> ./simulador_draft


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

## SICT0302: Toma decisiones

El algoritmo `Quicksort` es el mejor algoritmo para ordenar los jugadores debido a su eficiencia promedio de O(n log n) y su capacidad para ordenar "in-place", lo que salió perfecto para conjuntos de datos. Además, 
una lista doblemente enlazada para almacenar los jugadores, lo que permite inserciones y eliminaciones eficientes en ambos extremos de la lista, útil para las operaciones a la hora de simular el draft. 

La implementación de Quicksort se adapta a diferentes criterios de ordenamiento (PPG, Defense Rating, Three Point Percentage), demostrando flexibilidad en la toma de decisiones algorítmicas.


