#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(T* x, T* y) {
// 在此处补充你的代码
  T result = *x;
  for(T* i = x + 1; i < y; i++) {
    result += *i;
  }
  return result;
}
int main() {
	string array[4] = { "Tom","Jack","Mary","John"};
	cout << SumArray(array,array+4) << endl;
	int a[4] = { 1, 2, 3, 4};  //提示：1+2+3+4 = 10
	cout << SumArray(a,a+4) << endl;
	return 0;
}