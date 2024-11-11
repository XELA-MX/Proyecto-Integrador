/*
  Autor: Emilio Antonio Peralta Montiel
  Matrícula: A01712354
  Fecha de creación: 28/09/2024

  Descripción:
    Este archivo contiene una clase llamada Draft que usa otra clase
    llamada Player para crear un arreglo de jugadores.

    Simula un draft de jugadores , en este caso ordena el arreglo
    por PPG o points per game y se los asigna a un equipo aleatorio.

    Este archivo también lee 2 archivos de texto, uno con los nombres
    y otro con las estadísticas de los jugadores.

    Ya que encontré una lista con todos los jugadores de la NBA,
    decidí crear un arhcivo .txt en base a este , todos los créditos al
    creador apuntado.
*/

#pragma once
#include "ListaDoble.h"
#include "player.h"
#include <algorithm>
#include <fstream>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include <functional>

class Draft {
private:
    int number_of_players;
    std::vector<std::string> equipos = {"Atlanta Hawks", 
                                        "Boston Celtics",
                                        "Brooklyn Nets",
                                        "Charlotte Hornets",
                                        "Chicago Bulls",
                                        "Cleveland Cavaliers",
                                        "Dallas Mavericks",
                                        "Denver Nuggets",
                                        "Detroit Pistons", 
                                        "Golden State Warriors", 
                                        "Houston Rockets", 
                                        "Indiana Pacers", 
                                        "LA Clippers", 
                                        "Los Angeles Lakers", 
                                        "Memphis Grizzlies", 
                                        "Miami Heat", 
                                        "Milwaukee Bucks", 
                                        "Minnesota Timberwolves", 
                                        "New Orleans Pelicans", 
                                        "New York Knicks", 
                                        "Oklahoma City Thunder", 
                                        "Orlando Magic", 
                                        "Philadelphia 76ers", 
                                        "Phoenix Suns", 
                                        "Portland Trail Blazers", 
                                        "Sacramento Kings", 
                                        "San Antonio Spurs", 
                                        "Toronto Raptors", 
                                        "Utah Jazz", 
                                        "Washington Wizards"};

    DoublyLinkedList jugadores;

    // Complejidad: O(1)
    bool Archivo_Existe(const std::string &);

    // Complejidad: O(1)
    void EsperarEnter();

    // Complejidad: O(n) donde n es el número de equipos
    void GenerarListaDeEquipos(const std::vector<std::string> &);

    // Complejidad: O(1)
    void LimpiarConsola();

    // Complejidad: O(n) donde n es el número de líneas en el archivo
    void LeerArchivo(const std::string &);

    // Complejidad: O(n^2) donde n es el número de jugadores
    void BubbleSort();

    // Complejidad: O(1)
    std::string SeleccionarEquipoAleatorio();

    // Complejidad: O(1)
    std::vector<std::string> ObtenerRecomendaciones(const std::string &equipo);

    // Complejidad: O(n log n) en promedio, O(n^2) en el peor caso, donde n es el número de jugadores
    void Quicksort(Node *low, Node *high, int statChoice);

    // Complejidad: O(n) donde n es el número de elementos entre low y high 
    Node *Partition(Node *low, Node *high, int statChoice);

    // Complejidad: O(n) donde n es el número de jugadores 
    void ImprimirOrdenLista(const std::string&);

    // Complejidad: O(n) donde n es el número de nodos en el árbol
    void PreOrder(Node* node, std::ofstream& file);

    // Complejidad: O(n) donde n es el número de nodos en el árbol
    void InOrder(Node* node, std::ofstream& file);

public:
    // Complejidad: O(n) donde n es el número de jugadores leídos del archivo
    Draft();

    // Complejidad: O(1) una vuelta
    void set_number_of_players(int);

    // Complejidad: O(1) una vuelta
    int get_number_of_players();

    // Complejidad: O(n log n) donde n es el número de jugadores
    void SimularDraft();

    // Complejidad: O(1) - Solo una vuelta
    ~Draft();
};

// Implementación de las nuevas funciones

