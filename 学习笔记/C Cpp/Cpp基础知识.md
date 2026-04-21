# cpp基础知识
## hello word!
``` c
#include <iostream>
 
 int main(){
std::cout << "hello word!"  <<endl;
}
```

## 类型 变量 算术运算
### 声明 
是一条语句，引入新名字并指定类型：
    * 类型：定义一组可能的值，一组操作 
    * 对象：存放某类型数值的存储空间
    * 值
    * 变量：是一个命名对象
### cpp基本变量类型
    * bool 1
    * char 1
    * int  4
    * double 8
### cpp初始化符号
``` cpp
double d1 = 2.3;
double d2 {2.3};
complex<double> z = 1;//数值为双精度浮点数的复数 z = 1.0 + 0i
complex<double> z {1,2};//z =1.0 + 2.0i

std::cout << "实部" << z.real() << std::endl;
std::cout << "虚部" << z.imag() << std::endl;
std::cout << "复数的模" << std::abs(z) << std::endl;

double d1 = 1;
double d2 = 2;
complex<double> z1 {d1,d2};

//由整数构成的向量
vector<int> v {1,2,3,4};
```
### 常量
* const 值不会被改变
* constexpr 允许将变量置于只读内存中
``` cpp
const int dmv = 17;//dmv是一个命名的常量
int var = 17;//var不是常量

```
### 检验和循环
* <<输出运算符
* >>输入运算符
```
cout << "Do u want to process (y or n)?\n";
char answer = 0;
cin >> answer;
switch(answer) ...    
``` 
### 指针数组和循环

