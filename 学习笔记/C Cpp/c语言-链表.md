 链表
## 节点
节点实际上是一个自引用结构体指针，节点有数据和下一个节点的地址构成即data和nexrt。
``` c
struct Node 
{
	int data;
	int data2;
	struct Node * next;
}
struct Node *head;
```
其中head是一个结构体指针，也是一个节点。需要为每个节点分配一个地址，如head = distnation或者head = malloc(sizeof(struct Node))。
malloc可以为节点分配一个地址如0x001,这样head所指向的地址就是0x001,而head内部的成员的地址是连续的，并且内存对齐。每个成员的地址是相对于head地址的偏移地址。
如果地一个成员是char类型，第二个是Int则在char变量之后会分配三个“空隙”（无用字节）。其中地一个成员的偏移地址是0。
``` c
head pos 0x5f20eefea2a0
data pos 0x5f20eefea2a0
data2 pos 0x5f20eefea2a4
next (nil)
```
## 创建一个节点代码
``` c
# include <stdio.h>
# include <stdlib.h>
struct Node
{
	int data;
	int data1;
	struct Node * next;
}
int main()
{
	struct Node *head = malloc(sizeof(struct Node));
	if(head == NULL)
	{
		printf("error");
		return 1;
	}
	head->data = 100;
	head->data1 = 200;
	head->next = NULL;
	printf("data %d",head->data);
	printf("head pos %p",(void *)head);
	printf("data pos %p",(void *)&head->data);
	printf("data1 pos %p",(void *)&head->data1);
	prrintf("next pos %p",(void *)head->next);
	free(head);
	retrun 0;
}
```
## 链表
链表用于创建非连续存储地址的数据存储空间。这是与数组连续存储地址的一明显区别。链表的节点可以删减插入，而数组定义之后数组的大小不可以改变。链表通过节点中的指针将零散的存储块连接起来
### 单向链表结构
* 头指针-指向地一个节点的指针
* 结点-包含数据域与指针域的结构体
* NULL-最后一个结点必须指向NULL
### 由结点到链表
1）定义结构体
``` c
struct Node
{
    int data;
    struct Node *next;    
}
```
2) 初始化头指针
struct Node *head;

3) “穿针引线”
A->next = B;
### 链表四大基本功
* 遍历-使用一个临时指针temp从head开始直到temp == NULL结束，完成打印链表，查找数据的基本动作
* 头插法-创建一个新结点，让新结点的next指向head。
* 尾插法-找到最后一个节点即指向NULL的节点，让他的next指向新的结点。
* 删除节点-让待删除节点的前一个节点绕过待删除节点让它指向后继结点。
[注]修改指针之前，要确保还有指针指向后一个结点，否则一旦断了联系，就再也找不回它们，变成内存垃圾。
* 数组与链表
    数组：存储空间连续，固定大小，插入和删减数据麻烦，访问速度极快，无额外开销
    链表：存储空间非连续，大小可变，插入和删减速度非常快，访问速度较慢，需要额外空间存储指针
### 遍历链表
    1.创建链表
    2.创建临时指针（结点对应的结构体指针）
    3.使用临时指针从head开始遍历链表
    4.释放内存

