#include<iostream>
using namespace std;

class A {
public:
	virtual void print() {
		cout << "Class A is called!!!" << endl;
	}
	void print(char ch) {
		cout << "Base Class A is called!!!" << endl;
	}
};

class B: public A {
public:
	void print() override {
		cout << "Sub Class B is called!!!" << endl;
	}
};

class C: public B {
public:
	void print() override {
		cout << "Sub Class C is called!!!" << endl;
	}
};

class test {
public:
	test() {
		A objA;
		A* ptrA = &objA;
		ptrA->print('A'); //static bound
		B objB;
		A* ptrB = &objB;
		ptrB->print(); //dynamic bound
		C objC;
		A* ptrC = &objC;
		ptrC->print(); //dynamic bound
	}
};

int main()
{
	test T;
	return 0;
}
