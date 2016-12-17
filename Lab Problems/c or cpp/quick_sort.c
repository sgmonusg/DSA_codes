#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int arr[],int s,int e)
{
	int p = arr[s],i=s-1,j;
	
	for(j=s;j<=e;++j)
	{
		if(arr[j] <= p)
		{
			i++;
			swap(&arr[j],&arr[i]);
		}
	}
	swap(&arr[i],&arr[s]);
	return i;
}

void quick_sort(int arr[],int s,int e)
{
	if(s <= e)
	{
		int p = partition(arr,s,e);
		quick_sort(arr,s,p-1);
		quick_sort(arr,p+1,e);
	}
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
	int arr[] = {5,7,2,1,3,8,9,4},n=8;
	print_arr(arr,n);
	quick_sort(arr,0,n-1);
	print_arr(arr,n);
	return 0;
}
