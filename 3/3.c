#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int countDigits(int n);
int inc10(int temp);
void algo(int n,int times);


int countDigits(int n)
{
	int count = 0;
	while(n>0)
	{
		count++;
		n /= 10;
	}
	return count;
}

int inc10(int temp)
{
	int r = 1;
	while(temp--)
	{
		r *= 10;
	}
	return r;
}

void algo(int n,int times)
{	while(times--)
	{
		int digits,c;
		int sqCount;
		digits = countDigits(n);
		sqCount = countDigits((n*n));
		int temp;
		c = sqCount - digits;
		if(c%2 == 0)
			temp = c/2;
		else
			temp = (c/2)+1;
	
		temp = inc10(temp);
		digits = inc10(digits);
		
		n = ((n*n)/temp)%digits;
		printf("%d\n",n);
	}
}

int main()
{
	int n,times;
	scanf("%d%d",&n,&times);
	algo(n,times);
	return 0;
}
