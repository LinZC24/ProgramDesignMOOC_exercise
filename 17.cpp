#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
  private:
    int row, col;
    int **r;
  public:
    Array2() {}
    Array2(int x, int y):row(x), col(y) {
      if(x == 0) r = NULL;
      else {
        r = new int*[row];
        for(int i = 0; i < col; i++) {
          r[i] = new int[col];
        }
      }
    }
    int * operator[](int i) {
      return r[i];
    }
    int operator()(int i, int j) {
      return r[i][j];
    }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}