#include<stdio.h>

int binary_search(int arr[],int n,int s,int e, int key)
{
	if(s == e)
		return (arr[s] == key)?1 :0;
	
	int mid = (s+e)/2.0,count;
	count = binary_search(arr,n,s,mid,key) + binary_search(arr,n,mid+1,e,key);
	return count;
}

int main()
{
	int n,i,key;
	scanf("%d %d",&n,&key);
	int arr[100]={0};
	for(i=0;i<n;++i)
		scanf(" %d",&arr[i]);
	printf("\n%d\n",binary_search(arr,n,0,n,key));
	return 0;
}
