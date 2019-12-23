#ifndef COUNTED_H
#define COUNTED_H

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Counted {
public:
  int ID;
  static vector<int> id_;

public:
  Counted(); // Конструктор

  // Методы правила 5-ти
  ~Counted();                        // Деструктор
  Counted(Counted const &) = delete; // Конструктор копирования
  Counted(Counted &&) = delete; // Конструктор перемещения
  Counted &
  operator=(Counted const &) = delete; // Оператор присваивания копированием
  Counted &operator=(Counted &&) = delete; // Оператор присваивания перемещением
};

#endif // COUNTED_H
