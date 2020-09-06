#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* prev;
	int info;
	struct node* next;
};
struct node* insertInbeggining(struct node* start, int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info =  data;
	temp->prev = NULL;
	temp->next = start;
	start->prev = temp;
	start = temp;
	return(start);
}
void insertAfter(struct node* start, int x, int data)
{
	struct node* p;
	p = start;
	while (p != NULL)
	{
		if (p->info == x)
			break;
		p = p->next;
	}
	if (p == NULL)
	{
		printf("%d is not pressent in list", x);
	}
	else {
		struct node* temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;
		temp->next = p->next;
		temp->prev = p;
		if(p->next!=NULL)
		   p->next->prev = temp;
		p->next = temp;
	}
}
struct node *insertBefore(struct node* start, int x, int val)
{
	if (start == NULL)
	{
		printf("list is empty\n");
		return(start);
	}
	if (start->info== x)
	{
		start=insertInbeggining(start,val);
		return(start);
	}
	struct node* p;
	p = start;
	while (p != NULL)
	{
		if (p->info == x)
			break;
		p = p->next;
	}
	if (p == NULL)
	{
		printf("%d is not pressent in list", x);
	}
	else
	{
		struct node* temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = val;
		temp->next = p;
		temp->prev = p->prev;
		p->prev->next = temp;
		p->prev = temp;
	}
	return(start);
}
void count_nodes(struct node* start)
{
	struct node* p;
	p = start;
	int n = 0;
	while (p!= NULL)
	{
		n++;
		p = p->next;
	}
	printf("num of nodes:%d\n", n);
}
struct node* insertInemptylist(struct node* start, int data)
{

	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;
	temp->next = NULL;
	temp->prev = NULL;
	start = temp;
	return(start);
}

void insertAtend(struct node* start, int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;

	struct node* p;
	p = start;
	while (p->next!= NULL)
	{
		p = p->next;
	}
	p->next = temp;
	temp->next = NULL;
	temp->prev = p;
}
struct node* createlist(struct node* start)
{
	int n, data;
	printf("enter the no of nodes\n");
	scanf("%d",&n);
	if (n == 0)
		return(start);
	printf("enter first element\n");
	scanf("%d", &data);
	start=insertInemptylist(start, data);
	for (int i = 2; i <= n; i++)
	{
		printf("enter next element\n");
		scanf("%d", &data);
		insertAtend(start, data);
	}
	return(start);
}
struct node* reverse_list(struct node* start)
{
	if (start == NULL)
		return(start);

	struct node* p1, * p2;
	p1 = start;
	p2 = p1->next;
	p1->next = NULL;
	p1->prev = p2;
	while (p2 != NULL)
	{
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}
	start = p1;
	return(start);
}
void display_elements(struct node* start)
{
	struct node* p;
	if (start == NULL)
		printf("list is empty\n");
	
		printf("list is:  ");
		p = start;
		while (p!= NULL)
		{
			printf("%d\t",p->info);
			p = p->next;
		}
		printf("\n");
}
struct node * deleteNode(struct node* start, int x)
{
	struct node* temp;
	//empty list
	if (start == NULL)
	{
		printf("empty list!!!\n");
		return(start);
	}
	//deletion of only node
	if (start->next == NULL)
	{
		if (start->info == x)
		{
			temp = start;
			start = NULL;
			free(temp);
		}
		else
			printf("element s not there in list\n");
		return(start);
	}
	//deletion of first node

	if (start->info == x)
	{
		temp = start;
		start = start->next;
		start->prev = NULL;
		free(temp);
		return(start);
	}
	//deletion of in b/w nodes..
	temp = start->next;
	while (temp->next != NULL)
	{
		if (temp->info == x)
			break;
		temp = temp->next;
	}
	if (temp->next != NULL) {
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		free(temp);
	}
	//deletion of last node
	else
	{
		temp->prev->next = NULL;
		free(temp);
	}
	return(start);


	
}
void main()
{
	int choice,data,x,val;
	struct node* start = NULL;
	start = createlist(start);
	while (1)
	{
		printf("choose the option\n");
		printf("1: insert at begg\n");
		printf("2: display elements\n");
		printf("3: count no of nodes\n");
		printf("4: insert at end\n");
		printf("5: insert before x\n");
		printf("6: insert after x\n");
		printf("7: delete node with val x\n");
		printf("8: continue\n");
		printf("9: quit\n");
		printf("10: insertin empty\n");
		printf("11: reverse list\n");

		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("enter ele\n");
			scanf("%d", &data);
			start = insertInbeggining(start, data);
			break;
		case 2:
			display_elements(start);
			break;
		case 3:
			count_nodes(start);
			break;
		case 4:
			printf("enter ele\n");
			scanf("%d", &data);
			insertAtend(start, data);
			break;
		case 5:
			printf("enter pos x\n");
			scanf("%d", &x);
			printf("enter data to be inserted\n");
			scanf("%d",&val);
			start=insertBefore(start, x, val);
			break;
		case 6:
			printf("enter pos x\n");
			scanf("%d", &x);
			printf("enter data to be inserted\n");
			scanf("%d",&data);
			insertAfter(start, x, data);
			break;
		case 7:
			printf("enter the node value to be deleted\n");
			scanf("%d", &x);
			start = deleteNode(start, x);
			break;
		case 8:
			continue;
		case 9:
			exit(0);
		case 10:
			printf("enter val\n");
			scanf("%d", &data);
			start = insertInemptylist(start, data);
			break;
		case 11:
			start = reverse_list(start);
			printf("reversed list :\n");
			display_elements(start);
			break;
		default:
			printf("choose right option\n");
			break;
		}
	}
}
