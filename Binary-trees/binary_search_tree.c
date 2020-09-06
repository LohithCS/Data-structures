#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* lchild;
	int info;
	struct node* rchild;
};
struct node* getnode(int x);
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
struct node* deleteQueue();
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
		printf("%d  ", p->info);
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
	printf("%d  ", p->info);
	preorder(p->lchild);
	preorder(p->rchild);
}
void inorder(struct node* p)
{
	if (p == NULL)
		return;
	inorder(p->lchild);
	printf("%d  ", p->info);
	inorder(p->rchild);
}
void postorder(struct node* p)
{
	if (p == NULL)
		return;
	postorder(p->lchild);
	postorder(p->rchild);
	printf("%d  ", p->info);
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
struct node* getnode(int x)
{
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->info = x;
	p->lchild = p->rchild = NULL;
	return(p);
}
/*
struct node* search(struct node* p, int x)
{
	while (p != NULL)
	{
		if (x < p->info)
			p = p->lchild;
		else if (x > p->info)
			p = p->rchild;
		else
			return(p);
	}
	return(NULL);
}*/
/*recursive*/
struct node* search(struct node* p, int x)
{
		if(p==NULL)
			return(NULL);
		if (x < p->info)
			 return(search(p->lchild,x));
		else if (x > p->info)
			return(search(p->rchild,x));
	return(p);
}
struct node* Min(struct node* p)
{
	if (p == NULL)
		return(NULL);
	while (p->lchild != NULL)
		p = p->lchild;
	return(p);
}
struct node* Max(struct node* p)
{
	if (p == NULL)
		return(NULL);
	while (p->rchild != NULL)
		p = p->rchild;
	return(p);
}
struct node* insertNode(struct node* p, int x)
{
	if (p == NULL)
		p = getnode(x);
	else if (x < p->info)
		p->lchild = insertNode(p->lchild, x);
	else if (x > p->info)
		p->rchild = insertNode(p->rchild, x);
	else
		printf("%d is a duplicate key\n",x);
	return(p);
}
struct node* deletenode(struct node* root, int x)
{
	struct node* par, * p, * s, * ps,*ch;
	par = NULL;
	p = root;
	while (p != NULL)
	{
		if (x == p->info)
			break;
		par = p;
		if (x < p->info)
			p = p->lchild;
		else
			p = p->rchild;
	}
	if (p == NULL)
	{
		printf("%d is not found\n");
		return(root);
	}
	//case 3: node has 2 childs
	if (p->lchild != NULL && p->rchild != NULL)
	{
		ps = p;
		s = p->rchild;
		while (s->lchild != NULL)
		{
			ps = s;
			s = s->lchild;
		}
		p->info = s->info;
		p = s;
		par = ps;
	}
	//case 1/case 0 : single child or leaf node
	if (p->lchild != NULL)
		ch = p->lchild;
	else
		ch = p->rchild;

	if (par == NULL)
		root = ch;
	else if (p == par->lchild)
		par ->lchild = ch;
	else
		par->rchild = ch;
	free(p);
	return root;

}
struct node* insertnode(struct node* root, int x)
{
	struct node* p, * par, * temp;
	p= root;
	par = NULL;
	while (p != NULL)
	{
		par = p;
		if (x < p->info)
			p = p->lchild;
		else if (x > p->info)
			p = p->rchild;
		else
		{
			printf("%d is a dupliacte key\n",x);
			return(root);
		}
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
void main()
{
	struct node* root = NULL, * p;
	int choice,x;

	while (1)
	{
		printf("enter choice\n");
		printf("1: insert a node\n");
		printf("2: delete a node\n");
		printf("3: search a key\n");
		printf("4: height of tree\n");
		printf("5: display\n");
		printf("6: min key\n");
		printf("7: max key\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("enter the value of key :x\n");
			scanf("%d", &x);
			root = insertNode(root, x);
			break;
		case 2:
			printf("enter the value of key :x\n");
			scanf("%d", &x);
			root = deletenode(root, x);
			break;
		case 3:
			printf("enter the key to be searched: x\n");
			scanf("%d", &x);
			p = search(root, x);
			if (p == NULL)
				printf("key not found\n");
			else
				printf("key found\n");
			break;
		case 4:
			printf("height of the tree is %d\n\n", height(root));
			break;
		case 5:
			display(root, 0);
			printf("\n\n");
			break;
		case 6:
			p = Min(root);
			if (p == NULL)
				printf("tree is empty\n");
			else
				printf("smallest key is : %d \n\n", p->info);
			break;
		case 7:
			p = Max(root);
			if (p == NULL)
				printf("tree is empty\n");
			else
				printf("largest key is : %d \n", p->info);
		}
	}
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
	printf("%d", p->info);

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
	queue[rear] = item;
}
struct node* deleteQueue()
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
