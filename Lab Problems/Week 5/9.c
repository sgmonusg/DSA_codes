#include<stdio.h>
int lcs_one(int arr[],int n)
{
	int i,prev0=-1,prev_prev0=-1,max_count=0,max_ind;
	
	for(i=0;i<n;++i)
	{
		if(arr[i] == 0)
		{
			if(max_count < i-prev_prev0)
			{
				max_ind = prev0;
				max_count = i-prev_prev0;
			}
			prev_prev0 = prev0;
			prev0 = i;
		}
	}
	if(max_count < i-prev_prev0 || prev_prev0 == -1 && prev0 >= 0)
	{
		max_ind = prev0;
	}
	return max_ind;
}
int main()
{
	int n,arr[]={1, 1, 1, 1, 0},i;
	
	printf("%d\n",lcs_one(arr,sizeof(arr)/sizeof(arr[0])));
	return 0;
}
