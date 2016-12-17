#include<stdio.h>

#define left(i) i*2 + 1
#define right(i) i*2 + 2
#define parent(i) (i-1)/2

void heapify(int arr[],int n,int c)
{
	int tmp;
	while(c != 0)
	{
		if(arr[parent(c)] < arr[c])
		{
			tmp = arr[parent(c)];
			arr[parent(c)] = arr[c];
			arr[c] = tmp;
		}
		c = parent(c);
	}
}

void build_heap(int arr[],int n)
{
	int i;
	for(i=1;i<n;++i)
		heapify(arr,n,i);
}

void remove_top(int arr[],int *n)
{
	arr[0] = arr[(*n)--];
	build_heap(arr,(*n));
}

int find_max(int arr[],int n)
{
	return arr[0];
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	
	int arr[n];
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);
	
	build_heap(arr,n);
	for(i=0;i<n;++i)
		printf("%d ",arr[i]);
	printf("\n");
	
	remove_top(arr,&n);
	for(i=0;i<n;++i)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}
