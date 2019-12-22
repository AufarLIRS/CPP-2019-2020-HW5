#include <iostream>
#include <vector>
#include <string>
#include "counted.h"

using namespace std;

// Получить список ID в виде строки
string getAll_ID(vector<Counted>* vect)
{
  string str = "ID: ";
  for (auto it = vect->begin(); it < vect->end(); it++)
  {
    ostringstream ss;
    ss << it->ID;
    str += ss.str();
    if (it < (vect->end() - 1))
      str += ", ";
  }
  return str;
}

// Основная функция
int main()
{
  vector<Counted> cnt;
  Counted c1, c2, c3, c4, c5;

  // Вставка элементов первым способом (в конец вектора)
  cnt.push_back(c1);
  cnt.push_back(c2);
  cout << getAll_ID(&cnt) << endl;

  // Вставка элементов вторым способом (в начало вектора)
  auto it = cnt.begin();
  cnt.emplace(it, c3);
  cout << getAll_ID(&cnt) << endl;

  // Вставка элементов третьим способом (в конец вектора)
  cnt.emplace_back(c4);
  cout << getAll_ID(&cnt) << endl;

  // Вставка элементов четвертым способом (в начало вектора)
  it = cnt.begin();
  cnt.insert(it, c5);
  cout << getAll_ID(&cnt) << endl;

  return 0;
}
