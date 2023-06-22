#include <iostream>
#include <algorithm>
#include <string> 
#include <queue> 
#include <set>
#include <vector>
using namespace std;
int main()
{
// 在此处补充你的代码
q.push(2.4);
	q.push(3.8);
	q.push(1.8);
	q.push(4.9);
	cout << q.top()<<endl;
	q.pop();
	cout << q.top()<<endl;
	q.pop();
	cout << q.top()<<endl;
	q.pop();
	q.push(8.8);	
	while(! q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}
	return 0;
}