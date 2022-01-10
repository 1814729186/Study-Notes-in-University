package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"sort"
	"strconv"
	"strings"
)

//1.两数之和

/**
给定一个整数数组 nums和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
*/

/**
解题思路1：
	首先尝试排序后再进行处理，排序算法时间复杂度为O(nlogn)
	再使用双指针从两端进行遍历O(n)
	总的时间复杂度为O(nlong)
遇到的问题：由于执行了排序，还需要再返回原来的数组重新获得一次下标，增大了时间复杂度
*/
func twoSum1(nums []int, target int) []int {
	newNums := append(nums, 1, 2) //复制一份
	newNums = newNums[:len(newNums)-2]
	//对元素进行排序
	sort.Ints(nums)
	//fmt.Println(nums) //测试通过
	//fmt.Println(newNums)
	//双指针同时遍历
	var head, end = 0, len(nums) - 1
	for head < end {
		if nums[head]+nums[end] == target {
			//找到相关参数，返回相关参数值
			fmt.Println("values:", nums[head], nums[end])
			//在原数组中获得下标
			var index1, index2 int
			var flag bool
			for i := 0; i < len(newNums); i++ {
				if flag == false && nums[head] == newNums[i] {
					index1 = i
					flag = true
				} else if nums[end] == newNums[i] {
					index2 = i
				}
			}
			return []int{index1, index2}
		} else if nums[head]+nums[end] < target {
			//过小，则小数应该增大
			head++
		} else {
			//过大，大数应该减小
			end--
		}
	}
	return nil //没找到，返回nil
}

func main1() {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}
	//转换为数组元素
	var nums []int
	//对读入的字符串继续进行处理
	inputs := strings.Split(strings.TrimSpace(input), ",")
	for _, s := range inputs {
		num, err := strconv.ParseInt(s, 10, 32)
		if err != nil {
			log.Fatal(err)
		}
		nums = append(nums, int(num))
	}
	//输入target
	input, err = reader.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}
	target, err := strconv.ParseInt(strings.TrimSpace(input), 10, 32)
	if err != nil {
		log.Fatal(err)
	}
	//fmt.Println(nums) //测试通过
	n := twoSum(nums, int(target))
	fmt.Println(n)
}

/**
执行结果：
在本地执行正确，在leetcode却出现如下结果
通过测试用例：
24 / 57
输入：
[150,24,79,50,88,345,3]
200
输出：
[2,5]
预期结果：
[0,3]
本地执行结果：
[3,0]
*/