void Draft::ImprimirOrdenLista(const std::string& nombreArchivo) {
    std::ofstream file(nombreArchivo);
    if (file.is_open()) {
        file << "Orden original:\n";
        Node* current = jugadores.getHead();
        while (current != nullptr) {
            file << current->data.name << "\n";
            current = current->next;
        }
        
        file << "\nPreOrder:\n";
        current = jugadores.getHead();
        while (current != nullptr) {
            file << current->data.name << "\n";
            current = current->next;
        }
        
        file << "\nInOrder:\n";
        current = jugadores.getHead();
        while (current != nullptr) {
            file << current->data.name << "\n";
            current = current->next;
        }
        
        file.close();
        //std::cout << "Resultados guardados en " << nombreArchivo << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir.\n";
    }
}

// Esperar Enter
void Draft::EsperarEnter() {
  std::cout << "Presione Enter para continuar...";
  std::cin.ignore();
  std::cin.get();
}

// Leer el archivo de jugadores
// Implementación de LeerArchivo
void Draft::LeerArchivo(const std::string &nombreArchivo) {
  std::ifstream archivo(nombreArchivo);
  if (archivo.is_open()) {
    std::string linea;
    while (std::getline(archivo, linea)) {
      std::istringstream ss(linea);
      std::string nombre;
      double PPG, defensa, porcentajeTres;
      char delim;
      std::getline(ss, nombre, ',');
      ss >> PPG >> delim >> defensa >> delim >> porcentajeTres;
      jugadores.pushBack(Player(nombre, PPG, defensa, porcentajeTres));
    }
    archivo.close();
  } else {
    std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
  }
}

// Nombre,PPG,Defense Rating,%3p
bool Draft::Archivo_Existe(const std::string &nombre_archivo) {
  // Intentar abrir el archivo
  std::ifstream archivo(nombre_archivo);
  // Devolver true si el archivo se abrió correctamente
  return archivo.good();
}

// Genera la lista de equipos
void Draft::GenerarListaDeEquipos(const std::vector<std::string> &equipos) {
  std::ofstream archivo("Draft/equipos_nba.txt");
  if (archivo.is_open()) {
    for (const auto &equipo : equipos) {
      archivo << equipo << std::endl;
    }
    archivo.close();
    std::cout << "Archivo 'equipos_nba.txt' generado correctamente."
              << std::endl;
  } else {
    std::cerr << "No se pudo abrir o crear el archivo." << std::endl;
  }
}

// Limpia la consola
void Draft::LimpiarConsola() {
#if defined(_WIN32) || defined(_WIN64)
  int ret = std::system("cls");
#elif defined(__linux__) || defined(__APPLE__)
  int ret = std::system("clear");
  if (ret == -1) {
    std::cout << "Error al limpiar la pantalla" << std::endl;
  }
#else
  std::cerr << "No se puede limpiar la consola: sistema operativo no soportado."
            << std::endl;
#endif
}

// SER EL REPRESENTANTE DE UN EQUIPO

std::string Draft::SeleccionarEquipoAleatorio() {
  // Seleccionar un índice aleatorio
  int indice_aleatorio = rand() % equipos.size();

  // Devolver el equipo correspondiente al índice aleatorio
  return equipos[indice_aleatorio];
}

