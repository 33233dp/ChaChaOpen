# 变量与类型
## 动态数组
``` cpp
#include <vector>
//定义动态数组，nums是长度为0的动态数组
std::vevtor<int> nums
//给动态数组从末尾开始扩容并赋值
int n = 1;
nums.push_back(n);
//求动态数组的长度
int n1 = nums.size();
//访问动态数组
int out = nums[0];
//返回值为动态数组，传递参数为动态数组
std::vector<int> twoSum(std::vector<int> nums,int target)}{
	...
}
```


```
## 引用 &
类型 &别名 = 原变量名
``` cpp
int a = 10;
int &ref = a;
ref = 20;
printf("%d",a);
```
此时a也会变成20
## 布尔类型 <stdbool.h>
```
ture:真
false:假
```
## 空指针常量
在c中是NULL，但本质上是整数。在函数重载的时候可能引发歧义。
cpp引入了nullptr它只能而被赋值给指针类型，不可以被赋值给整数，更加安全。

## 自动类型推导
``` cpp
auto x = 3.14;
```
编译器可以自动推导x为double

## 作用域解析运算符 ::
当全局变量和局部变量重名的时候，c语言无法访问全局变量，但是cpp可以。
```cpp
int a = 100;

int main()
{
    int a = 10;
    std::cout << a << std::endl; //输出10--访问重名局部变量
    std::cout << ::a << std::endl;//输出100 -- 访问重名全局变量
}
```
## 结构体
c++中，定义变量可以不需要struct关键字
```
//内部定义函数
struct Point
{
    int x,y;
    void print()
    {
        std::cout << "hello" << std::endl;
    }
};
Point p1;//不需要struct关键字

//外部定义函数
struct PID
{
    int s;
    void parameter(int x);
};

void PID::parameter(int x)
{
    s = x;
}
//调用结构体函数
int main()
{
    PID pid;
    int x = 10;
    pid.parameter(x);
    return 1;
}
```
## 练习
* 编写一个swap函数，C语言中需要传入指针swap(int *a,int *b)。现在尝试引用swap(int &a,int &b)来实现。*
【注】在cpp中，&是引用的意思，而不是取地址。

* 用两种方式创建结构体函数，调用结构体函数。





