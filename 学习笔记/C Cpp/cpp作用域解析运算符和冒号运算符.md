## 1. 作用域解析运算符 (`::`)

在 C++ 中，`::` 被称为**作用域解析运算符 (Scope Resolution Operator)**。它的核心作用是告诉编译器：某个标识符（变量、函数或类）属于哪一个“领地”。

### 主要用法：

- **指定命名空间 (Namespace)：** 访问特定命名空间中的成员。
    
- **类外定义成员函数：** 在类声明之外实现该类的成员函数。
    
- **访问全局变量：** 当局部变量与全局变量重名时，强制访问全局变量。
    

C++

``` cpp
#include <iostream>

class Robot { 
	public: void move(); // 类内声明 
}; 
// 场景：类外实现 
void Robot::move() { 
	// 实现代码 
}
namespace RobotA {
    int speed = 10;
    void move() {
        std::cout << "机器人 A 正在以速度 " << speed << " 移动。" << std::endl;
    }
}

namespace RobotB {
    int speed = 50;
    void move() {
        std::cout << "机器人 B 正在以速度 " << speed << " 移动。" << std::endl;
    }
}

int main() {
    // 使用 :: 调用不同命名空间的同名变量
    std::cout << "A 的速度: " << RobotA::speed << std::endl;
    std::cout << "B 的速度: " << RobotB::speed << std::endl;

    // 使用 :: 调用不同命名空间的同名函数
    RobotA::move();
    RobotB::move();

    // 我们最熟悉的 std 命名空间
    std::string text = "Hello"; 
    std::cout << text << std::endl;

    return 0;
}
```

---

## 2. 冒号运算符 (`:`)

在 C++ 中，单个冒号 `:` 的用途更为多样，它通常作为**引导符**或**分隔符**，出现在不同的语法结构中。

### 主要用法：

- **构造函数初始化列表：** 在进入构造函数体之前初始化成员变量（这是 C++ 推荐的最佳实践）。、
	*   注意只有构造函数才可以使用:初始化列表
    
- **类继承：** 表示一个类继承自另一个类。
    
- **访问权限限定符：** 标记 `public:`、`protected:` 或 `private:`。
    
- **范围 for 循环 (Range-based for loop)：** 用于遍历容器（C++11 及以后）。
    
```cpp
#include <iostream>
#include <vector>

// 1. 类继承与访问说明符
class Animal {
public: // 权限限定
    void eat() { std::cout << "Eating..." << std::endl; }
};

class Dog : public/*继承方式为public*/ Animal { // 继承：Dog 继承自 Animal
private:
    int age;
public:
    // 2. 构造函数初始化列表
    // 在构造函数括号后使用 : 来初始化变量
    Dog(int a) : age(a) {
        // 此时 age 已经初始化为 a 了
    }

    void showAge() {
        std::cout << "Age: " << age << std::endl;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3};

    // 3. 范围 for 循环
    for (int n : nums) { // 这里的冒号读作 "in"
        std::cout << n << " ";
    }
    return 0;
}
```

子级函数调用父级函数

``` cpp
#include <iostream>
#include <string>

// 父类（基类）
class Printer {
public:
    void printHello() {
        std::cout << "Hello from the Parent Class!" << std::endl;
    }
};

// 子类（派生类）
// 使用 public 继承，意味着父类的 public 成员在子类中依然是 public
class LaserPrinter : public Printer {
public:
    void printSpecific() {
        std::cout << "Printing with laser technology..." << std::endl;
    }
};

int main() {
    LaserPrinter myPrinter;

    // 1. 调用子类自己的函数
    myPrinter.printSpecific();

    // 2. 直接调用父类的函数！
    // 即使 LaserPrinter 类内部没有写 printHello，它也继承了这个能力
    myPrinter.printHello(); 

    return 0;
}
```



### 构造函数传递参数
```cpp
#include <iostream>
class obj1 {

	public:
	
		void solve() {
		
			std::cout << "Enter two numbers: ";
			
			int a, b;
				
			std::cin >> a >> b;
			std::cout << a + b << std::endl;
				
		}

};

  

class obj2 : public obj1 {

	public:
		
		obj2(int x, int y) : a(x), b(y) {
		
		std::cout << "Constructor of obj2 called." << std::endl;
		
		std::cout << "a: " << a << ", b: " << b << std::endl;
		
		}
	
	private:
	
		int a, b;

};

  

int main() {

	obj2 o(3, 4);// 括号里面的参数是传给构造函数中对应参数的
	
	o.solve();
	
	return 0;

}
```

## 子类继承父类时，往父类传入参数
**编译器先将参数传递给父类的构造函数，并运行父类构造函数，然后再构造子类**
``` cpp
#include <iostream>

#include <string>

  

class parent {

	public:
	
		parent(int a) {
		
		std::cout << "parent constructor and get a:" << a << std::endl;
		
		}

};

  

class child : public parent {
	
	public:
	
		child(int x) : parent(x) {
		
		std::cout << "child constructor" << std::endl;
		
		}

};

  

int main() {

	child c(20);
	
	return 0;

}
```
## 术语与语法详细解释

基于上述代码，这里有几个你可能尚未完全掌握的 C++ 特有概念：

### 1. 命名空间 (Namespace)

**解释：** 想象一个大型图书馆，不同出版社可能有同名的书。命名空间就像是“出版社”的标签。`std` 是 C++ 标准库的命名空间，所以 `std::cout` 表示使用标准库里的 `cout` 对象。

C++

```
namespace CompanyA { void work() {} }
namespace CompanyB { void work() {} }

// 使用时通过 :: 区分
CompanyA::work();
```

### 2. 构造函数初始化列表 (Initializer List)

**解释：** 在 C 语言中，我们习惯在函数体里给结构体成员赋值。但在 C++ 中，成员变量的**初始化**和**赋值**是两个阶段。使用冒号初始化列表是在变量“出生”那一刻就给它值，效率更高，且对于 `const` 成员或引用成员是必须的。

C++

```
class Test {
    const int id;
public:
    // 必须使用初始化列表，因为 const 变量不能在函数体内被赋值
    Test(int i) : id(i) {} 
};
```

### 3. 范围 for 循环 (Range-based for)

**解释：** 这是 C++11 引入的语法糖，用于简化遍历。它会自动获取容器的开头和结尾，并将每个元素依次赋值给冒号前的变量。

C++

```
int arr[] = {10, 20, 30};
for (int x : arr) { 
    // x 会依次等于 10, 20, 30
}
```

---
