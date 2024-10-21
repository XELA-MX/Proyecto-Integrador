#include "Draft/draft.h"
#include <iostream>

/**
 * Función para limpiar la pantalla
 */

void LimpiarConsola() {
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

int main() {

  // Ciclo principal
  while (true) {
    // TEXTO DE EXPLICACIÓN EN CONSOLA
    std::cout << "Bienvenido al simulador de Draft de la NBA\n\n" << std::endl;
    std::cout << "1. Simular un draft" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "\n\nSelecciona una opción:";

    // VARIABLES
    std::string opcion;

    // ENTRADA DE DATOS
    std::cin >> opcion;

    // CONDICIONALES
    if (opcion == "0") {
      std::cout << "\n\nGracias por usar el simulador de Draft de la NBA"
                << std::endl;
      break;
    } else if (opcion == "1") {
      // SIMULAR EL DRAFT
      Draft draft;
    } else {
      LimpiarConsola();
      std::cerr
          << "Opción inválida. Por favor, selecciona una opción válida.\n\n"
          << std::endl;
    }
  }
}