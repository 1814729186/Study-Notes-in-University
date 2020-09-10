# 一、py文件标准格式

`#!/usr/bin/env python` 表示使用的解释器，env——优先在环境变量中寻找解释器

`#!/usr/bin/python` 仅在local安装的python版本中寻找解释器

`#! _*_coding:utf-8 _*_` （或者将下划线改成中划线）编码格式设置



# 二、变量

## 1. print（）方法中变量使用实例

变量名+赋值符号+值

`name = "Ma Zhongping"`

print()方法中可以使用变量进行直接的拼接打印，使用逗号分开

`print(“My name is”,name)`

其他类型的变量也可以

```python
num = 1
print("The value of num is",num)
```

``` python
# The value of num is 1
```

逗号中的变量使用多个变量的计算式

```python
num1 = 1
num2 = 2
print("num1 + num2 = ",num1+num2)
```

```python
# num1 + num2 = 3
```

甚至可以直接使用字符串变量的拼接

```python
firstName = 'Zhongping '
lastName = 'Ma'
print("My name is ",lastName + firstName)
```

```python
# My name is Ma Zhongping
```

---

**变量的命名规则与其他大部分语言基本一致**

## 2. 常见命名规范

### a. 匈牙利命名法

​	变量和函数名中加入前缀以提高可读性。

​	格式：标识符的名字以一个或者多个小写字母开头作为前缀，前缀说明类型，前缀之后是首字母大写的一个或者多个单词，该单词主要指明用途。

​	例如`lpszStr` 表示一个指向以`\0` 结尾的字符串`（sz）` 的长指针`(lp)` 变量。

### b. 驼峰命名法

​	首个单词的首字母小写，之后的首字母大写

### c. 帕斯卡命名法

​	与驼峰命名法相似，但第一个首字母大写。

### d. 下划线命名法(python官方建议采用的命名规则)

​	多个单词之间使用下划线进行连接。

## 3. python中常量的表示

​	python中没有常量的概念，通常使用全大写定义常量，程序中注意不再更改。

## 4.字符编码与二进制

​	ASCII码

​	GB2312（1980）中文编码——使用16位编码进行索引，索引目标为创建好的宫格汉字表。汉字表中储存有6763个汉字和682个其他符号。GB2312后来经过一次次地扩展，支持的汉字数量越来越多，GBK（1995）收录21886个汉字，GB18030（2000）收录27484个汉字和一些民族语言。ASCII、GB2312、GBK、GB18030是依次向下兼容的。

### unicode（统一码）

​	最少由2个字节进行表示，可能多余两个字节。为每种语言的每个字符设定了同意并且唯一的二进制编码。

​	**utf-8** 是对Unicode编码的压缩和优化，不再遵循最少使用两个字符的规则，而是acsii的内容用一个字节，欧洲的字符用两个字节，东亚的用三个字节等等。

​	python解释器再加载.py文件中代码的同时，会对内容进行编码（python2默认为ascii，python3为utf-8），如果未声明编码格式，无法使用中文。

如以下格式会报错，ascii不支持英文

```python
#!/usr/bin/env python
print("你好，世界！")
```

# 三、用户交互程序

## + 注释的使用

​	单行注释

```python
# 注释
```

​	多行注释

```python
'''
注释
'''
```

​	多行注释的实质是一个多行字符串，解释器解释时，多行字符串不会执行操作

​	可以用变量接受字符串,打印时会多行打印出来

```python
str = '''Ma Zhongping
is
a
student'''
print(str)
```

​	python中单双引号的含义完全一致，当需要嵌套使用时需要进行选择

## 1.  获取用户的输入

### input()函数

```python
inStr = input("plase input")
```

​	**input()** *返回的是一个字符串*

### 字符串格式化

​	print()函数的打印同样可以使用占位符进行变量的填入

```python
# 字符串占位符
sName = 'Ma Zhongping '
sAge = '21 '
sJob = 'Student '
info = '''
Name:%s
Age:%s
Job:%s
''' % (sName,sAge,sJob)
print(info)
```

​	python中print()函数同样也支持%d、%f等占位符。

​	另一种占位符（推荐使用方法）

```python
# 字符串占位符2
sName = 'Ma Zhongping '
sAge = '21 '
sJob = 'Student '
info = '''
----info of {name}
Name:{name}
Age:{age}
Job:{job}
'''.format(name = sName,age = sAge,job = sJob)
#name秩序赋值一次
print(info)
```

可以使用{0}的形式作为占位符

```python
# 字符串占位符3
sName = 'Ma Zhongping '
sAge = '21 '
sJob = 'Student '
info = '''
---info of {0}
Name:{0}
Age:{1}
Job:{2}
'''.format(sName,sAge,sJob)
print(info)
```





### python中字符串的强转

​	字符串直接强制转换成int或者其他类型

```python
intAge = int(input("age:"))
```

​	int转换为str

```python
strAge = str(intAge)
```

python中也可以使用eval()函数对字符串进行转换

### eval()函数

​	参数为字符串，返回结果为python语句，执行去掉字符串最外侧引号的语句

```python
intAge = eval(input("Age:"))
```

### raw_input()函数

存在于python2中，python2中的input函数会直接将输入作为语句读入。python3中不使用这一函数，而用input函数代替了raw_input()

_python中最好不用字符串的拼接_

__字符串可以直接用“=”进行匹配判断__

```python
a = 1;
b = 2;
if a == b:
    print("yes")
else:
    print("no")
```

__IndentationError__ :缩进错误



## 四、循环

#### 1、while循环

####　２、for循环

```python
for i in range(5):
    print(i)
```

##### range(起始，终止，步长)

```python
for i in range(0，10，2):
    print(i)
```

##### break

​	跳出循环

##### continue

​	跳出本次循环，进入下次循环

##### 循环嵌套

