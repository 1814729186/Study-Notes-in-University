package main

//leetcode4 寻找两个正序数组的中位数

/**
解题思路：双指针向后移动，每步仅移动指向较小的值的指针，直到一共移动 (m+n-1)/2次
		要注意考虑到细节问题
执行结果：
执行用时：12 ms, 在所有 Go 提交中击败了88.07%的用户
内存消耗：5.2 MB, 在所有 Go 提交中击败了100.00%的用户
通过测试用例：2094 / 2094
*/
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	times := (len(nums1) + len(nums2) - 1) / 2
	var i1, i2 int
	for i := 0; i < times; i++ {
		if i2 >= len(nums2) || (i2 < len(nums2) && i1 < len(nums1) && nums1[i1] < nums2[i2]) {
			i1++
		} else {
			i2++
		}
	}
	if (len(nums1)+len(nums2))%2 == 0 { //偶数
		if i2 >= len(nums2) || (i1+1 < len(nums1) && nums2[i2] > nums1[i1+1]) {
			return float64((nums1[i1] + nums1[i1+1])) / 2.0
		} else if i1 >= len(nums1) || (i2+1 < len(nums2) && nums2[i2+1] < nums1[i1]) {
			return float64((nums2[i2] + nums2[i2+1])) / 2.0
		} else {
			return float64((nums1[i1] + nums2[i2])) / 2.0
		}
	} else {
		//奇数个，返回较小的一个
		if i2 >= len(nums2) {
			return float64(nums1[i1])
		} else if i1 >= len(nums1) {
			return float64(nums2[i2])
		} else {
			if nums1[i1] < nums2[i2] {
				return float64(nums1[i1])
			} else {
				return float64(nums2[i2])
			}
		}
	}
}
