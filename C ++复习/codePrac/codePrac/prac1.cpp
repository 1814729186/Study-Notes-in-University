#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int main1() {
	//ˮ����Ϣ
	int T = 0;
	int n = 0;
	int sumLiquid = 0;//����ˮ��
	int lastH = 0;	//���ݵĸ߶���Ϣ
	int width = 0;//�ۻ����
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++) {
		//��ȡ����
		scanf_s("%d", &n);
		sumLiquid = 0;
		lastH = 0;
		width = 1;
		int* heights = (int*)malloc(sizeof(int) * n);	//������Ϣ
		//��˳�������Ϣ��ͳ���ҵ���ߴ�������Ϊ���ģ��ӷֱ���������м�ͳ����ˮ��
		int maxHeight = 0, maxHeightIndex = -1;
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &heights[j]);
			if (heights[j] > maxHeight) {
				maxHeight = heights[j];
				maxHeightIndex = j;
			}
		}
		//��1������ǰľ����ڻ������һ��ľ�壬�����ӵ���ˮ��Ϊ����һ�Ρ�ľ��߶�*��ˮ��ȣ�������һ��ľ��߶�Ϊ��ǰľ��߶ȣ���ˮ�����1
		//��2���Ҳ�ľ�������࣬����󴫵�ľ��߶����(������lastH)����ˮ���+1
	//��������
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
		//��������
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
