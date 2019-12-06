#include "counted.h"
#include <utility>

int Counted::count_ = 0;

Counted::Counted()
{
  count_++;
  id_ = count_;
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

int Counted::getId()
{
  return id_;
}
