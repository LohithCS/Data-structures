#include<stdio.h>
#include<stdlib.h>
struct node* create_list(struct node* start);
void insertAtend(struct node* start, int data);
void count_nodes(struct node* start);
struct node* insertInbeggining(struct node* start, int data);
struct node
{
	int info;
	struct node* link;
};
struct node* insertAtpos(struct node* start, int  k, int data)
{
	int i;
	if (k == 1)
	{
		struct node* temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = start;
		start = temp;
		return(start);
	}
	struct node* p;
	p = start;
	for (i = 1; i < k - 1 && p != NULL; i++)
	{
		p = p->link;
	}
	if (p == NULL)
		printf("u can insert until %d", i);
	else {
		struct node* temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = p->link;
		p->link = temp;
	}
	return(start);
}

struct node* insertBeforeX(struct node* start, int x, int ele)
{
	if (start == NULL)
	{
		printf("list is empty\n");
		return(start);
	}
	if (start->info == x)
	{
		struct node* temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = ele;
		temp->link = start;
		start = temp;
		return(start);
	}
	struct node* p;
	p = start;
	while (p->link != NULL)
	{
		if (p->link->info == x)
			break;
		p = p->link;
	}
	if (p->link == NULL)
	{
		printf("ele is not present\n");
	}
	else
	{
		struct node* temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = ele;
		temp->link = p->link;
		p->link = temp;
	}
	return(start);
}
void insertAfterX(struct node* start, int x, int ele)
{
	struct node* p;
	p = start;
	while (p != NULL)
	{
		if (p->info == x)
			break;
		p = p->link;
	}
	if (p == NULL)
	{
		printf("%d is not present\n", x);
	}
	else
	{
		struct node* temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = ele;
		temp->link = p->link;
		p->link = temp;
	}
}
struct node* create_list(struct node* start)
{
	int n, data;
	printf("enter the no of nodes\n");
	scanf("%d", &n);
	if (n == 0)
		return(start);
	printf("enter the first ele\n");
	scanf("%d", &data);
	start = insertInbeggining(start, data);
	for (int i = 2; i <= n; i++)
	{
		printf("enter the next ele\n");
		scanf("%d", &data);
		insertAtend(start, data);
	}
	return(start);
}
struct node* insertInbeggining(struct node* start, int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;
	temp->link = start;
	start = temp;
	return start;
}
void insertAtend(struct node* start, int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;
	struct node* p;
	p = start;
	while (p->link != NULL)
	{
		p = p->link;
	}
	p->link = temp;
	temp->link = NULL;
}
void display_elements(struct node* start)
{
	struct node* p;
	if (start == NULL)
	{
		printf("list is empty\n");
		return;
	}
	printf("list is:  ");
	p = start;
	while (p != NULL)
	{
		printf("%d\t", p->info);
		p = p->link;
	}
	printf("\n");
}
void count_nodes(struct node* start)
{
	struct node* p;
	p = start;
	int n = 0;
	while (p != NULL)
	{
		n++;
		p = p->link;
	}
	printf("num of nodes:%d\n", n);
}

struct node* deleteNode(struct node* start, int x)
{
	struct node* p, * temp;
	if (start == NULL)
	{
		printf("empty list\n");
		return(start);
	}
	//delete first node

	if (start->info == x)
	{
		temp = start;
		start = start->link;
		free(temp);
		return(start);
	}
	// delete in b/w or end of list
	p = start;
	while (p->link != NULL)
	{
		if (p->link->info == x)
			break;
		p = p->link;
	}
	if (p->link == NULL)
	{
		printf("element not in list\n");
	}
	else {
		temp = p->link;
		p->link = temp->link;
		free(temp);
	}
	return(start);
}
struct node* reverseList(struct node* start)
{
	struct node* prev, * ptr, * next;
	prev = NULL;
	ptr = start;
	while (ptr != NULL)
	{
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return(start);
}
void main()
{
	struct node* start = NULL;
	int choice, data, ele, x, k;
	start= create_list(start);
	
	while (1)
	{
		printf("choose the option\n");
		printf("1: insert at begg\n");
		printf("2: display elements\n");
		printf("3: count no of nodes\n");
		printf("4: insert at end\n");
		printf("5: insert after the node x\n");
		printf("6: insert before the node x\n");
		printf("7: insert at pos k\n");
		printf("8: delet a node with val x\n");
		printf("9: reverse a list\n");
		printf("10: quit\n");
		printf("11: continue\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("enter ele\n");
			scanf("%d", &data);
			start = insertInbeggining(start, data);
			break;
		case 2:
			display_elements(start);
			break;
		case 3:
			count_nodes(start);
			break;
		case 4:
			printf("enter ele\n");
			scanf("%d", &data);
			insertAtend(start, data);
			break;
		case 5:
			printf("enter X\n");
			scanf("%d", &x);
			printf("enter ele to be added after %d\n", x);
			scanf("%d", &ele);
			insertAfterX(start, x, ele);
			break;
		case 6:
			printf("enter X\n");
			scanf("%d", &x);
			printf("enter ele to be added before %d\n", x);
			scanf("%d", &ele);
			start = insertBeforeX(start, x, ele);
			break;
		case 7:
			printf("enter pos k\n");
			scanf("%d", &k);
			printf("enter data to be added at %d\n", k);
			scanf("%d", &data);
			start = insertAtpos(start, k, data);
			break;
		case 8:
			printf("enter the node to be deleted\n");
			scanf("%d", &x);
			start = deleteNode(start, x);
			break;
		case 9:
			start = reverseList(start);
			printf("reversed list\n");
			display_elements(start);
			break;
		case 10:
			exit(0);
		case 11:
			continue;
		default:
			printf("choose right option\n");
			break;
		}
	}

}