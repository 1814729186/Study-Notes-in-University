#include <iostream>

using namespace std;

class A {
public:
	virtual void f() { cout << "A" << endl; };
};
class B {
public:
	virtual void f() { cout << "B" << endl; };
};
class C {
public:
	virtual void f() { cout << "C" << endl; };
};
class D :public A, public B, public C {
public:
};


int main() {
	D d;
	d.C::f();
	
}