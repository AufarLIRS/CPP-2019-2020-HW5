#ifndef COUNTED_H
#define COUNTED_H

class Counted
{
  static int count_;
  int id_;

public:
  Counted();
  ~Counted();
  int getID();
  Counted(const Counted&) = delete;
  Counted& operator=(const Counted&) = delete;
};

#endif  // COUNTED_H
