#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	int data1;
	struct Node * next;
};

int main()
{
	//创建结点
	struct Node* head = malloc(sizeof(struct Node));
	struct Node* second = malloc(sizeof(struct Node));
	struct Node* third  = malloc(sizeof(struct Node));
	if(head == NULL && second == NULL && third == NULL) 
	{
		printf("error");
		return 1;
	}
	head->data = 100;
	head->data1 = 3200;
	head->next = second;

 	second->data = 100;
 	second->data1 = 1200;
	second->next = third;

 	third->data = 1100;
 	third->data1 = 4200;
	third->next = NULL;

	/*
	printf("data %d\n",head->data);
	printf("head pos %p\n",(void *)head);
	printf("data pos %p\n",(void *)&head->data);
	printf("data1 pos %p\n",(void *)&head->data1);
	printf("next %p\n",(void *)head->next);
	*/
	//遍历并打开链表
	struct Node *temp = head;
	printf("data:");
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}	
	printf("\nNULL\n");
	//用完释放内存
	free(second);
	free(third);
	free(head);
	return 0;
}
