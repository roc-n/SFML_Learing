#include <functional>
#include <iostream>
using namespace std;
int add(int a, int b) { return a + b; }
int main(void) {
  //   std::function
  std::function<int(int, int)> add1 = &add;
  std::function<int(int, int)> add2 = [](int a, int b) { return a + b; };
  std::cout << "The add1 function: " << add1(1, 2)
            << "\nThe add2 function: " << add2(1, 2) << std::endl;
  // std::bind
  std::function<int(int)> increase = std::bind(&add, std::placeholders::_1, 1);
  int increased = increase(5);
  std::cout << "The increased function: " << increased << std::endl;
  return 0;
}