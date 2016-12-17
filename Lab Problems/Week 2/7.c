#include<math.h>
#include<stdio.h>

int main()
{
	int i,n;
	scanf("%d",&n);
	n++;
	int lim = ceil(log10(n)),num = (pow(3,lim)-1)/2.0 - 1,p = pow(10,lim-1);
	
	for(i=lim-1;i>=0;--i)
	{
		if(n/p > 7)
			num += pow(3,i)*2;
		else if(n/p > 1)
			num += pow(3,i);
		
		n %= p;
		p /= 10;
	}
	printf("%d\n",num);
	return 0;
}
