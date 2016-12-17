#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int min(int a,int b)
{
	return a<b ? a : b;
}
int max(int a,int b)
{
	return a>b ? a : b;
}

unsigned int recurse(int d[],int n,int N)
{
	if(N < 0 || n <= 0)
		return INT_MAX;
	if(N == 0)
		return 0;
	return min(1 + recurse(d,n,N-d[n-1]), recurse(d,n-1,N));
}

int memoify(int d[],int n,int N)
{
	int table[N+1],i,j;
	for(i=0;i<=N;++i)
		table[i] = INT_MAX;
	
	for(i=0;i<=N;++i)
	{
		for(j=0;j<n;++j)
			table[j][i] = min(1+table[j][(i-d[i])],table[j-1][i]);
	}
	
	printf("%d ",table[N]);
	return table[N];
}

int main()
{
	int n,i,j,N;
	scanf("%d",&n);
	int d[n];
	for(i=0;i<n;++i)
		scanf("%d",&d[i]);
	scanf("%d",&N);
	
	printf("%u\n",recurse(d,n,N));
	//memoify(d,n,N);
	return 0;
}
