#include<iostream>
#include <vector>
#include <list>
using namespace std;

/*
	��rBrotherָ����Ķ��������ڿռ临�Ӷ�O(1)��ʵ��rBrother�ĸ���
*/

typedef struct node {
	int num; //�ڵ��ţ��ڵ���Ϊ-1��ʾ�ڵ㲻����
	struct node* lChild=nullptr, * rChild=nullptr;
	struct node* rBrother = nullptr; //���ֵܽڵ�ָ��
}node,*treeNode;

class tree {
	treeNode treenodes;
public:
	tree(vector<int>& nodes) {//ʹ�ô�null�ڵ�Ĳ���������鹹�����ṹ
		list < treeNode> queue;	//���нṹ�����ڹ�����
		treenodes = new node{nodes[0],nullptr,nullptr,nullptr};	
		treeNode curNode = treenodes;
		queue.push_back(curNode);
		for (int i = 1; i < nodes.size(); i += 2) {
			//�Ӷ�����ȡ��һ���ڵ㣬�Ӷ�����ȡ�����������������ӽڵ�����ӽڵ�
			curNode = *queue.begin(); queue.pop_front();
			if (nodes[i] != -1) {
				//�������ӽڵ�
				curNode->lChild = new node{nodes[i],nullptr,nullptr,nullptr};
				queue.push_back(curNode->lChild);
			}
			if (i+1<nodes.size()&&nodes[i + 1] != -1) {
				//�������ӽڵ�
				curNode->rChild = new node{ nodes[i + 1],nullptr,nullptr,nullptr };
				queue.push_back(curNode->rChild);
			}
		}
	}
	void setRBrotherPointer();
	void traverse();
};
//�������ӽڵ�ָ��
void tree::setRBrotherPointer() {
	treeNode pre = treenodes,curNode=treenodes;
	while (curNode) {
		//pre�����ֵ�ָ��ǰ�ڵ�����ӽڵ㣬���ӽڵ��ָ��ָ�����ӽڵ�
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
//����rBrotherָ��ʵ�ֲ������
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
	//������ 
	int n, num;
	cin >> n;
	vector<int>nodes;
	for (int i = 0; i < n; i++) {
		cin >> num;
		nodes.push_back(num);
	}
	//������
	tree T(nodes);
	T.setRBrotherPointer();
	//��������Ϣ
	T.traverse();
}