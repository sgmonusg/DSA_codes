#include<ctype.h>
#include<stdio.h>
int main()
{
	char argv[][20]={"tolower","file.txt"};
	
	int i;
	char word[100],f='n',ch;
	
	if(strcmp(argv[0],"tolower") == 0)
		f = 'l';
	else if(strcmp(argv[0],"toupper") == 0)
		f = 'u';
	
	FILE *file = fopen(argv[1],"r+");
	
	while((ch = getc(file)) != EOF)
	{ 
		if(f == 'l' || f == 'h')
		{
			fseek(file,-1,SEEK_CUR);
			
			if(f == 'l')
				fputc(tolower(ch),file);
			else
				fputc(toupper(ch),file);
			
			fseek(file,0,SEEK_CUR);
		}
	}
	
	fclose(file);
	return 0;
}
