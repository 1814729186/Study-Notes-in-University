#include <stdio.h>
//extern void f();
//static void f();


extern void f();

static void f(int a) {
	printf_s("hhh");
	return;
}
int main() {
	f(1);
	int i;
	for (int i = 0; i < 3; i++) {}
	return 0;
}