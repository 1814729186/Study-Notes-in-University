#include <iostream>
#include <vector>
using namespace std;
/*
甘特图： 计算多长时间才能完成所有任务
	关键路径信息
思路：构建图模型，循环执行如下过程：
	（1）查找没有依赖的任务，优先完成之。记录下相应时间

*/


#define MAXNUM 100005

//记录依赖和被依赖关系
int D[MAXNUM];//花费时间
//图节点
typedef struct node{
	int time; //时间花费
	int relyNum; //依赖任务数，当依赖任务数设置为-1时，表示该任务已经完成
	//vector<int> relays;//依赖关系数组
	vector<int>beRely;//被依赖关系数组
	int beginTime=0; //能够开始的时间
	int endTime=0; //结束的时间
}node;

long long sumTime(node*tasks,int N) {
	//遍历所有图结构
	long long endTime = 0;
	bool flag;
	while (1) {
		flag = true;
		//查找所有不存在依赖关系的节点信息
		for (int i = 0; i < N; i++) {
			if (tasks[i].relyNum == 0) {//不依赖任何节点
				tasks[i].relyNum = -1; //完成该任务
				//更新其结束时间为能够开始的时间 + 时间花费
				tasks[i].endTime = tasks[i].beginTime + tasks[i].time;
				//更新被依赖关系
				for (int j = 0; j < (int)tasks[i].beRely.size(); j++) {
					int index = tasks[i].beRely[j];
					tasks[index].relyNum--;	//更新其中的依赖信息
					//更新能够开始的时间
					if(tasks[index].beginTime < tasks[i].endTime)
						tasks[index].beginTime = tasks[i].endTime;
					//找出来删除TODO 暂时不做
				}
				flag = false;
			}
		}
		//设置退出状态
		if (flag) break;
	}
	//获取最大的结束时间
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
		//读入每组信息
		cin >> N;
		//创建数据结构
		node* tasks = new node[N];
		for (int j = 0; j < N; j++) {
			//读入数据信息
			cin >> tasks[j].time >> tasks[j].relyNum;
			//输入依赖关系
			for (int k = 0; k < tasks[j].relyNum; k++) {
				cin >> relayTask; //依赖的关系
				relayTask--;	//实际表示时是使用的数组下标
				//tasks[j].relays.push_back(relayTask);//依赖关系
				tasks[relayTask].beRely.push_back(j);//被依赖关系
			}
		}
		//计算并输出
		cout << sumTime(tasks, N) << endl;
		delete[] tasks;
	}


}