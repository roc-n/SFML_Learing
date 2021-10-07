#include <iostream>
using namespace std;
enum class Enumration : unsigned int { val1, val2 = 0, val3 = 1000, val4 };
enum jojo { jo1, jo2, jo3 };
int main(void) {
  /*无法进行int和Enumration之间的比较*/
  //   if (Enumration::val2 == 200) {
  //     cout << "Error" << endl;
  //   }
  if (Enumration::val1 == Enumration::val2) {
    cout << "It'a good idea" << endl;
  } else {
    cout << "Error" << endl;
  }
  cout << static_cast<int>(Enumration::val1) << endl;
  return 0;
}