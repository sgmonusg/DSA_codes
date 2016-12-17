#include<stdio.h>
int board[8][8]={0};

int is_safe_board()
{
	int row[8]={0},col[8]={0},diag1[15]={0},diag2[15]={0};
	int i,j;
	
	for(i=0;i<8;++i)
	for(j=0;j<8;++j)
	{
		if(board[i][j])
		{
			row[i]++;
			col[j]++;
			diag1[(j-i)+7]++;
			diag2[j+i]++;
		}
	}
	
	for(i=0;i<8;++i)
	if(row[i] > 1 || col[i] > 1)
		return 0;
	
	for(i=0;i<15;++i)
	if(diag1[i] > 1 || diag2[i] > 1)
		return 0;
	
	return 1;
}
int main()
{
	int i,j,t;
	for(i=0;i<8;++i)
	for(j=0;j<8;++j)
	{
		scanf("%d",&board[i][j]);
	}
	printf("%d\n",is_safe_board());
	return 0;
}
