#include <iostream>
#include <string>
using namespace std;

struct A {
	int n;
	A() { };
	A(int n_ ):n(n_) { }
// 在此处补充你的代码
};
int main()
{
	A c;
	const A a(10);
	c = a + A(30);
	cout << c.n << endl; 
	return 0;
}