#include <iostream>
#include <memory>
using namespace std;

struct test {
  float x = 0.f;
  float y = 0.f;
};

int main(void) {
  unique_ptr<test> ptr1(new test());
  shared_ptr<test> ptr2(new test());

  ptr1->y = 19;
  ptr2->x = 100;
  return 0;
}