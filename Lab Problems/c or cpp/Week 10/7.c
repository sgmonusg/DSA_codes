#include<stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

typedef struct {
	struct node *top;
	int size;
} stack;

void push(stack *s,int k)
{
	if(s->top == NULL)
		s->size = 0;
	
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->num = k;
	new_node->next = (s->top);
	(s->top) = new_node;
	
	s->size++;
}
int pop(stack *s)
{
	if(s->top == NULL)
	{
		s->size = 0;
		return 0;
	}
	
	int n = s->top->num;
	
	struct node *tmp = s->top;
	s->top = s->top->next;
	free(tmp);
	s->size--;
	
	return n;
}
int is_empty(stack s)
{
	return (s.top == NULL);
}
int top(stack s)
{
	if(!is_empty(s))
		return s.top->num;
	return -1;
}

int main()
{
	int arr[] = {6, 2, 5, 4, 5, 1, 6},n=7,i,tp,area=0,max_area=0;
	stack stk;
	stk.top = NULL;
	
	for(i=0;i<n;)
	{
		if(is_empty(stk) || arr[top(stk)] < arr[i])
			push(&stk,i++);
		else
		{
			tp = top(stk);
			pop(&stk);
			area = arr[tp] * (is_empty(stk) ? i : i - top(stk) - 1);
			
			if(max_area < area)
				max_area = area;
		}
	}
	while(!is_empty(stk))
	{
		tp = top(stk);
		pop(&stk);
		area = arr[tp] * (is_empty(stk) ? i : i - top(stk) - 1);
		
		if(max_area < area)
			max_area = area;
	}
	printf("%d\n",max_area); /**/
	return 0;
}
