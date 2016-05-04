#include<stdio.h>
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
    sort(arr);
    int left=0;
    int right=n-1;
    int temp=0;
    while(left<right){
            if(arr[left]+arr[right]>x){
                right--;
            }
            else if(arr[left]+arr[right]<x){
                left++;
            }
            else{
                printf("yes\n");
                temp=1;
                break;
            }
    }
    if(temp=0){
        printf("no\n");
    }

}
