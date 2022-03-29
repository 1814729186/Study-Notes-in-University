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
			//无法造成伤害，必定失败
			return -1;
		}
		while (1) {
			//主角攻击
			monster_hp[i] -= (att - monster_def[i]);
			//状态检测,设置为战胜状态
			if (monster_hp[i] <= 0) {
				hp -= monster_hp[i];
				break;
			}
			//怪物攻击
			hp -= (monster_att[i] - def) > 0 ? (monster_att[i] - def) : 0;
			if (hp < minHp) minHp = hp;
		}
	}
	//完成战斗
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
		//角色数据读入
		cin >> att >> def;
		//怪物数据读入
		for (int j = 0; j < n; j++) {
			cin >> monster_att[j] >> monster_def[j] >> monster_hp[j];
		}
		//模拟整个战斗过程，初始生命值设置为0，记录生命值的最低值lowest，最终需要的生命值即为1-lowest
		cout << minHp(att, def, n)<<endl;
	}
	return 0;
}