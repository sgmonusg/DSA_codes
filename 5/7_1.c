#include<stdio.h>
int cmp(const void *a,const void *b){
    int *p=(int *)a;
    int *q=(int *)b;
    return ((*p)>(*q));
}
int main(){
    int n;
    int m;
    scanf("%d",&n);
    scanf("%d",&m);
    int arr[n];
    int i=0;
    int temp=0;
    int j=0;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),cmp);
    //for(i=0;i<n;i++){
      //  printf("%d",arr[i]);
    //}
    for(i=0;i+m<=n;i++){
            int temp1=arr[i];
            temp=temp+arr[i];
        for(j=i;j<i+m;j++){
            arr[j]=arr[j]-temp1;
            printf("arr[j]=%d\n",arr[j]);
        }
        for(j=0;j<n;j++){
            printf("%d ",arr[j]);
        }
    }
    printf("%d",temp);

    return 0;
}
