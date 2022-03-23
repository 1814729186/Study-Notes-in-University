#include <iostream>
#include <vector>
#include<memory>
using namespace std;
void quick_sort(vector<int>& nums, int low, int high);
int partition(vector<int>& nums, int low, int high);
void MergeSort(vector<int>&nums);
void Merge_Sort(vector<int>& nums, int low, int high, vector<int>& buffer);
void Merge(vector<int>&nums, int low, int mid, int high, vector<int>& buffer);

void quick_sort(vector<int> &nums,int low,int high) {
	//��������
	if (low < high) {
		int pos = partition(nums, low, high);
		quick_sort(nums, low, pos-1);
		quick_sort(nums, pos+1, high);
	}
}
//����
int partition(vector<int>& nums,int low,int high) {
	int pivot = nums[low];
	while (low < high) {
		//���Ҳ�ı�pivot��Ľ��������
		while (low<high&&nums[high] >= pivot) high--;
		nums[low] = nums[high];
		//������pivot��Ľ������Ҳ�
		while (low < high && nums[low] <= pivot) low++;
		nums[high] = nums[low];
	}
	nums[low] = pivot;
	return low;
}

//�鲢����
void MergeSort(vector<int>&nums) {
	vector<int> buffer(nums.size());
	Merge_Sort(nums, 0, nums.size() - 1,buffer);
}

void Merge_Sort(vector<int>& nums,int low,int high,vector<int>&buffer) {
	//��������
	if (low < high) {
		int mid = (low + high) / 2;
		Merge_Sort(nums,low,mid,buffer);
		Merge_Sort(nums,mid + 1, high,buffer);
		//�ϲ�
		Merge(nums, low, mid, high,buffer);
	}
}
void Merge(vector<int>&nums, int low,int mid,int high,vector<int> &buffer) {
	//�ϲ����γ�һ�������
	//������buffer��
	for (int i = low; i <= high; i++) {
		buffer[i] = nums[i];
	}
	//�ϲ�
	int i, j, k;
	for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++) {
		if (buffer[i] <= buffer[j]) {
			nums[k] = buffer[i++];
		}
		else {
			nums[k] = buffer[j++];
		}
	}
	//�ϲ�δ��ɺϲ���
	while (i <= mid) { nums[k++] = nums[i++]; }
	while (j <= high) { nums[k++] = nums[j++]; }
}



int main() {
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(9);
	nums.push_back(10);
	//MergeSort(nums);
	quick_sort(nums, 0, nums.size() - 1);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	int a=0;
	(++a)++;
	++++a;


}