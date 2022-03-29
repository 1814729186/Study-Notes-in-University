#include <iostream>

#include <vector>
using namespace std;

#define MAXNUM 105

int monster_att[MAXNUM];
int monster_def[MAXNUM];
int monster_hp[MAXNUM];

int minHp(int att,int def,int n) {
	int hp = 0, minHp=0;
	for (int i = 0; i < n; i++) {
		if (att <= monster_def[i]) {
			//�޷�����˺����ض�ʧ��
			return -1;
		}
		while (1) {
			//���ǹ���
			monster_hp[i] -= (att - monster_def[i]);
			//״̬���,����Ϊսʤ״̬
			if (monster_hp[i] <= 0) {
				hp -= monster_hp[i];
				break;
			}
			//���﹥��
			hp -= (monster_att[i] - def) > 0 ? (monster_att[i] - def) : 0;
			if (hp < minHp) minHp = hp;
		}
	}
	//���ս��
	return 1 - minHp;
}

/*
1
3
10 5
10 5 6
10 5 7
10 5 8
*/

int main() {
	int T, n;
	int att, def;
	int hp = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		//��ɫ���ݶ���
		cin >> att >> def;
		//�������ݶ���
		for (int j = 0; j < n; j++) {
			cin >> monster_att[j] >> monster_def[j] >> monster_hp[j];
		}
		//ģ������ս�����̣���ʼ����ֵ����Ϊ0����¼����ֵ�����ֵlowest��������Ҫ������ֵ��Ϊ1-lowest
		cout << minHp(att, def, n)<<endl;
	}
	return 0;
}