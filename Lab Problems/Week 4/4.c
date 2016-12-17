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
	
	merge_sort(arr,mid);
	merge_sort(arr+mid,n-mid);
	
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
	int n,arr[100],i,max_count=1,count=1;
	scanf("%d",&n);
	for(i=0;i<n;++i)
		scanf(" %d",&arr[i]);
	merge_sort(arr,n);
	
	for(i=1;i<n;++i)
	{
		if(arr[i] == arr[i-1])
			count++;
		else
			count = 1;
		if(max_count < count)
			max_count = count;
	}
	printf("%d\n",max_count);
	return 0;
}
