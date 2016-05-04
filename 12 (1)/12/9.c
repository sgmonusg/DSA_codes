#include <stdio.h>
#include <stdlib.h>

long long  fast_exp(int base, int exp)
{
    long long res=1;
	while(exp>0)
    	{
        	if(exp%2==1)
            		res=(res*base);
       		base=(base*base);
       		exp/=2;
    	}
	return res;
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    long long int ans = fast_exp(a,b);
    printf("\n %lld \n",ans);
    return 0;
}
