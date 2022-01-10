package main

import (
	"bufio"
	"fmt"
	"html/template"
	"log"
	"net/http"
	"os"
)

//签名簿的储存类型
type Guestbook struct {
	SignatureCount int      //储存签名总数
	Signatures     []string //保存签名本身
}

//封装一下error的检查
func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}
func viewHandler(writer http.ResponseWriter, request *http.Request) {
	signatures := getStrings("signatures.txt")            //从文件中读取签名
	html, err := template.ParseFiles("../html/view.html") //基于“view.html”的内容创建一个模板
	check(err)
	//创建变量储存读入的信息
	guestbook := Guestbook{SignatureCount: len(signatures), Signatures: signatures}
	err = html.Execute(writer, guestbook) //将数据倒入模板，并将结果写入ResponseWriter
	check(err)
}
func newHandler(writer http.ResponseWriter, request *http.Request) {
	html, err := template.ParseFiles("../html/new.html") //从模板加载html表格
	check(err)
	err = html.Execute(writer, nil) //将模板写入ResponseWriter（）没有要插入的数据
	check(err)
}
func createHandler(writer http.ResponseWriter, request *http.Request) {
	signature := request.FormValue("signature") //获取signature表单字段的值
	options := os.O_WRONLY | os.O_APPEND | os.O_CREATE
	file, err := os.OpenFile("signatures.txt", options, os.FileMode(0600)) //打开文件进行追加，如果存在就进行追加，如果不存在就创建它
	check(err)
	_, err = fmt.Fprintln(file, signature) //将表单字段内容添加到文件中
	check(err)
	err = file.Close()
	check(err)
	http.Redirect(writer, request, "/guestbook", http.StatusFound) //将浏览器重定向到主留言簿页面
}

//从文件中获取字符串切片
func getStrings(fileName string) []string {
	var lines []string             //文件的每一行都将作为字符串追加到切片中
	file, err := os.Open(fileName) //打开文件
	if os.IsNotExist(err) {        //文件不存在时
		return nil
	}
	check(err)
	defer file.Close()
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	check(scanner.Err())
	return lines
}
func main() {
	http.HandleFunc("/guestbook", viewHandler)          //查看签名列表的请求
	http.HandleFunc("/guestbook/new", newHandler)       //获取HTML表单的请求
	http.HandleFunc("/guestbook/create", createHandler) //提交表单的请求
	fmt.Println("load")
	err := http.ListenAndServe("localhost:8080", nil)
	log.Fatal(err)
}
