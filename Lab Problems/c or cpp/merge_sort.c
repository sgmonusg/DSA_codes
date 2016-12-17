#include<stdio.h>
#include<stdlib.h>

void merge_sort(int arr[],int n)
{
	if(n <= 1)
		return;
	
	int arr1[n/2],arr2[n-n/2],i,j=0,k=0;
	for(i=0;i<n/2;++i)
		arr1[i] = arr[i];
	for(;i<n;++i)
		arr2[i-n/2] = arr[i];
	
	merge_sort(arr1,n/2);
	merge_sort(arr2,n-n/2);
	
	for(i=0,j=0,k=0;i<n/2 && j<n-n/2;)
	{
		if(arr1[i] < arr2[j])
			arr[k++] = arr1[i++];
		else
			arr[k++] = arr2[j++];
	}
	if(i == n/2)
		while(j < n-n/2)
			arr[k++] = arr2[j++];
	else
		while(i < n/2)
			arr[k++] = arr1[i++];
	
	return;
}

void print_arr(int arr[],int n)
{
	int i;
	for(i=0;i<n;++i)
		printf("%d ",arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {5,2,1,6,8,3,4,9},n=8;
	print_arr(arr,n);
	merge_sort(arr,n);
	print_arr(arr,n);
	return 0;
}
