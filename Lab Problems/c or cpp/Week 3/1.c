#include<stdio.h>
int main()
{
	char dig_word[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	char ten_word[][10]={"zero","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	
	int n,flag=0;
	scanf("%d",&n);
	
	if(n > 100 && n%100 > 0)
		flag = 1;
	
	if(n/1000 > 0)
	{
		printf("%s thousand ",dig_word[n/1000]);
	}
	n %= 1000;
	
	if(n/100 > 0)
	{
		printf("%s hundered ",dig_word[n/100]);
	}
	n %= 100;
	
	if(flag)
		printf("and ");
	
	if(n/10 > 0)
	{
		printf("%s ",ten_word[n/10]);
	}
	n %= 10;
	
	if(n > 0)
	{
		printf("%s ",dig_word[n]);
	}
	return 0;
}
