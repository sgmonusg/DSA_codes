#include<stdio.h>
void push(int arr[],int a,int j){
    arr[j]=a;
}
int max_element(int arr[],int j){
    return arr[j];
}
int comb(int a,int b){
    if(a==1){
        return 1;
    }
    if(b==0){
        return 0;
    }
    int sum=1;
    sum=sum*a;
    return sum;

}
void print(int arr[],int j){
    int i=0;
    for(i=j-1;i>=0;i--){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[100];
    int arr1[100];
    int i=0;
    for(i=0;i<100;i++){
        arr[i]=0;
        arr1[i]=0;
    }
    int j=0;
    int a;
    int count=0;
    for(i=0;i<n;i++){
            scanf("%d",&a);
            push(arr,a,j);
           // print(arr,j);
           int max;
           if(j!=0)
            max=max_element(arr1,j-1);
           else
            max=0;
            //printf("MAX =%d\n",max);
            if(a>=max){
                int k=j;
              // printf("k=%d\n",k);
                int c=0;
                while(k-1>=0&&max_element(arr1,k-1)==max){
                      //  printf("fine\n");
                    k--;
                    c++;
                }
               //printf("c=%d\n",c);
               if(c==1)
                count=count+comb(c,c-1);
                else
                    count=count+comb(c+1,c);
                //printf("count=%d\n",count);
                push(arr1,a,j);
                //print(arr1,j);
            }
            else{
                push(arr1,max,j);
            }
           // printf("j=%d\n",j);
            j++;
           // printf("j=%d\n",j);
    }
    print(arr,j);
    print(arr1,j);
    printf("%d\n",count);

}
