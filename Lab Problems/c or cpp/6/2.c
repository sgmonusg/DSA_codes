#include<stdio.h>
int find_candidate(int arr[],int n){
    int count=1;
    int i=1;
    int max=arr[0];
    while(i<n){
        if(arr[i]==max){
            count++;
        }
        else
            count--;
        if(count==0){
            max=arr[i];
            count=1;
        }
        i++;
        }
        return max;
    }

int main(){
    int n;
    scanf("%d",&n);
    int i=0;
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max=find_candidate(arr,n);
    printf("max is %d\n",max);
    int count=0;
    for(i=0;i<n;i++){
        if(arr[i]==max){
            count++;
        }
    }
    if(count>n/2){
        printf("%d\n",max);
    }
    else{
        printf("none\n");
    }
    return 0;
}
