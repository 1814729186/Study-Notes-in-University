package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var carry int
	var li *ListNode = &ListNode{0, nil} //创建一个头节点，便于处理
	list1, list2, list := l1, l2, li
	for list1 != nil || list2 != nil {
		var v1, v2 int
		if list1 != nil {
			v1 = list1.Val
			list1 = list1.Next
		} else {
			v1 = 0
		}
		if list2 != nil {
			v2 = list2.Val
			list2 = list2.Next
		} else {
			v2 = 0
		}
		//节点值处理
		list.Next = &ListNode{v1 + v2 + carry, nil}
		list = list.Next
		if list.Val >= 10 {
			list.Val -= 10
			carry = 1
		} else {
			carry = 0
		}
	}
	//处理最后一个节点
	if carry == 1 {
		list.Next = &ListNode{1, nil}
	}
	return li.Next
}

/**
执行结果
执行用时：8 ms, 在所有 Go 提交中击败了87.12%的用户
内存消耗：4.6 MB, 在所有 Go 提交中击败了60.78%的用户
通过测试用例：1568 / 1568
*/
