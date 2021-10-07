#include <iostream>
#include <string>
#include <utility>
#include <vector>

// void test(std::vector<int> &ss) {
//   std::vector<int> test;
//   test.push_back(ss[1]);
// }

int main() {
  int x = 20;
  int &&we = x * 99;

  std::string str = "Hello";
  std::vector<std::string> v;
  //调用常规的拷贝构造函数，新建字符数组，拷贝数据
  v.push_back(str);
  std::cout << "After copy, str is \"" << str << "\"\n";
  //调用移动构造函数，掏空str，掏空后，最好不要使用str
  v.push_back(std::move(str));
  std::cout << "After move, str is \"" << str << "\"\n";
  std::cout << "The contents of the vector are \"" << v[0] << "\", \"" << v[1]
            << "\"\n";

  std::vector<int> ss;
  std::vector<int> jojo;
  for (int i = 0; i < 10; ++i) {
    ss.push_back(i);
  }
  jojo.push_back(std::move(ss[1]));
  for (int i = 0; i < 10; ++i) {
    std::cout << ss[i] << " ";
  }
  std::cout << std::endl;
  //   int a = 100;
  //   int &&b = 100;
  //   b = 12;
  //   std::cout << b << std::endl;
  return 0;
}