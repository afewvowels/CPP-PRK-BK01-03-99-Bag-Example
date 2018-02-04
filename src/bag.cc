#include <algorithm>
#include <cassert>
#include "bag.h"
#include "bagProject.h"

using namespace std;

const Bag::size_type Bag::CAPACITY;

Bag::size_type Bag::erase(const value_type& target) {
  size_type index=0;
  size_type many_removed=0;

  while(index<used) {
    if(data[index]==target){
      --used;
      data[index]=data[used];
      ++many_removed;
    }
    else {
      index++;
    }
  }

  return many_removed;
}

bool Bag::erase_one(const value_type& target) {
  size_type index;

  index = 0;
  while((index<used)&&(data[index] != target)) {
    index++;
  }

  if(index==used) {
    return false;
  }

  --used;
  data[index]=data[used];
  return true;
}

void Bag::insert(const value_type& entry) {
  assert(size() < CAPACITY);

  data[used]=entry;
  ++used;
}

void Bag::operator+=(const Bag& addend) {
  assert(size()+addend.size()<= CAPACITY);

  copy(addend.data,addend.data+addend.used,data+used);
  used+=addend.used;
}

Bag::size_type Bag::count(const value_type& target) const {
  size_type answer;
  size_type i;

  answer=0;
  for(i=0;i<used;++i) {
    if(target==data[i]) {
      ++answer;
    }
  }

  return answer;
}

Bag operator+(const Bag& b1, const Bag& b2) {
  Bag answer;

  assert(b1.size()+b2.size()<=Bag::CAPACITY);

  answer+=b1;
  answer+=b2;

  return answer;
}
