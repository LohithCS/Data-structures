#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

char stack[MAX];
void push(char);
void initializeStack();
char pop();
int isEmpty();
int top;

int isValid(char exp[]);
int matchParenthesis(char leftPar,char rightPar);

void initializeStack()
{
	top = -1;
}
int isEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}
void push(char par)
{
	if (top == MAX - 1)
	{
		printf("stack is full\n");
		return;
	}
	top++;
	stack[top] = par;
}
char pop()
{
	char x;
	if (isEmpty())
	{
		printf("stack is empty\n");
			return(0);
	}
	else
	{
		x = stack[top];
		top--;
		return(x);
	}
}
int matchParenthesis(char leftPar, char rightPar)
{
	if (leftPar == '{' && rightPar == '}')
		return(1);
	if (leftPar == '[' && rightPar == ']')
		return(1);
	if (leftPar == '(' && rightPar == ')')
		return(1);
	return(0);
}
int isValid(char exp[])
{
	int i;
	char ch;
	for (i = 0; i < strlen(exp); i++)
	{
		if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
			push(exp[i]);
		if (exp[i] == ']' || exp[i] == '}' || exp[i] == ')')
			if (isEmpty())
			{
				printf("invalid expression\nright parenthesis are more in number\n");
				return(0);
			}
			else
			{
				ch = pop();
				if (!matchParenthesis(ch, exp[i]))
				{
					printf("mismatched parenthesis are :\n");
					printf("%c and %c \n", ch, exp[i]);
					return(0);
				}
			}
	}
	if (isEmpty())
	{
		printf("balanced parenthesis\n");
		return(1);
	}
	else
	{
		printf("left parenthesis is more than right parenthesi\n");
		return(0);
	}
}

void main()
{
	char expression[MAX];

	int choice = 'y';

	while (choice == 'y')
	{
		printf("enter the expression with parenthesis\n");
		gets(expression);

		initializeStack();

		if (isValid(expression))
		{
			printf("valid expression\n");
		}
		else
		{
			printf("invalid expression\n");
		}
		printf("want to check another expresssion\nenter 'y' for yes\n");
		scanf("%c",&choice);
		fflush(stdin);
	}
}