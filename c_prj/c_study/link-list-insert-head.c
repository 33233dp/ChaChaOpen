#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void printList(struct Node *n)
{
	printf("\ndata: ");
	while(n != NULL)
	{
		printf("%d ",n->data);
		n = n->next;
	}
	printf("NULL");
}

struct Node *insertAhead(struct Node *head,int newData)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->data = newData;
	newNode->next = head;

	return newNode;
}

int main()
{
	struct Node *head = malloc(sizeof(struct Node));
	head = NULL;
	
	for(int i = 1;i <= 3;i++)
	{
		head = insertAhead(head,i * 100);
		if(head == NULL)
		{
			printf("error!\n");
			return 1;
		}
	}
	
	printList(head);

	return 0;
}
