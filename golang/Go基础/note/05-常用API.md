# 1.Sort排序

- 调用Sort方法的条件——满足三个接口方法

```go
type Interface interface {
	// Len is the number of elements in the collection.
	// 获取数据集合元素个数
	Len() int
	
	 // 如果 i 索引的数据小于 j 索引的数据，返回 true，且不会调用下面的 Swap()，即数据升序排序
	// Less reports whether the element with
	// index i should sort before the element with index j.
	Less(i, j int) bool
	
	// 交换 i 和 j 索引的两个元素的位置
	// Swap swaps the elements with indexes i and j.
	Swap(i, j int)
}
```

---

## 1. 方法原型

- sort排序方法原型

```go
// Sort sorts data.
// It makes one call to data.Len to determine n, and O(n*log(n)) calls to
// data.Less and data.Swap. The sort is not guaranteed to be stable.
func Sort(data Interface) 
```

- Reverse-逆序

```go
// Reverse returns the reverse order for data.
func Reverse(data Interface) Interface
```

逆序排序的实现其实就是修改正序排序的前后入参，也就是说正序是less(i,j),则逆序是less(j,i)

- IsSorted -返回是否排序

```go
// IsSorted reports whether data is sorted.
func IsSorted(data Interface) bool 
```

---

## 2. 内置结构实现

### 1).IntSlice

提供方法

- Ints - 对[]切片进行排序

```go
// Ints sorts a slice of ints in increasing order.
func Ints(a []int) { Sort(IntSlice(a)) }
```

- Search - 在切片中查找对应的int元素

```go
// Search returns the result of applying SearchStrings to the receiver and x.
func (p StringSlice) Search(x string) int
```

### 2)Float64Slice

（基本同上）

### 3)StringSlice

（基本同上）

---

## 3.函数增强

### 1)sort.Slice - 自定义排序规则

- 通过实现匿名函数来实现相应切片的排序规则

```go
// Slice sorts the provided slice given the provided less function.
// The sort is not guaranteed to be stable. For a stable sort, use
// SliceStable.
// The function panics if the provided interface is not a slice.
func Slice(slice interface{}, less func(i, j int) bool)
```

### 2)sort.SliceStable - 稳定排序

```go
	// SliceStable sorts the provided slice given the provided less
	// function while keeping the original order of equal elements.
	//
	// The function panics if the provided interface is not a slice.
	func SliceStable(slice interface{}, less func(i, j int) bool)
```

### 3)sort.SliceIsSorted - 自定义规则判断是否有序

```go
	// SliceIsSorted tests whether a slice is sorted.
	//
	// The function panics if the provided interface is not a slice.
	func SliceIsSorted(slice interface{}, less func(i, j int) bool) bool
```

### 4)sort.Search - 自定义规则查找

```go
	func Search(n int, f func(int) bool) int
```

---

# 2.字符串处理

## 1.字符串分割

### 1)按空格分割

```go
//把字符串 s 按照空格分割后返回的字符串数组，保存在 变量 arr 中。
arr := strings.Fields(s)	//s：要分割的字符串。返回分割后的数组
```

### 2)按字符串分割

```go
//把字符串 s 按照字符串 sep 分割后返回的字符串数组，保存在变量 arr 中。
arr := strings.Split(s,sep)	//s:要分割的字符串,sep:字符串的分割符。返回分割后的数组
```

- 函数会以多个字符作为边界进行分割（也可以只用一个字符），分割后的字符不包含边界

### 3)按某些字符进行分割（可创建多种分隔符）。

```go
//把字符串 s 按照字符串按照函数 f 进行分割，分割后返回的字符串数组，保存在变量 arr 中。
arr := strings.FieldsFunc(s,f func(rune) bool)//s：要分割的字符串，f：分割的函数。返回分割后的数组
```

- 当func(rune)bool函数返回true时，则说明该字符可作为界符，否则不作为界符

---

## 2.字符串两侧空白符去除

```go
s = strings.TrimSpace(s)
```

