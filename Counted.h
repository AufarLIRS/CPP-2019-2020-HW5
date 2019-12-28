//#ifndef COUNTED_H
#define COUNTED_H
#include <vector>
#include <exception>
#include <utility>

class IDException : public std::exception
{
  virtual const char* what() const throw();
};

class Counted
{
  static std::vector<int> freeIDList;
  int id;
  static int lastID;

public:
  Counted();
  int getId();

  Counted(const Counted& a) = delete;
  Counted& operator=(const Counted& a) = delete;
  ~Counted();
  Counted& operator=(Counted&& a);
  Counted(const Counted&& a);
};

//#endif  // COUNTED_H
