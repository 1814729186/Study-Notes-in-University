#define _CRT_SECURE_NO_WARNINGS
/*#include <stdio.h>
int m = scanf_s("%d",&m);
const int n = m +10;
int main() {
	printf("main begin\n");
	//编程问题：黄金时间
	printf("%d %d\n", m, n);
	return 0;
}*/

#include <iostream>

using namespace std;

class A {
	mutable int v1;
	static int v2;
	friend void main();
	class B {
		int b;
	public:
		B(int b) :b(b) {}
	}b;
	A(int a):v1(a),b(0) {}
};
void main() {
	const A a(1);
	cout << a.v1;
	a.v1 = 1;
}
