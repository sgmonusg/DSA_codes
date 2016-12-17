#include<stdio.h>
void char_seq(char c)
{
	switch(c)
	{
		case 'a': printf("%d",2); break;
		case 'b': printf("%d",22); break;
		case 'c': printf("%d",222); break;
		case 'd': printf("%d",3); break;
		case 'e': printf("%d",33); break;
		case 'f': printf("%d",333); break;
		case 'g': printf("%d",4); break;
		case 'h': printf("%d",44); break;
		case 'i': printf("%d",444); break;
		case 'j': printf("%d",5); break;
		case 'k': printf("%d",55); break;
		case 'l': printf("%d",555); break;
		case 'm': printf("%d",6); break;
		case 'n': printf("%d",66); break;
		case 'o': printf("%d",666); break;
		case 'p': printf("%d",7); break;
		case 'q': printf("%d",77); break;
		case 'r': printf("%d",777); break;
		case 's': printf("%d",7777); break;
		case 't': printf("%d",8); break;
		case 'u': printf("%d",88); break;
		case 'v': printf("%d",888); break;
		case 'w': printf("%d",9); break;
		case 'x': printf("%d",99); break;
		case 'y': printf("%d",999); break;
		case 'z': printf("%d",9999); break;
		case ' ': printf("%d",0); break;
		
		default : break;
	}
	return;
}
int main()
{
	char line[1001];
	gets(line);
	int i;
	for(i=0;line[i] != '\0';++i)
	{
		char_seq(line[i]);
		while(line[i] == line[i+1])
		{
			printf(" ");
			char_seq(line[i+1]);
			++i;
		}
	}
	return 0;
}
