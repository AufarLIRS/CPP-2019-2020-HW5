#include "counted.h"

int Counted::count_ = 0;

Counted::Counted()
{
  count_++;
  id_ = count_;
}

Counted::~Counted()
{
  count_--;
}

int Counted::get_id()
{
  return id_;
}
