package fileopen

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func OpenPrintFile(path string) error {
	file, err := os.Open(path)
	if err != nil {
		return err
	}
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		fmt.Println(scanner.Text())
	}
	err = file.Close()
	if err != nil {
		return err
	}
	return scanner.Err()
}
func GetFloats(filePath string) ([]float64, error) {
	var numbers []float64
	file, err := os.Open(filePath)
	if err != nil {
		return nil, err
	}
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		number, err := strconv.ParseFloat(scanner.Text(), 64)
		if err != nil {
			return nil, err
		}
		numbers = append(numbers, number)
	}
	err = file.Close()
	if err != nil {
		return nil, err
	}
	return numbers, scanner.Err()
}
