#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* link;
};
struct node* insertInBeggining(struct node* last, int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;

	temp->link = last->link;
	last->link = temp;
	return(last);
}
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
void displayElements(struct node *last)
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
		printf("%d\t",p->info);
		p = p->link;
	} while (p!= last->link);
	printf("\n");
}
struct node* insertAfterX(struct node* last, int data, int x)
{
	struct node* p, * temp;
	p = last->link;
	do
	{
		if (p->info == x)
			break;
		p = p->link;
	} while (p != last->link);

	if (p == last->link && p->info != x)
		printf("%d is not present in the list\n", x);

	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;

		temp->link = p->link;
		p->link = temp;

		if (p == last)
			last = temp;

	}
	return(last);
}
struct node* deleteNode(struct node* last, int x)
{
	struct node* temp, * p;
	if (last == NULL)
	{
		printf("list is empty\n");
		return(last);
	}
	//dletion of only node
	if (last->link == last && last->info == x)
	{
		temp = last;
		last = NULL;
		free(temp);
		return(last);
	}
	//deletion of first node
	if (last->link->info == x)
	{
		temp = last->link;
		last->link = temp->link;
		free(temp);
		return(last);
	}
	//deletion in b/w nodes;
	p = last->link;
	while (p->link != last)
	{
		if (p->link->info == x)
			break;
		p = p->link;
	}
	if (p->link != last)
	{
		temp = p->link;
		p->link = temp->link;
		free(temp);
		return(last);
	}
	else
	{
		if (last->info == x) {
			temp = p->link;
			p->link = temp->link;
			last = p;
			free(temp);
		}
		else
		{
			printf("element not found\n");
		}
		return(last);
	}
}

void main()
{
	struct node* last = NULL;
	int x, choice, data;
	last = createList(last);

	while (1)
	{
		printf("choose the option\n");
		printf("1: insert in beggining\n");
		printf("2: insert in empty list\n");
		printf("3: insert at end\n");
		printf("4: display elements\n");
		printf("5: insert after x\n");
		printf("6: delete a node\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("enter the element to be inserted in begg\n");
			scanf("%d", &data);
			last = insertInBeggining(last, data);
			break;
		case 2:
			printf("enter the element to be inserted in empty list\n");
			scanf("%d", &data);
			last = insertInEmptyList(last, data);
			break;
		case 3:
			printf("enter the element to be inserted in end\n");
			scanf("%d", &data);
			last = insertAtEnd(last, data);
			break;
		case 4:
			displayElements(last);
			break;
		case 5:
			printf("enter the pos after which ele to be inserted\n");
			scanf("%d", &x);
			printf("enter the element to be inserted after %d\n", x);
			scanf("%d", &data);
			last = insertAfterX(last, data, x);
			break;
		case 6:
			printf("enter the node x to be deleted\n");
			scanf("%d", &x);
			last= deleteNode(last, x);
			displayElements(last);
			break;
		default:
			printf("choose correct option\n");
			break;

		}

	}
}
