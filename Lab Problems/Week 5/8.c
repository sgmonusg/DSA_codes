#include<stdio.h>
#include<string.h>
typedef struct {
	char str[51];
	int ones;
}string;

int find_ones(char str[])
{
	int j,count=0,char_sum=0,len=strlen(str);
	for(j=0;j<len;++j)
		char_sum += str[j];
	while(char_sum)
	{
		if(char_sum%2)
			count++;
		char_sum /= 2;
	}
	return count;
}

int main()
{
	int n,i,j,count,char_sum,no_ones[16]={0},len;
	scanf("%d",&n);
	
	string list[n],cpy[n];
	for(i=0;i<n;++i)
	{
		scanf(" %s",list[i].str);
		
		count = find_ones(list[i].str);
		no_ones[count]++;
		list[i].ones = count;
	}
	
	for(i=1;i<16;++i)
		no_ones[i] += no_ones[i-1];
	
	for(i=n-1;i>=0;--i)
	{
		cpy[no_ones[list[i].ones]-1] = list[i];
		no_ones[list[i].ones]--;
	}
	for(i=0;i<n;++i)
		printf("%s\n",cpy[i].str);
	
	return 0;
}
