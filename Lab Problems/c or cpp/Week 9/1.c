#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[1001];
	scanf("%s",str);
	int n=strlen(str),i,hash[256]={0},q=0;
	
	for(i=0;i<n;++i)
		if(hash[str[i]] == 0)
			hash[str[i]] = ++q;
	
	char out[1001];
	for(i=0;i<256;++i)
	if(hash[i])
		out[hash[i]-1] = (char) i;
	out[q++] = '\0';
	
	printf("%s",out);
	return 0;
}
