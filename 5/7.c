#include<stdio.h>
void main(){
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    int arr[n];
    int i=0;
    int temp=0;
    int temp1=0;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    i=0;
    int j=m-1;
    int k=0;
    while(j!=0){
        for(k=i;k<=j;k++){
            if(k!=j&&arr[k]!=0){
                arr[k]--;
            }
            else if(k==j){
                temp++;
            }
            else if(arr[k]==0){
                temp1++;
                int g=0;
                for(g=i;g<k;g++){
                    arr[g]++;
                }
                for(g=k;g<n-temp1;g++){
                    arr[g]=arr[g+1];
                }
                arr[n-temp1]=0;
                break;
            }
        }
    }
    printf("%d",temp);
}
