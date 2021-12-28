package main

import (
	"fmt"
	"math"
	"reflect"
	"strings"
)

func main() {
	v1 := 2
	v2, v3 := 2.4, "string"
	v_1 := "int"
	v4 := v1 + 3
	fmt.Println("HelloWorld!", "go!")
	fmt.Println(math.Floor(3.54))
	fmt.Println(strings.Title("hello world"))
	fmt.Println('1')
	fmt.Println(reflect.TypeOf("sss"))
	fmt.Println(v1)
	fmt.Println(v2, v3, v_1)
	fmt.Println(v4)
}
