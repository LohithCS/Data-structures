#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct node
{
	struct node* lchild;
	int info;
	struct node* rchild;
};
struct node* stack[MAX];
int top;
void push(struct node* item);
struct node* pop();
void initializeStack();
int empty();

struct node* getnode(int x);
struct node* insertnode(struct node *root, int x);
void inorder(struct node* root, int a[]);
struct node* Destroy(struct node* ptr);

void main()
{
	int a[50], i, n;
	struct node* root = NULL;
	printf("enter the number of elements\n");
	scanf("%d", &n);

	for(i=0; i < n; i++)
	{
		printf("enter element %d\n",i);
		scanf("%d", &a[i]);
	}

	printf("the array is :");
	for(i=0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	for (i = 0; i < n; i++)
		root = insertnode(root,a[i]);

	inorder(root, a);
	printf("the sorted array is :");

	for(i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	root = Destroy(root);
	system("pause");
}
void initializeStack()
{
	top = -1;
}
int empty()
{
	if (top == -1)
		return(1);
	else
		return(0);
}
struct node* getnode(int x)
{
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->lchild = NULL;
	p->info = x;
	p->rchild = NULL;
	return(p);
}
struct node *insertnode(struct node *root, int x)
{
	struct node* p, * temp, * par;
	p = root;
	par = NULL;
	while (p != NULL)
	{
		par = p;
		if (x < p->info)
			p = p->lchild;
		else
			p = p->rchild;
	}
	temp = getnode(x);

	if (par == NULL)
		root = temp;
	else if (x < par->info)
		par->lchild = temp;
	else
		par->rchild = temp;
	
	return(root);
}
void inorder(struct node* root, int a[])
{
	struct node* p;
	int i = 0;
	if (root== NULL)
	{
		printf("the tree is empty\n");
		return;
	}
	initializeStack();
	p = root;
	while (1)
	{

		while (p->lchild != NULL)
		{
			push(p);
			p = p->lchild;
		}
		while (p->rchild == NULL)
		{
			a[i++] = p->info;
			if (empty())
				return;
			p = pop();
		}
		a[i++] = p->info;
		p = p->rchild;
	}
	printf("\n");
}
struct node* Destroy(struct node* ptr)
{
	if (ptr != NULL)
	{
		Destroy(ptr->lchild);
		Destroy(ptr->rchild);
		free(ptr);
	}
	return(NULL);
}
void push(struct node* item)
{
	if (top == MAX - 1)
	{
		printf("stack overflow");
		return;
	}
	stack[++top] = item;
}
struct node* pop()
{
	struct node* item;
	if (empty())
	{
		printf("stack underflow\n");
		return;
	}
	item = stack[top--];
	return(item);
}