#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void print(int n,int t)
{
	while(t--)
		printf("%d",n);
}

int main()
{
	
	
	char* k[10];
	k[1] = "%";
	k[2] = "abc";
	k[3] = "def";
	k[4] = "ghi";
	k[5] = "jkl";
	k[6] = "mno";
	k[7] = "pqrs";
	k[8] = "tuv";
	k[9] = "wxyz";
	k[0] = " ";
	
	
	int i,j,q,flag1 = -1,flag2 = 0;
	char w[100];
	scanf("%[^\n]s",w);
	int n = strlen(w);
	for (i = 0;i < n;i++)
	{
		for (j = 0;j<10;j++)
		{
			for(q = 0;k[j][q] != '\0';q++)
			{
				if(w[i] == k[j][q])
				{
					flag2 = j;
					if(flag1 == flag2)
						printf(" ");
					flag1 = j;
					print(j,q+1);
				}
			}
		}
		
	}
	printf("\n");
	return 0;
}
