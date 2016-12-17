#include<stdio.h>
struct num{
    int a;
    int b;
};
merge_sort(struct num no[],int left ,int right){
    if(right>left){
        int mid=(left+right)/2;
        merge_sort(no,left, mid);
        merge_sort(no,mid+1,right);
        merge(no,left,mid+1,right);
    }
}
merge(struct num no[],int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int k=0;
    struct num b[left+right];
    while(i<=mid&&j<=right){
        if(no[i].b<no[i].b){
            b[k++]=no[i++];
        }
        else{
            b[k++]=no[j++];
        while(i<=mid)
            b[k++]=no[i++];
        while(j<=right){
            b[k++]=no[j++];
        }
    }
        k=0;
        for(i=left;i<right;i++){
            no[i]=b[k++];
        }
    }

}

struct num update_struct(struct num x){
    scanf("%d",&x.a);
    x.b=x.a%10;
    return x;
}
int main(){
    int n,i;
    scanf("%d",&n);
    struct num no[n];
    for(i=0;i<n;i++){
        no[i]=update_struct(no[i]);
    }
    merge_sort(no,0,n-1);
    for(i=0;i<n-1;i++){
        printf("%d ,",no[i].a);
    }
    printf("%d",no[n-1].a);
    return 0;
}
