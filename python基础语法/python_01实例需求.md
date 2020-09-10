# 密文密码显示

```python
import getpass	#标准库
usrName = input('Name:')
usrPass = getpass.getpass('Password:')
print("USER:",usrName)
print("PASSWORD:",usrPass)
```

​	上述方式在命令行中可用，输入Password时，屏幕不会显示输入（pycharm中无法使用）