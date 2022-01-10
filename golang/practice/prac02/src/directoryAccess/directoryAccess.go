package directoryAccess

import (
	"fmt"
	"io/ioutil"
)

//文件夹的递归访问函数，递归输出文件目录下的所有文件和子目录
func ShowDir(fileName string, layer int) error {
	files, err := ioutil.ReadDir(fileName)
	if err != nil {
		return err
	}
	if layer == 0 {
		fmt.Println("file directory:", fileName)
	}
	for _, file := range files {
		for i := 0; i < layer; i++ {
			fmt.Print("-")
		}
		if file.IsDir() {
			fmt.Println("d:", file.Name())
			//递归访问
			err = ShowDir(fileName+"\\"+file.Name(), layer+1) //添加目录再访问下一级
			if err != nil {
				return err
			}

		} else {
			fmt.Println("f：", file.Name())
		}
	}
	return nil
}

func ShowDirAlter(fileName string, layer int) {
	files, err := ioutil.ReadDir(fileName)
	if err != nil {
		panic(err)
	}
	if layer == 0 {
		fmt.Println("file directory:", fileName)
	}
	for _, file := range files {
		for i := 0; i < layer; i++ {
			fmt.Print("-")
		}
		if file.IsDir() {
			fmt.Println("d:", file.Name())
			//递归访问
			err = ShowDir(fileName+"\\"+file.Name(), layer+1) //添加目录再访问下一级
			if err != nil {
				panic(err)
			}

		} else {
			fmt.Println("f：", file.Name())
		}
	}
}
