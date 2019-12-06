#include <iostream>
#include "counted.h"
#include <vector>
#include <memory>

using namespace std;

int main()
{
  Counted c1;
  Counted c2;
  Counted c3;

  std::cout << c1.getId() << endl;  // it works - 1
  std::cout << c2.getId() << endl;  // 2
  std::cout << c3.getId() << endl;  // 3

  /*
  will cause an error
  auto c = std::vector<Counted>();
  c.push_back(c1);
  */

  auto someV = std::vector<std::unique_ptr<Counted>>();
  someV.push_back(std::make_unique<Counted>());  // 4
  someV.push_back(std::make_unique<Counted>());  // 5
  someV.push_back(std::make_unique<Counted>());  // 6

  for (const auto& i : someV)
  {
    std::cout << i->getId() << endl;  // 4, 5 ,6
  }

  auto anotherV = std::vector<std::unique_ptr<Counted>>();
  anotherV.emplace_back(new Counted);  // 7
  anotherV.emplace_back(new Counted);  // 8
  anotherV.emplace_back(new Counted);  // 9

  for (const auto& i : anotherV)
  {
    std::cout << i->getId() << endl;  // 7, 8 ,9
  }

  auto testV = std::vector<std::unique_ptr<Counted>>();
  testV.insert(0, c1);  // error
}
