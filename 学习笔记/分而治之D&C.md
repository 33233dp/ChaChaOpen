分而治之不是解决一个问题的方法，而是一种思路

分而治之的基本思路：
	1. 确定基线条件并且尽量简单；
	2. 确定如何缩小计算（解决问题）的规模，使其符合基线条件：即缩小规模接近基线条件

例：计算1，2，3，4的和
确定基线条件：1,2的和为3。1的和为1。因此可以将只含有一个数的情况作为基线条件
如何缩小规模？
	sum(1,2,3,4)可以写成1 + sum(2,3,4)
	而sum(2,3,4)可以写成2+sum(3,4)
	以上就是缩小规模的方法
``` cpp
//实例代码
#include <iostream>

using namespace std;

// 计算 arr[start] 到 arr[end] 的和
int sum(int arr[], int start, int end)
{
    // 基线条件：只剩一个元素时，直接返回该元素
    if (start == end)
    {
        return arr[start];
    }

    // 缩小问题规模：当前元素 + 剩余元素之和
    return arr[start] + sum(arr, start + 1, end);
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << sum(arr, 0, n - 1) << endl;

    return 0;
}

```
