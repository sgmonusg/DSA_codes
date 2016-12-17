#include<stdio.h>
int main(){
    int count=0;
    int n;
    scanf("%d",&n);
    char c[100];
    int i=n;
    scanf("%s",c);
    for(i=0;i<n;i++){
    if(c[i]=='('){
        count++;
       }
    else{
        if(count>0){
            count--;
        }
        else{
            count++;
        }
    }
    }
    printf("%d\n",count);
    return 0;
}
