#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* link;
};
struct node *insertInorder(struct node *start, int data)
{
	struct node* p, * temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;

	//list empty and new node to be inserted
	if (start == NULL || data < start->info)
	{
		temp->link = start;
		start = temp;
		return(start);
	}
	//find the node after which a new node to be added
	p = start;
	while (p->link != NULL && p->link->info <= data)
		p = p->link;
	temp->link = p->link;
	p->link = temp;
	return(start);
}
void displayElements(struct node *start)
{
	if (start == NULL) {
		printf("empty list\n");
		return(0);
	}
	struct node* p;
	p = start;
	while (p != NULL)
	{
		printf("%d ", p->info);
		p = p->link;
	}
	printf("\n");
}
void searchElement(struct node* start, int x)
{
	struct node* p;
	int n = 0;
	p = start;
	if (start == NULL) {

		printf("empty list\n");
		return;
	}
	while (p != NULL && p->info <= x)
	{
		if (p->info == x)
			break;
		n++;
		p = p->link;
	}
	if (p == NULL || p->info != x)
		printf("%d is not present in the list\n", x);
	else
		printf("element is at pos: %d\n", n);
}
struct node* createSortedList(struct node* start)
{
	int n, data;
	printf("enter the no of nodes\n");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("enter the ele to be inserted\n");
		scanf("%d", &data);
		start = insertInorder(start, data);
	}
	return(start);
}
//MERGING BY CREATING NEW LL

/*struct node* merge(struct node* p1, struct node* p2)
{
	struct node* temp, * pM, * startM;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->link = NULL;
	startM = temp;

	if (p1->info <= p2->info)
	{
		temp->info = p1->info;
		p1 = p1->link;
	}
	else
	{
		temp->info = p2->info;
		p2= p2->link;
	}
	pM = startM;
	while (p1 != NULL && p2 != NULL)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		if (p1->info <= p2->info)
		{
			temp->info = p1->info;
			p1 = p1->link;
		}
		else
		{
			temp->info = p2->info;
			p2 = p2->link;
		}
		temp->link = NULL;
		pM->link = temp;
		pM = temp;
	}

	while (p1!= NULL)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = p1->info;
		temp->link = NULL;
		pM->link = temp;
		pM = temp;
		
		p1 = p1->link;

	}
	while (p2 != NULL)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = p2->info;
		temp->link = NULL;
		pM->link = temp;
		pM = temp;

		p2 = p2->link;
	}
	return(startM);
}*/

//MERGING SORTED LL BY REARRANGING
struct node* merge(struct node* p1, struct node* p2)
{
	struct node* pM, * startM;

	if (p1->info <= p2->info)
	{
		startM = p1;
		p1 = p1->link;
	}
	else
	{
		startM = p2;
		p2 = p2->link;
	}
	pM = startM;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1 -> info <= p2->info)
		{
			pM->link = p1;
			pM = pM->link;
			p1 = p1->link;
		}
		else
		{

			pM->link = p2;
			pM = pM->link;
			p2 = p2->link;
		}
	}
	if (p1 == NULL)
		pM->link = p2;
	else
		pM->link = p1;
	return(startM);
}
void main()
{
	struct node* start1= NULL,*start2=NULL,*startM;

	start1 = createSortedList(start1);
	printf("first list :");
	displayElements(start1);

	start2= createSortedList(start2);
	printf("Second list :");
	displayElements(start2);

	startM = merge(start1, start2);
	printf("merged list :");
	displayElements(startM);

	system("pause");

	

}