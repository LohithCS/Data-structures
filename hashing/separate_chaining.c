#include<stdio.h>
#include<stdlib.h>
#define TSIZE 7
struct student
{
	int studentId;
	char studentName[20];
};
struct Node
{
	struct student info;
	struct Node* link;
};
void insert(struct student rec, struct Node *table[]);
int search(int key, struct Node* table[]);
void delete(int key, struct Node* table[]);
void display(struct Node* table[]);
int hash(int key);
int hash(int key)
{
	return(key % TSIZE);
}
void insert(struct student rec, struct Node *table[])
{
	struct Node* temp;
	int key, h;
	key = rec.studentId;
	if (search(key, table) != -1)
	{
		printf("duplicate key\n");
		return;
	}

	h = hash(key);
	// insert in beginning of linked list
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->info = rec;
	temp->link = table[h];
	table[h] = temp;
}
int search(int key, struct Node *table[])
{
	int h = hash(key);
	struct Node* p = table[h];
	while (p != NULL)
	{
		if (p->info.studentId == key)
		{
			printf("%d %s\n", p->info.studentId, p->info.studentName);
			return(h);
		}
		p = p->link;
	}
	return(-1);
}
void display(struct Node *table[])
{
	int i;
	struct Node* p;
	for (i = 0; i < TSIZE; i++)
	{
		printf("\n[%d]  :", i);
		if (table[i] != NULL)
		{
			p = table[i];
			while (p != NULL)
			{
				printf("%d %s\t", p->info.studentId, p->info.studentName);
				p = p->link;
			}
		}
	}
	printf("\n");
}
void delete(int key, struct Node* table[])
{
	struct Node* temp, * p;
	int h;
	h = hash(key);

	if (table[h] == NULL)
	{
		printf("key %d is not found\n", key);
		return;
	}
	if (table[h]->info.studentId == key)
	{
		temp = table[h];
		table[h] = table[h]->link;
		free(temp);
		return;
	}
	p = table[h];
	while (p->link != NULL)
	{
		if (p->link->info.studentId == key)
		{
			temp = p->link;
			p->link = temp->link;
			free(temp);
			return;
		}
		p = p->link;
	}
	printf("key %d is not found\n", key);
}
void main()
{
	struct Node *table[TSIZE];
	struct student rec;
	int i, key, choice;

	for (i = 0; i <= TSIZE - 1; i++)
		table[i] = NULL;

	while (1)
	{
		printf("1: insert a record\n");
		printf("2: search a record\n");
		printf("3: delete a record\n");
		printf("4: display\n");
		printf("5: quit\n");
		scanf("%d", &choice);
		if (choice == 5)
			break;
		switch (choice)
		{
		case 1:
			printf("enter student id:\n");
			scanf("%d", &rec.studentId);
			printf("enter student name:\n");
			scanf("%s", rec.studentName);
			insert(rec, table);
			break;
		case 2:
			printf("enter the key to be searched\n");
			scanf("%d", &key);
			i = search(key, table);
			if (i == -1)
				printf("key not found\n");
			else
			{                                                                                                             
				printf("key found at index %d\n", i);
				printf("%d %s\n", table[i]->info.studentId, table[i]->info.studentName);
			}
			break;
		case 3:
			printf("enter the key to be deleted\n");
			scanf("%d", &key);
			delete(key, table);
			break;
		case 4:
			display(table);
			break;
		}
	}
	system("pause");
}