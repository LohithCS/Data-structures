#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node* link;
};
struct node * rear;
void initializeQueue()
{
	rear = NULL;
}
int isEmpty()
{
	if (rear == NULL)
		return(1);
	else
		return(0);
}
int size()
{
	if (isEmpty())
	{
		printf("queue is empty\n");
		return(0);
	}
	struct node* p = rear->link;
	int s = 0;
	do
	{
		s++;
		p = p->link;
	} while (p != rear->link);
	return(s);

}
int peek()
{
	if (isEmpty())
	{
		printf("queue is empty\n");
		system("pause");
		exit(0);
	}
	return(rear->link->info);
}
void display()
{
	if (isEmpty())
	{
		printf("queue is empty\n");
		return;
	}
	printf("queue is : \n");

	struct node* p = rear->link;
	do
	{
		printf("%d ", p->info);
		p = p->link;
	} while (p != rear->link);
	printf("\n");
}
void insert(int x)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	if (temp == NULL) 
	{
		printf("no memory : queue is full\n");
		return;
	}
	temp->info = x;
	if (isEmpty())
	{
		rear = temp;
		rear->link = rear;
	}
	else
	{
		temp->link = rear->link;
		rear->link = temp;
		rear = temp;
	}
}

int delete()
{
	int x;
	if (isEmpty())
	{
		printf("queue is empty\n");
		system("pause");
		exit(0);
	}
	struct node* temp;
	if (rear->link == rear)
	{
		temp = rear;
		rear = NULL;
	}
	else
	{
		temp = rear->link;
		rear->link = temp->link;
	}
	x = temp->info;
	free(temp);
	return(x);
}

void main()
{
	int data, choice;

	initializeQueue();

	while (1)
	{
		printf("choose the option\n");
		printf("1: insert an element in the queue\n");
		printf("2: delete an element from the queue\n");
		printf("3: display all the elements of the queue\n");
		printf("4: display the first element of the queue\n");
		printf("5: display the size of the queue\n");
		printf("6: quit\n");
		scanf("%d", &choice);

		if (choice == 6)
			break;
		switch (choice)
		{
		case 1:
			printf("enter the element to be inserted\n");
			scanf("%d", &data);
			insert(data);
			break;
		case 2:
			data = delete();
			printf("the element that is removed from Q is %d\n", data);
			break;
		case 3:
			display();
			break;
		case 4:
			printf("the element at the front of the queue is %d\n", peek());
			break;
		case 5:
			printf("the size of the queue is %d\n", size());
			break;
		default:
			printf("choose correct option\n");
			break;
		}
	}
	system("pause");
}