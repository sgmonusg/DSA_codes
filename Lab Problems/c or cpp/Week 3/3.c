#include<math.h>
#include<stdio.h>
int mid_square(int s)
{
	long long sq = (long long)s*(long long)s;
	printf("%lld ",sq);
	
	int len=ceil(log10(sq)),n=ceil(log10(s)),i;
	sq /= pow(10,ceil((len-n)/2.0));
	sq %= (long long)pow(10,n);
	
	return sq;
}
int main()
{
	int seed,n,num;
	scanf("%d %d",&seed,&n);
	while(n--)
	{
		num = mid_square(seed);
		printf("%d\n",num);
		seed = num;
	}
	return 0;
}
