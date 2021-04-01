# C# 接口

更彻底的抽象

```C#
///不需要访问修饰符，因为只能是public的
interface ISort{
    ///可以有属性，get和set仅作为“只读/只写”的标志
    int[] Array {get;set}
    
    ///可以有方法，不能有实现
    int[] Ascend();
    int[] Descend();
}
```

