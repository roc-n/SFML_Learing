#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
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

  //   int a = 100;
  //   int &&b = 100;
  //   b = 12;
  //   std::cout << b << std::endl;
  return 0;
}