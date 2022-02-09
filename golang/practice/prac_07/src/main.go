package main

import (
	"bufio"
	"errors"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

type Elem float64

func (e Elem) Less(e1 ElemType) bool {
	e2, ok := e1.(Elem)
	if !ok {
		log.Fatal(errors.New("转化失败"))
	}
	return float64(e) < float64(e2)
}

func main() {
	//KMP算法测试
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("输入主串：")
	input, err := reader.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}
	s := input[:len(input)-2]
	fmt.Println("输入模式串：")
	input, err = reader.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}
	t := input[:len(input)-2]
	fmt.Println("匹配结果：", KMP(s, t, 0))

	//快排算法测试
	fmt.Println("输入排序序列")
	input, err = reader.ReadString('\n')
	numsStr := strings.Split(strings.TrimSpace(input), ",")
	var nums []ElemType
	for _, elem := range numsStr {
		num, err := strconv.ParseFloat(elem, 64)
		if err != nil {
			log.Fatal(err)
		}
		numElem := Elem(num)
		nums = append(nums, numElem)
	}
	//排序
	fmt.Println(QuickSort(nums, 0, len(nums)-1))
}

//快排算法实现
//快排算法接口
type ElemType interface {
	Less(elemType ElemType) bool //需要实现算法less，在需要交换时返回false
}

func QuickSort(elems []ElemType, low int, high int) []ElemType {

	if low < high {
		pos := partition(elems, low, high)
		QuickSort(elems, low, pos-1)
		QuickSort(elems, pos+1, high)
	}
	return elems
}

func partition(elems []ElemType, low int, high int) int {
	pivot := elems[low] //枢轴元素
	for low < high {
		//右侧移动
		for low < high && pivot.Less(elems[high]) {
			high--
		}
		elems[low] = elems[high] //移动到low位置
		//左侧滑动
		for low < high && elems[low].Less(pivot) {
			low++
		}
		elems[high] = elems[low]
	}
	elems[low] = pivot
	return low
}

//KMP模式匹配算法实现
func KMP(s string, t string, pos int) int {
	//根据t求解next数组
	next := kmpGetNext(t)
	sRunes := []rune(s)
	tRune := []rune(t)
	i, j := pos-1, -1
	for i < len(sRunes) && j < len(tRune) {
		if j == -1 || sRunes[i] == tRune[j] {
			i++
			j++
		} else {
			j = next[j]
		}
	}
	if j >= len(tRune) {
		return i - j
	} else {
		return -1
	}
}
func kmpGetNext(t string) []int {
	runeT := []rune(t)
	var next []int = make([]int, len(runeT))
	next[0] = -1
	var i, j int = 0, -1
	for i < len(runeT)-1 {
		if j == -1 || runeT[i] == runeT[j] {
			i++
			j++
			next[i] = j
		} else {
			j = next[j]
		}
	}
	return next
}
