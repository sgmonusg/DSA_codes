#include<math.h>
#include<stdio.h>
int dist(int a,int b,int c)
{
	return abs(b-a)+abs(c-b)+abs(a-c);
}
int min(int a,int b)
{
	return a<b ? a : b;
}
int max(int a,int b)
{
	return a>b ? a : b;
}
int main()
{
	int a[100],b[100],c[100],i,j,k,p,q,r,min_dist=dist(a[0],b[0],c[0])/2;
	int minim,maxim;
	int d1,d2,d3;
	
	for(i=0;j=0,k=0;i<p && j<q && k<r;)
	{
		minim = min(a[i],min(b[j],c[k]));
		maxim = max(a[i],max(b[j],c[k]));
		
		if(maxim - minim < min_dist)
			min_dist = maxim - minim;
		
		if(a[i] == minim) i++;
		else if(b[j] == minim) j++;
		else k++;
	}
	
	printf("%d\n",min_dist*2);
	return 0;
}
