#include <iostream>
using namespace std;
// 在此处补充你的代码
class Animal {
  public:
    static int number;
    Animal() {}
    virtual ~Animal() {
      number--;
    }
};

class Dog: public Animal {
  public:
    static int number;
    Dog() {
      Animal::number++;
      Dog::number++;
    }
    virtual ~Dog() {
      number--;
    }
};

class Cat: public Animal {
  public:
    static int number;
    Cat() {
      Animal::number++;
      Cat::number++;
    }
    virtual ~Cat() {
      number--;
    }
};

int Animal::number = 0;
int Dog::number = 0;
int Cat::number = 0;

void print() {
	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}