#include <iostream>
#include "counted.h"
#include <vector>
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

  // Error occurs
  std::vector<Counted> countedArr;
  countedArr.push_back(a);

  return 0;
}
