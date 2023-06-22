#include <iostream>
#include <algorithm>
#include <string> 
using namespace std;

class A {
public:
// 在此处补充你的代码
};
class B:public A 
{
public: 
	
	~B() { cout << "destructor B" << endl; } 
	
} ;
int main()
{
	A * p = new B();
	delete p;
	return 0;
}