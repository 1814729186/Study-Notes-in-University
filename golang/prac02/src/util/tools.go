package util

import (
	"bufio"
	"fmt"
	"os"
)

type Address struct {
	int
	string
	Code string
	Str  string
}
type MyStruct struct {
	ParamInt     int
	ParamFloat64 float64
	Str          string
	Address
}

func AlterValueStruct(s MyStruct) {
	s.ParamInt = 123
	s.ParamFloat64 = 6.6
	s.Str = "sdsd"
}

func AlterAddrStruct(s *MyStruct) {
	s.Str = "sss"
	s.ParamInt = 999
	s.ParamFloat64 = 3.3
}

/*func SumOfMany(param ...int) int {
	sum := 0
	for _, elem := range param {
		sum += elem
	}
	return sum
}*/

func SumOfMany(param ...float64) float64 {
	sum := float64(0.0)
	for _, elem := range param {
		sum += elem
	}
	return sum
}

//映射的使用，访问文件，记录每一个字母出现的次数，最后打印出来
//参数为文件路径，返回一个映射关系
func CountTimes(filePath string) (map[byte]int, error) {
	counts := map[byte]int{}
	//打开文件
	file, err := os.Open(filePath)
	if err != nil { //打开文件失败
		return nil, err
	}
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		//读取一行，依次检查每一个字符
		sentens := scanner.Text()
		for i := 0; i < len(sentens); i++ {
			renu := sentens[i]
			if renu != '\n' && renu != '\t' && renu != '\r' && renu != ' ' && renu != 0 {
				counts[renu] += 1
			}
		}
	}
	//关闭文件
	err = file.Close()
	if err != nil {
		return nil, err
	}
	if scanner.Err() != nil {
		return nil, scanner.Err()
	} else {
		return counts, nil
	}

}

type Mytype string

func (m Mytype) Method() {
	fmt.Println("value")
}
func (m *Mytype) PointerMethod() {
	fmt.Println("pointer")
}
