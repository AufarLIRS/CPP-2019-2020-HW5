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

Counted::Counted(Counted&& r)
{
  if (this != &r)
    std::swap(id_, r.id_);
}

Counted& Counted::operator=(Counted&& r)
{
  if (this != &r)
    std::swap(id_, r.id_);
  return *this;
}

int Counted::count_;
