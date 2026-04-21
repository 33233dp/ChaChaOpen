# 类与对象
## 封装public与private
* public:类可以直接访问，用于存放函数,也可以存放变量，这里的变量可以被外部修改
* private:只有类内部的函数可以访问，用于存放变量，防止外部意外修改。这里的变量不会被外部修改。
``` cpp
class Motor{
private:
    int speed;
public:
    int t;
    void setspeed(int s){
        if(s > 0 && s <= 100) speed = s;
    }    
    int getSpeed() {return speed;}
};
```
类的成员访问方式和结构体类似。
``` cpp
Motor myMotor;
myMotor.t = 10;
myMotor.setSpeed(80);
```
## 对象的生命周期：构造与析构
* 构造函数：在对象定义的时候**Motor m1;**，构造函数不需要调用就会自己运行(被编译器调用)
* 析构函数：当对象的生命周期结束，析构函数就会被执行。
* 【注】类名，析构函数，构造函数**三者**的名称必须一致。
* 【注】构造函数的调用是由PID p1;引起的，不是由PID.kp = 1引起的。因此函数中可以不写任何变量。
```cpp 
#include <iostream>

class Motor {
public:
    int speed;

    // 1. 构造函数：变量诞生时自动跑
    Motor() {
        speed = 0;
        std::cout << "构造函数：电机已启动并清零" << std::endl;
    }

    // 2. 析构函数：变量销毁时自动跑
    ~Motor() {
        speed = 0;
        std::cout << "析构函数：电机已安全停止" << std::endl;
    }
};

int main() {
    {
        Motor m1; // 这一行执行完，构造函数立刻自动运行
        m1.speed = 100;
        std::cout << "正在运行，速度：" << m1.speed << std::endl;
    } // 变量 m1 的作用域到这里结束，析构函数在这里自动运行

    std::cout << "程序结束" << std::endl;
    return 0;
}
```
## 补充：操作符**::**
**::**是作用域解析运算符
[1] 全局作用域访问
``` cpp
int age = 100; // 全局变量

void func() {
    int age = 20; // 局部变量
    std::cout << "局部 age: " << age << std::endl;   // 20
    std::cout << "全局 age: " << ::age << std::endl; // 100
}
```
[2] 命名空间成员访问  空间名::成员名
* 用于区分不同库中的成员，并且::可以嵌套使用（因为命名空间可以嵌套）
``` cpp
namespace Company {
    namespace Project {
        int version = 1;
    }
}
int v = Company::Project::version; // 多级定位
```

[3] 类成员的类外实现
``` cpp
class Camera {
public:
    void rotate(); // 仅声明
};

// 在类外部定义，必须指明作用域
void Camera::rotate() {
    std::cout << "旋转相机" << std::endl;
}
```
[4] 访问类的静态成员与常量
``` cpp
class Config {
public:
    static int MAX_USER;
};

int Config::MAX_USER = 1000; // 初始化静态变量
int limit = Config::MAX_USER; // 直接访问
```
[5] 访问别名 using创建别名
``` cpp
using IntVec = std::vector<int>;
IntVec my_data; // 直接访问

namespace MyProject {
    using ID = int;
}
MyProject::ID user_id; // 通过命名空间访问

class Subscription {
public:
    using SharedPtr = std::shared_ptr<Subscription>;
};
// 访问方式：类名::别名
Subscription::SharedPtr pointer;
```

# 总结

类实例化之后得到的是对象。命名空间不存在实例化的说法。
类的只能访问静态成员并且使用::操作符，对象成员的访问使用.操作符，命名空间成员的访问使用操作符::

### 访问类的函数

注意区分类成员的访问和对象成员的访问。类的成员的访问使用：：操作符并且只能访问和执行静态成员。如果想要访问类成员函数的地址，则需要使用&操作符告诉编译器不要执行这个函数而是获得这个函数的地址。
``` cpp


pose_sub_ = this->create_subscription<turtlesim::msg::Pose>(
            "/turtle1/pose", 10, std::bind(&TurtleController::pose_callback, this, std::placeholders::_1));
//&告诉编译器我的目的不是执行TurtleControllerr::pose_callback对应的函数，而是读取这个函数的地址。因为TurtleControllerr不是一个实例化的对象，因此使用操作符::。由于我们只是读取地址，因此不用关系::后面的是不是静态函数。
```


## 补充**:**操作符
* 用于初始化列表
``` cpp
Player(std::string name) : name(name) { ... }
```


## 实例化对象  
* 栈实例化
    类本身不会占用空间，但是实例化对象的时候，编译器会在栈内存上为该对象分配空间。
    栈实例化速度快，生命周期在进入作用于开始，离开作用于的时候自动销毁。
    使用**.**操作符就可以访问成员
    不会产生内存泄漏
    ```cpp
    class Player {
    public:
        Player() { std::cout << "出生了！\n"; }
        ~Player() { std::cout << "销毁了！\n"; }
        void move() { std::cout << "正在移动...\n"; }
    };

    int main() {
        {
            Player p1; // 栈实例化
            p1.move(); 
        } // p1 在离开这个花括号（作用域）时，自动调用析构函数释放
        return 0;
    }
    ```
* 堆实例化
堆实例化必须使用new关键字，通过指针接收分配的地址。
* 使用**->**访问成员。
* 需要手动使用delete销毁
``` cpp
class Player {
public:
    Player(std::string name) : name(name) { std::cout << name << " 进入了游戏\n"; }
    ~Player() { std::cout << name << " 离开了游戏\n"; }
private:
    std::string name;
}; 

int main() {
    // 1. 申请内存并实例化
    Player* p = new Player("Thor");

    // 2. 访问成员（使用 -> 符号）
    // p->move();

    // 3. 必须手动销毁
    delete p;

    return 0;
}
```
* 其中,private中的name是Player的成员，构造函数的name表示要传入的参数是std:string类，传入的name也是一个类，他有自己的成员，比如字符串长度,字符数组之类的。
* :name(name)指的是把传入的参数复制到类Player的成员name中。（初始化列表）
