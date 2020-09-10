# 一、模块初始

标准库——python环境集成的库

第三方库

## 1.sys标准库

```python
import sys
print(sys.path)
#环境变量路径、标准库路径：python_path/Base/lib/
print(sys.argv)
#相对路径（pyCharm中为绝对路径）
```

## 2.os标准库

```python
os.system('dir')
#打印当前路径存在的文件夹和文件
#执行成功返回0
```

```python
cmd_res = os.popen('dir').read()
#popen为打印内存地址
#read方法打印相应内容，上述代码执行结果与前一段代码一致
```

```python
os.mkdir("new_folder")
#创建新文件夹
```

模块寻找

1.本地目录中寻找

2.标准库目录中寻找:python_path/Base/lib/

3.第三方库中寻找:python_path/Base/lib/site-package/

## .pyc文件

python程序运行时，编译的结果保存在位于内存中的PyCodeObject中，党Python程序运行结束时，Python解释器将PyCodeObject昔日回到pyc文件中。

第二次运行时，首先会在硬盘中寻找pyc文件，如果找到，则直接载入，否则就重复上面的过程（更改源代码后，会重新编译）。

pyc时PyObjectObject的一种持久化保存方法。

# 二、数据类型

## 1、数类型

### （1）、整型

**python3中没有整型和长整型的区分**

python3中自动为整数提供无穷精度

### （2）、浮点数

python中的除法运算得到的结果总是浮点数，使用截断除法“//”时除外

同一算式中同时存在浮点数和整数时会自动进行类型转换，计算时自动忽略参与运算的小数尾部的0

### （3）、复数

### （4）、bytes类型（字节包）

​	bytes是python3中新增的内容

​	bytes 只负责以字节序列的形式（二进制形式）来存储数据，至于这些数据到底表示什么内容（字符串、数字、图片、音频等），完全由程序的解析方式决定。如果采用合适的字符编码方式（字符集），字节串可以恢复成字符串；反之亦然，字符串也可以转换成字节串。

​	bytes 类型的数据非常适合在互联网上传输，可以用于网络通信编程；bytes 也可以用来存储图片、音频、视频等二进制格式的文件。

​	字符串和 bytes 存在着千丝万缕的联系，我们可以通过字符串来创建 bytes 对象，或者说将字符串转换成 bytes 对象。有以下三种方法可以达到这个目的：

- 如果字符串的内容都是 ASCII 字符，那么直接在字符串前面添加`b`前缀就可以转换成 bytes。

  ```python
  b1 = b''		#通过b前缀将字符串转成bytes
  b2 = b'Hello World'
  ```

  

- bytes 是一个类，调用它的构造方法，也就是 bytes()，可以将字符串按照指定的字符集转换成 bytes；如果不指定字符集，那么默认采用 UTF-8。

  ```python
  b1 = bytes()	#通过构造函数创建bytes
  b2 = bytes('8岁了',encoding='UTF-8')
  ```

- 字符串本身有一个 encode() 方法，该方法专门用来将字符串按照指定的字符集转换成对应的字节串；如果不指定字符集，那么默认采用 UTF-8。

  ```python
  b1 = "8岁了"，encode('UTF-8')
  ```

  bytes类也有一个decode()方法，可将bytes对象转换为字符串

  ```python
  b1 = "8岁了"，decode('UTF-8')
  str1 = b1.decode('UTF-8')
  ```

## 2、布尔类型

**False** 假

**True** 真



# 三、数据运算

## 1、基本数值运算

加减乘除，求幂，截断式除法，取模运算divmod(x,y)

+和*也可以处理字符串

```python
"abc"+"def"
>>> "abcdef"
"ab"*3
>>> "ababab"
```

## 2、逻辑运算

**取反（~）、移位（>>）、按位与（&）、按位异或（^）、逻辑与（and）、逻辑或（or）**

## 3、部分内置函数

### 1、求幂pow()

```python
pow(2,3)
>>> 8
```

### 2、求绝对值：abs()

### 3、四舍五入取整：round()

### 4、截断取整：int()

###　5、转换成浮点数：float()

### 6、十进制转八进制：oct()，转十六进制：hex()，转二进制：bin()

math标准库中含有很多数值运算函数

## 4、其他相关

### （1）三元运算

```python
result = <值1> if <条件> or <值2>
```

### （2）进制

进制表示的前后缀

```python
101B	#二进制后缀
67FH	#十六进制后缀
0x11	#十六进制前缀
```



# 四、列表、元组

## 1、列表创建和访问

```python
#创建列表
names = ['Zhang San','Li Si','Wang Wu']
#列表数据访问（单个），与数组操作相同
print(names[1])
#切片：列表元素访问（多个）
#使用“:”分隔“起始位置”和“结束位置（不包含）”（取出的数据不包含结束位置的元素）
print(names[1:3])	
#要通过切片得到包含最后一个数据的元素组时，可以通过省略结束位置的方式实现
print(names[1:])
#取最后一个元素，结合列表的编码方式（正编码/负编码）
print(names[-1])
#取最后多个元素
print(names[-3,-1])
```

## 2、元素添加

### append()方法

插入元素至列表末尾

```python
names = ['Zhangsan']
names.append('Lisi')
```

### insert()方法

插入元素至指定位置

insert(locate,obj)	前一个参数为插入的位置，后一个参数为插入的对象

```python
names = ['ZhangSan','Li Si','Wang Wu']
names.insert(2,'Wang Fang')
```

## 3、元素替换

直接使用赋值语句即可

```python
names = ['Zhang San','Li Si','Wang Wu']
names[2] = 'Wang Fang'
```

## 4、元素删除

### pop()方法

删除对应位置下标的元素，若不指定位置，默认删除最后一个元素

```python
names = ['Zhang San','Li Si','Wang Wu']
names.pop()		#删除最后一个元素
names.pop(1)	#删除下标为1的元素
```

### remove()方法

按查找数据内容的方式删除列表内的元素

```pythom
names = ['Zhang San','Li Si','Wang Wu']
names.remove('Li Si')
```

### del关键字

使用del关键字删除列表中特定位置的元素

```python
names = ['Zhang San','Li Si','Wang Wu']
del namse[1]
```

## 5、其他操作

### index()方法：获得相应元素的索引位置

```python
names = ['Zhang San','Li Si','Wang Wu']
print(names.index('Li Si'))
```

