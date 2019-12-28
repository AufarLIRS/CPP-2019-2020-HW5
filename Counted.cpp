#include "Counted.h"
#include <exception>
#include <utility>

const char* IDException::what() const throw()
{
  return "ID ERROR";
}
int getMinID(std::vector<int> vec)
{
  int min = vec.front();
  int min_index = 0;
  for (int i = 0; i < vec.size(); i++)
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
  if (freeIDList.size() !=
      0)  //если у нас есть освободившиеся айдишники, то будем использовать их, начнем с минимального доступного
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

int Counted::getId()
{
  return id;
}

std::vector<int> Counted::freeIDList = std::vector<int>();
int Counted::lastID = 0;

Counted::Counted(const Counted&& a)
{
  freeIDList.push_back(this->id);
  this->id = a.id;
  a.~Counted();
  for (int i = 0; i < freeIDList.size(); i++)
  {
    if (freeIDList[i] == this->id)
    {
      freeIDList.erase(freeIDList.begin() + i);
      break;
    }
  }
}

Counted& Counted::operator=(Counted&& a)
{
  freeIDList.push_back(this->id);
  this->id = a.getId();
  a.~Counted();
  for (int i = 0; i < freeIDList.size(); i++)
  {
    if (freeIDList[i] == this->id)
    {
      freeIDList.erase(freeIDList.begin() + i);
      break;
    }
  }
  return *this;
}
