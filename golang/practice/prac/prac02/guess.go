package main

import (
	"bufio"
	"fmt"
	"log"
	"math/rand"
	"os"
	"strconv"
	"strings"
	"time"
)

func main2() {
	//猜数字游戏
	fmt.Println("猜测随机数")
	rand.Seed(time.Now().Unix())
	target := int64(rand.Intn(100) + 1)
	reader := bufio.NewReader(os.Stdin)
	for i := 1; i < 11; i++ { //十次猜数字
		fmt.Println("第", i, "次猜测，请输入数字")
		input, err := reader.ReadString('\n')
		if err != nil {
			println("错误")
			log.Fatal(err)
		}
		num, err := strconv.ParseInt(strings.TrimSpace(input), 10, 32)
		if err != nil {
			fmt.Println("输入格式错误，请重新输入")
			continue
		}
		if num == target {
			fmt.Println("猜对了，随机数正是", target)
			break
		} else if num < target {
			fmt.Println("猜错了，目标随机数比", num, "更大")
		} else {
			fmt.Println("猜错了，目标随机数比", num, "更小")
		}
		i++
		if i == 11 {
			println("游戏结束，随机数是", target)
		}
	}
	//猜测十次

}
