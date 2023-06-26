#include <iostream>
#include <string>
#include <map>
using namespace std;

string redWarrior[5] {"dragon", "lion", "wolf", "ninja", "iceman"};
string blueWarrior[5] {"wolf", "dragon", "ninja", "iceman", "wolf"};
map<string, int> warriorHP;

class base {
  private:
    int hp;
    bool canBuild[5]{};
    int warriotCount[5]{};
  public:
    bool stop = false;
    base() {}
    base(int currentBaseHP):hp(currentBaseHP) {
      for(int i = 0; i < 5; i++) {
        canBuild[i] = true;
      }
    }
    //void build(int hp) {}
    void nextID(int & id) {
      id++;
    }
    bool buildCheck(int & id, map<string, int> warriorHP) {
      
    }
    void build(int clock, int & id) {
      if(buildCheck(id, warriorHP)) {

      }
    }
    ~base() {}
};

class operation {
  private:
  public:
    base redBase;
    base blueBase;
    int redID, blueID, clock;
    operation() {}
    operation(int m):redBase(m), blueBase(m), redID(0), blueID(0), clock(0) {}
    void add() {
      clock++;
    }
};

int main() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int m, dragonHP, ninjaHP, icemanHP, lionHP, wolfHP;
    cin >> m >> dragonHP >> ninjaHP >> icemanHP >> lionHP >> wolfHP;
    warriorHP["dragon"] = dragonHP;
    warriorHP["ninja"] = ninjaHP;
    warriorHP["iceman"] = icemanHP;
    warriorHP["lion"] = lionHP;
    warriorHP["wolf"] = wolfHP;
    cout << "Case:" << i << endl;
    operation o(m);
    while(!o.redBase.stop && !o.blueBase.stop) {
      o.redBase.build(o.clock, o.redID);
      o.redBase.nextID(o.redID);
      o.blueBase.build(o.clock, o.blueID);
      o.blueBase.nextID(o.blueID);
      o.add();
    }
  }
}