#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <thread>
#include<mutex>
using namespace std;
std::mutex mtx;	//共享锁变量，用于线程实现互斥执行

struct S {
	int i = 0;
	S() {
		mtx.lock();//加锁
		cout << "S() called,i = " << i << endl;
		mtx.unlock();//开锁
	}
};
thread_local S gs;	//线程本地变量
void foo() {
	mtx.lock();
	gs.i += 1;
	cout << "In foo,gs is at " << &gs << " ,gs.i = " << gs.i << endl;
	mtx.unlock();
}
void bar() {
	std::lock_guard<std::mutex> lock(mtx);	//加锁，直到当前作用域结束
	gs.i += 4;
	cout << "In bar,gs is at " << &gs << " ,gs.i = " << gs.i << endl;
	//std::lock_guard<std::mutex> unlock(mtx);//即使由于异常，该行代码没有执行，也会解锁
}
int main() {
	std::thread a(foo), b(bar);	//创建两个线程对象
	a.join();
	b.join();
	cout << "In main,gs is at " << &gs << " ,gs.i = " << gs.i << endl;
	return 0;
}
