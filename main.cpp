#include <iostream>
#include "Counted.h"
#include <vector>
#include <memory>
using namespace std;

int main()
{
  // Counted c1;
  Counted c2;
  Counted c3;
  Counted c4;
  Counted c5;

  // cout << c1.getID() << endl; // was 1
  cout << c2.getID() << endl;  // 1
  cout << c3.getID() << endl;  // 2
  // c3 = c2; compile error

  c2 = move(c3);

  cout << c2.getID() << endl;  // 2
  cout << c3.getID() << endl;  // 1

  // first approach
  auto vector = std::vector<Counted>();
  vector.push_back(Counted());
  vector.push_back(Counted());
  vector.push_back(Counted());
  vector.push_back(Counted());

  for (auto& i : vector)
  {
    cout << i.getID();  // 5 6 7 8
  }

  // second approach
  auto vectorSec = std::vector<Counted>();
  vectorSec.push_back(move(c2));
  vectorSec.push_back(move(c3));
  vectorSec.push_back(move(c4));
  vectorSec.push_back(move(c5));
  cout << endl;

  for (auto& i : vectorSec)
  {
    cout << i.getID();  // 2 1 3 4
  }

  // third approach
  auto vectorThird = std::vector<Counted>();
  vectorThird.emplace_back();
  vectorThird.emplace_back();
  vectorThird.emplace_back();
  vectorThird.emplace_back();
  cout << endl;

  for (auto& i : vectorThird)
  {
    cout << i.getID();  // 9 10 11 12
  }

  // fourth approach, that's enough, in other approaches you may use shared_ptr or raw pointers with delete operations
  // if needed
  auto vectorPointer = std::vector<std::unique_ptr<Counted>>();
  vectorPointer.push_back(std::make_unique<Counted>());
  vectorPointer.push_back(std::make_unique<Counted>());
  vectorPointer.push_back(std::make_unique<Counted>());

  cout << endl;

  for (const auto& i : vectorPointer)
  {
    cout << i.get()->getID();  // 13 14 15
  }

  return 0;
}
