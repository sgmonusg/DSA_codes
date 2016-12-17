#include<stdio.h>
#include<string.h>
typedef char string[10001];
int main()
{
	string str;
	char *cpy;
	int long_comment_flag=0;
	
	FILE *fp = fopen("code.txt","r+");
	
	while(fgets(str,10000,fp) != NULL)
	{
		int i,lim=strlen(str);
		
		cpy = str;
		for(i=0;i<lim-1;++i)
		{
			if(str[i] == '/' && str[i+1] == '*')
			{
				long_comment_flag = 1;
				cpy[i] = '\0';
				printf("%s",cpy);
				cpy += strlen(cpy);
				continue;
			}
			if(long_comment_flag)
			{
				if(str[i] == '*' && str[i+1] == '/')
				{
					cpy = (str+i+2);
					long_comment_flag = 0;
				}
				else
					cpy = '\0';
			}
			
			if(str[i] == '/' && str[i+1] == '/')
			{
				cpy[i+1] = '\0';
				cpy[i] = '\n';
				break;
			}
		}
		if(cpy != NULL)
			printf("%s",cpy);
	}
	
	return 0;
}
