# python关键字

33个常见关键字

|   False   |    True    |     None     |    and    |     as     |    assert    |
| :-------: | :--------: | :----------: | :-------: | :--------: | :----------: |
| **break** | **class**  | **continue** |  **def**  |  **del**   |   **elif**   |
| **else**  | **except** | **finally**  |  **for**  |  **from**  |  **global**  |
|  **if**   | **import** |    **in**    |  **is**   | **lambda** | **nonlocal** |
|  **not**  |   **or**   |   **pass**   | **raise** | **return** |   **try**    |
| **while** |  **with**  |  **yield**   |           |            |              |

### 1. False

布尔类型假

### 2. True

布尔类型真

### 3. None

python中特殊的数据类型`None Type`

None与其他非None的数据类型相比，永远返回False

```python
>>> None == 0
$ False
>>> None == None
$ True
```

### 4. and

逻辑与

### 5.as

as具有两种常见的用法：

##### 1.import xx as xxx

第三方库导入，并使用一个简短的名字来代替

```python
import numpy as np
```

##### 2.with ... as ...

在一个代码块中使用一个名字来暂时代替某个变量

```python
file = open('b.txt'.'w')
with file as f:
    data = f.write('Hello World!\n')
    f.close()
```

或者使用某个名字来接收某个需要记住的变量

```python
with open('b.txt','r') as f:
    data = f.read()
    print(data)
```

### 6. assert

​	assert断言是声明其布尔值必须为真的判断，如果发生异常就说明表达式为假。可以理解assert断言为raise-if-not，用来测试表达式，若其返回值为假，就会触发异常

​	assert的异常参数，其实就是在断言表达式后面添加字符串信息，用来解释断言并更换更方便地得知哪些地方除了问题。

用法

```python
assert exprssion [,arquments]
assert 表达式 [,参数]
```

举例

```python
>>> lists = [1,2,3]
>>> assert len(lists) >= 5,'列表元素个数小于5'
$ AssertionError:列表元素少于5个
```

​	**即assert后面的表达式为假时，会抛出异常，为真时不抛出异常。**

### 7. break

​	跳出循环语句

### 8. class

​	类定义，用于面向对象编程

​	封装、继承、多态

```python
class Person(object):
    #构造函数
    def _init_(self,name,age):
        self.name = name
        self.age = age
obj = Person('Ma',21)
```

### 9. continue

​	下一轮循环

### 10. def

​	用于函数等的定义

```python
def add(a,b)：
	print('{:^20}'.format(a+b))
add(1,2)	#调用
```

### 11. del

​	手动删除变量

### 12. elif

​	同_else if_ 

### 13. else

​	即else

### 14.except

​	python中的异常机制关键字，和try结合使用

```python
try:
    # 尝试运行try代码块
    fh = open('testfile','w')
    fh.write("这是一个测试程序，用于测试异常")
except IOError:
    # 若try代码块中出现IOError异常，则跳过抛出异常执行except代码块
    print("Error:没有找到文件或读取文件失败")
else:
    # 若try代码块中未出现IO异常，执行else代码块
    print("内容读取成功")
finally:
    # 完成上述except或者else代码块的执行后，执行finally代码块
    fh.close()
    print("关闭文件")
```

### 15. finally

​	异常机制中配合try使用，详见14

### 16. for

​	用法逻辑与C相似

```python
for i in range(10):	# i从0遍历至9
    print('{:^20}'.format(i))
```

### 17. from

​	导入模块中的变量和函数

​	注意：**使用from导入的变量会被本地定义的同名变量覆盖，使用import时不会，但使用import时，需要加类名进行使用**

```python
from math import pi
print(pi)	# 3.1415926535...
pi = 4
print(pi)	# 4
```

```python
import math
print(math.pi)	#类名+变量名
```

### 18. global

​	在局部或函数内对全局变量进行修改，须在局部用global声明一次变量，不然无法修改

```python
num = 1
def fun():
    global num
    num = 123
    print(num)
fun()
print(num)
```

### 19. if

​	同C语言if

### 20.import

​	导入第三方库

### 21. in

​	用于判断键是否存在于字典之中，若存在，则返回True

