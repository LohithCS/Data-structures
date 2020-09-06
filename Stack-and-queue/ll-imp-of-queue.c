#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
	struct node* link;
};
struct node* front, * rear;
void initializeQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmpty()
{
	if (front == NULL)
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
	struct node* p=front;
	int s = 0;
	while (p != NULL)
	{
		s++;
		p = p->link;
	}
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
	return(front->info);
}
void display()
{
	if (isEmpty())
	{
		printf("queue is empty\n");
		return;
	}
	printf("queue is : \n");

	struct node* p = front;
	while (p != NULL)
	{
		printf("%d ", p->info);
		p = p->link;
	}
	printf("\n");
}
void insert(int x)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	if (temp == NULL) {
		printf("no memory : queue is full\n");
		return;
	}
	temp->info = x;
	temp->link = NULL;
	if (front == NULL)
		front = temp;
	else
		rear->link = temp;
	rear = temp;
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
	temp = front;
	x = temp->info;
	front = front->link;
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