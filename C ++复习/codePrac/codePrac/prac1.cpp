#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int main1() {
	//水量信息
	int T = 0;
	int n = 0;
	int sumLiquid = 0;//总蓄水量
	int lastH = 0;	//传递的高度信息
	int width = 0;//累积宽度
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++) {
		//读取输入
		scanf_s("%d", &n);
		sumLiquid = 0;
		lastH = 0;
		width = 1;
		int* heights = (int*)malloc(sizeof(int) * n);	//储存信息
		//按顺序读入信息，统计找到最高处，以其为中心，从分别从两端向中间统计蓄水量
		int maxHeight = 0, maxHeightIndex = -1;
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &heights[j]);
			if (heights[j] > maxHeight) {
				maxHeight = heights[j];
				maxHeightIndex = j;
			}
		}
		//（1）若当前木板高于或等于上一块木板，则增加的蓄水量为“上一次”木板高度*蓄水宽度，更新上一次木板高度为当前木板高度，蓄水宽度置1
		//（2）右侧木板低于左侧，则向后传递木板高度情况(不更新lastH)，蓄水宽度+1
	//从左往右
		for (int j = 0; j <= maxHeightIndex; j++) {
			if (lastH <= heights[j]) {
				sumLiquid += lastH * width;
				width = 1;
				lastH = heights[j];
			}
			else {
				width++;
			}
		}
		lastH = 0;
		//从右往左
		for (int j = n - 1; j >= maxHeightIndex; j--) {
			if (lastH <= heights[j]) {
				sumLiquid += lastH * width;
				width = 1;
				lastH = heights[j];
			}
			else {
				width++;
			}
		}
		printf("%d",sumLiquid);
	}
	return 0;
}
