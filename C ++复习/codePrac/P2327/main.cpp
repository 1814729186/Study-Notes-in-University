#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <iostream>
#include <vector>
using namespace std;


//KMP�㷨ʵ��
vector<int> get_next(string T) {
	vector<int> next(T.length(),0);
	int i = 0, j = -1;	//ɨ�����
	next[0] = -1;		//��׼ֵ
	while (i < T.length()-1) {	//��ǰ���ɨ��
		if (j == -1 || T[i] == T[j]) {	//j==-1��ʾ��ͷ��ʼ��
			++i; ++j;
			//next[i] = j;
			if (T[i] != T[j]) next[i] = j;	//����ͬ������
			else next[i] = next[j];			//��ͬ
		}
		else j = next[j];
	}
	return next;
}
int Index_KMP(string s, string t) {
	vector<int>next = get_next(t);
	int i = 0, j = 0;
	while (i < (int)s.length() && j < (int)t.length()) {	//��Ҫ����ǿת
		if (j == -1 || s[i] == t[j]) {
			++i; ++j;
		}
		else {
			j = next[j];
		}
	}
	if (j >= t.length()) {
		return i - t.length();
	}
	else {
		return -1;
	}
}

vector<int> getNextVal(string t) {
	vector<int> next(t.length());
	//���next����
	int i = 0,j = -1;
	next[0] = -1;
	while (i < t.length() - 1) {
		if (j == -1 || t[i] == t[j]) {
			i++; j++;
			if (t[i] != t[j]) next[i] = j;
			else next[i] = next[j];
		}
		else j = next[j];
	}
	return next;
}
int KMP(string s, string t) {
	vector<int> next = getNextVal(t);
	int i = 0, j = 0;
	while (i < (int)s.length()  && j < (int)t.length() ) {
		if (j == -1 || s[i] == t[j]) { //�����ȽϺ���
			i++; j++;
		}
		else j = next[j];
	}
	if (j >= t.length())
		return i - t.length();
	else return -1;
}



int main() {
	string s, t;
	while (1) {
		cin >> s;
		if (!s.compare("#quit")) break;
		cin >> t;
		cout << KMP(s, t) << endl;
	}
}
