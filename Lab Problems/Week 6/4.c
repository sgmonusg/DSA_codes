#include<stdio.h>

int freq[1001]={0};

void merge_sort(int arr[],int n)
{
	if(n <= 1)
		return;
	
	int mid=n/2,tmp1[mid],tmp2[n-mid],i,j,k;
	for(i=0;i<mid;++i)
		tmp1[i] = arr[i];
	for(;i<n;++i)
		tmp2[i-mid] = arr[i];
	
	merge_sort(tmp1,mid);
	merge_sort(tmp2,n-mid);
	
	int count=0;
	for(i=0,j=0,k=0;i<mid && j<n-mid;)
	{
		if(tmp1[i] < tmp2[j])
		{
			freq[tmp1[i]] += count;
			arr[k++] = tmp1[i++];
		}
		else
		{
			arr[k++] = tmp2[j++];
			count++;
		}
	}
	
	if(i == mid)
		while(j < n-mid)
			arr[k++] = tmp2[j++];
	else
		while(i < mid)
		{
			freq[tmp1[i]] += count;
			arr[k++] = tmp1[i++];
		}
}

int main()
{
	int n,cpy[1000],arr[1000],i;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
		cpy[i] = arr[i];
	}
	
	merge_sort(arr,n);
	
	for(i=0;i<n;++i)
		printf("%d ",freq[cpy[i]]);
	printf("\n");
	
	return 0;
}

