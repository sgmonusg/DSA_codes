#include<stdio.h>
void merge(int arr[],int n,int left,int mid,int right){
    int i=left;
    int j=mid;
    int k=0;
    int b[n];
    while(i<=mid&&j<=right){
        if(arr[i]<arr[j]){
            b[k++]=arr[i++];
        }
        else{
            b[k++]=arr[j++];
        while(i<=mid)
            b[k++]=arr[i++];
        while(j<=right){
            b[k++]=arr[j++];
        }
    }
        k=0;
        for(i=left;i<right;i++){
            arr[i]=b[k++];
        }
    }

}

void merge_sort(int arr[],int n,int left ,int right){
    while(left<right){
        int mid=(left+right)/2;
        merge_sort(arr ,n,left,mid);
        merge_sort(arr,n,mid+1,right);
        merge(arr,n,left,mid+1,right);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr1[n];
    int i=0;
    for(i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    int arr3[n];
    for(i=0;i<n;i++){
        arr3[i]=0;
    }
    int m;
    scanf("%d",&m);
    int arr2[m];
    for(i=0;i<m;i++){
        scanf("%d",&arr2[i]);
    }
   // merge_sort(arr1,n,0,n-1);
    //sort arr1;
    int k=0;
    //int i=0;
    int j=0;
    if(n>m){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(arr1[j]==arr2[i]){
                    arr3[k]=arr1[j];
                    arr1[j]=-1;
                    k++;
                }
            }
        }
        for(i=0;i<n;i++){
            if(arr1[i]!=-1){
                arr3[k]=arr1[i];
                k++;
            }
        }
    }
    else{
       for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(arr1[j]==arr2[i]){
                    arr3[k]=arr1[j];
                    k++;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",arr3[i]);
    }

}
