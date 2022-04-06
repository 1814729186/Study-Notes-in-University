#include<iostream>
#include <vector>
#include <list>
using namespace std;

/*
	带rBrother指针域的二叉树，在空间复杂度O(1)下实现rBrother的更新
*/

typedef struct node {
	int num; //节点编号，节点编号为-1表示节点不存在
	struct node* lChild=nullptr, * rChild=nullptr;
	struct node* rBrother = nullptr; //右兄弟节点指针
}node,*treeNode;

class tree {
	treeNode treenodes;
public:
	tree(vector<int>& nodes) {//使用带null节点的层序遍历数组构建树结构
		list < treeNode> queue;	//队列结构，用于构建树
		treenodes = new node{nodes[0],nullptr,nullptr,nullptr};	
		treeNode curNode = treenodes;
		queue.push_back(curNode);
		for (int i = 1; i < nodes.size(); i += 2) {
			//从队列中取出一个节点，从队列中取出两个数，创建左子节点和右子节点
			curNode = *queue.begin(); queue.pop_front();
			if (nodes[i] != -1) {
				//创建左子节点
				curNode->lChild = new node{nodes[i],nullptr,nullptr,nullptr};
				queue.push_back(curNode->lChild);
			}
			if (i+1<nodes.size()&&nodes[i + 1] != -1) {
				//创建右子节点
				curNode->rChild = new node{ nodes[i + 1],nullptr,nullptr,nullptr };
				queue.push_back(curNode->rChild);
			}
		}
	}
	void setRBrotherPointer();
	void traverse();
};
//设置右子节点指针
void tree::setRBrotherPointer() {
	treeNode pre = treenodes,curNode=treenodes;
	while (curNode) {
		//pre的右兄弟指向当前节点的左子节点，左子节点的指针指向右子节点
		if (curNode->lChild) {
			if (pre) pre->rBrother = curNode->lChild;
			pre = curNode->lChild;
		}
		if (curNode->rChild) {
			pre->rBrother = curNode->rChild;
			pre = curNode->rChild; 
		}
		curNode = curNode->rBrother;
	}
}
//利用rBrother指针实现层序遍历
void tree::traverse() {
	treeNode curNode = treenodes;
	while (curNode) {
		cout << curNode->num << " ";
		curNode = curNode->rBrother;
	}
}

/*
9
1 2 3 4 5 6 7 8 9
10
1 2 3 -1 4 -1 5 6 -1 7
*/

int main() {
	//创建树 
	int n, num;
	cin >> n;
	vector<int>nodes;
	for (int i = 0; i < n; i++) {
		cin >> num;
		nodes.push_back(num);
	}
	//创建树
	tree T(nodes);
	T.setRBrotherPointer();
	//遍历树信息
	T.traverse();
}