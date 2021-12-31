package main

import "prac02/src/util"

func main() {
	/*const v0 = 5
	var v1 = pkg1.LinkStart()
	var v2 = pkg2.LinkStart()
	fmt.Println(v1, v2)
	texts := [2]string{
		"Hello,everyone!",
		"how are you!", //这种格式下，末尾的逗号时必须的
	}
	fmt.Println(texts)
	fmt.Printf("%#v", texts)*/
	//文件访问
	/*err := fileopen.OpenPrintFile("D:\\gobang.c")
	if err != nil {
		log.Fatal(err)
	}*/
	/*numbers, err := fileopen.GetFloats("D:\\numbers.txt")
	fmt.Println(numbers)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(numbers)*/
	//切片
	/*var myArray [4]int
	for i, _ := range myArray {
		myArray[i] = i + 1
	}
	mySlice := myArray
	for i, _ := range mySlice {
		mySlice[i] += 100
	}
	fmt.Println(myArray)
	fmt.Println(mySlice)
	fmt.Println(len(myArray))
	fmt.Println(len(mySlice))*/
	/*myArray := [4]string{"a1", "a2", "a3", "a4"}
	mySlice1 := myArray[0:1]
	mySlice2 := myArray[0:1]
	mySlice3 := myArray[:3]
	mySlice3 = append(mySlice3, "s3_1", "s3_2", "s3_3")
	//fmt.Println(myArray)

	mySlice1 = append(mySlice1, "s1_1")
	mySlice2 = append(mySlice2, "s2_1", "s2_2")

	myArray[0] = "new_a1"

	fmt.Println(myArray)
	fmt.Println(mySlice1)
	fmt.Println(mySlice2)
	fmt.Println(mySlice3)*/
	/*floatSlice1 := []float64{1.1, 2.2, 3.3}
	var floatArray [3]float64 = [3]float64{1.1, 2.2, 3.3}
	fmt.Println(util.SumOfMany(floatSlice1...))
	fmt.Println(util.SumOfMany(floatArray[:]...))
	fmt.Println(util.SumOfMany(2.0, 3.0, 5.6, 7.8))*/

	//打开文件，统计字符数量
	/*counts, err := util.CountTimes("D:\\numbers.txt")
	if err != nil {
		log.Fatal(err)
	}
	for index, value := range counts {
		fmt.Printf("%c : %d\n", index, value)
	}*/

	//struct
	/*var s util.MyStruct
	util.AlterValueStruct(s)
	fmt.Println(s)
	util.AlterAddrStruct(&s)
	fmt.Println(s)*/

	//结构体嵌入
	/*var s util.MyStruct
	s.Str = "sss"
	fmt.Println(s)
	s.Address.Str = "aaa"
	fmt.Println(s)*/

	//指针和值接收器
	//util.Mytype("va").PointerMethod()
	util.Mytype("vv").Method()

}
