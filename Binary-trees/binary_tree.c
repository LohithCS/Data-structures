#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* lchild;
	char info;
	struct node* rchild;
};
struct node *getnode(char x);
int height(struct node* p);
void preorder(struct node* p);
void inorder(struct node* p);
void postorder(struct node* p);
void levelorder(struct node* p);
void display(struct node* p, int level);

#define MAX 100
struct node* queue[MAX];
int front = -1, rear = -1;
void insertQueue(struct node* item);
struct node *deleteQueue();
int queueEmpty();

void levelorder(struct node* p)
{
	if (p == NULL)
	{
		printf("tree is empty\n");
		return;
	}
	insertQueue(p);
	while (!queueEmpty())
	{
		p = deleteQueue();
		printf("%c  ",p->info);
		if (p->lchild != NULL)
			insertQueue(p->lchild);
		if (p->rchild != NULL)
			insertQueue(p->rchild);
	}
}

void preorder(struct node* p)
{
	if (p == NULL)
		return;
	printf("%c  ", p->info);
	preorder(p->lchild);
	preorder(p->rchild);
}
void inorder(struct node* p)
{
	if (p == NULL)
		return;
	inorder(p->lchild);
	printf("%c  ", p->info);
	inorder(p->rchild);
}
void postorder(struct node* p)
{
	if (p == NULL)
		return;
	postorder(p->lchild);
	postorder(p->rchild);
	printf("%c  ",p->info);
}
int height(struct node* p)
{
	int hl, hr;
	if (p == NULL)
	{
		return 0;
	}
	hl = height(p->lchild);
	hr = height(p->rchild);
	if (hl > hr)
		return(1 + hl);
	else
		return(1 + hr);
}
struct node* getnode(char x)
{
	struct node *p = (struct node*)malloc(sizeof(struct node));
	p->info = x;
	p->lchild = p->rchild = NULL;
	return(p);
}
void main()
{
	struct node* root = NULL;
	root = getnode('P');
	root->lchild = getnode('Q');
	root->rchild = getnode('R');
	root->lchild->lchild = getnode('A');
	root->lchild->rchild = getnode('B');
	root->rchild->lchild = getnode('X');

	display(root, 0);
	printf("\n\n");

	printf("preorder:\n");
	preorder(root);
	printf("\n\n");

	printf("inorder:\n");
	inorder(root);
	printf("\n\n");

	printf("postorder:\n");
	postorder(root);
	printf("\n\n");
	 
	printf("levelorder:\n");
	levelorder(root);
	printf("\n\n");

	printf("height of the tree is %d ",height(root));

	system("pause");
}
void display(struct node* p, int level)
{ 
	int i;
	if (p == NULL)
		return;

	display(p->rchild, level + 1);
	printf("\n");

	for (i = 0; i < level; i++)
		printf("   ");
	printf("%c", p->info);

	display(p->lchild, level + 1);
} 
void insertQueue(struct node* item)
{
	if (rear == MAX - 1)
	{
		printf("queue is full\n");
		return;
	}
	if (front == -1)
		front = 0;
	rear = rear + 1;
	queue[rear] =item;
}
struct node *deleteQueue()
{
	struct node* item;
	if (queueEmpty())
	{
		printf("queue underflow\n");
		system("pause");
		exit(0);
	}
	item = queue[front];
	front = front + 1;
	return item;
}
int queueEmpty()
{
	if (front == -1 || front == rear + 1)
		return(1);
	else
		return(0);
}