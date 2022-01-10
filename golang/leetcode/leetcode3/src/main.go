package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

// leetcode3 最长子串
/**
无重复最长子串
解题思路：从前往后遍历字符串值，将相关值存入map，扫到已经出现过的字符时，说明已经出现相同的字符
执行情况：
执行用时：224 ms, 在所有 Go 提交中击败了8.29%的用户
内存消耗：6.9 MB, 在所有 Go 提交中击败了5.12%的用户
通过测试用例：987 / 987
*/
func lengthOfLongestSubstring1(s string) int {
	//无重复最长子串
	var maxLen, curLen int
	var chMap map[rune]int
	//转为字符数组进行处理
	runes := []rune(s)
	//遇到一个已经出现过的字符，此时则可以统计出maxLen
	//然后再从已经出现的字符的下一个字符开始，重复上述过程
	chMap = make(map[rune]int)
	for i := 0; i < len(runes); {
		//如果没有出现
		index, ok := chMap[runes[i]]
		if !ok {
			chMap[runes[i]] = i //记录出现的位置
			i++
			curLen++
		} else {
			//出现已经出现过的字母
			//记录maxLen，并从已经出现过的字符的下一个位置开始重复
			if maxLen < i-index {
				maxLen = i - index
			}
			i = index + 1 //从下一个位置开始
			//重置map
			chMap = make(map[rune]int)
			//重置curLen
			curLen = 0
		}
		if curLen > maxLen {
			maxLen = curLen
		}
	}
	return maxLen
}

/**
解题思路2：滑动窗口，右指针一直右移，遇到出现过的字符，则左边的指针向右移动，直到将已经出现过的字符从窗口中移出
	实际上与解题思路1相似，但应优化map的使用方法，不应该删除并重新创建
执行结果：
执行用时：8 ms, 在所有 Go 提交中击败了71.20%的用户
内存消耗：3.6 MB, 在所有 Go 提交中击败了20.82%的用户
通过测试用例：987 / 987
*/

func lengthOfLongestSubstring2(s string) int {
	runeMap := make(map[rune]int)
	//遇到已经出现过的字符，或者上一次出现的位置位于开始统计的元素之后，则视作未出现，降低思路1造成的重置map的开销
	runes := []rune(s)
	var maxLen, curLen int
	var curHead int //当前所使用的首位置
	for index, curRune := range runes {
		lastIndex, ok := runeMap[curRune] //获得值
		runeMap[curRune] = index          //更新新的位置信息
		if ok && lastIndex >= curHead {
			//已经出现过
			curHead = lastIndex + 1 //更新新的统计开始元素
			curLen = index - lastIndex
		} else {
			curLen++
			if curLen > maxLen {
				maxLen = curLen
			}
		}
	}
	return maxLen
}

/**
对思路2中的代码进行优化
执行结果：
执行用时：4 ms, 在所有 Go 提交中击败了91.37%的用户
内存消耗：3.2 MB, 在所有 Go 提交中击败了29.30%的用户
通过测试用例：987 / 987
*/
func lengthOfLongestSubstring(s string) int {
	runeMap := make(map[rune]int)
	//遇到已经出现过的字符，或者上一次出现的位置位于开始统计的元素之后，则视作未出现，降低思路1造成的重置map的开销
	var maxLen int
	var curHead int //当前所使用的首位置
	for index, curRune := range s {
		lastIndex, ok := runeMap[curRune] //获得值
		runeMap[curRune] = index          //更新新的位置信息
		if ok && lastIndex >= curHead {
			//已经出现过
			if maxLen < index-curHead {
				maxLen = index - curHead
			}
			curHead = lastIndex + 1 //更新新的统计开始元素
		}
	}
	if maxLen < len(s)-curHead {
		maxLen = len(s) - curHead
	}
	return maxLen
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	input, err := reader.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%#v\n", input)
	fmt.Printf("%#v\n", input[:len(input)-2])
	fmt.Println(lengthOfLongestSubstring(input[:len(input)-2]))
}
