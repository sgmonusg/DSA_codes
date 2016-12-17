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

void push(stack *stk, int val)
{
	if(stk->top == NULL)
		stk->size = 0;
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->num = val;
	new_node->next = stk->top;
	
	stk->top = new_node;
	stk->size++;
}

void pop(stack *stk)
{
	if(stk->top == NULL)
	{
		printf("Stack is Empty\n");
		return;
	}
	struct node *tmp = stk->top;
	stk->top = stk->top->next;
	free(tmp);
	
	stk->size--;
}

int top(stack stk)
{
	if(stk.top != NULL)
		return stk.top->num;
	return -1;
}

void display_stack(stack stk)
{
	if(stk.top == NULL)
	{
		printf("Stack is Empty\n");
		return;
	}
	struct node *tmp = stk.top;
	while(tmp != NULL)
	{
		printf("%d->",tmp->num);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

int main()
{
	stack stk;
	int i,n,tmp,count=0;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&tmp);
		while(top(stk) != -1 && tmp > top(stk))
		{
			count++;
			pop(&stk);
		}
		
		if(top(stk) != -1)
			count++;
		push(&stk,tmp);
	}
	printf("%d",count);
	
	return 0;
}
