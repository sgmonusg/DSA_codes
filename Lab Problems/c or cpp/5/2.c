#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int i=0;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int j=0;
    int k=n-1;
    int arr1[n];
    for(i=0;i<n;i++){
        if(arr[i]%2==0){
            arr1[j]=arr[i];
            j++;
        }
        else{
            arr1[k]=arr[i];
            k--;
        }
    }
    for(i=0;i<n;i++){
        printf("%d , ",arr1[i]);
    }
    return 0;
}
