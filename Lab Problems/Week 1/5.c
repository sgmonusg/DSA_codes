#include<stdio.h>
const long long mod = 10000000000;

long long exp_two(int n)
{
	if(n == 0)
		return 1;
	long long e = (long long)(exp_two(n-1)*2)%mod;
	return e;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld\n",exp_two(n));
	return 0;
}
