#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define lim 400

typedef struct {
	int dig[lim];
	int size;
}bignum;

void initialize_bignum(bignum *num,long long n)
{
	int i;
	num->size=1;
	
	for(i=0;i<lim;++i)
	{
		num->dig[i] = n%10;
		n /= 10;
		if(n > 0)
			num->size++;
	}
}

void print_bignum(bignum num)
{
	int i,s=num.size;
	for(i=s-1;i>=0;--i)
		printf("%d",num.dig[i]);
	printf("\n");
}

void multiply(bignum *num,int mult)
{
	int s=num->size,i,c=0;
	
	for(i=0;i<lim;++i)
	{
		num->dig[i] = num->dig[i]*mult + c;
		
		c = num->dig[i]/10;
		num->dig[i] %= 10;
		
		if(num->dig[i] > 0)
		{
			num->size = i+1;
		}
	}
}
int main()
{
	int n,i,j,size=0;
	bignum num;
	initialize_bignum(&num,1);
	
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		multiply(&num,i);
	}
	print_bignum(num);
	return 0;
}
