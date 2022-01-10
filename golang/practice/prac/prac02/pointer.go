package main

import "fmt"

func main() {
	pointer := createPointer()
	fmt.Println(pointer)
	fmt.Println(*pointer)
}
func createPointer() *float64 {
	myFloat64 := 98.5
	fmt.Println(&myFloat64)
	return &myFloat64
}
