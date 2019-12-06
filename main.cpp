#include <iostream>
#include "counted.h"

using namespace std;

Counted func()
{
  Counted c;
  return c;
}

int main()
{
  {
    Counted c1;
    c1 = func();                      // EXCEPTION
    std::cout << c1.getId() << endl;  // 1
    Counted c2;
    std::cout << c2.getId() << endl;  // 2
  }
  Counted c3;
  std::cout << c3.getId() << endl;  // 1 (fixed)
}
