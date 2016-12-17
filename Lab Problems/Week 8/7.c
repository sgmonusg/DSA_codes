#include<stdio.h>
#include<stdlib.h>

#define n 10

typedef struct {
	int i,j;
} pair;

pair make_pair(int a,int b)
{
	pair s;
	s.i = a;
	s.j = b;
	return s;
}

typedef struct {
	pair stk[1000];
	int size;
} stack;

void push(stack *s,pair val)
{
	s->stk[s->size++] = val;
}

pair pop(stack *s)
{
	if(s->size > 0)
		return s->stk[--s->size];
	else return make_pair(-1,-1);
}

pair top(stack *s)
{
	return s->stk[s->size-1];
}

int is_empty(stack s)
{
	return (s.size > 0);
}

int is_valid(int maze[n][n], int i, int j)
{
	if(i < 0 || j < 0 || i >= n || j >= n)
		return 0;
	return maze[i][j];
}

void print_stack(stack s)
{
	int i=s.size;
	while(i--)
		printf("%d %d\n",s.stk[i].i,s.stk[i].j);
}

void solve_maze(int maze[n][n], int sol[n][n])
{
	int i=0,j=0,f=1;
	pair tmp;
	
	stack s;
	s.size = 0;
	
	while(i != n-1 && j != n-1 && f)
	{
		if(is_valid(maze,i,j) && sol[i][j] == 0)
		{
			sol[i][j] = 1;
			if(is_valid(maze,i-1,j))
				push(&s,make_pair(i-1,j));
			if(is_valid(maze,i,j-1))
				push(&s,make_pair(i,j-1));
			if(is_valid(maze,i+1,j))
				push(&s,make_pair(i+1,j));
			if(is_valid(maze,i,j+1))
				push(&s,make_pair(i,j+1));
		}
		
		tmp = pop(&s);
		
		i = tmp.i;
		j = tmp.j;
		
		//printf("%d %d\n",i,j);
		
		if(i < 0 && j < 0)
			f = 0;
	}
}

int main()
{
	int maze[n][n] =  { {1,1,1,1,1,1,1,0,0,0},
	{1,0,1,1,0,0,0,0,0,0},
	{1,1,0,0,1,1,0,0,0,0},
	{1,0,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,1,1,1,0,0,0},
	{0,0,0,0,1,0,0,1,1,1},
	{0,0,0,0,1,1,1,1,0,1},
	{0,0,0,1,1,1,1,1,0,1} };
	
	int sol[n][n] = {0},i,j;
	
	solve_maze(maze,sol);
	
	for(i=0;i<n;++i,printf("\n"))
	for(j=0;j<n;++j)
		printf("%d ",sol[i][j]);
	return 0;
}
