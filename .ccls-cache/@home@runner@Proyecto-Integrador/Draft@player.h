#pragma once

#include <iostream>

class Player {
public:
  std::string name;
  double ppg;
  double defense_rating;
  double three_point_percentage;
  ~Player() = default;
  Player(std::string name, double ppg, double defense_rating,
         double three_point_percentage);
};

// Constructor definition
Player::Player(std::string name, double ppg, double defense_rating,
               double three_point_percentage) {
  this->name = std::move(name);
  this->ppg = ppg;
  this->defense_rating = defense_rating;
  this->three_point_percentage = three_point_percentage;
}