#include<stdio.h>
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int even_odd_partition(int arr[],int n)
{
	int i=0,j;
	for(j=1;j<n;++j)
	{
		if(arr[j]%2 == 0)
		{
			swap(&arr[i],&arr[j]);
			++i;
		}
	}
	for(j=0;j<n;++j)
		printf("%d ",arr[j]);
	printf("\n");
	return;
}
int main()
{
	int n,arr[100],i;
	scanf("%d",&n);
	for(i=0;i<n;++i)
		scanf(" %d",&arr[i]);
	even_odd_partition(arr,n);
	return 0;-
}
