#ifndef COUNTED_H
#define COUNTED_H

class Counted
{
  int id_;
  static int count_;

public:
  Counted();
  ~Counted();
  Counted(const Counted&) = delete;
  Counted(Counted&& r);
  Counted& operator=(Counted&& r) = delete;
  Counted& operator=(const Counted&) = delete;
  int getId();
};

#endif  // COUNTED_H
