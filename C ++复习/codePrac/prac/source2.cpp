#include <stdio.h>
#include <iostream>
#include <thread>
using namespace std;
typedef struct treeNode {
	int val;
	struct treeNode *leftChild, *rightChild;
}*Tree;
#define MAX_SIZE 100

//非递归先序
void preOrderTraverse(Tree tree) {
	//先序遍历
	//从栈中取出一个节点，访问，然后压栈右子树，然后压栈左子树
	struct treeNode* stack[MAX_SIZE],*curNode;
	int stackPointer = 0;
	//压栈头节点
	stack[stackPointer++] = tree;
	while (stackPointer) {
		//取出元素
		curNode = stack[--stackPointer];
		//访问
		cout << curNode->val;
		//压栈右子树，压栈左子树
		if(curNode->rightChild) stack[stackPointer++] = curNode->rightChild;
		if(curNode->leftChild)stack[stackPointer++] = curNode->leftChild;
	}
}
//非递归中序
void midOrderTraverse(Tree tree) {
	//中序遍历
	//左子树全部依次进栈直到不存在左子树
	struct treeNode* stack[MAX_SIZE], * curNode;
	int stackPointer = 0;
	curNode = tree;
	do {
		//全部完成压栈
		while (curNode) {
			stack[stackPointer++] = curNode;
			curNode = curNode->leftChild;
		}
		//出栈，访问该节点，并以同样的方式处理其右节点
		if (stackPointer) {
			curNode = stack[--stackPointer];	//出栈
			cout << curNode->val;
			curNode = curNode->rightChild;
		}
	} while (stackPointer||curNode);		//栈非空或者当前仍存在右节点未访问
}
//非递归后续
void postOrderTraverse(Tree tree) {
	//后续遍历
	struct treeNode* pre;	//pre指针
	struct treeNode* stack[MAX_SIZE], * curNode=tree;
	int stackPointer = 0, flag = 0;
	if (!tree) return;
	do {
		//左子树全部入栈
		while (curNode) {
			stack[stackPointer++] = curNode;
			curNode = curNode->leftChild;
		}
		//设置标记和前序指针
		pre = nullptr; flag = 1;
		while (stackPointer && flag) {
			curNode = stack[stackPointer - 1];//检查栈顶元素有没有右子树或者右子树是否已经访问
			if (curNode->rightChild == pre) {	//若右子树已经访问则访问该节点，（也可能没有右子树）
				cout << curNode->val;
				stackPointer--;
				pre = curNode;
			}
			else {
				curNode = curNode->rightChild;	//右子树未访问，则需要先处理右子节点
				flag = 0;
			}
		}
	}while (stackPointer);
}


//手写后续遍历
void postOrder(Tree tree) {
	struct treeNode* curNode = tree,*pre;
	struct treeNode* stack[MAX_SIZE];
	int top = 0, flag;
	if (!tree) return;
	do {
		//将所有元素入栈
		while (curNode) {
			stack[top++] = curNode;
			curNode = curNode->leftChild;
		}
		//检查栈顶元素
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