#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void ones(int n)
{
	if(n == 1)
		printf("one");
	else if(n == 2)
		printf("two");
	else if(n == 3)
		printf("three");
	else if(n == 4)
		printf("four");
	else if(n == 5)
		printf("five");
	else if(n == 6)
		printf("six");
	else if(n == 7)
		printf("seven");
	else if(n == 8)
		printf("eight");
	else if(n == 9)
		printf("nine");
	else if(n == 10)
		printf("ten");
	else if(n == 11)
		printf("eleven");
	else if(n == 12)
		printf("twelve");
	else if(n == 13)
		printf("thirteen");
	else if(n == 14)
		printf("fourteen");
	else if(n == 15)
		printf("fifteen");
	else if(n == 16)
		printf("sixteen");
	else if(n == 17)
		printf("seventeen");
	else if(n == 18)
		printf("eighteen");
	else if(n == 19)
		printf("nineteen");
}

void twos(int n)
{
	if(n == 20 || n == 2)
		printf("twenty");
	else if(n == 30 || n == 3)
		printf("thirty");
	else if(n == 40 || n == 4)
		printf("fourty");
	else if(n == 50 || n == 5)
		printf("fifty");
	else if(n == 60 || n == 6)
		printf("sixty");
	else if(n == 70 || n == 7)
		printf("seventy");
	else if(n == 80 || n == 8)
		printf("eighty");
	else if(n == 90 || n == 9)
		printf("ninty");
}

int main()
{
	int n;
	scanf("%d",&n);
	if(n == 0)
	{
		printf("zero");
	}
	int a = n/1000;
	ones(a);
	if(a != 0)
		printf(" thousand ");
	int b = (n/100)%10;
	ones(b);
	if(b != 0)
		printf(" hundred ");
	if (a != 0 || b != 0)
		printf("and ");
	int c = n%100;
	if(c/10 != 0)
		ones(c);
	if(c/10 !=1)
		{
			twos(c/10);
			printf(" ");
			ones(c%10);
		}
	printf("\n");
	return 0;	
}
