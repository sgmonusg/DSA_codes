#include<stdio.h>
int main()
{
	int small[]={1,0,2,3,4,5,6,7,8,9},large[]={9,8,7,6,5,4,3,2,1,0},n,k,i,j;
	scanf("%d %d",&n,&k);
	
	for(i=1,printf("1");i<n-k;++i)
		printf("0");
	for(j=i;j<n;++j)
		printf("%d",small[j-i+1]);
	printf(" ");
	
	for(i=0;i<n-k;++i)
		printf("9");
	for(j=i;j<n;++j)
		printf("%d",large[j-i]);
	return 0;
}
