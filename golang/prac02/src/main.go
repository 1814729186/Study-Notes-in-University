package main

import (
	"fmt"
	"prac02/src/pkg1"
	"prac02/src/pkg2"
)

func main() {
	const v0 = 5
	var v1 = pkg1.LinkStart()
	var v2 = pkg2.LinkStart()
	fmt.Println(v1, v2)

}
