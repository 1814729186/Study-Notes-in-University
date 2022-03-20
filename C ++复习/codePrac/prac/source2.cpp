#include <stdio.h>
#include <iostream>
#include <thread>
using namespace std;
typedef struct treeNode {
	int val;
	struct treeNode *leftChild, *rightChild;
}*Tree;
#define MAX_SIZE 100

//�ǵݹ�����
void preOrderTraverse(Tree tree) {
	//�������
	//��ջ��ȡ��һ���ڵ㣬���ʣ�Ȼ��ѹջ��������Ȼ��ѹջ������
	struct treeNode* stack[MAX_SIZE],*curNode;
	int stackPointer = 0;
	//ѹջͷ�ڵ�
	stack[stackPointer++] = tree;
	while (stackPointer) {
		//ȡ��Ԫ��
		curNode = stack[--stackPointer];
		//����
		cout << curNode->val;
		//ѹջ��������ѹջ������
		if(curNode->rightChild) stack[stackPointer++] = curNode->rightChild;
		if(curNode->leftChild)stack[stackPointer++] = curNode->leftChild;
	}
}
//�ǵݹ�����
void midOrderTraverse(Tree tree) {
	//�������
	//������ȫ�����ν�ջֱ��������������
	struct treeNode* stack[MAX_SIZE], * curNode;
	int stackPointer = 0;
	curNode = tree;
	do {
		//ȫ�����ѹջ
		while (curNode) {
			stack[stackPointer++] = curNode;
			curNode = curNode->leftChild;
		}
		//��ջ�����ʸýڵ㣬����ͬ���ķ�ʽ�������ҽڵ�
		if (stackPointer) {
			curNode = stack[--stackPointer];	//��ջ
			cout << curNode->val;
			curNode = curNode->rightChild;
		}
	} while (stackPointer||curNode);		//ջ�ǿջ��ߵ�ǰ�Դ����ҽڵ�δ����
}
//�ǵݹ����
void postOrderTraverse(Tree tree) {
	//��������
	struct treeNode* pre;	//preָ��
	struct treeNode* stack[MAX_SIZE], * curNode=tree;
	int stackPointer = 0, flag = 0;
	if (!tree) return;
	do {
		//������ȫ����ջ
		while (curNode) {
			stack[stackPointer++] = curNode;
			curNode = curNode->leftChild;
		}
		//���ñ�Ǻ�ǰ��ָ��
		pre = nullptr; flag = 1;
		while (stackPointer && flag) {
			curNode = stack[stackPointer - 1];//���ջ��Ԫ����û�������������������Ƿ��Ѿ�����
			if (curNode->rightChild == pre) {	//���������Ѿ���������ʸýڵ㣬��Ҳ����û����������
				cout << curNode->val;
				stackPointer--;
				pre = curNode;
			}
			else {
				curNode = curNode->rightChild;	//������δ���ʣ�����Ҫ�ȴ������ӽڵ�
				flag = 0;
			}
		}
	}while (stackPointer);
}


//��д��������
void postOrder(Tree tree) {
	struct treeNode* curNode = tree,*pre;
	struct treeNode* stack[MAX_SIZE];
	int top = 0, flag;
	if (!tree) return;
	do {
		//������Ԫ����ջ
		while (curNode) {
			stack[top++] = curNode;
			curNode = curNode->leftChild;
		}
		//���ջ��Ԫ��
		flag = 1; pre = nullptr;
		while (top && flag) {
			curNode = stack[top - 1];
			if (curNode->rightChild == pre) {
				cout << curNode->val;
				top--;
				pre = curNode;
			}
			else {
				curNode = curNode->rightChild;
				flag = 0;
			}
		}
	} while (curNode);
}



int main() {
	
}