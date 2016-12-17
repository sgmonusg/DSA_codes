#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int i,n,x,count=0;
	scanf("%d %d",&n,&x);
	int arr[n];
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);
	for(i=1;i<n;++i)
	{
		if(ceil((arr[i]-arr[i-1])/x) > 0)
		{
			arr[i] = ceil((arr[i]-arr[i-1])/x);
			count++;
		}
	}
	
	
	return 0;
}
