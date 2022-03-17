#include <stdio.h>
#include <iostream>
#include <thread>

template <typename T>

class A {
	friend T;
private:
	A() {}
	~A() {}
};
class B : virtual public A<B> {
public :
	B() {}
	~B() {}
};
class C : B {
public:
	C() {}
	~C() {}

};

int main() {
	
}