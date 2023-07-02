#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

string redWarrior[5] {"iceman", "lion", "wolf", "ninja", "dragon"};
string blueWarrior[5] {"lion", "dragon", "ninja", "iceman", "wolf"};
map<string, int> warriorHP;
string weapon[3] {"sword", "bomb", "arrow"};

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
    bool buildCheck(int & id, map<string, int> warriorHP);
    void build (int clock, int & id);
    void state(int id, int color, int n);
    void hpChange (int & h, int x) {
      h -= x;
    }
    int getColor() {
      return color;
    }
    int getWarriotID() {
      return warriorID;
    }
    ~base() {}
};

class warrior {
  protected:
    int hp, id;
  public:
    warrior() {}
    warrior(int n, int h):id(n), hp(h) {}
};

class dragon:public warrior {
  private:
    double morale;
    string weapon;
  public:
    dragon(int n, double h, double bh, string w):warrior(n, h), weapon(w), morale(0) {
      morale = bh / h;
    }
    void print();
};

class ninja:public warrior {
  private:
    string weapon1, weapon2;
  public:
    ninja(int n, int h, string w1, string w2):warrior(n, h), weapon1(w1), weapon2(w2) {}
    void print();
};

class iceman:public warrior {
  private:
    string weapon;
  public:
    iceman(int n, int h, string w):warrior(n, h), weapon(w) {}
    void print();
};

class lion:public warrior {
  private:
    int loyalty;
  public:
    lion(int n, int h, int l):warrior(n, h), loyalty(l) {}
    void print();
};

class wolf:public warrior {
  private:
  public:
    wolf(int n, int h):warrior(n, h) {};
    void print();
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
      o.redBase.state(o.redID, o.redBase.getColor(), o.redBase.getWarriotID());
      o.redBase.nextID(o.redID);
      o.blueBase.build(o.clock, o.blueID);
      o.blueBase.state(o.blueID, o.blueBase.getColor(), o.blueBase.getWarriotID());
      o.blueBase.nextID(o.blueID);
      o.add();
    }
  }
}

bool base::buildCheck(int & id, map<string, int> warriorHP) {
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

void base::build (int clock, int & id) {
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

void base::state(int id, int color, int n) {
  if(stop) return;
  if(color == 0) {
    switch (id)
    {
    case 0: {
      lion l(n, warriorHP["lion"], hp);
      l.print();
      break;
    }
    case 1: {
      dragon d(n, warriorHP["dragon"], double(hp), weapon[n % 3]);
      d.print();
      break;
    }
    case 2: {
      ninja N(n, warriorHP["ninja"], weapon[n % 3], weapon[(n + 1) % 3]);
      N.print();
      break;
    }
    case 3: {
      iceman i(n, warriorHP["iceman"], weapon[n % 3]);
      i.print();
      break;
    }
    case 4: {
      break;
    }
    default:
      break;
    }
  } else if(color == 1) {
    switch (id)
    {
    case 0: {
      iceman i(n, warriorHP["iceman"], weapon[n % 3]);
      i.print();
      break;
    }
    case 1: {
      lion l(n, warriorHP["lion"], hp);
      l.print();
      break;
    }
    case 2: {
      break;
    }
    case 3: {
      ninja N(n, warriorHP["ninja"], weapon[n % 3], weapon[(n + 1) % 3]);
      N.print();
      break;
    }
    case 4: {
      dragon d(n, warriorHP["dragon"], double(hp), weapon[n % 3]);
      d.print();
      break;
    }
    default:
      break;
    }
  }
}

void dragon::print() {
  cout << "It has a " << weapon << ",and it's morale is ";
  printf("%.2f\n", morale);
}

void lion::print() {
  cout << "It's loyalty is " << loyalty << endl;
}

void ninja::print() {
  cout << "It has a " << weapon1 << " and a " << weapon2 << endl;
}

void iceman::print() {
  cout << "It has a " << weapon << endl;
}