#include <stdio.h>
#include <limits.h>
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int n;
	printf("Enter no of coins then final amt then each coin denomination in this order\n");
	scanf("%d",&n);
	int N;scanf("%d",&N);
	int dp[N+1];
	int i;
	for(i=0;i<=N;i++)
		dp[i]=INT_MAX;
	int coins[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&coins[i]);
		//dp[coins[i]]=1;
	}
	dp[0]=0;
	for(i=1;i<=N;i++)
	{
		int ans=INT_MAX;
        int j;
		for(j=0;j<n;j++)
		{
			if (i-coins[j]>=0)
			{
				if(dp[i-coins[j]]!=INT_MAX)
				ans=min(ans,min(dp[i],dp[i-coins[j]]+1));
			}
		}
		dp[i]=ans;
	}

	printf("%d\n",dp[N]);
}
