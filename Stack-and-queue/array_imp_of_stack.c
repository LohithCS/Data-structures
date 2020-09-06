#include<stdio.h>
#define MAX 50

int top;
int stack[MAX];


void initializeStack()
{
	top = -1;
}
int size()
{
	return(top + 1);
}
int isEmpty()
{
	if (top == -1)
		return(1);
	else
		return(0);
}
int isFull()
{
	if (top ==MAX - 1)
		return(1);
	else
		return(0);
}
void push(int data)
{
	if (isFull())
	{
		printf("stack is overflow\n");
		return;
	}
	top++;
	stack[top] = data;
}
int pop()
{
	int x;
	if (isEmpty())
	{
		printf("stack underflow\n");
		system("pause");
		exit(0);
	}
	x = stack[top];
	top -= 1;
	return(x);
}
int peek()
{
	if (isEmpty())
	{
		printf("stack underflow\n");
		system("pause");
		exit(0);
	}
	return(stack[top]);
}
void display()
{
	if (isEmpty())
	{
		printf("stack underflow\n");
		system("pause");
		exit(0);
		
	}
	printf("tops is %d\n", top);
	printf("the stack is :\n");
	for (int i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}
void main()
{
	int choice,data=0;
	initializeStack();

	while (1)
	{
		printf("\n\nenter the choice\n");
		printf("1: push an element into stack\n");
		printf("2: pop an element from stack\n");
		printf("3: display all elements of the stack\n");
		printf("4: display the top element of stack\n");
		printf("5: display the size of the stack\n");
		printf("6: quit\n");
		scanf("%d",&choice);
		if (choice == 6)
			break;
		switch (choice)
		{
		case 1:
			printf("enter the element to be pushed\n");
			scanf("%d",&data);
			push(data);
			break;

		case 2:
			data = pop();
			printf("the popped element is : %d\n", data);
			break;

		case 3:
			display();
			break;

		case 4:
			printf("the element at the top of the stack is : %d\n", peek()); 
			break;

		case 5:
			printf("the size of the stack is : %d \n", size());
			break;

		default:
			printf("invalid choice, choose correct option\n");
			break;
		}
	}
	system("pause");
}
