package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

//1614.括号的最大深度

/**
如果字符串满足以下条件之一，则可以称之为 有效括号字符串（valid parentheses string，可以简写为 VPS）：
	字符串是一个空字符串 ""，或者是一个不为 "(" 或 ")" 的单字符。
	字符串可以写为 AB（A 与 B 字符串连接），其中 A 和 B 都是 有效括号字符串 。
	字符串可以写为 (A)，其中 A 是一个 有效括号字符串 。
类似地，可以定义任何有效括号字符串 S 的 嵌套深度 depth(S)：
	depth("") = 0
	depth(C) = 0，其中 C 是单个字符的字符串，且该字符不是 "(" 或者 ")"
	depth(A + B) = max(depth(A), depth(B))，其中 A 和 B 都是 有效括号字符串
	depth("(" + A + ")") = 1 + depth(A)，其中 A 是一个 有效括号字符串
例如：""、"()()"、"()(()())" 都是 有效括号字符串（嵌套深度分别为 0、1、2），而 ")(" 、"(()" 都不是 有效括号字符串 。

给你一个 有效括号字符串 s，返回该字符串的 s 嵌套深度 。

*/

/**
遍历整个字符串即可，遇到(则深度+1，遇到)则深度-1
*/
func maxDepth(s string) int {
	var curDepth, maxDepth int
	for _, ch := range s {
		//fmt.Printf("%c ", ch)
		if ch == '(' {
			curDepth++
			if curDepth > maxDepth {
				maxDepth = curDepth
			}
		} else if ch == ')' {
			curDepth--
		}
	}
	return maxDepth
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(maxDepth(input))
}

/**
运行结果：
执行用时：
0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：
1.9 MB, 在所有 Go 提交中击败了66.04%的用户
通过测试用例：
167 / 167
*/
