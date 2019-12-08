#include <iostream>
#include "counted.h"
#include <vector>
#include <memory>

using namespace std;

int main()
//--------------------------------------Task-1--------------------------------------//
{
  {
    Counted a;
    Counted b;
    Counted c;
    std::cout << a.getID() << endl;
    std::cout << b.getID() << endl;
    std::cout << c.getID() << endl;
  }
  cout << endl;
  {
    Counted d;
    Counted e;
    std::cout << d.getID() << endl;
    std::cout << e.getID() << endl;
  }

  //
  //
  //
  //--------------------------------- Error occurs------------------------------------//
  /* std::vector<Counted> countedArr;
              countedArr.push_back(a);*/
  //--------------------------------- Error occurs------------------------------------//
  //
  //
  //
  //
  //--------------------------------------Task-3--------------------------------------//

  auto vectorTest1 = std::vector<std::unique_ptr<Counted>>();
  vectorTest1.emplace_back(new Counted());
  vectorTest1.emplace_back(new Counted());
  cout << endl;
  for (const auto& i : vectorTest1)
  {
    cout << i->getID() << endl;
  }

  cout << endl;

  auto element1 = std::make_unique<Counted>();
  auto element2 = std::make_unique<Counted>();
  auto element3 = std::make_unique<Counted>();
  auto vectorTest2 = std::vector<std::unique_ptr<Counted>>();
  vectorTest2.push_back(move(element1));
  vectorTest2.push_back(move(element2));
  vectorTest2.push_back(move(element3));
  cout << endl;
  for (const auto& i : vectorTest2)
  {
    cout << i->getID() << endl;
  }

  cout << endl;
  return 0;
}
