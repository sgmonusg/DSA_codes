#include<stdio.h>
int strlen(char *str){
    int len=0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}

char *strcpy(char *dest, char *src){
    int i=0;
    while(*(src+i)!='\0'){
        dest[i]=src[i];
        i++;
    }
    return dest;

 }

char *strcat(char *dest, char *src){
    char str[strlen(src)+strlen(dest)+1];
    int i=0;
    int j=0;
    while(i<strlen(src)){
        str[i]=src[i];
        i++;
    }
    while(j<strlen(dest)){
        str[i]=dest[j];
        i++;
        j++;
    }
    str[strlen(src)+strlen(dest)]='\0';
    return str;
}
int main(){
    char str[1000];
    char str1[1000];
        scanf("%s",str1);
        scanf(" %s",str);
    char *des;
    des=strcpy(des,str);

    char *dest;
    dest=strcat(str,str1);
    printf("%d\n",strlen(str));
    printf("%s",des);
    printf("%s",dest);
}
