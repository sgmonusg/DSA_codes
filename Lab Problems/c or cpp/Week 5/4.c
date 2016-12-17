#include<stdio.h>
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int mod_partition(int arr[],int n)
{
	int k,q,i=0,j;
	for(k=0;k<10;++k)
	{
		for(j=i+1;j<n;++j)
		{
			if(arr[j]%10 <= k && i<n)
			{
				swap(&arr[i],&arr[j]);
				++i;
			}
		}
	}
	
	for(q=0;q<n;++q)
		printf("%d ",arr[q]);
	printf("\n");
	return;
}
int main()
{
	int n,arr[100],i;
	scanf("%d",&n);
	for(i=0;i<n;++i)
		scanf(" %d",&arr[i]);
	mod_partition(arr,n);
	return 0;
}
