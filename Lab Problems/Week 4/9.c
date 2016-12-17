#include<stdio.h>
void merge_sort(int arr[],int n)
{
	if(n <= 1)
		return;
	int mid=n/2,i,j,k;
	int tmp1[mid],tmp2[n-mid];
	
	for(i=0;i<mid;++i)
		tmp1[i] = arr[i];
	for(i=mid;i<n;++i)
		tmp2[i-mid] = arr[i];
	
	merge_sort(tmp1,mid);
	merge_sort(tmp2,n-mid);
	
	for(i=0,j=0,k=0;i<mid && j<n-mid;)
	{
		if(tmp1[i] < tmp2[j])
			arr[k++] = tmp1[i++];
		else
			arr[k++] = tmp2[j++];
	}
	while(k < n)
	{
		if(i == mid)
			arr[k++] = tmp2[j++];
		else
			arr[k++] = tmp1[i++];
	}
	
	return;
}
int main()
{
	int n,arr[1000],i,j,k,count=0;
	scanf("%d",&n);
	for(i=0;i<n;++i)
		scanf(" %d",&arr[i]);
	merge_sort(arr,n);
	
	for(k=n-1;k>=0;++k)
	{
		for(i=0,j=k-1;i<j;)
		{
			if(arr[i]+arr[j] == arr[k])
			{
				count++;
				j--;
			}
			else if(arr[i]+arr[j] > arr[k])
				j--;
			else
				i++;
		}
	}
	return 0;
}
