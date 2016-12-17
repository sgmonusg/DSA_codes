#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
	return a<b ? a : b;
}

int recurse(int d[],int n,int N)
{
	if(n < 1 || N < 0)
		return 12000;
	if(N == 0)
		return 0;
	int tmp = min(recurse(d,n-1,N),recurse(d,n,N-d[n-1])+1);
	return tmp;
}

int dp(int d[],int n,int N)
{
	int table[N+1],i,j;
	for(i=1;i<=N;++i)
		table[i] = 12000;
	table[0] = 0;
	
	for(j=0;j<n;++j)
	{
		if(d[j] <= N)
			table[d[j]] = 1;
	}
	
	
	for(i=0;i<=N;++i)
	{
		for(j=0;j<n;++j)
		{
			if(d[j] <= i)
				table[i] = min(table[i],1 + table[i-d[j]]);
		}
	}
	
	return table[N];
}

int main()
{
	int d[] = {1,2,3},n=3,N=4;
	printf("%d",dp(d,n,N));
	return 0;
}
