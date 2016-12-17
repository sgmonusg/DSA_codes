#include<stdio.h>
int main()
{
	int n,i,arr[1000]={0},i1=-1,i2=-1;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf(" %d",&arr[i]);
		if(i && arr[i] < arr[i-1])
		{
			if(i1 >= 0)
				i2 = i;
			else
			{
				i1 = i-1;
				i2 = i;
			}
		}
	}
	printf("%d,%d\t%d,%d\n",i1,arr[i1],i2,arr[i2]);
	
	return 0;
}
