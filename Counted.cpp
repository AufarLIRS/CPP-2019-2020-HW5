#include "Counted.h"
#include "exception"

Counted::Counted()
{
  if (freeIDList.size() != 0)
  {
    id = freeIDList.back();
    freeIDList.pop_back();
  }
  else if (lastID > -1)
  {
    lastID++;
    id = lastID;
  }
  else
  {
    this->~Counted();
  }
}

Counted::~Counted()
{
  if (id > 0)
    freeIDList.push_back(this->id);
}

int Counted::getId()
{
  return id;
}

std::vector<int> Counted::freeIDList = std::vector<int>();
int Counted::lastID = 0;
