#include <algorithm>
#include <iostream>
#include <vector>
class test {
private:
  int x = 1;
  int some_func() { return x; }

public:
  void Lambda() {
    std::vector<int> some_list;
    int total = 0;
    int value = 1;
    for (int i = 0; i < 5; ++i)
      some_list.push_back(i);
    std::for_each(begin(some_list), end(some_list), [&, value, this](int x) {
      total += x * value * this->some_func();
    });
    std::cout << total << std::endl;
  };
};

int main(void) {
  test t;
  t.Lambda();
  return 0;
};