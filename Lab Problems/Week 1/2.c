#include<stdio.h>
typedef char *string;
int main()
{
	string word,*txt,tmp;
	int i,len,count=0;
	scanf("%s ",word);
	getline(stdin,txt);
	
	for(i=0;i<10;++i)
	{
		sscanf(txt," %s",tmp);
		printf("%s\n",tmp);
		if(strcmp(word,tmp) == 0)
			count++;
	}
	printf("%d\n",count);
	return 0;
}