// DAR RECOMENDACIONES PARA EL EQUIPO
std::vector<std::string>
Draft::ObtenerRecomendaciones(const std::string &equipo) {
  // LISTA DE RECOMENDACIONES
  std::vector<std::string> todasLasRecomendaciones = {
      "Priorizar jugadores con alto PPG",
      "Considerar seleccionar un base fuerte",
      "Buscar aleros versátiles",
      "Enfocarse en jugadores con buena defensa",
      "Buscar tiradores de tres puntos",
      "Considerar un pívot atlético",
      "Mejorar la profundidad del banquillo",
      "Buscar jugadores con potencial de desarrollo",
      "Priorizar la versatilidad defensiva",
      "Considerar jugadores con experiencia en playoffs",
      "Buscar líderes en la cancha",
      "Mejorar el juego en transición",
      "Enfocarse en reboteadores fuertes",
      "Buscar jugadores con buen manejo de balón",
      "Considerar especialistas defensivos"};

  // INDICAR CUANTOS QUEREMOS
  std::vector<std::string> recomendacionesAleatorias;
  int numRecomendaciones = 3; // Número de recomendaciones a devolver

  // Verificar si hay suficientes recomendaciones disponibles
  for (int i = 0; i < numRecomendaciones; ++i) {
    if (todasLasRecomendaciones.empty()) {
      break; // Salir si ya no quedan recomendaciones
    }
    // Seleccionar una recomendación aleatoria
    int indiceAleatorio = rand() % todasLasRecomendaciones.size();
    recomendacionesAleatorias.push_back(
        todasLasRecomendaciones[indiceAleatorio]);
    todasLasRecomendaciones.erase(todasLasRecomendaciones.begin() +
                                  indiceAleatorio);
  }

  // Devolver las recomendaciones
  return recomendacionesAleatorias;
}
// ¡Hora de jugar al ordenamiento mágico de jugadores!
void Draft::Quicksort(Node *low, Node *high, int statChoice) {
    ImprimirOrdenLista("OrdenDeLaLista.txt");
  // Si existe algo , simplemente por seguridad
  if (low != nullptr && high != nullptr && low != high && low != high->next) {
    // Jugador de en medio
    Node *pivot = Partition(low, high, statChoice);

    // Los maletas a comparación del de en medio
    Quicksort(low, pivot->prev, statChoice);

    // Los que son mejorcitos
    Quicksort(pivot->next, high, statChoice);
  }
}

// A que lado irá nuestro jugador?? Jaja adoro estos comentarios
Node *Draft::Partition(Node *low, Node *high, int statChoice) {
  double pivot;

  // Elegimos qué habilidad vamos a comparar
  switch (statChoice) {
  case 0:
    pivot = high->data.ppg; // Puntos por juego
    break;
  case 1:
    pivot = high->data.defense_rating; // Habilidad defensiva
    break;
  case 2:
    pivot = high->data.three_point_percentage; // Porcentaje de triples
    break;
  }

  // Empezamos justo antes del jugador de en medio
  Node *i = low->prev;

  // Dle primero al penúmltimo
  for (Node *j = low; j != high; j = j->next) {
    bool shouldSwap = false;

    // Comparar al jugador con el de en medio
    switch (statChoice) {
    case 0:
      shouldSwap = j->data.ppg > pivot; // Anota más puntos?
      break;
    case 1:
      shouldSwap = j->data.defense_rating > pivot; // Defensa es mejor?
      break;
    case 2:
      shouldSwap = j->data.three_point_percentage > pivot; // Más triples?
      break;
    }

    // Si es mejor , cambiar
    if (shouldSwap) {
      i = (i == nullptr) ? low : i->next;
      std::swap(i->data, j->data);
    }
  }

  // El de en medio en su POS final
  i = (i == nullptr) ? low : i->next;
  std::swap(i->data, high->data);

  // Devolvemos la posición del pivote
  return i;
}

