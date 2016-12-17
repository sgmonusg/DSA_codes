#include<stdio.h>
#include<string.h>
int longest_repeated_substring(char str[])
{
	int count=0,n=strlen(str),i,j,k,a,b,c,flag=0,s=0,e=0;
	char lrs[100],tmp[100];
	
	for(c=1;c<=n;++c)
	{
		for(a=0;a<=n-c;++a)
		{
			flag = 1;
			for(b=a;b<a+c;++b)
				tmp[b-a] = str[a];
			
			for(i=a+1;i<=n-c;++i)
			{
				for(j=0;j<c;++j)
				{
					if(tmp[j] != str[i+j])
					{
						flag = 0;
						break;
					}
					printf("%c",tmp[j]);
				}
			}
			printf("\n");
		}
	}
}

int main()
{
	char T[501];
	scanf("%s",T);
	longest_repeated_substring(T);
	return 0;
}
