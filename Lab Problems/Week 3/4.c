#include<stdio.h>

int main()
{
	int mat[10][10]={0};
	int n,i,j,q;
	scanf("%d",&n);
	
	int l=0,r=n-1,u=0,d=n-1;
	for(q=1,i=0,j=0;l<=r && u <= d;)
	{
		i=u; j=l;
		for(j=l;j<r;++j)
			mat[i][j] = q++;
		for(i=u;i<d;++i)
			mat[i][j] = q++;
		for(j=r;j>l;--j)
			mat[i][j] = q++;
		for(i=d;i>u;--i)
			mat[i][j] = q++;
		
		l++; r--; u++; d--;
	}
	
	for(i=0;i<n;++i,printf("\n"))
	for(j=0;j<n;++j)
		printf("%d ",mat[i][j]);
	return 0;
}