// El momento que todos estabamos esperando
// Implementación de SimularDraft
void Draft::SimularDraft() {
  // Primero, elegimos un equipo al azar
  std::string equipoSeleccionado = SeleccionarEquipoAleatorio();
  std::cout << "¡Y el equipo elegido es: " << equipoSeleccionado << std::endl;

  // Fortalezas a buscar:
  std::vector<std::string> recomendaciones =
      ObtenerRecomendaciones(equipoSeleccionado);
  std::cout << "\nEl entrenador susurra sabiamente:" << std::endl;
  for (const auto &recomendacion : recomendaciones) {
    std::cout << "- " << recomendacion << std::endl;
  }

  // Habilidad que priorizar
  int statChoice = rand() % 3;
  std::string statNombre;
  switch (statChoice) {
  case 0:
    statNombre = "PPG (Anotadores natos)";
    break;
  case 1:
    statNombre = "Defense Rating (Muros humanos)";
    break;
  case 2:
    statNombre = "Three Point Percentage (Francotiradores)";
    break;
  }

  // Ordenamos a los jugadores usando Quicksort
  std::cout << "\n¡Atención! Ordenando jugadores por " << statNombre
            << " usando la magia del Quicksort..." << std::endl;
  Quicksort(jugadores.getHead(), jugadores.getTail(), statChoice);

  // Aquí guardaremos qué jugador elige cada equipo
  std::map<std::string, std::string> equipoJugador;

  // Ahora, cada equipo elige un jugador
  for (const auto &equipo : equipos) {
    if (equipo == equipoSeleccionado) {
      // Si es nuestro turno, mostramos los 5 mejores jugadores disponibles
      std::cout << "\n¡Es tu turno para elegir! Los 5 mejores talentos "
                   "disponibles son:"
                << std::endl;
      Node *current = jugadores.getHead();
      for (int i = 0; i < 5 && current != nullptr; i++) {
        // Mostramos el nombre y la estadística relevante de cada jugador
        std::cout << i + 1 << ". " << current->data.name << " (";
        switch (statChoice) {
        case 0:
          std::cout << "PPG: " << current->data.ppg;
          break;
        case 1:
          std::cout << "Defense Rating: " << current->data.defense_rating;
          break;
        case 2:
          std::cout << "Three Point %: "
                    << current->data.three_point_percentage;
          break;
        }
        std::cout << ")" << std::endl;
        current = current->next;
      }

      // El usuario elige un jugador
      int eleccion;
      while (true) {
        std::cout << "\nElige un jugador (1-5): ";
        if (std::cin >> eleccion) {
          if (eleccion >= 1 && eleccion <= 5 &&
              eleccion <= jugadores.getSize()) {
            break; // Entrada válida, salimos del bucle
          }
        }
        // Si llegamos aquí, la entrada no fue válida
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n'); // Descartamos la entrada inválida
        std::cout << "Entrada inválida. Por favor, introduce un número entre 1 "
                     "y 5."
                  << std::endl;
      }

      // Guardamos la elección del usuario
      Node *selectedNode = jugadores.getHead();
      for (int i = 1; i < eleccion; i++) {
        selectedNode = selectedNode->next;
      }
      equipoJugador[equipo] = selectedNode->data.name;
      jugadores.remove(selectedNode);
    } else {
      // Los otros equipos eligen al azar
      if (jugadores.getSize() > 0) {
        int indiceAleatorio = rand() % jugadores.getSize();
        Node *selectedNode = jugadores.getHead();
        for (int i = 0; i < indiceAleatorio; i++) {
          selectedNode = selectedNode->next;
        }
        equipoJugador[equipo] = selectedNode->data.name;
        jugadores.remove(selectedNode);
      }
    }
  }

  // Finalmente, mostramos los resultados del Draft
  std::cout << "\nResultados del Draft:" << std::endl;
  for (const auto &[equipo, jugador] : equipoJugador) {
    std::cout << equipo << ": " << jugador << std::endl;
  }

  // ARCHIVOS:
}

// Constructor
Draft::Draft() {
  // Verificar si existen los equipos
  if (!Archivo_Existe("equipos_nba.txt")) {
    GenerarListaDeEquipos(equipos);
  }
  // Leer el archivo de jugadores
  LeerArchivo("Draft/jugadores.txt");

  // Limpiar la consola
  LimpiarConsola();

  // Dar bienvenida en Texto
  std::cout << "Bienvenido al Draft de la NBA" << std::endl;
  int totalJugadores = jugadores.getSize();
  std::cout << "\n\nTotal de jugadores: " << totalJugadores << std::endl;
  int totalDeEquipos = equipos.size();
  std::cout << "Total de equipos: " << totalDeEquipos << std::endl;

  SimularDraft();
}

// Destructor
Draft::~Draft() {
  std::cout << "\n\nEl draft ha terminado!.\n\n" << std::endl;
  EsperarEnter();
  LimpiarConsola();
}
