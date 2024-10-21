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



