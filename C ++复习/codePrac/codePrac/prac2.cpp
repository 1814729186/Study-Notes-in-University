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
	int v1;
	friend void main();
	A(int a):v1(a) {}
};
void main() {
	A a(1);
	cout << a.v1;
}