```python
dict = {'Name':'MZP','Age':21}
	if 'Age' in dict:
        print("键'Age'存在")
    else:
        print("键’Age'不存在")
```

### 22. is

​	判断两个变量的指向知否一致

​	即：**内容与地址完全相同时才返回True，否则返回False**

​	不同与“ == ”，此内容相同就会返回True

```python
>>> a = 'MZP'
>>> b = 'MZP'
>>> b is a
$ True	#python中具有同java字符串相同的利用和回收机制
>>> a = ['ma','zhong','ping']
>>> b = a[:]	#复制一份给b
>>> b is a
$ False
>>> b == a
$ True
```

### 23. lambda

​	匿名函数，使用该关键字可以一行定义一个方法

```python
sum = lambda arg1,arg2:arg1+arg2
# 方法名 = lambda 参数列表：方法体
print(sum(1.3,2.8))	#和正常方法一样的调用
```

### 24. nonlocal

​	python3.2后引入的一个关键字

​	用于封装函数中，且一般使用于嵌套函数的场景中

​	在python2.x中，闭包只能读取外部函数的变量，而不能改写它

不使用nonlocal：

```python
def a():
	x = 0
	def b():
		print(locals())	#打印当前所有的局部变量
		y = x +1
        print(locals())
        print(x,y)
        # 该函数中不能添加修改x的语句
    return b
a()()	#调用
```

​	打印结果如下

```python
{'x':0}
{'x':0,'y':1}
0 1
```

使用nonlocal：

```python
def a():
    x = 0
    def b():
		nonlocal x
        x += 1
        print(locals())
        print(x)
    return b
a()()	#调用
```

​	打印结果

```python
{'x':1}
1
```

### 25. not

​	逻辑非

​	优先级not > and > or

​	非0或者非False才会返回True

### 26. or

​	逻辑或

​	**或运算会触发短路现象，即若第一个条件为真，则返回首个条件的值（不一定是布尔型）**

```python
>>> 1 or 0
$ 1
>>> 0 or 1
$ 1
>>> 2 or 3
$ 2
```

### 27. pass

​	占位符，用于空函数

​	当一个函数未实现时，可用pass占位，代码才不会报错

```python
def sample():
    pass
```

### 28. raise

​	python异常机制

​	python可自定义异常，使用raise手动抛出

```python
class CustomException(Exception):	#异常类必须以Exception为父类
    def __init__(self,ErrorInfo):
        super().__init__(self)	#初始化父类对象
        self.errorinfo = ErrorInfo
    def __str__(self):
		return self.errorinfo
    if __name__=='__main__':
    	try:
            raise CustomError('客户异常')
        except CustomError as e:
			print(e)
```

### 29. return 

​	函数返回

### 30.try

​	见14.except

### 31. while

​	循环

### 32. with

​	常用于“with ... as..."

​	其他情况时，要求with后面的对象必须有`__enter__()`或者`__exit__()` 这两个方法

​	可重写上述两个函数对执行的目标进行修改

```python
class Test:
	def __enter__():
        print('__enter__() is called!')
        return self
    def dosomething(self):
        x = 1/0
        print('dosomething')
    def __exit__(self,exc_type,exc_value,traceback):
        print('__exit__() is called!')
        print(f'type:{exc_type}')
        print(f'value:{exc_value}')
        print(f'trace:{tracebace}')
        
    with Test() as sample:
        sample.dosomething()
```

### 33.  yield

​	使用yield定义的函数都称之为生成器，而生成器通常可以理解为迭代器

​	python3.4.3之后需要用`__next__` 方法来生成下一个值

```python
>>> def count(n):
		while n > 0:
			yield n		#生成（迭代n）
			n -= 1
>>> c = count(5)		#设定初值
>>> c.__next__()
$ 5
>>> c.__next__()
$ 4
>>> c.__next__()
$ 3
```

​	生成器只有在调用`__next__()` 方法时才开始执行函数中的语句

​	`c = count(5)`	并未执行count中的语句

​	调用`c.__next__()` 时才真正执行里面的语句，每次调用`__next__()` 时，执行到yield为止

​	`__next__()` 的返回值就是生成的n