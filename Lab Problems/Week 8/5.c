#include<stdio.h>
#include<stdlib.h>

#define left(i) 2*i + 1
#define right(i) 2*i + 2
#define parent(i) (i-1)/2

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(int arr[],int n,int c)
{
	if(left(c) < n && arr[c] < arr[left(c)])
		swap(&arr[c],&arr[left(c)]);
	if(right(c) < n && arr[c] < arr[right(c)])
		swap(&arr[c],&arr[right(c)]);
}

void build_heap(int arr[],int n)
{
	int i;
	for(i=parent(n);i>=0;--i)
		heapify(arr,n,i);
}

void heap_sort(int arr[],int n)
{
	build_heap(arr,n);
	int i;
	
	while(n > 1)
	{	
		swap(&arr[0],&arr[n-1]);
		n--;
		heapify(arr,n,0);
	}
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);
	
	build_heap(arr,n);
	for(i=0;i<n;++i)
		printf("%d ",arr[i]);
	printf("\n");
	
	heap_sort(arr,n);
	for(i=0;i<n;++i)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
