#include<stdio.h>
#include<stdlib.h>
/*void tobinary(int n)
{
	if (n == 0)
		return;
	tobinary(n / 2);
	printf("%d ", n % 2);
}
void convertBase(int n, int base)
{
	int remainder;
	if (n == 0)
		return;
	convertBase(n / base, base);
	remainder = n % base;
	if (remainder < 10)
		printf("%d ", remainder);
	else
		printf("%c", remainder - 10 + 'A');

}*/
float power(float x, int n)
{
	if (n == 0)
		return(1);
	return(x * power(x, n - 1));
}
void main()
{
	int n;
	float x;
	printf("enter x:\n");
	scanf("%f",&x);
	printf("enter n:\n");
	scanf("%d",&n);
	printf("%f^%d = %f\n ",x,n,power(x, n));
	/*printf("binary using tobinary:");
	tobinary(n);
	printf("\n");
	printf("binary :");
	convertBase(n, 2);
	printf("\n");
	printf("hexa decimal:");
	convertBase(n, 16);
	printf("\n");
	printf("octal:");
	convertBase(n, 8);
	printf("\n");*/
	system("pause");
 }