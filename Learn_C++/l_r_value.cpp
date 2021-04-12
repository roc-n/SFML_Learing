#include <iostream>
using namespace std;

void fun(int &lref) { cout << "l-value reference" << endl; }
void fun(int &&rref) { cout << "r-value reference" << endl; }
void fun(const int &lref) { cout << "l-value const reference" << endl; }

template <typename T> class DynamicArray {
public:
  explicit DynamicArray(int size) : m_size{size}, m_array{new T[size]} {
    cout << "Constructor: dynamic array is created!\n";
  }

  virtual ~DynamicArray() {
    delete[] m_array;
    cout << "Destructor: dynamic array is destroyed!\n";
  }

  // 复制构造函数
  DynamicArray(const DynamicArray &rhs) : m_size{rhs.m_size} {

    m_array = new T[m_size];
    for (int i = 0; i < m_size; ++i)
      m_array[i] = rhs.m_array[i];
    cout << "Copy constructor: dynamic array is created!\n";
  }

  // 复制赋值操作符
  DynamicArray &operator=(const DynamicArray &rhs) {
    cout << "Copy assignment operator is called\n";
    if (this == &rhs)
      return *this;

    delete[] m_array;

    m_size = rhs.m_size;
    m_array = new T[m_size];
    for (int i = 0; i < m_size; ++i)
      m_array[i] = rhs.m_array[i];

    return *this;
  }

  // 索引运算符
  T &operator[](int index) {
    // 不进行边界检查
    return m_array[index];
  }

  const T &operator[](int index) const { return m_array[index]; }

  int size() const { return m_size; }

  // 移动构造函数
  DynamicArray(DynamicArray &&rhs) : m_size{rhs.m_size}, m_array{rhs.m_array} {
    rhs.m_size = 0;
    rhs.m_array = nullptr;
    cout << "Move constructor: dynamic array is moved!\n";
  }

  // 移动赋值操作符
  DynamicArray &operator=(DynamicArray &&rhs) {
    cout << "Move assignment operator is called\n";
    if (this == &rhs)
      return *this;
    delete[] m_array;
    m_size = rhs.m_size;
    m_array = rhs.m_array;
    rhs.m_size = 0;
    rhs.m_array = nullptr;

    return *this;
  }

private:
  T *m_array;
  int m_size;
};

DynamicArray<int> arrayFactor(int size) {
  DynamicArray<int> arr{size};
  return arr;
}

int main(void) {
  int x = 10;
  const int y = 10;
  const int &lx1 = y; // const->const T
  const int &lx2 = x; // non-const->const T
  /*! const引用可以被右值初始化*/
  const int &lx3 = 100; // l_v->const T

  //   int &&rm = x; // l_v->r_l F
  /*! 右值引用一定不能被左值所初始化，只能用右值初始化*/
  int &&rm = x * 2; //
  rm = x; // 一旦初始化一个右值引用变量，该变量就成为了一个左值，可以被赋值

  fun(x);
  fun(rm); //输出为"l-value reference"证明此时rm为左值
  fun(12); //若将5行注释,输出"l-value const reference".
  fun(lx1);

  { DynamicArray<int> arr = arrayFactor(10); }

  return 0;
}