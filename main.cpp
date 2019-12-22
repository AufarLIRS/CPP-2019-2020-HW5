#include <iostream>
#include <vector>
#include <string>
#include "counted.h"

using namespace std;

// �������� ������ ID � ���� ������
string getAll_ID(vector<Counted>* vect)
{
  string str = "ID: ";
  for (auto it = vect->begin(); it < vect->end(); it++)
  {
    ostringstream ss;
    ss << it->ID;
    str += ss.str();
    if (it < (vect->end() - 1))
      str += ", ";
  }
  return str;
}

// �������� �������
int main()
{
  vector<Counted> cnt;
  Counted c1, c2, c3, c4, c5;

  // ������� ��������� ������ �������� (� ����� �������)
  cnt.push_back(c1);
  cnt.push_back(c2);
  cout << getAll_ID(&cnt) << endl;

  // ������� ��������� ������ �������� (� ������ �������)
  auto it = cnt.begin();
  cnt.emplace(it, c3);
  cout << getAll_ID(&cnt) << endl;

  // ������� ��������� ������� �������� (� ����� �������)
  cnt.emplace_back(c4);
  cout << getAll_ID(&cnt) << endl;

  // ������� ��������� ��������� �������� (� ������ �������)
  it = cnt.begin();
  cnt.insert(it, c5);
  cout << getAll_ID(&cnt) << endl;

  return 0;
}
