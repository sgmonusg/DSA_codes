#include<stdio.h>

int lower_bound(int arr[],int n,int l,int h,int key)
{
	if(l <= h)
	{
		int mid = (l+h)/2;
		if((mid == 0 || arr[mid-1] < key) && arr[mid] == key)
			return mid;
		if(arr[mid] > key)
			return lower_bound(arr,n,l,mid-1,key);
		return lower_bound(arr,n,mid+1,h,key);
	}
	return -1;
}

int qsort_cmp(const void *a,const void *b)
{
	int *p = (int *)a;
	int *q = (int *)b;
	return (*p  > *q);
}

void sort_according(int arr1[],int n1,int arr2[],int n2)
{
	int tmp[n1],visited[n1],i,j;
	for(i=0;i<n1;++i)
	{
		tmp[i] = arr1[i];
		visited[i] = 0;
	}
	
	qsort(tmp,tmp+n1);
	
	int ind=0;
	
	// Consider all elements of A2[], find them in temp[] and copy to A1[] in order.
    for (i=0; i<n2; i++)
    {
        // Find index of the first occurrence of A2[i] in temp
        int f = lower_bound(tmp, n1, 0, n1-1, arr2[i]);
 
        // If not present, no need to proceed
        if (f == -1)
			continue;
 
        // Copy all occurrences of A2[i] to A1[]
        for (j = f;(j<n1 && tmp[j] == arr2[i]); j++)
        {
            arr1[ind++] = tmp[j];
            visited[j] = 1;
        }
    }

    // Now copy all items of temp[] which are not present in A2[]
    for (i=0; i<n1; i++)
        if (visited[i] == 0)
            arr1[ind++] = tmp[i];
    
	return;
}

int main()
{
	int A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int A2[] = {2, 1, 8, 3};
    int m = sizeof(A1)/sizeof(A1[0]);
    int n = sizeof(A2)/sizeof(A2[0]),i;
    
    sort_according(A1,m,A2,n);
    
    for(i=0;i<m;++i)
    	printf("%d ",A1[i]);
    printf("\n");
	return 0;
}
