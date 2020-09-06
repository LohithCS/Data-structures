#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
	struct node* link;
};
struct node* top;
void initializeStack()
{
	top = NULL;
}
int isEmpty()
{
	if (top == NULL)
		return(1);
	else
		return(0);
}
int size()
{
	int s=0;
	struct node* p = top;
	while (p != NULL)
	{
		s++;
		p = p->link;
	}
	return(s);
}
void display()
{
	struct node* p;
	p = top;
	if (isEmpty())
	{
		printf("stack is empty\n");
		return;
	}
	printf("the stack is :\n");
	while (p != NULL)
	{
		printf("%d\n", p->info);
		p = p->link;
	}
}
int peek()
{
	if (isEmpty())
	{
		printf("stack underflow\n");
		system("pause");
		exit(0);
	}
	return(top->info);
}
void push(int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("no memory: stack overflow\n");
		return;
	}
	temp->info = data;
	temp->link = top;
	top = temp;
}
int pop()
{
	int x;
	struct node* temp;
	if (isEmpty())
	{
		printf("stack underflow\n");
		system("pause");
		exit(0);
	}
	temp = top;
	x = temp->info;
	top = top->link;
	free(temp);
	return(x);
}
void main()
{
	int choice, data = 0;
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
		scanf("%d", &choice);
		if (choice == 6)
			break;
		switch (choice)
		{
		case 1:
			printf("enter the element to be pushed\n");
			scanf("%d", &data);
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
