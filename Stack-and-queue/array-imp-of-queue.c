#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue[MAX];
int front, rear;

void initializeQueue()
{
	front = -1;
	rear = -1;
}
int isEmpty()
{
	if (front == -1 || front == rear + 1)
		return(1);
	else
		return(0);
}
int isFull()
{
	if (rear==MAX-1)
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
	return(rear - front + 1);
}
int peek()
{
	if (isEmpty())
	{
		printf("queue is empty\n");
		system("pause");
		exit(0);
	}
	return(queue[front]);
}
void display()
{
	if (isEmpty())
	{
		printf("queue is empty\n");
		return;
	}
	printf("queue is : \n");
	for (int i = front; i <= rear; i++)
	{
		printf("%d ", queue[i]);
	}
	printf("\n");
}
void insert(int x)
{
	if (isFull())
	{
		printf("queue is full\n");
		return;
	}if (front == -1)
		front = 0;
	rear += 1;
	queue[rear] = x;
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
	x = queue[front];
	front += 1;
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