#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
  private:
    string str;
  public:
    CHugeInt(int x) {
      
    }
    CHugeInt(string s):str(s) {}

    CHugeInt & operator+(int n) {
      
    }
    friend ostream & operator<<(ostream & o, const CHugeInt & c) {
      o << c.str;
      return o;
    }
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}