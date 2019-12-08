#ifndef COUNTED_H
#define COUNTED_H

class Counted
{
  int id_;
  static int count_;

public:
  Counted();
  ~Counted();
  int getId();
  Counted(const Counted&) = delete;
  Counted& operator=(const Counted&) = delete;
  Counted(Counted&&) = delete;
  Counted& operator=(Counted&&) = delete;
};

#endif  // COUNTED_H
