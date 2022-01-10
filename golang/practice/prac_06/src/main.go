package main

import (
	"fmt"
	"reflect"
)

var vInt int

func main() {
	fmt.Println(vInt)
	var vInt int = 3
	fmt.Println(reflect.TypeOf(vInt))
	if vInt := 1; vInt < 2 {
		fmt.Println(vInt)
	}
	fmt.Println(vInt)
	func1()
}
func func1() {
	fmt.Println(vInt)
}
