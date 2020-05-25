#include <iostream>
#include <memory>
#include "Counted.h"

using namespace std;

Counted* f(Counted* counted)
{
  return counted;
}

int main()
{
  vector<Counted*> countedList;
  Counted* a = new Counted();

  Counted* b = new Counted();
  Counted* c = new Counted();
  Counted* d = new Counted();
  delete d;
  Counted* e = new Counted();
  f(e);
  countedList.push_back(a);
  countedList.push_back(b);
  countedList.push_back(c);
  countedList.push_back(e);

  // countedList().push_back(c);
  // countedList().push_back(d);
  // countedList().push_back(e);
  std::vector<std::shared_ptr<Counted>> counteds;
  counteds.push_back(std::make_shared<Counted>());

  std::cout << counteds.back()->getId();

  return 0;
}
