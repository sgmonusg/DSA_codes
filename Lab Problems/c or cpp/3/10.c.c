#include <stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int arr1[n];
    int arr2[n];
    int i=0;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&arr2[i]);
    }
    i=0;
    int j=0;
    int k=0;
    int min=abs(arr[0]-arr1[0])+abs(arr1[0]-arr2[0])+abs(arr2[0]-arr[0]);
    for(;;){
            if((abs(arr[i]-arr1[j])+abs(arr1[j]-arr2[k])+abs(arr2[k]-arr[i]))<min){
                min=abs(arr[i]-arr1[j])+abs(arr1[j]-arr2[k])+abs(arr2[k]-arr[i]);
            }
            if(arr[i]<arr1[j]&&arr[i]<arr2[k]){
                i++;
            }
            else if(arr1[j]<arr[i]&&arr1[j]<arr2[k]){
                j++;
            }
            else if(arr2[k]<arr[i]&&arr2[k]<arr1[j]){
                k++;
            }
        if(i==n||j==n||k==n){
            break;
        }
    }
   // printf("i=%d\n",arr[i]);
   // printf("j=%d\n",arr1[j]);
   // printf("k=%d\n",arr2[k]);
    printf("%d\n",min);

return 0;
}
