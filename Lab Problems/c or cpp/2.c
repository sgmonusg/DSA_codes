#include<stdio.h>
#include<string.h>

int count=0;
int j=0;
char l[100][100];


int length(char *a){
int i=0;
int len=0;
while(a[i]!='\0'){
len++;
i++;}
//printf("%d\n",len);
return len;

}





void equal(char *b,char *t){
if(length(b)==length(t))
{
int temp=0;
int i=0;
for(i=0;i<length(b);i++){
    if(b[i]==t[i]){
        temp++;
    }
    else{
        temp=-1;
        break;
    }
}
    if(temp==length(b)){
        count++;
        //printf("%d",temp);
    }

}
}


void stringTokenizer(char *a){
    int i=0;j=0;
int k=0;
for(i=0;i<length(a);i++){
if(a[i]!=' '&& a[i]!='\0'){
        l[j][k]=a[i];
        k++;
}
else{
        l[j][k]='\0';
    k=0;
    j++;
}

}
//for(i=0;i<=j;i++){
    //printf("Wor is:%s\n",l[i]);
//}

}
int main(){
    char t[100];
    char a[1000];
    scanf("%s",t);
    scanf(" %[^\n]s",a);
    //printf("ja;kf=%d\n",length(a));

    stringTokenizer(a);
    int i=0;
    for(i=0;i<=j;i++){
        equal(l[i],t);
    }
    printf("%d",count);
    return 0;
}
