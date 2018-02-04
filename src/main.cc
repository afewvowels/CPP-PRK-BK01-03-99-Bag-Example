#include <iostream>
#include "bag.h"
#include "bagProject.h"


void get_ages(Bag& ages);

void check_ages(Bag& ages);

using namespace std;

int main() {
  Bag ages;

  get_ages(ages);
  check_ages(ages);

  cout << "Program ran\n";

  return EXIT_SUCCESS;
}

void get_ages(Bag& ages) {
  int user_input;

  cout << "Type the ages in your family.\n";
  cout << "Type a negative number when you are done:\n";

  cin >> user_input;
  while(user_input>=0) {
    if(ages.size()<ages.CAPACITY) {
      ages.insert(user_input);
    }
    else {
      cout << "I have run out of room and can't add that age.\n";
    }
    cin >> user_input;
  }
}

void check_ages(Bag& ages) {
  int user_input;

  cout << "Type those ages again. Press return after each age:\n";
  while(ages.size()>0) {
    cin >> user_input;
    if(ages.erase_one(user_input)) {
      cout << "Yes, I've found that age and removed it.\n";
    }
    else {
      cout << "No, that age does not occur!\n";
    }
  }
}
