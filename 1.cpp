//填空，使得输出结果是：5,3
#include <iostream>
using namespace std;
class A
{
	public:
	int x;
	int getX() { return x; }	
};
void swap(
  A & a, A & b
// 在此处补充你的代码
)
{
	int  tmp = a.x;
	a.x = b.x;
	b.x = tmp;
}
int main()
{
	A a,b;
	a.x = 3;
	b.x = 5;
	swap(a,b);
	cout << a.getX() << "," << b.getX();
	return 0;
}