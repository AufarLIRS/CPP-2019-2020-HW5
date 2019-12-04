#include "Counted.h"
#include <utility>

int Counted::getID()
{
  return id_;
}

Counted::Counted()
{
  id_ = count_ + 1;
  count_++;
}

Counted::~Counted()
{
  count_--;
}

int Counted::count_;
