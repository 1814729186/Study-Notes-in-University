package main

import "fmt"

/*func a() {
	for i := 0; i < 50; i++ {
		fmt.Print("a")
	}
}
func b() {
	for i := 0; i < 50; i++ {
		fmt.Print("b")
	}
}
func main() {
	go a()
	go b()
	for i := 0; i < 50; i++ {
		fmt.Print("c")
	}
	time.Sleep(time.Second)
	fmt.Println("\nend main")
}*/
func greeting(myChannel chan string) {
	myChannel <- "hi"
}
func main() {
	myChannel := make(chan string)
	go greeting(myChannel)
	var str string
	str = <-myChannel
	fmt.Println(str)
}
