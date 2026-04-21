## 关键字template --- 占位

template 告诉编译器T是某种类型，只是还不确定。而T相当于一个占位符，先在代码里面把位置占好，在函数后面补充int的时候，编译过程中就会将T换成int 。


``` cpp
#include <iostream>

// T 是占位符，告诉编译器：这里有一个类型，现在叫 T
template <typename T>
void printContent(T content) {
    std::cout << "当前数据的内容是: " << content << std::endl;
    std::cout << "该类型占据的字节数: " << sizeof(T) << std::endl;
}

int main() {
    // 显式指定 T 为 int
    printContent<int>(100); 

    // 显式指定 T 为 double
    printContent<double>(3.14159);

    // 甚至可以让编译器自动推导 (隐式实例化)
    printContent("Hello"); // 编译器自动识别 T 为 const char*

    return 0;
}
```

## STL 容器数据类型
``` cpp
#include <iostream>
#include <vector> // 包含向量模板头文件
#include <string>

int main() {
    // 1. 在 C 语言中，你需要定义 int arr[10]
    // 2. 在 C++ 中，我们使用模板类 vector
    
    // 语法：类名<类型> 对象名
    std::vector<int> scores;         // 创建一个专门存放 int 的动态数组
    std::vector<std::string> names;  // 创建一个专门存放 string 的动态数组

    scores.push_back(95);
    scores.push_back(88);

    names.push_back("Alice");

    std::cout << names[0] << " 的分数是: " << scores[0] << std::endl;

    return 0;
}
```