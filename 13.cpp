#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

string redWarrior[5] {"iceman", "lion", "wolf", "ninja", "dragon"};
string blueWarrior[5] {"lion", "dragon", "ninja", "iceman", "wolf"};
map<string, int> warriorHP;

class base {
  private:
    int hp, color, canBuild, warriorID;
    bool canbuild[5]{};
    int warriotCount[5]{};
  public:
    bool stop = false;
    base() {}
    base(int currentBaseHP, int c):hp(currentBaseHP), color(c), canBuild(5), warriorID(0) {
      for(int i = 0; i < 5; i++) {
        canbuild[i] = true;
      }
    }
    void nextID(int & id) {
      id = (id + 1) % 5;
    }
    bool buildCheck(int & id, map<string, int> warriorHP) {
      //if(stop) return false;
      if(color == 0) {//蓝色
        if(hp >= warriorHP[blueWarrior[id]]) return true;
        else {
          while(hp < warriorHP[blueWarrior[id]] && canBuild > 0) {
            if(canbuild[id]) {
              canbuild[id] = false;
              canBuild--;
            }
            nextID(id);
          }
          if(canBuild == 0) return false;
          else return true;
        }
      } else if(color == 1) { //红色
        if(hp >= warriorHP[redWarrior[id]]) return true;
        else {
          while(hp < warriorHP[redWarrior[id]] && canBuild > 0) {
            if(canbuild[id]) {
              canbuild[id] = false;
              canBuild--;
            }
            nextID(id);
          }
          if(canBuild == 0) return false;
          else return true;
        }
      }
      return false;
    }
    void hpChange (int & h, int x) {
      h -= x;
    }
    void build(int clock, int & id) {
      if(stop) return;
      if(buildCheck(id, warriorHP)) {
        if(color == 0) {
          cout << setw(3) << setfill('0') << clock << " blue " << blueWarrior[id] << " " << (++warriorID) << " born with strength " << warriorHP[blueWarrior[id]] << ','<< (++warriotCount[id]) << " " << blueWarrior[id] << " in blue headquarter\n";
          hpChange(hp, warriorHP[blueWarrior[id]]);
        } else if(color == 1) {
          cout << setw(3) << setfill('0') << clock << " red " << redWarrior[id] << " " << (++warriorID) << " born with strength " << warriorHP[redWarrior[id]] << ','<< (++warriotCount[id]) << " " << redWarrior[id] << " in red headquarter\n";
          hpChange(hp, warriorHP[redWarrior[id]]);
        }
      } else {
        if(color == 0) {
          cout << setw(3) << setfill('0') << clock << " blue headquarter stops making warriors\n";
        } else if(color == 1) {
          cout << setw(3) << setfill('0') << clock << " red headquarter stops making warriors\n";
        }
        stop = true;
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
    operation(int m):redBase(m, 1), blueBase(m, 0), redID(0), blueID(0), clock(0) {}
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
    while(!o.redBase.stop || !o.blueBase.stop) {
      o.redBase.build(o.clock, o.redID);
      o.redBase.nextID(o.redID);
      o.blueBase.build(o.clock, o.blueID);
      o.blueBase.nextID(o.blueID);
      o.add();
    }
  }
}