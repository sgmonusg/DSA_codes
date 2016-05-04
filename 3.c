#include<stdio.h>
int main(){
    char a[1000];
    scanf(" %[^\n]s",a);
    int i=0;
    int arr[255];
    for(i=0;i<256;i++){
        arr[i]=0;
    }
    i=0;
    while((a[i]!='\0')){
        arr[(int)a[i]]++;
        i++;
    }
    for(i=0;i<256;i++){
        if(arr[i]!=0){
            char s=(char)i;
            printf("%c",s);
            printf("%d",arr[i]);
            printf("\n");

        }
        else
            continue;
    }


return 0;
}
