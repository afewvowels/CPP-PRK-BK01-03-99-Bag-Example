#ifndef _BAG_H
#define _BAG_H

#include <cstdlib>
#include "bagProject.h"

using namespace std;

class Bag {
public:
  typedef int value_type;
  typedef size_t size_type;
  static const size_type CAPACITY = 30;

  Bag() { used = 0; }

  size_type erase(const value_type& target);
  bool erase_one(const value_type& target);
  void insert(const value_type& entry);

  void operator+=(const Bag& addend);

  size_type size() const { return used; };
  size_type count(const value_type& target) const;
private:
  value_type data[CAPACITY];
  size_type used;
};

Bag operator+(const Bag& b1, const Bag& b2);

#endif
