#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue[MAX];
int rear, front;
void initializeQueue()
{
	front = -1;
	rear = -1;
}
int isEmpty()
{
	if (front == -1)
		return(1);
	else
		return(0);
}
int isFull()
{
	if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
		return(1);
	else
		return(0);
}
void insertFront(int data)
{
	if (isFull())
	{
		printf("queu is full\n");
		return;
	}
	if (front == -1)
	{
		front = 0;
		rear = 0;
	}
	else if (front == 0)
		front = MAX - 1;
	else
		front -= 1;
	queue[front] = data;
}
void insertRear(int data)
{
	if (isFull())
	{
		printf("queu is full\n");
		return;
	}
	if (front == -1)
	{
		front = 0;
	}
	if (rear == MAX - 1)
		rear = 0;
	else
		rear += 1;
	queue[rear] = data;
}
int deleteFront()
{
	int x;
	if (isEmpty())
	{
		printf("queue is empty\n");
		system("pause");
		exit(0);
	}
	x = queue[front];
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == MAX - 1)
		front = 0;
	else
		front += 1;
	return(x);
}
int deleteRear()
{
	int x;
	if (isEmpty())
	{
		printf("queue is empty\n");
		system("pause");
		exit(0);
	}
	x = queue[rear];
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (rear == 0)
		rear = MAX - 1;
	else
		rear = rear - 1;
	return(x);
}
void display()
{
	int i;
	if (isEmpty())
	{
		printf("queue is empty\n");
		return;
	}
	printf("front= %d \t rear=%d \n", front, rear);
	printf("queue is : \n");
	i = front;
	if (front <= rear)
	{
		while (i <= rear)
			printf("%d ", queue[i++]);
	}
	else
	{
		while (i <= MAX - 1)
			printf("%d ", queue[i++]);
		i = 0;
		while (i <= rear)
			printf("%d ", queue[i++]);
	}
	printf("\n");
}
int size()
{
	int i, sz;
	if (isEmpty())
	{
		return(0);
	}
	if (isFull())
	{
		return(MAX);
	}
	i = front;
	sz = 0;
	if (front <= rear)
	{
		while (i <= rear)
		{
			sz++;
			i++;
		}
	}
	else
	{
		while (i <= MAX - 1)
		{
			sz++;
			i++;
		}
		i = 0;
		while (i <= rear)
		{
			sz++;
			i++;
		}
	}
	return(sz);
}
void main()
{
	int data, choice;

	initializeQueue();

	while (1)
	{
		printf("choose the option\n");
		printf("1: insert an element from front end\n");
		printf("2: insert an element from rear end\n");
		printf("3: delete an element from from front end\n");
		printf("4: delete an element from from rear end\n");
		printf("5: display all the elements of the queue\n");
		printf("6: display the size of the queue\n");
		printf("7: quit\n");
		scanf("%d", &choice);

		if (choice == 7)
			break;
		switch (choice)
		{
		case 1:
			printf("enter the element to be inserted at front end\n");
			scanf("%d", &data);
			insertFront(data);
			break;
		case 2:
			printf("enter the element to be inserted at rear end\n");
			scanf("%d", &data);
			insertRear(data);
			break;
		case 3:
			data = deleteFront();
			printf("the element that is removed from front end is %d\n", data);
			break;
		case 4:
			data = deleteRear();
			printf("the element that is removed from rear end is %d\n", data);
			break;
		case 5:
			display();
			break;
		case 6:
			printf("the size of the queue is %d\n", size());
			break;
		default:
			printf("choose correct option\n");
			break;
		}
	}
	system("pause");
}