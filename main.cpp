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
  cout << c4.getID() << endl;  // 3
  cout << c5.getID() << endl;  // 4
  // c3 = c2; compile error

  // c2 = move(c3); compile error

  // first approach
  auto vectorPointer = std::vector<std::unique_ptr<Counted>>();
  vectorPointer.push_back(std::make_unique<Counted>());
  vectorPointer.push_back(std::make_unique<Counted>());
  vectorPointer.push_back(std::make_unique<Counted>());
  cout << endl;

  for (const auto& i : vectorPointer)
  {
    cout << i->getID();  // 5 6 7
  }

  // second approach
  auto p1 = std::make_unique<Counted>();
  auto p2 = std::make_unique<Counted>();
  auto p3 = std::make_unique<Counted>();
  auto p4 = std::make_unique<Counted>();

  auto vectorSec = std::vector<std::unique_ptr<Counted>>();

  vectorSec.push_back(move(p1));
  vectorSec.push_back(move(p2));
  vectorSec.push_back(move(p3));
  vectorSec.push_back(move(p4));
  cout << endl;

  for (const auto& i : vectorSec)
  {
    cout << i->getID();  // 8 9 10 11
  }

  // third approach
  auto vectorThird = std::vector<std::unique_ptr<Counted>>();
  vectorThird.emplace_back(new Counted());
  vectorThird.emplace_back(new Counted());
  vectorThird.emplace_back(new Counted());
  vectorThird.emplace_back(new Counted());
  cout << endl;

  for (const auto& i : vectorThird)
  {
    cout << i->getID();  // 12 13 14 15
  }

  // fourth approach
  auto vectorFourth = std::vector<std::shared_ptr<Counted>>();
  vectorFourth.push_back(std::make_shared<Counted>());
  vectorFourth.push_back(std::make_shared<Counted>());
  vectorFourth.push_back(std::make_shared<Counted>());
  vectorFourth.push_back(std::make_shared<Counted>());
  cout << endl;

  for (const auto& i : vectorFourth)
  {
    cout << i->getID();  // 16 17 18 19
  }
  // that's enough, in other approaches you may use raw pointers with delete operations if needed

  return 0;
}
