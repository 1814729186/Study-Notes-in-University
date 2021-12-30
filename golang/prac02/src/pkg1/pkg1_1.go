package pkg1

import "fmt"

func LinkStart() int {
	fmt.Println("pkg1_LinkStart")
	linkStart()
	return 0
}
func linkStart() {
	fmt.Println("pkg1_linkStart")
}
