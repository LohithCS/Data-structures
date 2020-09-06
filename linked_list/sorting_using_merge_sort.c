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
struct node* merge(struct node* p1, struct node* p2)
{
	struct node* pM, * startM;

	if (p1->info <= p2->info)
	{
		startM = p1;
		p1 = p1->link;
	}
	else
	{
		startM = p2;
		p2 = p2->link;
	}
	pM = startM;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->info <= p2->info)
		{
			pM->link = p1;
			pM = pM->link;
			p1 = p1->link;
		}
		else
		{

			pM->link = p2;
			pM = pM->link;
			p2 = p2->link;
		}
	}
	if (p1 == NULL)
		pM->link = p2;
	else
		pM->link = p1;
	return(startM);
}
struct node* divideList(struct node *p)
{
	struct node* q, * start2;
	q = p->link->link;
	while (q != NULL && q->link != NULL)
	{
		p = p->link;
		q = q->link->link;
	}
	start2 = p->link;
	p->link = NULL;
	return(start2);
}
struct node* mergeSort(struct node* start)
{
	struct node* start1, * start2, * startM;

	if (start == NULL || start->link == NULL)
		return(start);

	
	start1 = start;
	start2 = divideList(start);
	start1 = mergeSort(start1);
	start2 = mergeSort(start2);
	startM = merge(start1, start2);
	return(startM);
}
void main()
{
	struct node* start= NULL;
	int choice, data, ele, x, k;
	start = create_list(start);
	printf("the first list is;\n");
	display_elements(start);

	start = mergeSort(start);
	printf("the sorted list is:\n");
	display_elements(start);
	system("pause");
}
