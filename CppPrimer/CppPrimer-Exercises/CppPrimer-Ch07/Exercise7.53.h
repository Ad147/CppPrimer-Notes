// Exercise7.53.h
// Ad
// Define your own version of Debug.

#ifndef EXERCISE_7_53_H
#define EXERCISE_7_53_H

class Debug
{
public:
  constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
  constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
  constexpr bool any() { return hw || io || other; }
  void set_hw(bool b) { hw = b; }
  void set_io(bool b) { io = b; }
  void set_other(bool b) { other = b; }

private:
  bool hw;
  bool io;
  bool other;
};

#endif