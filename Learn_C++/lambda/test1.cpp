#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  std::vector<int> test_list;
  int total = 0;
  for (int i = 0; i < 5; ++i) {
    test_list.push_back(i);
  }
  std::for_each(begin(test_list), end(test_list),
                [&total](int x) { total += x; });
  cout << total << endl;
  return 0;
}