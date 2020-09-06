#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* link;
};
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
struct node* insertInbeggining(struct node* start, int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;
	temp->link = start;
	start = temp;
	return start;
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
	printf("ok");
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
	p = start;
	while (p!= NULL)
	{
		printf("%d\t", p->info);
		p = p->link;
	}
	printf("\n");
}
struct node* concatenae(struct node* start1, struct node* start3)
{
	struct node* p;
	if (start1==NULL)
	{
		start1 = start3;
		return(start1);
	}
	if (start3== NULL)
		return(start1);
	p = start1;
	while (p->link!=NULL)
		p = p->link;
	p->link = start3;
	return(start1);
}
void main()
{
	struct node *start1 = NULL,*start3 = NULL;

	printf("first list STARTS here\n");
	start1 = create_list(start1);
	printf("the first list is:");
	display_elements(start1);

	printf("second list STARTS here\n");
	start3 = create_list(start3);
	printf("the second list is:");

	display_elements(start3);

	start1 = concatenae(start1, start3);
	printf("the concatenated list is:");
	display_elements(start1);
	system("pause");
}
