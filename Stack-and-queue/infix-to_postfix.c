#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

void infixToPostfix(char infix[],char postfix[]);
long int evaluatePostfix(char postfix[]);
long int stack[MAX];
int top = -1;
int precedence(char symbol);
int power(int b, int a);
void push(long int symbol);
long int pop();
int isEmpty();
char infix[MAX], postfix[MAX];
void main()
{

	printf("enter the infix expression\n");
	gets(infix);

	infixToPostfix(infix, postfix);
	printf("the postfix expression is %s\n", postfix);
	printf("the value of expression is %ld \n", evaluatePostfix(postfix));
	system("pause");
}
void infixToPostfix(char infix[], char postfix[])
{
	unsigned int i, p;
	char next,symbol;
	p = 0;
	for (i = 0; i < strlen(infix); i++)
	{
		symbol = infix[i];

		if (symbol == ' ' || symbol == '\t')
			continue;

		switch (symbol)
		{
		case '(':
			push(symbol);
			break;
		case ')':
			while ((next = pop())!='(')
				postfix[p++]= next;
			break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '%':
			while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
				postfix[p++] = pop();
			push(symbol);
			break;
		default:
			postfix[p++] = symbol;
			break;
		}
	}
	while (!isEmpty())
		postfix[p++] = pop();
	postfix[p] = '\0';
}
int precedence(char symbol)
{
	switch (symbol)
	{
	case '(':
		return(0);
	case '+':
	case '-':
		return(1);
	case '*':
	case '/':
	case '%':
		return(2);
	case '^':
		return(3);
	default:
		return(0);
	}
}
void push(long int symbol)
{
	if (top == MAX - 1)
	{
		printf("stack is full\n");
		return;
	}
	top++;
	stack[top] = symbol;
}
long int pop()
{
	long int x;
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
int isEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}
long int evaluatePostfix(char postfix[])
{
	long int x, y, result;
	unsigned int i;

	for (i = 0; i<strlen(postfix); i++)
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')
			push(postfix[i] -'0');
		else
		{
			x = pop();
			y = pop();
			switch (postfix[i])
			{
			case '+':
				push(y + x);
				break;
			case '-':
				push(y - x);
				break;
			case '*':
				push(y * x);
				break;
			case '/':
				push(y / x);
				break;
			case '%':
				push(y % x);
				break;
			case '^':
				push(power(y,x));
				break;
			}
		}
	}
	result = pop();
	return(result);
}
int power(int b, int a)
{
	int p, r = 1;
	p = b;
	while (a > 0)
	{
		if (a % 2 == 1)
			r *= p;
		p *= p;
		a /= 2;
	}
	return(r);
}