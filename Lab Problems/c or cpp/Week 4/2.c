/* A typical recursive implementation of quick sort */
#include<stdio.h>

void swap(int *a ,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[],int s,int e)
{
	int piv = arr[e];
	int i=s-1,j;
	
	for(j=s;j<=e-1;++j)
	{
		if(arr[j] <= piv)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[e]);
	
	return i+1;
}

void quick_sort(int arr[],int s,int e)
{
	if(s < e)
	{
		int p = partition(arr,s,e);
		quick_sort(arr,s,p-1);
		quick_sort(arr,p+1,e);
	}
}

int main()
{
	int arr[10]={5,2,3,8,1,9,7,6,4,10},i;
	
	for(i=0;i<10;++i)
		printf("%d ",arr[i]);
	printf("\n");
	
	quick_sort(arr,0,9);
	
	for(i=0;i<10;++i)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
