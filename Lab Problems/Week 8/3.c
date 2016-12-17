#include<stdio.h>
#include<stdlib.h>

#define parent(i) (i-1)/2
#define left(i) 2*i + 1
#define right(i) 2*i + 2

typedef struct {
	int num;
	int index;
} pair;

void swap(pair *a,pair *b)
{
	pair tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(pair arr[], int n, int c)
{
	if(left(c) < n && arr[c].num < arr[left(c)].num)
		swap(&arr[c],&arr[left(c)]);
	if(right(c) < n && arr[c].num < arr[right(c)].num)
		swap(&arr[c],&arr[right(c)]);
}

void build_heap(pair arr[],int n)
{
	int i;
	for(i=parent(n);i>=0;--i)
		heapify(arr,n,i);
}

int main()
{
	pair max_heap[1000],aux[1000];
	int n,i,k,q=0,g;
	scanf("%d %d",&n,&k);
	
	for(i=0;i<n;++i)
	{
		scanf("%d",&max_heap[i].num);
	}
	
	build_heap(max_heap,n);
	for(i=0;i<n;++i)
	{
		printf("%d ",max_heap[i].num);
		max_heap[i].index = i;
	}
	printf("\n");
	
	aux[0] = max_heap[0]; k--;
	printf("%d %d\n",aux[0].index,aux[0].num);
	
	for(i=0; i < k ;++i)
	{
		aux[q++] = max_heap[left(aux[0].index)];
		aux[0] = max_heap[right(aux[0].index)];
		heapify(aux,q,0);
		
		for(g=0;g<n;++g)
			printf("%d ",aux[g]);
		printf("\n");
	}
	printf("%d\n",aux[0]);
	
	return 0;
}
