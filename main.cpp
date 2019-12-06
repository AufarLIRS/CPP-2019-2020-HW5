#include <iostream>
#include "counted.h"

using namespace std;

int main()
{
  Counted c1;
  Counted c2;
  std::cout << c1.getId() << endl;
  std::cout << c2.getId() << endl;
}
