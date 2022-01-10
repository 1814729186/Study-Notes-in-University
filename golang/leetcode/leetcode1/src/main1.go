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
解题思路2：
	使用map进行算法实现，建立索引，降低查询开销
	twoSum_1:自定义数据结构进行实现
	twoSum:使用map进行实现
*/

//两个参数
type myMap struct {
	value int
	index int
}
type myMaps []myMap //类型定义
//实现接口，便于使用排序函数
func (m myMaps) Len() int {
	return len(m)
}
func (m myMaps) Less(i, j int) bool {
	return m[i].value < m[j].value
}
func (m myMaps) Swap(i, j int) {
	value := m[i].value
	index := m[i].index
	m[i].value = m[j].value
	m[i].index = m[j].index
	m[j].value = value
	m[j].index = index
}

/**
对于twoSum_1
执行结果：
执行用时：8 ms, 在所有 Go 提交中击败了44.42%的用户
内存消耗：5.1 MB, 在所有 Go 提交中击败了7.79%的用户
通过测试用例：57 / 57
*/
func twoSum_1(nums []int, target int) []int {
	//根据输入创建myMap
	var myNumMap myMaps
	for i := 0; i < len(nums); i++ {
		myNumMap = append(myNumMap, myMap{nums[i], i})
	}
	//myNumMap进行排序
	sort.Sort(myNumMap)
	fmt.Println(myNumMap)
	//双指针，判定
	var head, end = 0, myNumMap.Len() - 1
	for head < end {
		if myNumMap[head].value+myNumMap[end].value == target {
			return []int{myNumMap[head].index, myNumMap[end].index}
		} else if myNumMap[head].value+myNumMap[end].value < target {
			head++
		} else {
			end--
		}
	}
	return nil
}

/**
执行用时：
4 ms
, 在所有 Go 提交中击败了
96.98%
的用户
内存消耗：
5.5 MB
, 在所有 Go 提交中击败了
5.24%
的用户
通过测试用例：
57 / 57
*/
func twoSum(nums []int, target int) []int {
	//创建map映射，使用值作为键，索引作为值
	myMap := make(map[int]int)
	//数组中可能存在相同的值，此时就需要储存额外的信息（由于每种输入只会对应同一种答案，所以最多只能有同样的键值对应两个下标，这时候可以进行覆盖，
	//因为从前往后查找，前面的值的索引必定找到后面的索引（不可能重复/重复就会出错）
	for index, value := range nums {
		myMap[value] = index
	}
	//fmt.Println(myMap)
	//查找元素
	for index, value := range nums {
		//查找相关值
		index1, ok := myMap[target-value]
		if !ok { //未找到
			continue
		}
		//若index和index_1相等，则非法
		if index1 != index {
			return []int{index, index1}
		}
	}
	return nil
}

/**
事实上，在twoSum的基础上。还可以边存边找，减少搜索时间
执行用时：
4 ms
, 在所有 Go 提交中击败了
96.98%
的用户
内存消耗：
4.2 MB
, 在所有 Go 提交中击败了
56.18%
的用户
通过测试用例：
57 / 57
*/
func twoSum_2(nums []int, target int) []int {
	//创建map映射，使用值作为键，索引作为值
	myMap := make(map[int]int)
	for index, value := range nums {
		//先检查能不能找到
		index1, ok := myMap[target-value]
		if ok { //找到符合要求的值
			return []int{index1, index}
		} else {
			myMap[value] = index
		}
	}
	return nil
}
func main() {
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
	n := twoSum_2(nums, int(target))
	fmt.Println(n)
}
