#include<stdio.h>
#include<stdlib.h>
#define lim 10000000

int freq_count[lim]={0};

void count_sort(int arr[],int n)
{
	int i,output[n];
	for(i=0;i<n;++i)
		freq_count[arr[i]]++;
	for(i=1;i<lim;++i)
		freq_count[i] += freq_count[i-1];
	
	for(i=n-1;i>=0;--i)
	{
		output[freq_count[arr[i]]-1] = arr[i];
		freq_count[arr[i]]--;
	}
	for(i=0;i<n;++i)
		arr[i] = output[i];
}

void bucket_sort(int arr[],int n)
{
	int bucket[][1000]={0},size[1000]={0},i,j,k,tmp;
	
	for(i=0;i<n;++i)
	{
		bucket[size[arr[i]%1000]++][arr[i]%1000] = arr[i];
	}
	for(i=0;i<1000;++i)
	{
		for(j=size[i];j>0;--j)
		for(k=1;k<j;++k)
		{
			if(bucket[k][i] < bucket[k-1][i])
			{
				tmp = bucket[k][i];
				bucket[k-1][i] = bucket[k][i];
				bucket
			}
		}
	}
	
	
}

void count_sort_radix(int arr[],int n,int place)
{
	int count[10]={0},output[n],i;
	for(i=0;i<n;++i)
		count[(arr[i]/place)%10]++;

	for(i=1;i<10;++i)
		count[i] += count[i-1];
	
	for(i=n-1;i>=0;--i)
	{
		output[count[(arr[i]/place)%10]-1] = arr[i];
		count[(arr[i]/place)%10]--;
	}
	for(i=0;i<n;++i)
		arr[i] = output[i];
}

void radix_sort(int arr[],int n)
{
	long long p;
	int i;
	for(i=0,p=1;i<8;++i,p*=10)
		count_sort_radix(arr,n,p);
}

int main()
{
	int i,n=100,arr[n];
	time_t t,start_time,end_time;
	
	srand((unsigned int) time(&t));
	
	for(i=0;i<n;++i)
	{
		arr[i] = rand()%lim;
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	count_sort(arr,n);
	
	for(i=0;i<n;++i)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}
