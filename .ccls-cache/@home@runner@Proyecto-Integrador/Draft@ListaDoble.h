#pragma once
#include "player.h"

class Node {
public:
  Player data;
  Node *prev;
  Node *next;

  Node(const Player &player) : data(player), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
  Node *head;
  Node *tail;
  int size;

public:
  DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

  void pushBack(const Player &player);   // Agregar un jugador al final
  void popFront();                       // Eliminar el primer jugador
  Node *getHead() const { return head; } // Nodo Cabeza
  int getSize() const { return size; }   // Tamaño de la lista
  Node *getTail() const { return tail; } // Nodo Cola
  void remove(Node *node);               // Eliminar un nodo específico
};

/*

  MÉTODOS

*/

// Agregar un jugador al final de la lista
void DoublyLinkedList::pushBack(const Player &player) {
  Node *newNode = new Node(player);
  if (tail == nullptr) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
  size++;
}

// Eliminar el primer jugador de la lista
void DoublyLinkedList::popFront() {
  if (head == nullptr)
    return;
  Node *temp = head;
  head = head->next;
  if (head != nullptr) {
    head->prev = nullptr;
  } else {
    tail = nullptr;
  }
  delete temp;
  size--;
}

// Eliminar un nodo específico de la lista
void DoublyLinkedList::remove(Node *node) {
  if (node == nullptr)
    return;

  // Si el nodo a eliminar es la cabeza
  if (node == head) {
    head = node->next;
    if (head != nullptr) {
      head->prev = nullptr;
    } else {
      // Si la lista queda vacía, actualizar también la cola
      tail = nullptr;
    }
  } else {
    // El nodo a eliminar no es la cabeza
    node->prev->next = node->next;
    if (node->next != nullptr) {
      node->next->prev = node->prev;
    } else {
      // Si el nodo a eliminar es la cola, actualizar la cola
      tail = node->prev;
    }
  }

  // Liberar la memoria del nodo eliminado
  delete node;
  size--;
}