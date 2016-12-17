#include<stdio.h>
#include<string.h>
struct string{
    char name[1000];
    int sum;
    int count;
};
/*void merge_sort(struct string no[],int left ,int right){
    if(right>left){
        int mid=(left+right)/2;
        merge_sort(no,left, mid);
        merge_sort(no,mid+1,right);
        merge(no,left,mid+1,right);
    }
}
void merge(struct string no[],int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int k=0;
    struct string b[left+right];
    while(i<=mid&&j<=right){
        if(no[i].count<no[i].count){
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

}*/
void count_sort()
struct string update_struct(struct string x){
    scanf("%s",x.name);
    int i=0;
    for(i=0;i<strlen(x.name);i++){
            x.sum=x.sum+(int)x.name[i];
    }
    int temp=x.sum;
    while(temp!=0){
        x.count+=temp%2;
        temp=temp/2;
    }

}
int main(){
    int n;
    scanf("%d",&n);
    struct string a[n];
    int i=0;
    for(i=0;i<n;i++){
        a[i]=update_struct(a[i]);
    }
    merge_sort(a,0,n-1);
    for(i=0;i<n;i++){
        printf("%s",a[i].a);
    }


}
