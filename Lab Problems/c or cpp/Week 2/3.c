#include<stdio.h>
typedef struct {
	int row,col,value;
}tuple;

int main()
{
	int mat[6][6]={0},num=0,i,j;
	
	for(i=0;i<6;++i)
	for(j=0;j<6;++j)
	{
		scanf("%d ",&mat[i][j]);
		if(mat[i][j])
			num++;
	}
	
	return 0;
}
