#include<stdio.h>
int cmp(const void *a, const void *b)
{
	int *p = (int *) a;
	int *q = (int *) b;
	return (*p < *q);
}
void occurences(int arr[],int n)
{
	int count=1,i;
	qsort(arr,n,sizeof(int),cmp);
	for(i=1;i<n;++i)
	{
		if(arr[i] == arr[i-1])
			count++;
		else
		{
			printf("%d %d; ",arr[i-1],count);
			count = 1;
		}
	}
	if(count > 1)
		printf("%d %d; ",arr[i-1],count);
	return;
}
int main()
{
	int arr[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);
	occurences(arr,n);
	return 0;
}
