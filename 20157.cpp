#include <iostream>
#include <algorithm>
#include <string> 
#include <queue> 
#include <set>
#include <map>
#include <vector> 
using namespace std;
int main()
{

	int a[10] = {1, 3, 2, 10,7, 18,20,31,47,59};
	sort(a,a+10);
	
	pair<int*,int*> p;
	
	p =
// 在此处补充你的代码
(a,a+10,18);
	
	cout << * (p.first) << "," << * (p.second) << endl; 
	return 0;
}