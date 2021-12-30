package main

import (
	"bufio"
	"fmt"
	"os"
)

var vaa int

func main1() {
	/*reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}
	input = strings.TrimSpace(input)
	grade, err := strconv.ParseInt(input, 8, 32)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Print(grade)*/
	var status int = 20
	//var err error = nil
	var str string
	reader := bufio.NewReader(os.Stdin)
	var err error
	str, err = reader.ReadString('\n')
	println(str, err)
	if 1 > 2 {
		var status int
		status = 30
		fmt.Println(status)
	} else {
		status := 40
		fmt.Println(status)
	}
	fmt.Println(status)
}
