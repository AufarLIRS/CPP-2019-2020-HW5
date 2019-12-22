#ifndef COUNTED_H
#define COUNTED_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cassert>


using namespace std;

class Counted
{
public:
    int ID;
    static vector<int> id_;

public:
    Counted();                               // Конструктор

    // Методы правила 5-ти
    ~Counted();                              // Деструктор
    Counted(Counted const &);                // Конструктор копирования
    Counted(Counted &&);                     // Конструктор перемещения
    Counted& operator=(Counted const &);     // Оператор присваивания копированием
    Counted& operator=(Counted &&);          // Оператор присваивания перемещением
};

#endif // COUNTED_H
