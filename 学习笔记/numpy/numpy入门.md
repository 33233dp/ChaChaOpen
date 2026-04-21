相关的库
```c
import numpy as np
```
## 矩阵
初始化一个矩阵
``` c
>>> a = np.array([1,2,3])
>>> b = np.array([[1,2,3],[4,5,6],[7,8,9]])
```
访问元素
``` c
>>> a[0]
>>> b[2,2]
```
切片读取
```c 
>>> a = np.arrya([1,2,3,4,5])
>>> b = a[3:]
>>> c = a[:3]
```
## 矩阵的属性

``` c
# 获得矩阵的维度数 The number of dimensions of an array
>>> a.ndim
# 形状
>>> a.shape
# 元素个数
>>> a.size
# 矩阵中都是相同的元素都是相同的数据类型
>>> a.dtype
```
