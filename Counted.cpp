#include "Counted.h"
#include <exception>
#include <utility>

const char* IDException::what() const throw()
{
  return "ID ERROR";
}
size_t getMinID(std::vector<size_t> vec)
{
  size_t min = vec.front();
  size_t min_index = 0;
  for (size_t i = 0; i < vec.size(); i++)
  {
    if (vec[i] < min)
    {
      min = vec[i];
      min_index = i;
    }
  }
  vec.erase(vec.begin() + min_index);

  return min;
}

Counted::Counted()
{
  if (freeIDList.size() != 0)  //если у нас есть освободившиеся айдишники, то будем использовать их, начнем с
                               //минимального доступного
  {
    id = getMinID(freeIDList);
  }
  else if (lastID + 1 > 0)  //иначе, если максимальный айдишник валидный, то увеличиваем его и кладем в айдишник каутеда
  {
    lastID++;
    id = lastID;
  }
  else  //в конечном итоге, если не удалось создать объект с валидным айдишником, выкидываем эксэпшен
  {
    IDException e;
    throw e;
  }
}

Counted::~Counted()
{
  freeIDList.push_back(this->id);
}

size_t Counted::getId()
{
  return id;
}

std::vector<size_t> Counted::freeIDList = std::vector<size_t>();
size_t Counted::lastID = 0;
