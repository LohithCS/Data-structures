#include<stdio.h>
#include<stdlib.h>
#define TSIZE 19
enum type_of_record { EMPTY, OCCUPIED, DELETED };
struct student
{
	int studentId;
	char studentName[20];
};
struct Record
{
	struct student info;
	enum type_of_record status;
};
void insert(struct student rec, struct Record table[]);
int search(int key, struct Record table[]);
void delete(int key, struct Record table[]);
void display(struct Record table[]);
int hash(int key);
int hash(int key)
{
	return(key % TSIZE);
}
void insert(struct student rec, struct Record table[])
{
	int key, h, location,i;
	key = rec.studentId;
	h = hash(key);
	location = h;
	for (i = 1; i < TSIZE; i++)
	{
		if (table[location].status == EMPTY || table[location].status == DELETED)
		{
			table[location].info = rec;
			table[location].status = OCCUPIED;
			printf("record inserted\n");
			return;
		}
		if (table[location].info.studentId == key)
		{
			printf("duplicate key\n");
			return;
		}
		location = (h + i) % TSIZE;
	}
	printf("record cant be inserted, table overflow\n");
}
int search(int key, struct Record table[])
{
	int h, location, i;
	h = hash(key);

	location = h;
	for (i = 1; i < TSIZE; i++)
	{
		if (table[location].status == EMPTY)
			return(-1);
		if (table[location].info.studentId == key)
			return(location);
		location = (h + i) % TSIZE;
	}
	return(-1);
}
void display(struct Record table[])
{
	int i;
	for (i = 0; i < TSIZE; i++)
	{
		printf("[%d]  :", i);
		if (table[i].status == OCCUPIED)
			printf("occupied: %d  %s\n", table[i].info.studentId, table[i].info.studentName);
		else if (table[i].status == DELETED)
			printf("deleted\n");
		else
			printf("empty\n");
	}
}
void delete(int key, struct Record table[])
{
	int location = search(key, table);
	if (location == -1)
		printf("key not found\n");
	else
		table[location].status = DELETED;
}
void main()
{
	struct Record table[TSIZE];
	struct student rec;
	int i, key, choice;

	for (i = 0; i <= TSIZE - 1; i++)
		table[i].status = EMPTY;

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
				printf("%d %s\n", table[i].info.studentId, table[i].info.studentName);
			}
			break;
		case 3:
			printf("enter the key to be deleted\n");
			scanf("%d",&key);
			delete(key, table);
			break;
		case 4:
			display(table);
			break;
		}
	}
	system("pause");

}