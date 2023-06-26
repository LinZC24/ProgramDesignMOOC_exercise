#include <iostream>
#include <string>
#include <map>
using namespace std;

string redWarrior[5] {"dragon", "lion", "wolf", "ninja", "iceman"};
string blueWarrior[5] {"wolf", "dragon", "ninja", "iceman", "wolf"};

class operation;
class base {
  private:
    int hp;
    bool canBuild[5]{};
    int warriotCount[5]{};
  public:
    bool stop = false;
    base() {}
    base(int currentBaseHP):hp(currentBaseHP) {}
    //void build(int hp) {}
    void build(int clock) {

    }
    ~base() {}
};

class operation {
  private:
    int redID, blueID, clock;
  public:
    base redBase;
    base blueBase;
    operation() {}
    operation(int m):redBase(m), blueBase(m), redID(0), blueID(0), clock(0) {}
};

int main() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int m, dragonHP, ninjaHP, icemanHP, lionHP, wolfHP;
    cin >> m >> dragonHP >> ninjaHP >> icemanHP >> lionHP >> wolfHP;
    map<string, int> warriorHP;
    warriorHP["dragon"] = dragonHP;
    warriorHP["ninja"] = ninjaHP;
    warriorHP["iceman"] = icemanHP;
    warriorHP["lion"] = lionHP;
    warriorHP["wolf"] = wolfHP;
    cout << "Case:" << i << endl;
    operation o(m);
    while(!o.redBase.stop && !o.blueBase.stop) {

    }
  }
}