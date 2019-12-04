#ifndef COUNTED_H
#define COUNTED_H

class Counted
{
  static int count_;
  int id_;

public:
  int getID();
  Counted();
  Counted(const Counted&) = delete;
  Counted& operator=(const Counted&) = delete;
  Counted(Counted&& r);
  Counted& operator=(Counted&& r);
  ~Counted() = default;
};

#endif  // COUNTED_H
