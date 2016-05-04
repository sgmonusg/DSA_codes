#include<stdio.h>
int cmp(const void *p,const void *q){
    int *a=(int *)p;
    int *b=(int *)q;
    return ((*a)>(*b));
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int i=0;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),cmp);
    for(i=0;i<n;i++){
       printf("%d ",arr[i]);
    }
    printf("\n");
    int temp=1;
    int j=0;
    for(i=1;i<n;i++){
        if(arr[i-1]==arr[i]){
            temp++;
        }
        else{
            printf("%d %d;\n",arr[i-1],temp);
            temp=1;
        }
    }
    printf("%d %d;",arr[n-1],temp);
    return 0;
}
