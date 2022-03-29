#include <iostream>
#include <vector>
using namespace std;
/*
����ͼ�� ����೤ʱ����������������
	�ؼ�·����Ϣ
˼·������ͼģ�ͣ�ѭ��ִ�����¹��̣�
	��1������û�������������������֮����¼����Ӧʱ��

*/


#define MAXNUM 100005

//��¼�����ͱ�������ϵ
int D[MAXNUM];//����ʱ��
//ͼ�ڵ�
typedef struct node{
	int time; //ʱ�仨��
	int relyNum; //����������������������������Ϊ-1ʱ����ʾ�������Ѿ����
	//vector<int> relays;//������ϵ����
	vector<int>beRely;//��������ϵ����
	int beginTime=0; //�ܹ���ʼ��ʱ��
	int endTime=0; //������ʱ��
}node;

long long sumTime(node*tasks,int N) {
	//��������ͼ�ṹ
	long long endTime = 0;
	bool flag;
	while (1) {
		flag = true;
		//�������в�����������ϵ�Ľڵ���Ϣ
		for (int i = 0; i < N; i++) {
			if (tasks[i].relyNum == 0) {//�������κνڵ�
				tasks[i].relyNum = -1; //��ɸ�����
				//���������ʱ��Ϊ�ܹ���ʼ��ʱ�� + ʱ�仨��
				tasks[i].endTime = tasks[i].beginTime + tasks[i].time;
				//���±�������ϵ
				for (int j = 0; j < (int)tasks[i].beRely.size(); j++) {
					int index = tasks[i].beRely[j];
					tasks[index].relyNum--;	//�������е�������Ϣ
					//�����ܹ���ʼ��ʱ��
					if(tasks[index].beginTime < tasks[i].endTime)
						tasks[index].beginTime = tasks[i].endTime;
					//�ҳ���ɾ��TODO ��ʱ����
				}
				flag = false;
			}
		}
		//�����˳�״̬
		if (flag) break;
	}
	//��ȡ���Ľ���ʱ��
	for (int i = 0; i < N; i++) {
		if (endTime < tasks[i].endTime) endTime = tasks[i].endTime;
	}
	return endTime;
}

/*
2
3
5 0
10 1 1
15 1 1
4
3 0
4 0
7 1 1
6 2 1 2
*/
/*
1
3
5 0
10 1 1
15 1 1
*/

int main() {
	int T, N;
	cin >> T;
	int relayTask;
	for (int i = 0; i < T; i++) {
		//����ÿ����Ϣ
		cin >> N;
		//�������ݽṹ
		node* tasks = new node[N];
		for (int j = 0; j < N; j++) {
			//����������Ϣ
			cin >> tasks[j].time >> tasks[j].relyNum;
			//����������ϵ
			for (int k = 0; k < tasks[j].relyNum; k++) {
				cin >> relayTask; //�����Ĺ�ϵ
				relayTask--;	//ʵ�ʱ�ʾʱ��ʹ�õ������±�
				//tasks[j].relays.push_back(relayTask);//������ϵ
				tasks[relayTask].beRely.push_back(j);//��������ϵ
			}
		}
		//���㲢���
		cout << sumTime(tasks, N) << endl;
		delete[] tasks;
	}


}