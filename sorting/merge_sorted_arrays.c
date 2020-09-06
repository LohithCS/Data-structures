#include<stdio.h>
#define MAX 50
void merge(int a1[], int a2[], int a[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if(a1[i] < a2[j])
            a[k++] = a1[i++];
        else
            a[k++] = a2[j++];
    }
    while (i < n1)
        a[k++] = a1[i++];
    while (j < n2)
        a[k++] = a2[j++];
}
void main()
{
    int i, j, k, n1, n2, n, a1[MAX], a2[MAX], a[MAX];
    printf("enter the size of first array\n");
    scanf("%d", &n1);
    printf("enter the first sorted array: a1\n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &a1[i]);
    }
    for (i = 0; i < n1; i++)
    {
        printf("%d ", a1[i]);
    }
        printf("\nenter the size of second array\n");
        scanf("%d", &n2);
        printf("enter the second sorted array: a2   \n");
        for (i = 0; i < n2; i++)
        {
            scanf("%d", &a2[i]);
        }
        for (i = 0; i < n2; i++)
        {
            printf("%d ", a2[i]);
        }
        merge(a1, a2, a, n1, n2);
        printf("the merged array is a:\n");
        for (i = 0; i < (n1 + n2); i++)
            printf("%d ", a[i]);
        printf("\n");
        system("pause");
}