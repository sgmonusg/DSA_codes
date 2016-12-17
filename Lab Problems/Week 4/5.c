#include<stdio.h>
int find_pivot(int arr[],int s,int e)
{
	if(s > e)
		return 0;
	if(s == e)
		return s;
	int mid=(s+e)/2;
	if(arr[mid] < arr[mid-1])
		return mid;
	if(arr[mid] > arr[mid+1])
		return mid+1;
	if(arr[e] > arr[mid])
		return find_pivot(arr,s,mid-1);
	return find_pivot(arr,mid+1,e);
}

int binary_search(int arr[],int s,int e,int key)
{
	if(s == e)
		return (arr[s] == key) ? s : -1;
	int mid = (s+e)/2;
	if(arr[mid] == key)
		return mid;
	if(arr[mid] > key)
		return binary_search(arr,s,mid,key);
	return binary_search(arr,mid+1,e,key);
}

int pivoted_binary_search(int arr[],int n,int key)
{
	int pivot_key = find_pivot(arr,0,n);
	int b1 = binary_search(arr,0,pivot_key,key),b2 = binary_search(arr,pivot_key+1,n-1,key);
	
	return b1 >= 0 ? b1 : b2;
}

int main()
{
	int n,arr[100],i,k,max_count=1,count=1;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;++i)
		scanf(" %d",&arr[i]);
	
	printf("%d\n",pivoted_binary_search(arr,n,k));
	
	return 0;
}
