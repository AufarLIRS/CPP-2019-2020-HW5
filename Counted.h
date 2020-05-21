//#ifndef COUNTED_H
#define COUNTED_H
#include <vector>
#include <exception>
#include <utility>
#include <cstddef>

class IDException : public std::exception
{
  virtual const char* what() const throw();
};

class Counted
{
  static std::vector<size_t> freeIDList;
  size_t id;
  static size_t lastID;

public:
  Counted();
  size_t getId();

  Counted(const Counted& a) = delete;
  Counted& operator=(const Counted& a) = delete;
  ~Counted();
  Counted& operator=(Counted&& a);
  Counted(const Counted&& a);
};

//#endif  // COUNTED_H
