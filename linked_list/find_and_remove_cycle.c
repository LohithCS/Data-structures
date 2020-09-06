#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* link;
};
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
		printf("%d ", p->info);
		p = p->link;
	}
	printf("\n");
}
struct node* findCycle(struct node* start)
{
	struct node* slowP, * fastP;
	if (start->link == NULL)
		return(NULL);

	slowP = fastP = start;
	while (fastP != NULL && fastP->link != NULL)
	{
		slowP = slowP->link;
		fastP = fastP->link->link;
		if (slowP==fastP)
			return(slowP);
	}
	return(NULL);
}
void removeCycle(struct node* start, struct node* pC)
{
		struct node* p, * q;
		int lengthOfCycle = 0, lengthOfRemList = 0, lengthOfList = 0;

		printf("the node at which cycle is detected is %d \n", pC->info);

		p = q = pC;
		do
		{
			lengthOfCycle++;
			q = q->link;
		} while (p != q);
		printf("length of cycle is %d:\n", lengthOfCycle);

		p = start;
		while (p != q)
		{
			lengthOfRemList++;
			p = p->link;
			q = q->link;
		}
		printf("length of rem list is: %d\n", lengthOfRemList);
		lengthOfList = lengthOfCycle + lengthOfRemList;

		printf("the lenth of the list is : %d\n", lengthOfList);

		p = start;
		for (int i = 1; i < lengthOfList; i++)
		{
			p = p->link;
		}
		p->link = NULL;
}


	void insertCycle(struct node *start, int x)
	{
		struct node* p, * px = NULL, * prev = start;
		p = start;

		while (p != NULL)
		{
			if (p->info == x)
				px = p;
			prev = p;
			p = p->link;
		}
		if (px != NULL)
			prev->link = px;
	}

	void main()
	{
		struct node* start = NULL, * ptr;
		int choice, data, ele, x, k;
		start = create_list(start);
		printf("the first list is;\n");
		display_elements(start);

		if (start == NULL)
			exit(1);

		x = 5;
		insertCycle(start, x);

		ptr = findCycle(start);
		if (ptr == NULL)
			printf("list is null terminated\n");
		else {
			printf("cycle found in the list\n");
			removeCycle(start, ptr);
			printf("list is now null terminated and new list is:\n");
			ptr=findCycle(start);
			display_elements(start);
			if (ptr == NULL)
				printf("list is null terminated\n");
		}
		system("pause");
	}