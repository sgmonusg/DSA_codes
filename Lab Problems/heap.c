#include<stdio.h>
#include<stdlib.h>

#define left(i) i*2 + 1
#define right(i) i*2 + 2
#define parent(i) (i-1)/2

void heapify_up(int arr[],int c)
{
	if(c > 0)
	{
		if(arr[parent(c)] < arr[c])
		{
			int tmp;
			tmp = arr[parent(c)];
			arr[parent(c)] = arr[c];
			arr[c] = tmp;
		}
		heapify_up(arr,parent(c));
	}
}

void heapify_down(int arr[],int c)
{
	int largest=0,tmp;
	if(left(c) < n && arr[left(c)] < arr[right(c)])
		largest = right(c);
	else largest = left(c);
	
	if(arr[largest] > arr[c])
	{
		tmp = arr[largest];
		arr[largest] = arr[c];
		arr[c] = tmp;
		
		heapify_down(arr,largest);
	}
}

void heap_insert(int arr[],int n,int num)
{
	arr[n] = num;
	heapify_up(arr,n);
}

int remove_top(int arr[],int n)
{
	int top = arr[0];
	arr[0] = arr[n];
	heapify_down(arr,0);
}

void max_heapify(int heap[],int i)
{
	int largest=0,tmp;
	if(left(i) <= n && arr[left(i)] > arr[right(i)])
		largest = left(i);
	else largest = i;
	
	if(right(i) < n && arr[right(i)] > arr[i])
		largest = right(i);
		
	if(largest != i)
	{
		tmp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = tmp;
		
		max_heapify(arr,largest);
	}
}

void build_maxheap(int arr[],int n,int heap[])
{
	for(i=n/2;i>=0;--i)
		max_heapify(heap,i);
}

int main()
{
	return 0;
}
