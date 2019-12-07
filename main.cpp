#include <iostream>
#include "counted.h"
using namespace std;

int main()
{
  Counted a;
  Counted b;
  Counted c;
  Counted d;
  Counted e;

  std::cout << a.getID() << endl;
  std::cout << b.getID() << endl;
  std::cout << c.getID() << endl;
  std::cout << d.getID() << endl;
  std::cout << e.getID() << endl;

  return 0;
}
