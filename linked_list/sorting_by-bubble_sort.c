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
void SortByExchangingData(struct node* start)
{
	struct node* p, * q, * end;
	int temp;
	for (end = NULL; end != start->link; end = p)
	{
		for (p = start; p->link != end; p = p->link)
		{
			q = p->link;
			if (p->info > q->info)
			{
				temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
		}
	}
}
struct node* SortByExchangingLink(struct node* start)
{
	struct node* p, * q,*r, * temp,*end;
	for (end = NULL; end != start->link; end = p)
	{
		for (r = p = start; p->link != end; r = p, p = p->link)
		{
			q = p->link;
			if (p->info > q->info)
			{
				p->link = q->link;
				q->link = p;
				if (p != start)
					r->link = q;
				else
					start = q;
				temp = p;
				p = q;
				q = temp;
			}
		}
	}
	return(start);
}
void main()
{
	struct node* start1 = NULL, * start2 = NULL;
	int choice, data, ele, x, k;
	start1 = create_list(start1);
	printf("the first list is;\n");
	display_elements(start1);

	SortByExchangingData(start1);
	printf("the sorted list is:\n");
	display_elements(start1);

	printf("========================================================================\n\n\n");
	start2 = create_list(start2);
	printf("the second list is;\n");
	display_elements(start2);

	start2 = SortByExchangingLink(start2);
	printf("the sorted list is:\n");
	display_elements(start2);
	system("pause");
}
	