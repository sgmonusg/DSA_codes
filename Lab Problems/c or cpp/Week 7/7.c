#include<stdio.h>
#include<stdlib.h>

struct node {
	char b;
	struct node *next;
};

typedef struct {
	struct node *top;
	int size;
} stack;

void stack_push(stack *s,char v)
{
	if(s->top == NULL)
		s->size = 0;
	
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->b = v;
	new_node->next = s->top;
	s->top = new_node;
	
	s->size++;
}

void stack_pop(stack *s)
{
	if(s->top == NULL)
	{
		printf("Stack is Empty\n");
		s->size = 0;
		return;
	}
	
	struct node *tmp = s->top;
	if(s->top->next != NULL)
		s->top = s->top->next;
	else
		s->top = NULL;
	free(tmp);
	
	s->size--;
	return;
}

char stack_top(stack s)
{
	if(s.top == NULL)
		return 0;
	return (s.top->b);
}

int main()
{
	char str[501];
	stack stk;
	stk.top = NULL;
	int i;
	scanf("%s",str);
	
	/*
	for(i=0; str[i]!='\0' ;++i)
	{
		stack_push(&stk,str[i]);
	}
	display_stack(stk);
	printf("%d",stk.size);
	for(i=0; str[i]!='\0' ;++i)
	{
		stack_pop(&stk);
	}
	stack_pop(&stk); /**/
	
	for(i=0; str[i]!='\0' ;++i)
	{
		if(str[i] == ')' && stack_top(stk) == '(')
			stack_pop(&stk);
		else
			stack_push(&stk,str[i]);
	}
	printf("%d\n",stk.size); /**/
	return 0;
}
