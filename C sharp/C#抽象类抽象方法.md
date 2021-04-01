# 抽象类

由abstruct修饰

（1）不能实例化，常做基类

（2）可以包含抽象方法

（3）继承抽象类必须重写其抽象方法

（4）可以用父类容器装子类

```C#
abstruct class Fruit{
    //与普通类相似，知识不能实例化
    public string name;
    //抽象方法：
    //1.只在抽象类中声明
    //2.没有方法体
    //3.不能是私有的(可以是公有的或者可继承的)
    //4.继承后必须实现，用override重写
    public abstrct void Bad();
    
    //虚方法
    //1.可选择实现
    //2.子类可选择性实现
    //3.抽象方法和虚方法都可以无限重写
    public virtual void Test(){...};
    //抽象类可理解为纯虚类
    //用于政体框架设计
}
public Apple:Fruit{
    public override void Bad(){...}
}


```

