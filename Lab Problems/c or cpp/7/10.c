#include<stdio.h>
void insert_element(int arr[],int a,int i){
    arr[i]=a;
    int j=i;
    while(j!=0){
        if(j%2==0){
            if(arr[j]<arr[j/2]){
                break;
            }
            else{
                int temp=arr[j/2];
                arr[j/2]=arr[j];
                arr[j]=temp;
                j=j/2;
            }
        }
        else{
            if(arr[j]<arr[j/2]&&arr[j]<arr[j-1]){
                break;
            }
            else if(arr[j]<arr[j/2]&&arr[j]>arr[j-1]){
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                break;
            }
            else{
               int temp=arr[j/2];
                arr[j/2]=arr[j];
                arr[j]=temp;
                j=j/2;
            }

        }
    }

}
void delete_element(int arr[],int i){
    //printf("%d",arr[i]);
    arr[0]=arr[i-1];
    arr[i]=0;
    int j=i-1;
    while(j<i-1/2){
        int left=(j*2);
        int right=left+1;
        if(arr[j]<arr[left]||arr[j]<arr[right]){
                if(arr[left]<arr[right]){
            int temp=arr[right];
            arr[right]=arr[j];
            arr[j]=temp;
            j=right;
                }
                else{
            int temp=arr[left];
            arr[left]=arr[j];
            arr[j]=temp;
            j=left;

                }
        }
        else{
            break;
        }
    }
}

void menu(){
    printf("*************************************************\n");
    printf("PRESS 1 TO INSERT AN ELEMENT IN HEAP\n");
    printf("PRESS 2 TO DELETE MAX ELEMENT\n");
    printf("PRESS 3 TO DISPLAY MAX ELEMENT\n");
    printf("press 4 to display heap\n");
    printf("*****************************************************\n");

}
int main(){
    int arr[100];
    int i=0;
    for(i=0;i<100;i++){
       arr[i]=0;
    }
    int n=2;
    i=0;
    while(n<5&&n>0){
        menu();
        scanf("%d",&n);
        if(n==1){
            int a;
            printf("enter the no u want to add\n");
            scanf("%d",&a);
            insert_element(arr,a,i);
            i++;
        }
        else if(n==2){
            delete_element(arr,i);
            i--;
        }
        else if(n==3){
            printf("%d\n",arr[0]);
        }
        else if(n==4){
                int j=0;
            for(j=0;j<i;j++){
                printf("%d ",arr[j]);
            }
            printf("\n");
        }
        else
            return 0;
    }
    return 0;
}


