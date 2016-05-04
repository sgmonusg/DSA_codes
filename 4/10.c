#include<stdio.h>
#include<string.h>
int j=0;
char l[100][100];
void stringTokenizer(char *a){
    int i=0;j=0;
int k=0;
for(i=0;i<strlen(a);i++){
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
for(i=0;i<=j;i++){
    printf("Wor is:%s\n",l[i]);
}

for(i=0;i<=j;i++){
        int n=strlen(l[i]);
        printf("len=%d\n",n);
    for(k=0;k<n/2;k++){
        char temp=l[i][k];
        l[i][k]=l[i][n-k-1];
        l[i][n-k-1]=temp;
    }
}
for(i=0;i<=j;i++){
    printf("Wor is:%s\n",l[i]);
}

}
int main(){
    char str[1000];
    //*str=str;
    scanf("%[^\n]s",str);
    //printf("%s",str);
    int n=strlen(str);
    int i=0;
    char temp;
    for(i=0;i<n/2;i++){
        temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
    //printf("%s",str);
    stringTokenizer(str);

    return 0;
}
