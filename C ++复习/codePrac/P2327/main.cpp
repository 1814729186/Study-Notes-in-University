#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <thread>
#include<mutex>
using namespace std;
std::mutex mtx;	//�����������������߳�ʵ�ֻ���ִ��

struct S {
	int i = 0;
	S() {
		mtx.lock();//����
		cout << "S() called,i = " << i << endl;
		mtx.unlock();//����
	}
};
thread_local S gs;	//�̱߳��ر���
void foo() {
	mtx.lock();
	gs.i += 1;
	cout << "In foo,gs is at " << &gs << " ,gs.i = " << gs.i << endl;
	mtx.unlock();
}
void bar() {
	std::lock_guard<std::mutex> lock(mtx);	//������ֱ����ǰ���������
	gs.i += 4;
	cout << "In bar,gs is at " << &gs << " ,gs.i = " << gs.i << endl;
	//std::lock_guard<std::mutex> unlock(mtx);//��ʹ�����쳣�����д���û��ִ�У�Ҳ�����
}
int main() {
	std::thread a(foo), b(bar);	//���������̶߳���
	a.join();
	b.join();
	cout << "In main,gs is at " << &gs << " ,gs.i = " << gs.i << endl;
	return 0;
}
