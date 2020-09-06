#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* link;
};
void displayElements(struct node* head)
{
	struct node* p;
	if (head->link == NULL) {
		printf("list is empty:\n");
		return(0);
	}
	p = head->link;
	while (p != NULL)
	{
		printf("%d ",p->info);
		p = p->link;
	}
	printf("\n");
}
void insertAtEnd(struct node* head, int data)
{
	struct node* temp, * p;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;
	p = head;// inorder to make use of same func for insertion in empty list head is used or else head->link must have been used
	while (p->link != NULL)
		p = p->link;
	temp->link = NULL;
	p->link = temp;
}
void createlist(struct node* head)
{
	int n, data;
	printf("enter the no of nodes \n");
	scanf("%d",&n);
	printf("enter the first element\n");
	scanf("%d", &data);
	insertAtEnd(head, data);

	for (int i = 2; i <= n; i++)
	{
		printf("enter the next element:\n");
		scanf("%d", &data);
		insertAtEnd(head, data);
	}
}
void insertBeforeX(struct node* head, int data, int x)
{
	struct node* p, * temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;
	p = head;
	while (p->link != NULL)
	{
		if (p->link->info == x)
			break;
		p = p->link;
	}
	if (p->link == NULL)
	{
		printf("%d is not present in the list\n", x);
		return(0);
	}
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = p->link;
		p->link = temp;

	}
}
void insertAtPosition(struct node* head, int data, int k)
{
	struct node* p, * temp;
	p = head;
	int i;
	for (i = 1; i < k - 1 && p != NULL; i++)
		p = p->link;
	if (p == NULL)
		printf("u can insert only until %d\n", i);
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = p->link;
		p->link = temp;
	}
}
void deleteNode(struct node* head, int x)
{
	struct node* temp, * p;
	p = head;
	while (p->link != NULL)
	{
		if (p->link->info == x)
			break;
		p = p->link;
	}
	if (p->link == NULL)
		printf("%d is not prsent in the list\n", x);
	else
	{
		temp = p->link;
		p->link = temp->link;
		free(temp);
	}
}
void main()
{
	int choice, data, k, x, ele;
	struct node* head;

	head = (struct node*)malloc(sizeof(struct node));
	head->info = 0;
	head->link = NULL;

	createlist(head);
	while (1)
	{
		printf("choose the option\n");
		printf("1: display elements\n");
		printf("2: insert at end\n");
		printf("3: insert before the node x\n");
		printf("4: insert at pos k\n");
		printf("5: delet a node with val x\n");
		printf("6: quit\n");
		printf("7: continue\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			displayElements(head);
			break;
		case 2:
			printf("enter ele\n");
			scanf("%d", &data);
			insertAtEnd(head, data);
			break;
		case 3:
			printf("enter X\n");
			scanf("%d", &x);
			printf("enter ele to be added before %d\n", x);
			scanf("%d", &ele);
			insertBeforeX(head, ele, x);
			break;
		case 4:
			printf("enter pos k\n");
			scanf("%d", &k);
			printf("enter data to be added at %d\n", k);
			scanf("%d", &data);
			insertAtPosition(head, data, k);
			break;
		case 5:
			printf("enter the node to be deleted\n");
			scanf("%d", &x);
			deleteNode(head, x);
			break;
		case 6:
			exit(0);
		case 7:
			continue;
		default:
			printf("choose right option\n");
			break;
		}
	}
}