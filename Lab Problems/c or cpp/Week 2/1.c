#include<math.h>
#include<stdio.h>

#define lim pow(3,8)

void forms_100(int m)
{
	int i,n=m,q,n1;
	long long sum=0,c=0,p=1;
	
	for(q=0,i=9;q<9;++q,--i,n/=3)
	{
		for(c=i*p;n%3==0 && i>0;n/=3)
		{
			--i; p *= 10;
			c += i*p;
		}
		
		if(n%3 == 1 || i==0)
		{
			sum += c;
			c = 0;
			p = 1;
		}
		else if(n%3 == 2)
		{
			sum -= c;
			c = 0;
			p = 1;
		}
	}
	
	for(i=0,n=0,n1=m;i<8;++i)
	{
		n = (n*3) + (n1%3);
		n1 /= 3;
	}
	
	if(sum == 100)
	{
		printf("1");
		for(i=2;i<10;++i,n/=3)
		{
			if(n%3 == 0);
			else if(n%3 == 1)
				printf(" + ");
			else if(n%3 == 2)
				printf(" - ");
			printf("%d",i);
		}
		printf(" = 100 %d\n",m);
	}
	return;
}
int main()
{
	int i;
	for(i=0;i<lim;++i)
		forms_100(i);
	return 0;
}
