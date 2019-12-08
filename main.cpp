#include <iostream>
#include <vector>
#include <memory>
#include <counted.h>

using namespace std;

int main()
{
  cout << "Task1: " << endl;
  Counted count1;
  Counted count2;
  cout << count1.get_id() << endl;
  cout << count2.get_id() << endl;
  for (int i = 0; i < 3; i++)
  {
    Counted count_new;
    cout << count_new.get_id() << endl;
  }

  cout << endl << "Task3.1: " << endl;
  std::vector<std::unique_ptr<Counted>> vect1 = std::vector<std::unique_ptr<Counted>>();
  vect1.push_back(std::make_unique<Counted>());
  vect1.push_back(std::make_unique<Counted>());
  for (auto& i : vect1)
  {
    cout << i->get_id() << endl;
  }

  cout << endl << "Task3.2: " << endl;
  std::vector<std::shared_ptr<Counted>> vect2 = std::vector<std::shared_ptr<Counted>>();
  vect2.push_back(std::make_shared<Counted>());
  vect2.push_back(std::make_shared<Counted>());
  for (auto& j : vect2)
  {
    cout << j->get_id() << endl;
  }
  cout << endl;
}
