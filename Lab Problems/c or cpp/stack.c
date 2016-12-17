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

void push(stack *stk,int n)
{
	if(stk->top == NULL)
		stk->size = 0;
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->num = n;
	new_node->next = stk->top;
	
	stk->top = new_node;
	stk->size++;
}

int pop(stack *stk)
{
	if(stk->top == NULL)
	{
		printf("Stack is Empty!\n");
		return 0;
	}
	
	struct node *tmp = stk->top;
	int n = stk->top->num;
	
	stk->top = stk->top->next;
	free(tmp);
	stk->size--;
	
	return n;
}

int top(stack stk)
{
	return stk.top->num;
}

int main()
{
	stack stk;
	stk.top = NULL;
	int n;
	scanf("%d",&n);
	push(&stk,n);
	printf("%d\n",pop(&stk));
	return 0;
}
