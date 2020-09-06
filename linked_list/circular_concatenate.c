#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* link;
};
struct node* insertInEmptyList(struct node* last, int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;

	last = temp;
	last->link = last;
	return(last);
}
struct node* insertAtEnd(struct node* last, int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;

	temp->link = last->link;
	last->link = temp;
	last = temp;
	return(last);
}
struct node* createList(struct node* last)
{
	int n, data, x;
	printf("enter the no of nodes\n");
	scanf("%d", &n);
	last = NULL;
	if (n == 0)
		return(last);
	printf("enter the first node\n");
	scanf("%d", &data);
	last = insertInEmptyList(last, data);

	for (int i = 2; i <= n; i++)
	{
		printf("enter the next node\n", i);
		scanf("%d", &data);
		last = insertAtEnd(last, data);

	}
	return(last);
}
void displayElements(struct node* last)
{
	struct node* p;
	if (last == NULL)
	{
		printf("empty list\n");
		return(0);
	}
	printf("list is: ");
	p = last->link;
	do
	{
		printf("%d\t", p->info);
		p = p->link;
	} while (p != last->link);
	printf("\n");
}
struct node* concatenate(struct node* last1, struct node* last2)
{
	if (last1 = NULL)
	{
		last1 = last2;
		return(last1);
	}
	if (last2 = NULL)
	{
		return(last1);
	}
	struct node* p;
	p = last1->link;
	last1->link = last2->link;
	last2->link = p;
	last1 = last2;
	return(last1);
}
void main()
{
	struct node* last1 = NULL;
	struct node *last2 = NULL;

	last1= createList(last1);
	printf("the first list is:");
	displayElements(last1);

	last2 = createList(last2);
	printf("the second list is:");
	displayElements(last2);

	last1 = concatenate(last1, last2);
	printf("the concatenated list is:");
	displayElements(last1);

	system("pause");
	return(0);
}