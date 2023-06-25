#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
// 在此处补充你的代码
  private:
    char name[25];
    int age, id;
    double score1, score2, score3, score4;
  public:
    void input() {
      cin.getline(name, 25, ',');
      cin >> age; cin.get();
      cin >> id; cin.get();
      cin >> score1; cin.get();
      cin >> score2; cin.get();
      cin >> score3; cin.get();
      cin >> score4; cin.get();
    }
    void calculate() {
      score1 = (score1 + score2 + score3 + score4) / 4;
    }
    void output() {
      cout << name << ',' << age << ',' << id << ',' << score1;
    }
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}