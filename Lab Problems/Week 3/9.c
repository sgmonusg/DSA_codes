#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fin;
	char line[10001],*word;
	
	int line_count=0,word_count=0,char_count_spaces=0,char_count_nospace=0;
	
	fin = fopen("file.txt","r");
	for( ; fgets(line,10000,fin) != NULL ; line_count++)
	{
		char_count_spaces += strlen(line);
		
		for(word = strtok(line," .\n\0"); word != NULL ;word = strtok(NULL," .\n\0"))
		{
			word_count++;
			//printf("%s ",word);
			//char_count_nospace += strlen(word);
		}
	}
	fclose(fin);
	
	printf("Line Count: %d\n",line_count);
	printf("Word Count: %d\n",word_count);
	printf("Character Count: %d\n",char_count_spaces);
	
	return 0;
}
