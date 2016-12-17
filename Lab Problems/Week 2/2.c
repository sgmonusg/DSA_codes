#include<stdio.h>
int luhn_test(long long num)
{
	int chk=num%10,i=1,sum=0,tmp;
	num /= 10;
	
	for(;(num);++i)
	{
		if(i%2)
		{
			tmp = (num%10)*2;
			tmp = (tmp%10) + (tmp/10)%10;
		}
		else
			tmp = num%10;
		sum += tmp;
		num /= 10;
	}
	if((sum+chk)%10)
		return 0;
	return 1;
}

int main()
{
	long long n = 30130708434187;
	printf("%d\n",luhn_test(n));
	return 0;
}
