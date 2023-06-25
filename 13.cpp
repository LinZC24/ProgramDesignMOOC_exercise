#include <iostream>
#include <string>
#include <map>
using namespace std;

string redWarrior[5] {"dragon", "lion", "wolf", "ninja", "iceman"};
string blueWarrior[5] {"wolf", "dragon", "ninja", "iceman", "wolf"};

class base {
  private:
    int hp, id;
    bool stopBuilding = false;
  public:
    base(int currentBaseHP):hp(currentBaseHP) {}
    void pause(int hp, int id) {
      
    }

};

class operation {
  private:
    map<string, int> redWarriorHP;
    map<string, int> blueWarriorHP;
    friend base;
    base redBase;
    base blueBase;
  public:
    operation() {}
    operation(int m, int dHP, int nHP, int iHP, int lHP, int wHP):redBase(m), blueBase(m)  {
      for(int i = 0; i < 5; i++) {
        redWarriorHP[redWarrior[i]]
      }
    }
};

int main() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int m, dragonHP, ninjaHP, icemanHP, lionHP, wolfHP;
    cin >> m >> dragonHP >> ninjaHP >> icemanHP >> lionHP >> wolfHP;
    cout << "Case:" << i << endl;
    operation o;
  }
}