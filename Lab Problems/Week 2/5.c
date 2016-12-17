#include<stdio.h>
#include<string.h>
typedef char string[1001];
void encrypt(string clear,int key)
{
	int n=strlen(clear),i,j=0,k;
	string cipher;
	for(k=0;k<key;++k)
	{
		for(i=k;i<n;i+=key)
			cipher[j++] = clear[i];
	}
	cipher[j++] = '\0';
	
	printf("%s\n",cipher);
	return;
}
int main()
{
	string line,clr={'\0'};
	char *tmp;
	gets(line);
	
	for(tmp = strtok(line," .\n\0"); tmp != NULL ;tmp = strtok(NULL," .\n\0"))
		strcat(clr,tmp);
	int k;
	scanf(" %d",&k);
	
	encrypt(clr,k);
	return 0;
}
