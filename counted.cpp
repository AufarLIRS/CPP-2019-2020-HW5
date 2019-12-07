#include "counted.h"

int Counted::count_ = 0;

Counted::Counted()
{
  count_++;
  id_ = count_;
}

int Counted::getID()
{
  return id_;
}

Counted::~Counted()
{
  count_--;
}
