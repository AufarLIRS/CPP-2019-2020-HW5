//#ifndef COUNTED_H
#define COUNTED_H
#include <vector>

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
};

//#endif  // COUNTED_H
