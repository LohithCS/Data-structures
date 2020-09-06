#include<stdio.h>
#include<stdlib.h>

struct node
{
	int priority;
	int info;
	struct node* link;
};
struct node* front;
void initializeQueue()
{
	front = NULL;
}
int isEmpty()
{
	if (front== NULL)
		return(1);
	else
		return(0);
}
void insert(int elementPriority, int element)
{
	struct node* temp, * p;
	temp = (struct node*)malloc(sizeof(struct node));
	if (temp ==NULL)
	{
		printf("memeory not available\n");
		return;
	}
	temp->info = element;
	temp->priority = elementPriority;

	if (isEmpty() || elementPriority < front->priority)
	{
		temp->link = front;
		front = temp;
	}
	else
	{
		p = front;
		while (p->link != NULL && p->link->priority <= elementPriority)
			p = p->link;
		temp->link = p->link;
		p->link = temp;
	}
}
int delete()
{
	struct node *temp;
	int element;
	if (isEmpty())
	{
		printf("queue is empty\n");
		system("pause");
		exit(0);
	}
	temp = front;
	element = temp->info;
	front = front->link;
	free(temp);
	return(element);
}
void display()
{
	struct node* p;
	if (isEmpty())
	{
		printf("queue is empty\n");
		return;
	}
	else
	{
		p = front;
		printf("queue is \n");
		printf("priority          element\n");
		while (p != NULL)
		{
			printf("%5d            %5d\n", p->priority, p->info);
			p = p->link;
		}
	}
	printf("\n");
}
void main()
{
	int element, elementPriority,choice;

	initializeQueue();

	while (1)
	{
		printf("choose the option\n");
		printf("1:  insert an element\n");
		printf("2:  delete an element\n");
		printf("3:  display the queue\n");
		printf("quit\n");
		scanf("%d", &choice);

		if (choice == 4)
			break;
		switch (choice)
		{
		case 1:
			printf("enter the element priority\n");
			scanf("%d", &elementPriority);
			printf("enter the element to be inserted\n");
			scanf("%d",&element);
			insert(elementPriority, element);
			break;
		case 2:
			element = delete();
			printf("the element that is removed from queue is %d", element);
			break;
		case 3:
			display();
			break;
		default:
			printf("choose correct option\n");
			break;
		}
	}
	system("pause");
}