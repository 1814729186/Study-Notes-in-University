package main

import (
	"errors"
	"fmt"
)

func main3() {
	fmt.Printf("About one-third: %.2f\n", 10.0/3.0)
	//fmt.Printf("%#v", '\t')
	str, err := func1()
	fmt.Println(str, err)
}
func func1() (string, error) {
	err := errors.New("My Error")
	fmt.Println(err.Error())
	return "func1", err
}
