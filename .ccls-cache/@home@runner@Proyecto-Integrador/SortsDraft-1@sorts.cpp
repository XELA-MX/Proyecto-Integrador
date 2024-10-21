#include "sorts.h"
#include <iostream>

std::vector<Player> bubbleSort(std::vector<Player> &j) {
  bool swapped;
  do {
    swapped = false;
    // CICLO FOR
    for (int i = 1; i < j.size(); i++) {
      if (j[i - 1].ppg > j[i].ppg) {
        std::swap(j[i - 1], j[i]);
        swapped = true;
      }
    }
  } while (swapped);

  return j;
}