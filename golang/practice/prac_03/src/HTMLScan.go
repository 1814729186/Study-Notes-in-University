package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
)

func HTMLScan() {
	response, err := http.Get("http://www.baidu.com")
	if err != nil {
		log.Fatal(err)
	}
	defer response.Body.Close()
	body, err := ioutil.ReadAll(response.Body)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(string(body))
	//创建文件
	workSpace := "F:\\" //工作目录
	file, err := os.OpenFile(workSpace+"example.html", os.O_WRONLY|os.O_CREATE, 0666)
	if err != nil {
		fmt.Println("文件创建失败")
		log.Fatal(err)
	}
	defer file.Close()
	write := bufio.NewWriter(file)
	write.WriteString(string(body))
	write.Flush()
}
