#include<stdio.h>
int cmp(const void *p, const void *q)
{
	int *a = (int *)p;
	int *b = (int *)q;
	return (*a > *b);
}
int main()
{
	int n,X,i,j;
	scanf("%d %d",&n,&X);
	int arr[n];
	for(i=0;i<n;++i)
		scanf(" %d",&arr[i]);
	qsort(arr,n,sizeof(int),cmp);
	
	for(i=0,j=n-1;i<j;)
	{
		if(arr[i]+arr[j] == X)
			break;
		else if(arr[i]+arr[j] > X)
			j--;
		else
			i++;
	}
	if(i<j && arr[i]+arr[j] == X)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
