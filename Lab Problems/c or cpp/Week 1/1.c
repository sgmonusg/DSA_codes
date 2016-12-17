#include<stdio.h>

int strlen(char *str)
{
	int len;
	for(len=0;str[len] != '\0';++len);
	return len;
}
char *strcpy(char *dest, char *src)
{
	int i;
	for(i=0;src[i]!='\0';++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return dest;
}
int main()
{
	
}
