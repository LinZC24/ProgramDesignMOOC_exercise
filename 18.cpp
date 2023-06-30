#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
  private:
    char str[210];
    //int len;
  public:
    void reverse(char* s) {
      int i = 0, j = strlen(s) - 1;
      while(i <= j) {
        swap(s[i], s[j]);
        i++;
        j--;
      }
    }
    CHugeInt(int x) {
      memset(str, '\0', sizeof(str));
      sprintf(str, "%d", x);
      //len = strlen(str);
      reverse(str);
    }
    CHugeInt(char* s) {
      memset(str, '\0', sizeof(str));
      strcpy(str, s);
      //len = strlen(str);
      reverse(str);
    }
    CHugeInt operator+(const CHugeInt & b) {
      CHugeInt t(0);
      int a = 0;
      for(int i = 0; i < 210; i++) {
        char c1 = str[i], c2 = b.str[i];
        if(c1 == 0 && c2 == 0 && a == 0) break;
        if(c1 == 0) c1 = '0';
        if(c2 == 0) c2 = '0';
        int k = c1 - '0' + c2 - '0' + a;
        a = k / 10;
        t.str[i] = (k % 10) + '0';
      }
      return t;
    }
    CHugeInt operator+(int n) {
      return *this + CHugeInt(n);
    }
    friend CHugeInt operator+(int n, CHugeInt & a) {
      return a + n;
    }
    CHugeInt & operator+=(int n) {
      *this = *this + n;
      return *this;
    }
    CHugeInt & operator++() {
      *this = *this + 1;
      return *this;
    }
    CHugeInt operator++(int) {
      CHugeInt temp(*this);
      *this = *this + 1;
      return temp;
    }
    friend ostream & operator<<(ostream & o, const CHugeInt & c) {
      for(int i = strlen(c.str) - 1; i >= 0; i--) {
        o << c.str[i];
      }
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