#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int i=0;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr);
    int left=0;
    int right=0;
    for(i=n-1;i>=1;i--){
            right=i-1;
            left=0;
            while(left<right){
                if(arr[left]+arr[right]>arr[i]){
                    right--;
                }
                else if(arr[left]+arr[right]<arr[i]){
                    left++;
                }
                else{
                    printf("%d+%d=%d",arr[left],arr[right],arr[i]);
                    break;
                }
            }

    }
    return 0;

}
