#include<stdio.h>
   int binary_search(int arr[],int x,int length,int high,int low){
       int mid=(high+low)/2;
       int flag=0;
       if(arr[high]==x){
        return 1;
       }
       else{
       while(high!=low){
       if((arr[mid]>x&&arr[length-1]>x)){

            low=mid;
            return binary_search(arr,x,length,high,low);
       }
       else if(arr[mid]<x&&arr[length-1]<x){
            high=mid;
            return binary_search(arr,x,length,high,low);
        }
        else if(arr[mid]<x&&arr[length-1]>x){
            low=mid;
            return binary_search(arr,x,length,high,low);
       }
       else if(arr[mid]>x&&arr[length-1]<x){
            high=mid;
            return binary_search(arr,x,length,high,low);
       }
       else if(arr[mid]==x){
            flag=1;
            return flag;


       }

       }
       }
       return flag;
   }
int main(){
    int n;
    scanf("%d",&n);
    int x;
    scanf("%d",&x);
    int arr[n];
    int i=0;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int flag=binary_search(arr,x,n,n-1,0);
    if(flag==1){
        printf("yes");
    }
    else{
        printf("no");
    }

    return 0;
}
